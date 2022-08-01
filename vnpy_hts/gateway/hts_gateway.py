from typing import Any, Dict, List
from datetime import datetime
from copy import copy

from vnpy.event import EventEngine
from vnpy.trader.event import EVENT_TIMER
from vnpy.trader.constant import (
    Exchange,
    Product,
    Direction,
    OrderType,
    Status,
    Offset,
    OptionType
)
from vnpy.trader.gateway import BaseGateway
from vnpy.trader.object import (
    CancelRequest,
    OrderRequest,
    SubscribeRequest,
    TickData,
    ContractData,
    OrderData,
    TradeData,
    PositionData,
    AccountData
)
from vnpy.trader.utility import get_folder_path, ZoneInfo

from ..api import (
    MdApi,
    TdApi,
    DFITCSEC_EI_SH,
    DFITCSEC_EI_SZ,
    DFITCSEC_SOP_LimitPrice,
    DFITCSEC_SOP_LastPrice,
    DFITCSEC_OCF_Open,
    DFITCSEC_OCF_Close,
    DFITCSEC_ED_Buy,
    DFITCSEC_ED_Sell,
    DFITCSEC_OT_CALL,
    DFITCSEC_OT_PUT,
    DFITCSEC_COLLECTTYPE_APEX,
    DFITCSEC_COLLECTTYPE_HS,
    DFITCSEC_COLLECTTYPE_KD,
    DFITCSEC_COLLECTTYPE_KS,
    DFITCSEC_COMPRESS_TRUE,
    DFITCSEC_COMPRESS_FALSE
)


# 多空方向映射
DIRECTION_VT2HTS: Dict[Direction, int] = {
    Direction.LONG: DFITCSEC_ED_Buy,
    Direction.SHORT: DFITCSEC_ED_Sell
}
DIRECTION_HTS2VT: Dict[int, Direction] = {v: k for k, v in DIRECTION_VT2HTS.items()}

# 委托类型映射
OPTION_PRICE_TYPE_HTS2VT: Dict[int, OrderType] = {
    DFITCSEC_SOP_LimitPrice: OrderType.LIMIT,
    DFITCSEC_SOP_LastPrice: OrderType.MARKET
}
OPTION_PRICE_TYPE_VT2HTS: Dict[OrderType, int] = {v: k for k, v in OPTION_PRICE_TYPE_HTS2VT.items()}

# 开平方向映射
OFFSET_VT2HTS: Dict[Offset, int] = {
    Offset.OPEN: DFITCSEC_OCF_Open,
    Offset.CLOSE: DFITCSEC_OCF_Close,
}
OFFSET_HTS2VT: Dict[int, Offset] = {v: k for k, v in OFFSET_VT2HTS.items()}

# 交易所映射
EXCHANGE_HTS2VT: Dict[str, Exchange] = {
    DFITCSEC_EI_SH: Exchange.SSE,
    DFITCSEC_EI_SZ: Exchange.SZSE
}
EXCHANGE_VT2HTS: Dict[Exchange, str] = {v: k for k, v in EXCHANGE_HTS2VT.items()}

# 期权类型映射
OPTION_TYPE_HTS2VT: Dict[int, OptionType] = {
    DFITCSEC_OT_CALL: OptionType.CALL,
    DFITCSEC_OT_PUT: OptionType.PUT
}

# 对冲方向映射
HEDGE_DIRECTION: Dict[int, int] = {
    DFITCSEC_ED_Buy: 2,
    DFITCSEC_ED_Sell: 1
}

# 采集类型映射
COLLECTION_TYPE_VT2HTS: Dict[str, int] = {
    "顶点": DFITCSEC_COLLECTTYPE_APEX,
    "恒生": DFITCSEC_COLLECTTYPE_HS,
    "金证": DFITCSEC_COLLECTTYPE_KD,
    "金仕达": DFITCSEC_COLLECTTYPE_KS
}

# 行情压缩映射
COMPRESS_VT2HTS: Dict[str, int] = {
    "Y": DFITCSEC_COMPRESS_TRUE,
    "N": DFITCSEC_COMPRESS_FALSE
}

# 其他常量
CHINA_TZ = ZoneInfo("Asia/Shanghai")       # 中国时区

# 合约数据全局缓存字典
symbol_contract_map: Dict[str, ContractData] = {}


class HtsGateway(BaseGateway):
    """
    VeighNa用于对接顶点HTS期权柜台的交易接口。
    """

    default_name: str = "HTS"

    default_setting: Dict[str, Any] = {
        "账号": "",
        "密码": "",
        "行情地址": "",
        "交易地址": "",
        "行情协议": ["TCP", "UDP"],
        "授权码": "",
        "产品号": "",
        "采集类型": ["顶点", "恒生", "金证", "金仕达"],
        "行情压缩": ["N", "Y"],
    }

    exchanges: List[Exchange] = list(EXCHANGE_VT2HTS.keys())

    def __init__(self, event_engine: EventEngine, gateway_name: str) -> None:
        """构造函数"""
        super().__init__(event_engine, gateway_name)

        self.md_api: "HtsMdApi" = HtsMdApi(self)
        self.td_api: "HtsTdApi" = HtsTdApi(self)

    def connect(self, setting: dict) -> None:
        """连接交易接口"""
        accountid: str = setting["账号"]
        password: str = setting["密码"]
        md_address: str = setting["行情地址"]
        td_address: str = setting["交易地址"]
        quote_protocol: str = setting["行情协议"]
        auth_code: str = setting["授权码"]
        appid: str = setting["产品号"]
        collection_type: int = COLLECTION_TYPE_VT2HTS[setting["采集类型"]]
        compress_flag: int = COMPRESS_VT2HTS[setting["行情压缩"]]

        if (
            (not md_address.startswith("tcp://"))
            and (not md_address.startswith("ssl://"))
        ):
            md_address = "tcp://" + md_address

        if (
            (not td_address.startswith("tcp://"))
            and (not td_address.startswith("ssl://"))
        ):
            td_address = "tcp://" + td_address

        if quote_protocol == "UDP":
            md_address = md_address.replace("tcp", "udp")

        self.md_api.connect(
            accountid,
            password,
            md_address,
            auth_code,
            appid,
            collection_type,
            compress_flag,
        )
        self.td_api.connect(
            accountid,
            password,
            td_address,
            auth_code,
            appid,
            collection_type,
        )
        self.init_query()

    def subscribe(self, req: SubscribeRequest) -> None:
        """订阅行情"""
        self.md_api.subscrbie(req)

    def send_order(self, req: OrderRequest) -> str:
        """委托下单"""
        return self.td_api.send_order(req)

    def cancel_order(self, req: CancelRequest) -> None:
        """委托撤单"""
        self.td_api.cancel_order(req)

    def query_account(self) -> None:
        """查询资金"""
        self.td_api.query_account()

    def query_position(self) -> None:
        """查询持仓"""
        self.td_api.query_position()

    def close(self) -> None:
        """关闭接口"""
        self.md_api.close()
        self.td_api.close()

    def write_error(self, msg: str, error: dict) -> None:
        """输出错误信息日志"""
        error_id: int = error["errorID"]
        error_msg: str = error["errorMsg"]
        msg: str = f"{msg}，代码:{error_id}，信息:{error_msg}"
        self.write_log(msg)

    def process_timer_event(self, event) -> None:
        """定时事件处理"""
        self.count += 1
        if self.count < 2:
            return
        self.count = 0

        func = self.query_functions.pop(0)
        func()
        self.query_functions.append(func)

    def init_query(self) -> None:
        """初始化查询任务"""
        self.count: int = 0
        self.query_functions: list = [self.query_account, self.query_position]
        self.event_engine.register(EVENT_TIMER, self.process_timer_event)


class HtsMdApi(MdApi):
    """"""

    def __init__(self, gateway: HtsGateway) -> None:
        """构造函数"""
        super().__init__()

        self.gateway: HtsGateway = gateway
        self.gateway_name: str = gateway.gateway_name

        self.accountid: str = ""
        self.password: str = ""
        self.md_address: str = ""

        self.connect_status: bool = False
        self.login_status: bool = False
        self.compress_flag: int = 1
        self.auth_code: str = ""
        self.app_id: str = ""
        self.collection_type: int = 1

        self.reqid: int = 0
        self.subscribed: set = set()

        self.sse_inited: bool = False
        self.szse_inited: bool = False

    def onFrontConnected(self) -> None:
        """服务器连接成功回报"""
        self.gateway.write_log("行情服务器连接成功")
        self.connect_status = True

        self.login_server()

    def onFrontDisconnected(self, reason: int) -> None:
        """服务器连接断开回报"""
        self.connect_status = False
        self.login_status = False
        self.gateway.write_log(f"行情服务器连接断开, 原因{reason}")

    def onRspSOPUserLogin(self, data: dict, error: dict) -> None:
        """用户登录请求回报"""
        if not error:
            self.gateway.write_log("股票期权行情服务器登录成功")
            self.login_status = True
        else:
            self.gateway.write_error("股票期权行情服务器登录失败,", error)

    def onRspError(self, error: dict) -> None:
        """请求报错回报"""
        self.gateway.write_error("行情接口报错", error)

    def onRspSOPSubMarketData(self, data: dict, error: dict) -> None:
        """订阅行情回报"""
        if not error or not error["errorID"]:
            return

        self.gateway.write_error("股票期权行情订阅失败", error)

    def onSOPMarketData(self, data: dict) -> None:
        """行情数据推送"""
        timestamp: str = str(data["tradingDay"]) + str(data["updateTime"])
        dt: datetime = datetime.strptime(timestamp, "%Y%m%d%H:%M:%S.%f")
        dt: datetime = dt.replace(tzinfo=CHINA_TZ)

        tick: TickData = TickData(
            symbol=data["securityID"],
            exchange=EXCHANGE_HTS2VT[data["exchangeID"]],
            datetime=dt,
            volume=data["tradeQty"],
            last_price=data["latestPrice"],
            limit_up=data["upperLimitPrice"],
            limit_down=data["lowerLimitPrice"],
            open_price=data["openPrice"],
            high_price=data["highestPrice"],
            low_price=data["lowestPrice"],
            pre_close=data["preClosePrice"],
            gateway_name=self.gateway_name
        )
        tick.bid_price_1 = data["bidPrice1"]
        tick.bid_price_2 = data["bidPrice2"]
        tick.bid_price_3 = data["bidPrice3"]
        tick.bid_price_4 = data["bidPrice4"]
        tick.bid_price_5 = data["bidPrice5"]

        tick.ask_price_1 = data["askPrice1"]
        tick.ask_price_2 = data["askPrice2"]
        tick.ask_price_3 = data["askPrice3"]
        tick.ask_price_4 = data["askPrice4"]
        tick.ask_price_5 = data["askPrice5"]

        tick.bid_volume_1 = data["bidQty1"]
        tick.bid_volume_2 = data["bidQty2"]
        tick.bid_volume_3 = data["bidQty3"]
        tick.bid_volume_4 = data["bidQty4"]
        tick.bid_volume_5 = data["bidQty5"]

        tick.ask_volume_1 = data["askQty1"]
        tick.ask_volume_2 = data["askQty2"]
        tick.ask_volume_3 = data["askQty3"]
        tick.ask_volume_4 = data["askQty4"]
        tick.ask_volume_5 = data["askQty5"]

        contract: ContractData = symbol_contract_map.get(tick.symbol, None)
        if contract:
            tick.name = contract.name

        self.gateway.on_tick(tick)

    def connect(
        self,
        accountid: str,
        password: str,
        md_address: str,
        auth_code: str,
        appid: str,
        collection_type: int,
        compress_flag: int,
    ) -> None:
        """连接服务器"""
        self.accountid = accountid
        self.password = password
        self.md_address = md_address
        self.auth_code = auth_code
        self.app_id = appid
        self.collection_type = collection_type
        self.compress_flag = compress_flag

        if not self.connect_status:
            path: str = str(get_folder_path(self.gateway_name.lower()))
            self.createDFITCMdApi(path.encode("GBK"))
            self.init(md_address)

    def login_server(self) -> None:
        """用户登录"""
        self.reqid += 1
        data: dict = {
            "requestID": self.reqid,
            "accountID": self.accountid,
            "password": self.password,
            "compressflag": self.compress_flag,
            "authenticCode": self.auth_code,
            "appID": self.app_id,
            "collectInterType": self.collection_type
        }
        self.reqSOPUserLogin(data)

    def subscrbie(self, req: SubscribeRequest) -> None:
        """订阅行情"""
        if self.login_status:
            self.reqid += 1

            symbol: str = str(EXCHANGE_VT2HTS[req.exchange] + req.symbol)
            self.subscribeSOPMarketData(symbol, self.reqid)
            self.subscribed.add(req.symbol)

    def close(self) -> None:
        """关闭连接"""
        if self.connect_status:
            self.exit()


class HtsTdApi(TdApi):
    """"""

    def __init__(self, gateway: HtsGateway) -> None:
        """构造函数"""
        super().__init__()

        self.gateway: HtsGateway = gateway
        self.gateway_name: str = gateway.gateway_name

        self.accountid: str = ""
        self.password: str = ""
        self.auth_code: str = ""
        self.compress_flag: int = 0
        self.auth_code: str = ""
        self.app_id: str = ""
        self.collection_type: int = 1
        self.positions: Dict[str, PositionData] = {}

        self.sessionid: str = ""
        self.reqid: int = 0
        self.localid: int = 10000
        self.orders: Dict[str, OrderData] = {}

        self.connect_status: bool = False
        self.login_status: bool = False

    def onFrontConnected(self) -> None:
        """服务器连接成功回报"""
        self.gateway.write_log("交易服务器连接成功")
        self.connect_status = True

        self.login_server()

    def onFrontDisconnected(self, reason: int) -> None:
        """服务器连接断开回报"""
        self.connect_status = False
        self.login_status = False
        self.gateway.write_log(f"交易服务器连接断开, 原因{reason}")

    def onRspSOPUserLogin(self, data: dict, error: dict) -> None:
        """用户登录请求回报"""
        if not error:
            self.sessionid = str(data["sessionID"])

            self.gateway.write_log("股票期权交易服务器登录成功")
            self.login_status = True

            self.query_option_contracts("")
        else:
            self.gateway.write_error("股票期权交易服务器登录失败", error)

    def onRspError(self, error: dict) -> None:
        """请求报错回报"""
        self.gateway.write_error("交易接口报错", error)

    def onSOPEntrustOrderRtn(self, data: dict) -> None:
        """委托更新推送"""
        localid: str = str(data["localOrderID"])
        sessionid: str = str(data["sessionID"])
        orderid: str = f"{sessionid}_{localid}"

        timestamp: str = str(datetime.date(datetime.now())) + str(data["entrustTime"])
        dt: datetime = datetime.strptime(timestamp, "%Y-%m-%d%H:%M:%S.%f")
        dt: datetime = dt.replace(tzinfo=CHINA_TZ)

        if orderid in self.orders:
            order: OrderData = self.orders[orderid]
            order.datetime = dt
        else:
            order: OrderData = OrderData(
                symbol=data["securityID"],
                exchange=EXCHANGE_HTS2VT[data["exchangeID"]],
                orderid=orderid,
                direction=DIRECTION_HTS2VT[data["entrustDirection"]],
                offset=OFFSET_HTS2VT[data["openCloseFlag"]],
                price=data["entrustPrice"],
                volume=data["entrustQty"],
                datetime=dt,
                gateway_name=self.gateway_name
            )
            self.orders[orderid] = order

        if order.volume == order.traded:
            order.status = Status.ALLTRADED
        elif order.traded > 0:
            order.status = Status.PARTTRADED
        else:
            order.status = Status.NOTTRADED

        self.gateway.on_order(copy(order))

    def onSOPTradeRtn(self, data: dict) -> None:
        """成交数据推送"""
        timestamp: str = str(datetime.date(datetime.now())) + str(data["tradeTime"])
        dt: datetime = datetime.strptime(timestamp, "%Y-%m-%d%H:%M:%S.%f")
        dt: datetime = dt.replace(tzinfo=CHINA_TZ)
        localid: str = str(data["localOrderID"])
        sessionid: str = str(data["sessionID"])
        orderid: str = f"{sessionid}_{localid}"

        trade: TradeData = TradeData(
            symbol=data["securityID"],
            exchange=EXCHANGE_HTS2VT[data["exchangeID"]],
            tradeid=data["tradeID"],
            orderid=orderid,
            direction=DIRECTION_HTS2VT[data["entrustDirection"]],
            offset=OFFSET_HTS2VT[data["openCloseFlag"]],
            price=data["tradePrice"],
            volume=data["tradeQty"],
            datetime=dt,
            gateway_name=self.gateway_name
        )

        # 获取缓存的委托信息
        order: OrderData = self.orders.get(orderid, None)
        if not order:
            return

        order.traded += trade.volume
        order.traded = min(order.volume, order.traded)

        # 检查委托状态
        if order.volume == order.traded:
            order.status = Status.ALLTRADED
        elif order.traded > 0:
            order.status = Status.PARTTRADED

        order.datetime = trade.datetime

        self.gateway.on_order(copy(order))
        self.gateway.on_trade(trade)

        # 更新持仓数据
        if trade.offset == Offset.CLOSE:
            hedge_direction: int = HEDGE_DIRECTION[data["entrustDirection"]]
            trade_symbol: str = f"{data['securityID']}_{hedge_direction}"
            pos: PositionData = self.positions.get(trade_symbol, None)

            if not pos:
                return

            if trade.volume - pos.volume == 0:
                pos.volume = 0
                self.gateway.on_position(pos)

    def onSOPWithdrawOrderRtn(self, data: dict) -> None:
        """委托撤单数据推送"""
        localid: str = str(data["localOrderID"])
        sessionid: str = str(data["sessionID"])
        orderid: str = f"{sessionid}_{localid}"

        if orderid in self.orders:
            order: OrderData = self.orders[orderid]
        else:
            order: OrderData = OrderData(
                symbol=data["securityID"],
                exchange=EXCHANGE_HTS2VT[data["exchangeID"]],
                orderid=orderid,
                direction=DIRECTION_HTS2VT[data["entrustDirection"]],
                price=data["entrustPrice"],
                traded=data["tradeQty"],
                offset=OFFSET_HTS2VT[data["openCloseFlag"]],
                volume=data["tradeQty"] + data["withdrawQty"],
                gateway_name=self.gateway_name
            )
            self.orders[orderid] = order

        if data["withdrawQty"]:
            order.status = Status.CANCELLED

        self.gateway.on_order(copy(order))

    def onRspSOPEntrustOrder(self, data: dict, error: dict) -> None:
        """委托下单失败回报"""
        if error:
            localid: str = str(error["localOrderID"])
            sessionid: str = str(error["sessionID"])
            orderid: str = f"{sessionid}_{localid}"
            order: OrderData = self.orders.get(orderid, None)

            if order:
                dt: datetime = datetime.now()
                dt: datetime = dt.replace(tzinfo=CHINA_TZ)
                order.datetime = dt
                order.status = Status.REJECTED
                self.gateway.on_order(copy(order))

                self.gateway.write_error("期权委托错误", error)

    def onRspSOPWithdrawOrder(self, data: dict, error: dict) -> None:
        """委托撤单失败回报"""
        if error:
            self.gateway.write_error("撤单错误", error)

    def onRspSOPQryContactInfo(self, data: dict, error: dict, last: bool) -> None:
        """合约查询回报"""
        if not data["securityOptionID"]:
            self.gateway.write_log("期权交易合约信息获取成功")
            return

        contract: ContractData = ContractData(
            symbol=data["securityOptionID"],
            exchange=EXCHANGE_HTS2VT[data["exchangeID"]],
            name=data["contractName"],
            size=data["contactUnit"],
            pricetick=data["miniPriceChange"],
            product=Product.OPTION,
            option_portfolio=data["securityID"] + "_O",
            option_type=OPTION_TYPE_HTS2VT[data["optType"]],
            option_strike=data["execPrice"],
            option_underlying="-".join([data["securityID"], str(data["endDate"])[:-2]]),
            option_expiry=datetime.strptime(str(data["endDate"]), "%Y%m%d"),
            gateway_name=self.gateway_name
        )

        contract.option_index = get_option_index(
            contract.option_strike, data["contractID"]
        )

        symbol_contract_map[contract.symbol] = contract

        self.gateway.on_contract(contract)

        if last:
            index: str = data["exchangeID"] + data["securityOptionID"]
            self.query_option_contracts(index)

    def onRspSOPQryCapitalAccountInfo(self, data: dict, error: dict) -> None:
        """资金查询回报"""
        if not data:
            return

        account: AccountData = AccountData(
            accountid=data["accountID"],
            balance=data["totalFunds"],
            frozen=data["totalFunds"] - data["availableFunds"],
            gateway_name=self.gateway_name
        )
        self.gateway.on_account(account)

    def onRspSOPQryPosition(self, data: dict, error: dict, last: bool) -> None:
        """持仓查询回报"""
        if not data or not data["securityOptionID"]:
            return

        pos: PositionData = PositionData(
            symbol=data["securityOptionID"],
            exchange=EXCHANGE_HTS2VT[data["exchangeID"]],
            direction=DIRECTION_HTS2VT[data["entrustDirection"]],
            volume=data["totalQty"],
            price=data["openAvgPrice"],
            gateway_name=self.gateway_name
        )
        self.gateway.on_position(pos)

        pos_symbol: str = f"{data['securityOptionID']}_{data['entrustDirection']}"
        self.positions[pos_symbol] = pos

    def connect(
        self,
        accountid: str,
        password: str,
        td_address: str,
        auth_code: str,
        appid: str,
        collection_type: int,
    ) -> None:
        """连接服务器"""
        self.accountid = accountid
        self.password = password
        self.auth_code = auth_code
        self.app_id = appid
        self.collection_type = collection_type

        if not self.connect_status:
            path: str = str(get_folder_path(self.gateway_name.lower()))
            self.createDFITCSECTraderApi(path.encode("GBK"))

            self.init(td_address)

    def login_server(self) -> None:
        """用户登录"""
        # 在登录前订阅私有流
        self.subscribePrivateTopic(2)

        self.reqid += 1
        data: dict = {
            "requestID": self.reqid,
            "accountID": self.accountid,
            "password": self.password,
            "compressflag": self.compress_flag,
            "authenticCode": self.auth_code,
            "appID": self.app_id,
            "collectInterType": self.collection_type
        }
        self.reqSOPUserLogin(data)

    def send_order(self, req: OrderRequest) -> str:
        """委托下单"""
        self.reqid += 1
        self.localid += 1

        hts_req: dict = {
            "securityID": req.symbol,
            "exchangeID": EXCHANGE_VT2HTS[req.exchange],
            "entrustPrice": req.price,
            "entrustQty": int(req.volume),
            "localOrderID": self.localid,
            "accountID": self.accountid,
            "requestID": self.reqid,
            "entrustDirection": DIRECTION_VT2HTS[req.direction],
            "orderType": OPTION_PRICE_TYPE_VT2HTS[req.type],
            "openCloseFlag": OFFSET_VT2HTS[req.offset]
        }
        self.reqSOPEntrustOrder(hts_req)

        localid: str = str(self.localid)
        orderid: str = f"{self.sessionid}_{localid}"

        order: OrderData = req.create_order_data(orderid, self.gateway_name)
        self.orders[orderid] = order
        self.gateway.on_order(copy(order))

        return order.vt_orderid

    def cancel_order(self, req: CancelRequest) -> None:
        """委托撤单"""
        self.reqid += 1
        sessionid, localid = req.orderid.split("_")

        hts_req: dict = {
            "localOrderID": int(localid),
            "accountID": self.accountid,
            "requestID": self.reqid,
            "sessionID": int(sessionid)
        }

        self.reqSOPWithdrawOrder(hts_req)

    def query_account(self) -> None:
        """查询资金"""
        self.reqid += 1
        req: dict = {
            "requestID": self.reqid,
            "accountID": self.accountid
        }
        self.reqSOPQryCapitalAccountInfo(req)

    def query_position(self) -> None:
        """查询持仓"""
        self.reqid += 1
        req: dict = {
            "requestID": self.reqid,
            "accountID": self.accountid
        }
        self.reqSOPQryPosition(req)

    def query_option_contracts(self, index: str) -> None:
        """查询合约"""
        self.reqid += 1
        req: dict = {
            "requestID": self.reqid,
            "accountID": self.accountid,
            "rowIndex": index
        }
        self.reqSOPQryContactInfo(req)

    def close(self) -> None:
        """关闭连接"""
        if self.connect_status:
            self.exit()


def get_option_index(strike_price: float, exchange_instrument_id: str) -> str:
    """获取期权索引"""
    exchange_instrument_id: str = exchange_instrument_id.replace(" ", "")

    if "M" in exchange_instrument_id:
        n: int = exchange_instrument_id.index("M")
    elif "A" in exchange_instrument_id:
        n: int = exchange_instrument_id.index("A")
    elif "B" in exchange_instrument_id:
        n: int = exchange_instrument_id.index("B")
    else:
        return str(strike_price)

    index: str = exchange_instrument_id[n:]
    option_index: str = f"{strike_price:.3f}-{index}"

    return option_index

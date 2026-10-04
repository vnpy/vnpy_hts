from collections.abc import Callable, Iterator
from datetime import datetime
from typing import Any

import pytest

pytest.importorskip("vnpy_hts.api", reason="缺少 HTS 原生扩展")

from vnpy.event import EventEngine  # noqa: E402
from vnpy.trader.constant import (  # noqa: E402
    Direction,
    Exchange,
    Offset,
    OrderType,
    Status,
)
from vnpy.trader.object import (  # noqa: E402
    OrderData,
    OrderRequest,
    PositionData,
    TickData,
)

from vnpy_hts.api import (  # noqa: E402
    DFITCSEC_ED_Buy,
    DFITCSEC_EI_SH,
    DFITCSEC_OCF_Open,
    DFITCSEC_SOP_LimitPrice,
)
from vnpy_hts.gateway import hts_gateway  # noqa: E402
from vnpy_hts.gateway.hts_gateway import (  # noqa: E402
    CHINA_TZ,
    HtsGateway,
    HtsMdApi,
    HtsTdApi,
)


class Sink:
    def __init__(self) -> None:
        self.logs: list[str] = []
        self.ticks: list[TickData] = []
        self.orders: list[OrderData] = []
        self.positions: list[PositionData] = []

    def attach(self, gateway: HtsGateway) -> None:
        gateway.write_log = self.logs.append
        gateway.on_tick = self.ticks.append
        gateway.on_order = self.orders.append
        gateway.on_position = self.positions.append


class CallRecorder:
    def __init__(self) -> None:
        self.calls: list[tuple[str, Any]] = []

    def patch(self, monkeypatch: pytest.MonkeyPatch, api: object, names: list[str]) -> None:
        for name in names:
            monkeypatch.setattr(api, name, self.make_stub(name))

    def make_stub(self, name: str) -> Callable[..., int]:
        def stub(*args: Any) -> int:
            self.calls.append((name, args[0] if args else None))
            return 0
        return stub

    def names(self) -> list[str]:
        return [name for name, _ in self.calls]


TD_METHODS: list[str] = [
    "createDFITCSECTraderApi",
    "subscribePrivateTopic",
    "init",
    "exit",
    "reqSOPUserLogin",
    "reqSOPEntrustOrder",
    "reqSOPWithdrawOrder",
    "reqSOPQryCapitalAccountInfo",
    "reqSOPQryPosition",
    "reqSOPQryContactInfo",
]

MD_METHODS: list[str] = [
    "createDFITCMdApi",
    "init",
    "exit",
    "reqSOPUserLogin",
    "subscribeSOPMarketData",
]


@pytest.fixture(autouse=True)
def clear_contracts() -> Iterator[None]:
    hts_gateway.symbol_contract_map.clear()
    yield
    hts_gateway.symbol_contract_map.clear()


@pytest.fixture
def sink() -> Sink:
    return Sink()


@pytest.fixture
def recorder() -> CallRecorder:
    return CallRecorder()


@pytest.fixture
def gateway(sink: Sink, recorder: CallRecorder, monkeypatch: pytest.MonkeyPatch) -> HtsGateway:
    engine: EventEngine = EventEngine()
    gateway: HtsGateway = HtsGateway(engine, "HTS")
    sink.attach(gateway)
    recorder.patch(monkeypatch, gateway.td_api, TD_METHODS)
    recorder.patch(monkeypatch, gateway.md_api, MD_METHODS)
    return gateway


@pytest.fixture
def td_api(gateway: HtsGateway) -> HtsTdApi:
    return gateway.td_api


@pytest.fixture
def md_api(gateway: HtsGateway) -> HtsMdApi:
    return gateway.md_api


def connect_setting(**overrides: str) -> dict[str, str]:
    data: dict[str, str] = {
        "账号": "u1",
        "密码": "p1",
        "行情地址": "127.0.0.1:41213",
        "交易地址": "127.0.0.1:41205",
        "行情协议": "TCP",
        "授权码": "",
        "产品号": "",
        "采集类型": "顶点",
        "行情压缩": "N",
    }
    data.update(overrides)
    return data


def order_request() -> OrderRequest:
    return OrderRequest(
        symbol="10001234",
        exchange=Exchange.SSE,
        direction=Direction.LONG,
        type=OrderType.LIMIT,
        volume=2,
        price=0.05,
        offset=Offset.OPEN,
    )


def entrust_rtn(**overrides: Any) -> dict[str, Any]:
    data: dict[str, Any] = {
        "localOrderID": 7,
        "sessionID": 3,
        "entrustTime": "09:30:00.000000",
        "securityID": "10001234",
        "exchangeID": DFITCSEC_EI_SH,
        "entrustDirection": DFITCSEC_ED_Buy,
        "openCloseFlag": DFITCSEC_OCF_Open,
        "entrustPrice": 0.05,
        "entrustQty": 2,
    }
    data.update(overrides)
    return data


def withdraw_rtn(**overrides: Any) -> dict[str, Any]:
    data: dict[str, Any] = {
        "localOrderID": 7,
        "sessionID": 3,
        "securityID": "10001234",
        "exchangeID": DFITCSEC_EI_SH,
        "entrustDirection": DFITCSEC_ED_Buy,
        "openCloseFlag": DFITCSEC_OCF_Open,
        "entrustPrice": 0.05,
        "tradeQty": 0,
        "withdrawQty": 1,
    }
    data.update(overrides)
    return data


def market_data(**overrides: Any) -> dict[str, Any]:
    data: dict[str, Any] = {
        "tradingDay": "20250926",
        "updateTime": "09:30:00.500000",
        "securityID": "10001234",
        "exchangeID": DFITCSEC_EI_SH,
        "tradeQty": 10,
        "latestPrice": 0.05,
        "upperLimitPrice": 0.1,
        "lowerLimitPrice": 0.01,
        "openPrice": 0.04,
        "highestPrice": 0.06,
        "lowestPrice": 0.03,
        "preClosePrice": 0.045,
        "bidPrice1": 0.049,
        "bidPrice2": 0.048,
        "bidPrice3": 0.047,
        "bidPrice4": 0.046,
        "bidPrice5": 0.045,
        "askPrice1": 0.051,
        "askPrice2": 0.052,
        "askPrice3": 0.053,
        "askPrice4": 0.054,
        "askPrice5": 0.055,
        "bidQty1": 1,
        "bidQty2": 2,
        "bidQty3": 3,
        "bidQty4": 4,
        "bidQty5": 5,
        "askQty1": 6,
        "askQty2": 7,
        "askQty3": 8,
        "askQty4": 9,
        "askQty5": 10,
    }
    data.update(overrides)
    return data


def test_connect_prefixes_bare_address(gateway: HtsGateway, monkeypatch: pytest.MonkeyPatch) -> None:
    seen: dict[str, str] = {}
    monkeypatch.setattr(gateway.md_api, "connect", lambda *args: seen.__setitem__("md", args[2]))
    monkeypatch.setattr(gateway.td_api, "connect", lambda *args: seen.__setitem__("td", args[2]))

    setting: dict[str, str] = connect_setting()
    setting["交易地址"] = "127.0.0.1:41205"
    setting["行情地址"] = "ssl://127.0.0.1:41213"
    gateway.connect(setting)

    assert seen["td"] == "tcp://127.0.0.1:41205"
    assert seen["md"] == "ssl://127.0.0.1:41213"


def test_connect_rewrites_udp_quote(gateway: HtsGateway, monkeypatch: pytest.MonkeyPatch) -> None:
    seen: dict[str, str] = {}
    monkeypatch.setattr(gateway.md_api, "connect", lambda *args: seen.__setitem__("md", args[2]))
    monkeypatch.setattr(gateway.td_api, "connect", lambda *args: seen.__setitem__("td", args[2]))

    setting: dict[str, str] = connect_setting(行情协议="UDP")
    setting["行情地址"] = "127.0.0.1:41213"
    setting["交易地址"] = "tcp://127.0.0.1:41205"
    gateway.connect(setting)

    assert seen["md"] == "udp://127.0.0.1:41213"
    assert seen["td"] == "tcp://127.0.0.1:41205"


def test_send_order_returns_session_local_id(td_api: HtsTdApi, sink: Sink, recorder: CallRecorder) -> None:
    td_api.sessionid = "9"
    vt_orderid: str = td_api.send_order(order_request())

    assert vt_orderid == "HTS.9_10001"
    request: dict[str, Any] = recorder.calls[0][1]
    assert recorder.names() == ["reqSOPEntrustOrder"]
    assert request["localOrderID"] == 10001
    assert request["orderType"] == DFITCSEC_SOP_LimitPrice
    assert request["openCloseFlag"] == DFITCSEC_OCF_Open
    assert request["entrustQty"] == 2
    assert sink.orders[0].orderid == "9_10001"
    assert sink.orders[0].status == Status.SUBMITTING


def test_new_order_is_not_traded(td_api: HtsTdApi, sink: Sink) -> None:
    td_api.onSOPEntrustOrderRtn(entrust_rtn())

    order: OrderData = sink.orders[0]
    assert order.orderid == "3_7"
    assert order.status == Status.NOTTRADED
    assert order.direction == Direction.LONG
    assert order.offset == Offset.OPEN
    assert order.exchange == Exchange.SSE


def test_partial_fill_is_part_traded(td_api: HtsTdApi, sink: Sink) -> None:
    td_api.orders["3_7"] = OrderData(
        symbol="10001234",
        exchange=Exchange.SSE,
        orderid="3_7",
        direction=Direction.LONG,
        offset=Offset.OPEN,
        price=0.05,
        volume=2,
        traded=1,
        gateway_name="HTS",
    )
    td_api.onSOPEntrustOrderRtn(entrust_rtn())

    assert sink.orders[0].status == Status.PARTTRADED


def test_full_fill_is_all_traded(td_api: HtsTdApi, sink: Sink) -> None:
    td_api.orders["3_7"] = OrderData(
        symbol="10001234",
        exchange=Exchange.SSE,
        orderid="3_7",
        direction=Direction.LONG,
        offset=Offset.OPEN,
        price=0.05,
        volume=2,
        traded=2,
        gateway_name="HTS",
    )
    td_api.onSOPEntrustOrderRtn(entrust_rtn())

    assert sink.orders[0].status == Status.ALLTRADED


def test_withdraw_sets_cancelled(td_api: HtsTdApi, sink: Sink) -> None:
    td_api.onSOPWithdrawOrderRtn(withdraw_rtn())

    order: OrderData = sink.orders[0]
    assert order.orderid == "3_7"
    assert order.status == Status.CANCELLED
    assert order.volume == 1


def test_entrust_error_sets_rejected(td_api: HtsTdApi, sink: Sink) -> None:
    td_api.sessionid = "9"
    td_api.send_order(order_request())
    td_api.onRspSOPEntrustOrder({}, {
        "localOrderID": 10001,
        "sessionID": 9,
        "errorID": 12,
        "errorMsg": "拒单",
    })

    assert sink.orders[-1].status == Status.REJECTED
    assert sink.orders[-1].orderid == "9_10001"
    assert "期权委托错误" in sink.logs[0]


def test_position_volume_uses_total_qty(td_api: HtsTdApi, sink: Sink) -> None:
    td_api.onRspSOPQryPosition({
        "securityOptionID": "10001234",
        "exchangeID": DFITCSEC_EI_SH,
        "entrustDirection": DFITCSEC_ED_Buy,
        "totalQty": 3,
        "openAvgPrice": 0.12,
    }, {}, False)

    position: PositionData = sink.positions[0]
    assert position.symbol == "10001234"
    assert position.exchange == Exchange.SSE
    assert position.direction == Direction.LONG
    assert position.volume == 3
    assert position.price == 0.12
    assert position.yd_volume == 0


def test_empty_position_query_is_ignored(td_api: HtsTdApi, sink: Sink) -> None:
    td_api.onRspSOPQryPosition({}, {}, True)

    assert sink.positions == []


def test_empty_contract_id_ends_query(td_api: HtsTdApi, sink: Sink, recorder: CallRecorder) -> None:
    td_api.onRspSOPQryContactInfo({"securityOptionID": ""}, {}, True)

    assert sink.logs == ["期权交易合约信息获取成功"]
    assert recorder.calls == []
    assert hts_gateway.symbol_contract_map == {}


def test_tick_datetime_uses_trading_day(md_api: HtsMdApi, sink: Sink) -> None:
    md_api.onSOPMarketData(market_data())

    tick: TickData = sink.ticks[0]
    assert tick.symbol == "10001234"
    assert tick.exchange == Exchange.SSE
    assert tick.datetime == datetime(2025, 9, 26, 9, 30, 0, 500000, tzinfo=CHINA_TZ)
    assert tick.bid_price_1 == 0.049
    assert tick.ask_volume_5 == 10


def test_close_without_connection_does_not_exit(
    td_api: HtsTdApi,
    md_api: HtsMdApi,
    recorder: CallRecorder,
) -> None:
    td_api.close()
    md_api.close()

    assert recorder.calls == []

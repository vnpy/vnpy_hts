#pragma once
//系统
#ifdef WIN32
#include "pch.h"
#endif

#include "vnhts.h"
#include "pybind11/pybind11.h"
#include "DFITCSECTraderApi.h"

using namespace pybind11;
using namespace std;

//常量

#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONRTNNOTICE 2
#define ONRSPERROR 3
#define ONRSPSTOCKUSERLOGIN 4
#define ONRSPSTOCKUSERLOGOUT 5
#define ONRSPSTOCKUSERPASSWORDUPDATE 6
#define ONRSPSTOCKENTRUSTORDER 7
#define ONRSPSTOCKWITHDRAWORDER 8
#define ONRSPSTOCKQRYENTRUSTORDER 9
#define ONRSPSTOCKQRYREALTIMETRADE 10
#define ONRSPSTOCKQRYSERIALTRADE 11
#define ONRSPSTOCKQRYPOSITION 12
#define ONRSPSTOCKQRYCAPITALACCOUNTINFO 13
#define ONRSPSTOCKQRYACCOUNTINFO 14
#define ONRSPSTOCKQRYSHAREHOLDERINFO 15
#define ONRSPSTOCKTRANSFERFUNDS 16
#define ONRSPSTOCKENTRUSTBATCHORDER 17
#define ONRSPSTOCKWITHDRAWBATCHORDER 18
#define ONRSPSTOCKCALCABLEENTRUSTQTY 19
#define ONRSPSTOCKCALCABLEPURCHASEETFQTY 20
#define ONRSPSTOCKQRYFREEZEFUNDSDETAIL 21
#define ONRSPSTOCKQRYFREEZESTOCKDETAIL 22
#define ONRSPSTOCKQRYTRANSFERSTOCKDETAIL 23
#define ONRSPSTOCKQRYTRANSFERFUNDSDETAIL 24
#define ONRSPSTOCKQRYSTOCKINFO 25
#define ONRSPSTOCKQRYSTOCKSTATICINFO 26
#define ONRSPSTOCKQRYTRADETIME 27
#define ONSTOCKENTRUSTORDERRTN 28
#define ONSTOCKTRADERTN 29
#define ONSTOCKWITHDRAWORDERRTN 30
#define ONRSPSOPUSERLOGIN 31
#define ONRSPSOPUSERLOGOUT 32
#define ONRSPSOPUSERPASSWORDUPDATE 33
#define ONRSPSOPENTRUSTORDER 34
#define ONRSPSOPQUOTEENTRUSTORDER 35
#define ONRSPSOPGROUPSPLIT 36
#define ONRSPSOPGROUPEXECTUEORDER 37
#define ONRSPSOPQRYGROUPPOSITION 38
#define ONRSPSOPLOCKOUNLOCKSTOCK 39
#define ONRSPSOPWITHDRAWORDER 40
#define ONRSPSOPQRYENTRUSTORDER 41
#define ONRSPSOPQRYSERIALTRADE 42
#define ONRSPSOPQRYPOSITION 43
#define ONRSPSOPQRYCOLLATERALPOSITION 44
#define ONRSPSOPQRYCAPITALACCOUNTINFO 45
#define ONRSPSOPQRYACCOUNTINFO 46
#define ONRSPSOPQRYSHAREHOLDERINFO 47
#define ONRSPSOPCALCABLEENTRUSTQTY 48
#define ONRSPSOPQRYABLELOCKSTOCK 49
#define ONRSPSOPQRYCONTACTINFO 50
#define ONRSPSOPEXECTUEORDER 51
#define ONRSPSOPQRYEXECASSIINFO 52
#define ONRSPSOPQRYTRADETIME 53
#define ONRSPSOPQRYEXCHANGEINFO 54
#define ONRSPSOPQRYCOMMISSION 55
#define ONRSPSOPQRYDEPOSIT 56
#define ONRSPSOPQRYCONTRACTOBJECTINFO 57
#define ONSOPENTRUSTORDERRTN 58
#define ONSOPTRADERTN 59
#define ONSOPWITHDRAWORDERRTN 60
#define ONSOPQUOTEENTRUSTORDERRTN 61
#define ONRSPSOPCAPITALTRANINOUT 62
#define ONRSPSOPCAPITALDISTRIBUTIONRATIO 63
#define ONRSPSOPFUNDTRANSBETWEENNODES 64
#define ONRSPSOPMODCAPITALDISTRIBUTIONRATIO 65
#define ONRSPFASLUSERLOGIN 66
#define ONRSPFASLUSERLOGOUT 67
#define ONRSPFASLQRYABLEFININFO 68
#define ONRSPFASLQRYABLESLOINFO 69
#define ONRSPFASLTRANSFERCOLLATERAL 70
#define ONRSPFASLDIRECTREPAYMENT 71
#define ONRSPFASLREPAYSTOCKTRANSFER 72
#define ONRSPFASLENTRUSTCRDTORDER 73
#define ONRSPFASLENTRUSTORDER 74
#define ONRSPFASLCALCABLEENTRUSTCRDTQTY 75
#define ONRSPFASLQRYCRDTFUNDS 76
#define ONRSPFASLQRYCRDTCONTRACT 77
#define ONRSPFASLQRYCRDTCONCHANGEINFO 78
#define ONRSPFASLTRANSFERFUNDS 79
#define ONRSPFASLTRANSFERSTOCK 80
#define ONRSPFASLQRYACCOUNTINFO 81
#define ONRSPFASLQRYCAPITALACCOUNTINFO 82
#define ONRSPFASLQRYSHAREHOLDERINFO 83
#define ONRSPFASLQRYPOSITION 84
#define ONRSPFASLQRYENTRUSTORDER 85
#define ONRSPFASLQRYSERIALTRADE 86
#define ONRSPFASLQRYREALTIMETRADE 87
#define ONRSPFASLQRYFREEZEFUNDSDETAIL 88
#define ONRSPFASLQRYFREEZESTOCKDETAIL 89
#define ONRSPFASLQRYTRANSFERFUNDSDETAIL 90
#define ONRSPFASLWITHDRAWORDER 91
#define ONRSPFASLQRYSYSTEMTIME 92
#define ONRSPFASLQRYTRANSFERREDCONTRACT 93
#define ONRSPFASLDESIRABLEFUNDSOUT 94
#define ONRSPFASLQRYGUARANTEEDCONTRACT 95
#define ONRSPFASLQRYUNDERLYINGCONTRACT 96
#define ONRSPFASLQRYCENTREFUNDAVLINFO 97
#define ONRSPFASLQRYPLACINGINTERESTSINFO 98
#define ONRSPFASLUSERPASSWORDUPDATE 99
#define ONFASLENTRUSTORDERRTN 100
#define ONFASLTRADERTN 101
#define ONFASLWITHDRAWORDERRTN 102
#define ONFASLLIABILITIESRTN 103
#define ONRSPSTOCKETFENTRUSTORDER 104
#define ONRSPSTOCKETFBASKETORDER 105
#define ONRSPSTOCKBONDREPURCHASEORDER 106
#define ONRSPSTOCKBONDINOUTSTOCKORDER 107
#define ONRSPSTOCKISSUEBUSINESSORDER 108
#define ONRSPSTOCKLOFENTRUSTORDER 109
#define ONRSPSTOCKAFTERHOURSPRICEORDER 110
#define ONRSPSTOCKNONTRADINGBUSINESSORDER 111
#define ONRSPSTOCKSHMUTUALFUNDORDER 112
#define ONRSPSTOCKCALCABLEPURCHASEETFBASKETQTY 113
#define ONRSPSTOCKCALCABLEBONDREPURCHASEQTY 114
#define ONRSPSTOCKCALCABLEISSUEBUSINESSQTY 115
#define ONRSPSTOCKCALCABLEPURCHASELOFQTY 116
#define ONRSPSTOCKCALCABLEAFTERHOURSPRICEQTY 117
#define ONRSPSTOCKCALCABLENONTRADINGBUSINESSQTY 118
#define ONRSPSTOCKCALCABLESHMUTUALFUNDQTY 119


///-------------------------------------------------------------------------------------
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现

class TdApi : public DFITCSECTraderSpi
{
private:
	DFITCSECTraderApi* api;            //API对象
	thread task_thread;                    //工作线程指针（向python中推送数据）
	TaskQueue task_queue;                //任务队列
	bool active = false;                //工作状态
public:
	TdApi()
	{
	};

	~TdApi()
	{
		if (this->active)
		{
			this->exit();
		}
	};
	//-------------------------------------------------------------------------------------
	//API回调函数
	//-------------------------------------------------------------------------------------

	/**
	 * SEC-网络连接正常响应
	 */
	virtual void OnFrontConnected();
	/**
	 * SEC-网络连接不正常响应
	 */
	virtual void OnFrontDisconnected(int nReason);
	/**
	 * SEC-消息通知
	 */
	virtual void OnRtnNotice(DFITCSECRspNoticeField *pNotice);
	/**
	* ERR-错误应答
	* @param pRspInfo:指针若非空，返回错误信息结构地址
	*/
	virtual void OnRspError(DFITCSECRspInfoField *pRspInfo);
	/**
	* STOCK-登录响应
	* @param pData:指针若非空,返回用户登录响应信息结构体的地址,表明登录请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明登录请求失败
	*/
	virtual void OnRspStockUserLogin(DFITCSECRspUserLoginField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* STOCK-登出响应
	* @param pData:指针若非空,返回用户登出响应信息结构体的地址,表明登出请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明登出请求失败
	*/
	virtual void OnRspStockUserLogout(DFITCSECRspUserLogoutField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* STOCK-密码更新响应
	* @param pData:指针若非空,返回用户密码更新响应信息结构体的地址,表明密码更新请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明密码更新请求失败
	*/
	virtual void OnRspStockUserPasswordUpdate(DFITCSECRspPasswordUpdateField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* STOCK-委托报单响应
	* @param pData:指针若非空,返回用户委托报单响应信息结构体的地址,表明报单请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明委托报单请求失败
	*/
	virtual void OnRspStockEntrustOrder(DFITCStockRspEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* STOCK-委托撤单响应
	* @param pData:指针若非空,返回用户委托撤单响应信息结构体的地址,表明撤单请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明委托撤单请求失败
	*/
	virtual void OnRspStockWithdrawOrder(DFITCSECRspWithdrawOrderField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* STOCK-委托查询响应
	* @param pData:指针若非空,返回用户委托查询响应信息结构体的地址,表明查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明委托查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspStockQryEntrustOrder(DFITCStockRspQryEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* STOCK-实时成交查询响应
	* @param pData:指针若非空,返回用户实时成交查询响应信息结构体的地址,表明实时成交查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明实时成交查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspStockQryRealTimeTrade(DFITCStockRspQryRealTimeTradeField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* STOCK-分笔成交查询响应
	* @param pData:指针若非空,返回用户分笔成交查询响应信息结构体的地址,表明分笔成交查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明分笔成交查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspStockQrySerialTrade(DFITCStockRspQrySerialTradeField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* STOCK-持仓查询响应
	* @param pData:指针若非空,返回用户持仓查询响应信息结构体的地址,表明持仓查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明持仓查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspStockQryPosition(DFITCStockRspQryPositionField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* STOCK-资金账号查询响应
	* @param pData:指针若非空,返回用户资金账号查询响应信息结构体的地址,表明资金账号查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明资金账号查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspStockQryCapitalAccountInfo(DFITCStockRspQryCapitalAccountField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* STOCK-交易账号查询响应
	* @param pData:指针若非空,返回用户交易账号查询响应信息结构体的地址,表明交易账号查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明交易账号查询请求失败
	*/
	virtual void OnRspStockQryAccountInfo(DFITCStockRspQryAccountField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* STOCK-股东号查询响应
	* @param pData:指针若非空,返回用户股东号查询响应信息结构体的地址,表明股东号查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明股东号查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspStockQryShareholderInfo(DFITCStockRspQryShareholderField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* STOCK-资金调拨响应
	* @param pData:指针若非空,返回用户资金调拨响应信息结构体的地址,表明股资金调拨请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明资金调拨请求失败
	*/
	virtual void OnRspStockTransferFunds(DFITCStockRspTransferFundsField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* STOCK-批量委托响应
	* @param pData:指针若非空,返回用户批量委托响应信息结构体的地址,表明批量委托请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明批量委托请求失败
	*/
	virtual void OnRspStockEntrustBatchOrder(DFITCStockRspEntrustBatchOrderField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* STOCK-批量撤单响应
	* @param pData:指针若非空,返回用户批量撤单响应信息结构体的地址,表明批量撤单请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明批量撤单请求失败
	*/
	virtual void OnRspStockWithdrawBatchOrder(DFITCStockRspWithdrawBatchOrderField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* STOCK-计算可委托数量响应
	* @param pData:指针若非空,返回用户计算可委托数量响应信息结构体的地址,表明计算可委托数量请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明计算可委托数量请求失败
	*/
	virtual void OnRspStockCalcAbleEntrustQty(DFITCStockRspCalcAbleEntrustQtyField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* STOCK-计算申购ETF数量响应
	* @param pData:指针若非空,返回用户计算申购ETF数量响应信息结构体的地址,表明计算申购ETF数量请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明计算申购ETF数量请求失败
	*/
	virtual void OnRspStockCalcAblePurchaseETFQty(DFITCStockRspCalcAblePurchaseETFQtyField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* STOCK-冻结资金明细查询响应
	* @param pData:指针若非空,返回用户冻结资金明细查询响应信息结构体的地址,表明冻结资金明细查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明冻结资金明细查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspStockQryFreezeFundsDetail(DFITCStockRspQryFreezeFundsDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* STOCK-冻结证券明细查询响应
	* @param pData:指针若非空,返回用户冻结证券明细查询响应信息结构体的地址,表明冻结证券明细查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明冻结证券明细查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspStockQryFreezeStockDetail(DFITCStockRspQryFreezeStockDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* STOCK-调拨证券明细查询响应
	* @param pData:指针若非空,返回用户调拨证券明细查询响应信息结构体的地址,表明调拨证券明细查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明调拨证券明细查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspStockQryTransferStockDetail(DFITCStockRspQryTransferStockDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* STOCK-调拨资金明细查询响应
	* @param pData:指针若非空,返回用户调拨资金明细查询响应信息结构体的地址,表明调拨资金明细查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明调拨资金明细查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspStockQryTransferFundsDetail(DFITCStockRspQryTransferFundsDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* STOCK-证券信息查询响应
	* @param pData:指针若非空,返回用户证券信息查询响应信息结构体的地址,表明证券信息查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明证券信息查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspStockQryStockInfo(DFITCStockRspQryStockField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* STOCK-证券静态信息查询响应
	* @param pData:指针若非空,返回用户证券静态信息查询响应信息结构体的地址,表明证券静态信息查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明证券静态信息查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspStockQryStockStaticInfo(DFITCStockRspQryStockStaticField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* STOCK-交易时间查询响应
	* @param pData:指针若非空,返回用户交易时间查询响应信息结构体的地址,表明交易时间查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明交易时间查询请求失败
	*/
	virtual void OnRspStockQryTradeTime(DFITCStockRspQryTradeTimeField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* STOCK-委托回报响应
	* @param pData:返回委托回报结构体的地址
	*/
	virtual void OnStockEntrustOrderRtn(DFITCStockEntrustOrderRtnField * pData);
	/**
	* STOCK-成交回报响应
	* @param pData:返回成交回报结构体的地址
	*/
	virtual void OnStockTradeRtn(DFITCStockTradeRtnField * pData);
	/**
	* STOCK-撤单回报响应
	* @param pData:返回撤单回报结构体的地址
	*/
	virtual void OnStockWithdrawOrderRtn(DFITCStockWithdrawOrderRtnField * pData);

	/**
	* SOP-登录响应
	* @param pRspUserLogin:指针若非空,返回用户登录响应信息结构地址,表明登录请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明登录请求失败
	*/
	virtual void OnRspSOPUserLogin(DFITCSECRspUserLoginField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	 * SOP-登出响应
	 * @param pData:指针若非空,返回用户登出响应信息结构地址,表明登出请求成功
	 * @param pRspInfo:指针若非空，返回错误信息地址，表明登出请求失败
	 */
	virtual void OnRspSOPUserLogout(DFITCSECRspUserLogoutField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* SOP-用户口令更新响应
	* @param pData:指针若非空,返回用户口令更新响应信息结构地址,表明用户口令更新请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明用户口令更新请求失败
	*/
	virtual void OnRspSOPUserPasswordUpdate(DFITCSECRspPasswordUpdateField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* SOP-报单响应
	* @param pData:指针若非空,返回用户报单响应信息结构地址,表明报单请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明报单请求失败
	*/
	virtual void OnRspSOPEntrustOrder(DFITCSOPRspEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* SOP-做市商报单响应
	* @param pData:指针若非空,返回用户报价委托响应信息结构地址,表明做市商报单请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明做市商报单请求失败
	*/
	virtual void OnRspSOPQuoteEntrustOrder(DFITCSOPRspQuoteEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* SOP-组合拆分委托响应
	* @param pData:指针若非空,返回用户组合拆分委托响应信息结构地址,表明组合拆分委托请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明组合拆分委托请求失败
	*/
	virtual void OnRspSOPGroupSplit(DFITCSOPRspEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	 * SOP-期权组合行权委托响应
	 * @param pData:指针若非空,返回用户期权组合行权委托响应信息结构地址,表明期权组合行权委托请求成功
	 * @return pRspInfo:指针若非空，返回错误信息地址，表明期权组合行权委托请求失败，具体错误请对照error.xml
	 */
	virtual void OnRspSOPGroupExectueOrder(DFITCSOPRspGroupExectueOrderField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* SOP-查询客户组合持仓明细响应
	* @param pData:指针若非空,返回用户查询客户组合持仓明细响应结构地址,表明查询客户组合持仓明细请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明查询客户组合持仓明细请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspSOPQryGroupPosition(DFITCSOPRspQryGroupPositionField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* SOP-证券锁定解锁响应
	* @param pData:指针若非空,返回用户证券锁定解锁响应信息结构地址,表明证券锁定解锁请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明证券锁定解锁请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspSOPLockOUnLockStock(DFITCSOPRspLockOUnLockStockField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* SOP-撤单响应
	* @param pData:指针若非空,返回用户撤单响应信息结构地址,表明撤单请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明撤单请求失败
	*/
	virtual void OnRspSOPWithdrawOrder(DFITCSECRspWithdrawOrderField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* SOP-委托查询响应
	* @param pData:指针若非空,返回用户委托查询响应信息结构地址,表明委托查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明委托查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspSOPQryEntrustOrder(DFITCSOPRspQryEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* SOP-分笔成交查询响应
	* @param pData:指针若非空,返回用户分笔成交查询响应信息结构地址,表明分笔成交查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明分笔成交查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspSOPQrySerialTrade(DFITCSOPRspQrySerialTradeField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* SOP-持仓查询响应
	* @param pData:指针若非空,返回用户持仓查询响应信息结构地址,表明持仓查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明持仓查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspSOPQryPosition(DFITCSOPRspQryPositionField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* SOP-客户担保持仓查询响应
	* @param pData:指针若非空,返回用户客户担保持仓查询响应信息结构地址,表明客户担保持仓查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户担保持仓查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspSOPQryCollateralPosition(DFITCSOPRspQryCollateralPositionField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* SOP-客户资金查询响应
	* @param pData:指针若非空,返回用户客户资金查询响应信息结构地址,表明客户客户资金查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户客户资金查询请求失败
	*/
	virtual void OnRspSOPQryCapitalAccountInfo(DFITCSOPRspQryCapitalAccountField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* SOP-客户信息查询响应
	* @param pData:指针若非空,返回用户客户信息查询响应信息结构地址,表明客户客户信息查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户客户信息查询请求失败
	*/
	virtual void OnRspSOPQryAccountInfo(DFITCSOPRspQryAccountField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* SOP-股东信息查询响应
	* @param pData:指针若非空,返回用户股东信息查询响应信息结构地址,表明客户股东信息查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户股东信息查询请求失败
	*/
	virtual void OnRspSOPQryShareholderInfo(DFITCSOPRspQryShareholderField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* SOP-可委托数量查询响应
	* @param pData:指针若非空,返回用户可委托数量查询响应信息结构地址,表明客户可委托数量查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户可委托数量查询请求失败
	*/
	virtual void OnRspSOPCalcAbleEntrustQty(DFITCSOPRspCalcAbleEntrustQtyField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* SOP-客户可锁定证券查询响应
	* @param pData:指针若非空,返回用户客户可锁定证券查询响应信息结构地址,表明客户客户可锁定证券查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户客户可锁定证券查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspSOPQryAbleLockStock(DFITCSOPRspQryAbleLockStockField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* SOP-期权合约代码查询响应
	* @param pData:指针若非空,返回用户期权合约代码查询响应信息结构地址,表明客户期权合约代码查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户期权合约代码查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspSOPQryContactInfo(DFITCSOPRspQryContactField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* SOP-执行委托响应
	* @param pData:指针若非空,返回用户执行委托响应信息结构地址,表明客户执行委托请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户执行委托请求失败
	*/
	virtual void OnRspSOPExectueOrder(DFITCSOPRspExectueOrderField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* SOP-客户行权指派信息查询响应
	* @param pData:指针若非空,返回用户客户行权指派信息查询响应信息结构地址,表明客户客户行权指派信息查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户客户行权指派信息查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspSOPQryExecAssiInfo(DFITCSOPRspQryExecAssiInfoField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* SOP-查询交易时间响应
	* @param pData:指针若非空,返回用户查询交易时间响应信息结构地址,表明客户查询交易时间请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户查询交易时间请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspSOPQryTradeTime(DFITCSOPRspQryTradeTimeField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* SOP-获取所有交易所参数响应
	* @param pData:指针若非空,返回用户获取所有交易所参数响应信息结构地址,表明客户获取所有交易所参数请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户获取所有交易所参数请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspSOPQryExchangeInfo(DFITCSOPRspQryExchangeInfoField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* SOP-查询手续费参数响应
	* @param pData:指针若非空,返回用户查询手续费参数响应信息结构地址,表明客户查询手续费参数请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户查询手续费参数请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspSOPQryCommission(DFITCSOPRspQryCommissionField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* SOP-查询保证金率参数响应
	* @param pData:指针若非空,返回用户查询保证金率参数响应信息结构地址,表明客户查询保证金率参数请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户查询保证金率参数请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspSOPQryDeposit(DFITCSOPRspQryDepositField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* SOP-期权标的信息查询响应
	* @param pData:指针若非空,返回用户期权标的信息查询响应信息结构地址,表明客户期权标的信息查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户期权标的信息查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspSOPQryContractObjectInfo(DFITCSOPRspQryContractObjectField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* SOP-委托回报响应
	* @param pData:返回委托回报结构体的地址
	*/
	virtual void OnSOPEntrustOrderRtn(DFITCSOPEntrustOrderRtnField * pData);
	/**
	* SOP-成交回报响应
	* @param pData:返回成交回报结构体的地址
	*/
	virtual void OnSOPTradeRtn(DFITCSOPTradeRtnField * pData);
	/**
	* SOP-撤单回报响应
	* @param pData:返回撤单回报结构体的地址
	*/
	virtual void OnSOPWithdrawOrderRtn(DFITCSOPWithdrawOrderRtnField * pData);
	/**
	* SOP-做市委托回报响应
	* @param pData:返回做市双边报价委托回报结构体的地址
	*/
	virtual void OnSOPQuoteEntrustOrderRtn(DFITCSOPQuoteEntrustOrderRtnField * pData);

	/**
	* SOP-资金调入调出响应
	* @param pData:指针若非空,返回资金调入调出响应信息结构地址,表明客户资金调入调出请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明资金调入调出请求失败
	*/
	virtual void OnRspSOPCapitalTranInOut(DFITCSOPRspCapitalTranInOutField *pData, DFITCSECRspInfoField *pRspInfo);

	/**
	* SOP-资金多节点分配比例查询响应
	* @param pData:指针若非空,返回资金多节点分配比例响应信息结构地址,表明客户资金多节点分配比例请求查询成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明资金多节点分配比例查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspSOPCapitalDistributionRatio(DFITCSOPRspQryCapitalDistributionRatioField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);

	/**
	* SOP-节点间资金划拨响应
	* @param pData:指针若非空,返回节点间资金划拨响应信息结构地址,表明客户节点间资金划拨请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明节点间资金划拨请求失败
	*/
	virtual void OnRspSOPFundTransBetweenNodes(DFITCSOPRspFundTransBetweenNodesField *pData, DFITCSECRspInfoField *pRspInfo);

	/**
	* SOP-修改资金多节点分配比例响应
	* @param pData:指针若非空,返回设置资金多节点分配比例响应信息结构地址,表明设置客户资金多节点分配比例请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明设置资金多节点分配比例请求失败
	*/
	virtual void OnRspSOPModCapitalDistributionRatio(DFITCSOPRspModCapitalDistributionRatioField *pData, DFITCSECRspInfoField *pRspInfo);

	/**
	* FASL-登录响应
	* @param pData:指针若非空,返回用户融资融券登录响应信息结构地址,表明客户融资融券登录请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户融资融券登录请求失败
	*/
	virtual void OnRspFASLUserLogin(DFITCSECRspUserLoginField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* FASL-登出响应
	* @param pData:指针若非空,返回用户融资融券登出响应信息结构地址,表明客户融资融券登出请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户融资融券登出请求失败
	*/
	virtual void OnRspFASLUserLogout(DFITCSECRspUserLogoutField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* FASL-客户可融资信息响应
	* @param pData:指针若非空,返回用户客户可融资信息响应信息结构地址,表明客户客户可融资信息请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户客户可融资信息请求失败
	*/
	virtual void OnRspFASLQryAbleFinInfo(DFITCFASLRspAbleFinInfoField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* FASL-客户可融券信息响应
	* @param pData:指针若非空,返回用户客户可融券信息响应信息结构地址,表明客户客户可融券信息请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户客户可融券信息请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryAbleSloInfo(DFITCFASLRspAbleSloInfoField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* FASL-担保物划转响应
	* @param pData:指针若非空,返回用户担保物划转响应信息结构地址,表明客户担保物划转请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户担保物划转请求失败
	*/
	virtual void OnRspFASLTransferCollateral(DFITCFASLRspTransferCollateralField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* FASL-直接还款响应
	* @param pData:指针若非空,返回用户直接还款响应信息结构地址,表明客户直接还款请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户直接还款请求失败
	*/
	virtual void OnRspFASLDirectRepayment(DFITCFASLRspDirectRepaymentField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* FASL-还券划转响应
	* @param pData:指针若非空,返回用户还券划转响应信息结构地址,表明客户还券划转请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户还券划转请求失败
	*/
	virtual void OnRspFASLRepayStockTransfer(DFITCFASLRspRepayStockTransferField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* FASL-信用交易响应
	* @param pData:指针若非空,返回用户信用交易响应信息结构地址,表明客户信用交易请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户信用交易请求失败
	*/
	virtual void OnRspFASLEntrustCrdtOrder(DFITCFASLRspEntrustCrdtOrderField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* FASL-融资融券交易响应
	* @param pData:指针若非空,返回用户融资融券交易响应信息结构地址,表明客户融资融券交易请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户融资融券交易请求失败
	*/
	virtual void OnRspFASLEntrustOrder(DFITCFASLRspEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* FASL-信用可委托数量查询响应
	* @param pData:指针若非空,返回用户信用可委托数量查询响应信息结构地址,表明客户信用可委托数量查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户信用可委托数量查询请求失败
	*/
	virtual void OnRspFASLCalcAbleEntrustCrdtQty(DFITCFASLRspCalcAbleEntrustCrdtQtyField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* FASL-查询信用资金响应
	* @param pData:指针若非空,返回用户查询信用资金响应信息结构地址,表明客户查询信用资金请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户查询信用资金请求失败
	  * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryCrdtFunds(DFITCFASLRspQryCrdtFundsField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* FASL-信用合约信息响应
	* @param pData:指针若非空,返回用户信用合约信息响应信息结构地址,表明客户信用合约信息请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户信用合约信息请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryCrdtContract(DFITCFASLRspQryCrdtContractField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLat);
	/**
	* FASL-信用合约变动信息查询响应
	* @param pData:指针若非空,返回用户信用合约变动信息查询响应信息结构地址,表明客户信用合约变动信息查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户信用合约变动信息查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryCrdtConChangeInfo(DFITCFASLRspQryCrdtConChangeInfoField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* FASL-资金调转响应
	* @param pData:指针若非空,返回用户资金调转响应信息结构地址,表明客户资金调转请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户资金调转请求失败
	*/
	virtual void OnRspFASLTransferFunds(DFITCFASLRspTransferFundsField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* FASL-证券调转响应
	* @param pData:指针若非空,返回用户证券调转响应信息结构地址,表明客户证券调转请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户证券调转请求失败
	*/
	virtual void OnRspFASLTransferStock(DFITCFASLRspTransferStockField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* FASL-客户信息查询响应
	* @param pData:指针若非空,返回用户客户信息查询响应信息结构地址,表明客户客户信息查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户客户信息查询请求失败
	*/
	virtual void OnRspFASLQryAccountInfo(DFITCFASLRspQryAccountField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* FASL-客户资金查询响应
	* @param pData:指针若非空,返回用户客户资金查询响应信息结构地址,表明客户客户资金查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户客户资金查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryCapitalAccountInfo(DFITCFASLRspQryCapitalAccountField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* FASL-股东信息查询响应
	* @param pData:指针若非空,返回用户股东信息查询响应信息结构地址,表明客户股东信息查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户股东信息查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryShareholderInfo(DFITCFASLRspQryShareholderField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* FASL-持仓查询响应
	* @param pData:指针若非空,返回用户持仓查询响应信息结构地址,表明客户持仓查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户持仓查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryPosition(DFITCFASLRspQryPositionField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* FASL-委托查询响应
	* @param pData:指针若非空,返回用户委托查询响应信息结构地址,表明客户委托查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户委托查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryEntrustOrder(DFITCFASLRspQryEntrustOrderField * pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* FASL-分笔成交查询响应
	* @param pData:指针若非空,返回用户分笔成交查询响应信息结构地址,表明客户分笔成交查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户分笔成交查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQrySerialTrade(DFITCFASLRspQrySerialTradeField * pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* FASL-实时成交查询响应
	* @param pData:指针若非空,返回用户实时成交查询响应信息结构地址,表明客户实时成交查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户实时成交查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryRealTimeTrade(DFITCFASLRspQryRealTimeTradeField * pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* FASL-资金冻结明细查询响应
	* @param pData:指针若非空,返回用户资金冻结明细查询响应信息结构地址,表明客户资金冻结明细查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户资金冻结明细查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryFreezeFundsDetail(DFITCFASLRspQryFreezeFundsDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* FASL-证券冻结明细查询响应
	* @param pData:指针若非空,返回用户证券冻结明细查询响应信息结构地址,表明客户证券冻结明细查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户证券冻结明细查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryFreezeStockDetail(DFITCFASLRspQryFreezeStockDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* FASL-资金调拨明细查询响应
	* @param pData:指针若非空,返回用户资金调拨明细查询响应信息结构地址,表明客户资金调拨明细查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户资金调拨明细查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryTransferFundsDetail(DFITCFASLRspQryTransferFundsDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* FASL-撤单响应
	* @param pData:指针若非空,返回用户撤单响应信息结构地址,表明撤单请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明撤单请求失败
	*/
	virtual void OnRspFASLWithdrawOrder(DFITCFASLRspWithdrawOrderField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* FASL-当前系统时间查询请求响应
	* @param pData:指针若非空,返回用户系统时间查询响应信息结构地址,表明系统时间查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明系统时间查询请求失败
	*/
	virtual void OnRspFASLQrySystemTime(DFITCFASLRspQryTradeTimeField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* FASL-可转入担保证券查询请求响应
	* @param pData:指针若非空,返回可转入担保证券查询响应信息结构地址,表明可转入担保证券查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明可转入担保证券查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryTransferredContract(DFITCFASLRspQryTransferredContractField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* FASL-客户可取资金调出请求响应
	* @param pData:指针若非空,返回客户可取资金调出响应信息结构地址,表明客户可取资金调出请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户可取资金调出请求失败
	*/
	virtual void OnRspFASLDesirableFundsOut(DFITCFASLRspDesirableFundsOutField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* FASL-担保证券查询请求响应
	* @param pData:指针若非空,返回担保证券查询响应信息结构地址,表明担保证券查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明担保证券查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryGuaranteedContract(DFITCFASLRspQryGuaranteedContractField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* FASL-标的证券查询请求响应
	* @param pData:指针若非空,返回标的证券查询响应信息结构地址,表明标的证券查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明标的证券查询失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryUnderlyingContract(DFITCFASLRspQryUnderlyingContractField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* FASL-集中交易资金查询请求响应
	* @param pData:指针若非空,返回集中交易资金查询响应信息结构地址,表明集中交易资金查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明标的证券查询失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryCentreFundAvlInfo(DFITCFASLRspQryCentreFundAvlField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* FASL-客户配售权益查询请求响应
	* @param pData:指针若非空,返回客户配售权益查询响应信息结构地址,表明客户配售权益查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明标的证券查询失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryPlacingInterestsInfo(DFITCFASLRspQryPlacingInterestsField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);
	/**
	* FASL-密码更新响应
	* @param pData:指针若非空,返回用户密码更新响应信息结构体的地址,表明密码更新请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明密码更新请求失败
	*/
	virtual void OnRspFASLUserPasswordUpdate(DFITCSECRspPasswordUpdateField *pData, DFITCSECRspInfoField *pRspInfo);
	/**
	* FASL-委托回报响应
	* @param pData:返回委托回报结构体的地址
	*/
	virtual void OnFASLEntrustOrderRtn(DFITCFaslEntrustOrderRtnField *pData);
	/**
	* FASL-成交回报响应
	* @param pData:返回成交回报结构体的地址
	*/
	virtual void OnFASLTradeRtn(DFITCFaslTradeRtnField *pData);
	/**
	* FASL-撤单回报响应
	* @param pData:返回撤单回报结构体的地址
	*/
	virtual void OnFASLWithdrawOrderRtn(DFITCFaslWithdrawOrderRtnField *pData);
	/**
	* FASL-负债变动响应
	* @param pData:返回负债变动结构体的地址
	*/
	virtual void OnFASLLiabilitiesRtn(DFITCFaslLiabilitiesRtnField *pData);

	//以下为STOCK新增业务的响应接口
	/**
	* STOCK-ETF申赎委托响应
	* @param pData:指针若非空,返回ETF申赎委托响应信息结构体的地址,表明ETF申赎委托请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明ETF申赎委托请求失败
	*/
	virtual void OnRspStockETFEntrustOrder(DFITCStockRspETFEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo);

	/**
	* STOCK-ETF篮子股买卖响应
	* @param pData:指针若非空,返回ETF篮子股买卖响应信息结构体的地址,表明ETF篮子股买卖请求成功,pData->localOrderID小于0说明该成分股买卖失败。
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明ETF篮子股买卖请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspStockETFBasketOrder(DFITCStockRspETFBasketOrderField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast);

	/**
	* STOCK-债券回购响应
	* @param pData:指针若非空,返回债券回购响应信息结构体的地址,表明债券回购请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明债券回购请求失败
	*/
	virtual void OnRspStockBondRepurchaseOrder(DFITCStockRspBondRepurchaseOrderField *pData, DFITCSECRspInfoField *pRspInfo);


	/**
	* STOCK-债券出入库响应
	* @param pData:指针若非空,返回债券出入库响应信息结构体的地址,表明债券出入库请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明委托报单请求失败
	*/
	virtual void OnRspStockBondInOutStockOrder(DFITCStockRspBondInOutStockOrderField *pData, DFITCSECRspInfoField *pRspInfo);

	/**
	* STOCK-发行业务响应
	* @param pData:指针若非空,返回发行业务响应信息结构体的地址,表明发行业务请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明发行业务请求失败
	*/
	virtual void OnRspStockIssueBusinessOrder(DFITCStockRspIssueBusinessOrderField *pData, DFITCSECRspInfoField *pRspInfo);


	/**
	* STOCK-LOF基金响应
	* @param pData:指针若非空,返回LOF基金响应信息结构体的地址,表明LOF基金请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明LOF基金请求失败
	*/
	virtual void OnRspStockLOFEntrustOrder(DFITCStockRspLOFEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo);

	/**
	* STOCK-盘后定价响应
	* @param pData:指针若非空,返回盘后定价响应信息结构体的地址,表明盘后定价请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明盘后定价请求失败
	*/
	virtual void OnRspStockAfterHoursPriceOrder(DFITCStockRspAfterHoursPriceOrderField *pData, DFITCSECRspInfoField *pRspInfo);

	/**
	* STOCK-非交易业务响应
	* @param pData:指针若非空,返回非交易业务响应信息结构体的地址,表明非交易业务请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明非交易业务请求失败
	*/
	virtual void OnRspStockNonTradingBusinessOrder(DFITCStockRspNonTradingBusinessOrderField *pData, DFITCSECRspInfoField *pRspInfo);

	/**
	* STOCK-上海基金通响应
	* @param pData:指针若非空,返回上海基金通响应信息结构体的地址,表明上海基金通请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明上海基金通失败
	*/
	virtual void OnRspStockSHMutualFundOrder(DFITCStockRspSHMutualFundOrderField *pData, DFITCSECRspInfoField *pRspInfo);

	/**
	* STOCK-计算可买入ETF股票篮子数响应
	* @param pData:指针若非空,返回用户计算可买入ETF股票篮子数响应信息结构体的地址,表明计算可买入ETF股票篮子数请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明计算可买入ETF股票篮子数请求失败
	*/
	virtual void OnRspStockCalcAblePurchaseETFBasketQty(DFITCStockRspCalcAblePurchaseETFBasketQtyField *pData, DFITCSECRspInfoField *pRspInfo);

	/**
	* STOCK-计算债券回购可委托数量响应
	* @param pData:指针若非空,返回用户计算债券回购可委托数量响应信息结构体的地址,表明计算债券回购可委托数量请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明计算债券回购可委托数量请求失败
	*/
	virtual void OnRspStockCalcAbleBondRepurchaseQty(DFITCStockRspCalcAbleBondRepurchaseQtyField *pData, DFITCSECRspInfoField *pRspInfo);

	/**
	* STOCK-计算发行业务可认购数量响应
	* @param pData:指针若非空,返回用户计算发行业务可认购数量响应信息结构体的地址,表明计算发行业务可认购数量请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明计算发行业务可认购数量请求失败
	*/
	virtual void OnRspStockCalcAbleIssueBusinessQty(DFITCStockRspCalcAbleIssueBusinessQtyField *pData, DFITCSECRspInfoField *pRspInfo);

	/**
	* STOCK-计算LOF业务可委托数量响应
	* @param pData:指针若非空,返回用户计算LOF业务可委托数量响应信息结构体的地址,表明计算LOF业务可委托数量请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明计算LOF业务可委托数量请求失败
	*/
	virtual void OnRspStockCalcAblePurchaseLOFQty(DFITCStockRspCalcAblePurchaseLOFQtyField *pData, DFITCSECRspInfoField *pRspInfo);

	/**
	* STOCK-计算盘后定价可买卖数量响应
	* @param pData:指针若非空,返回用户计算盘后定价可买卖数量应信息结构体的地址,表明计算盘后定价可买卖数量请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明计算盘后定价可买卖数量请求失败
	*/
	virtual void OnRspStockCalcAbleAfterHoursPriceQty(DFITCStockRspCalcAbleAfterHoursPriceQtyField *pData, DFITCSECRspInfoField *pRspInfo);

	/**
	* STOCK-计算非交易业务可认购数量响应
	* @param pData:指针若非空,返回用户计算非交易业务可认购数量响应信息结构体的地址,表明计算非交易业务可认购数量请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明计算非交易业务可认购数量请求失败
	*/
	virtual void OnRspStockCalcAbleNonTradingBusinessQty(DFITCStockRspCalcAbleNonTradingBusinessQtyField *pData, DFITCSECRspInfoField *pRspInfo);

	/**
	* STOCK-计算上海基金业务可认购数量响应
	* @param pData:指针若非空,返回用户计算上海基金业务可认购数量响应信息结构体的地址,表明计算上海基金业务可认购数量请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明计算上海基金业务可认购数量请求失败
	*/
	virtual void OnRspStockCalcAbleSHMutualFundQty(DFITCStockRspCalcAbleSHMutualFundQtyField *pData, DFITCSECRspInfoField *pRspInfo);

	//-------------------------------------------------------------------------------------
	//task：任务
	//-------------------------------------------------------------------------------------
	void processTask();

	void processFrontConnected(Task *task);

	void processFrontDisconnected(Task *task);

	void processRtnNotice(Task *task);

	void processRspError(Task *task);

	void processRspStockUserLogin(Task *task);

	void processRspStockUserLogout(Task *task);

	void processRspStockUserPasswordUpdate(Task *task);

	void processRspStockEntrustOrder(Task *task);

	void processRspStockWithdrawOrder(Task *task);

	void processRspStockQryEntrustOrder(Task *task);

	void processRspStockQryRealTimeTrade(Task *task);

	void processRspStockQrySerialTrade(Task *task);

	void processRspStockQryPosition(Task *task);

	void processRspStockQryCapitalAccountInfo(Task *task);

	void processRspStockQryAccountInfo(Task *task);

	void processRspStockQryShareholderInfo(Task *task);

	void processRspStockTransferFunds(Task *task);

	void processRspStockEntrustBatchOrder(Task *task);

	void processRspStockWithdrawBatchOrder(Task *task);

	void processRspStockCalcAbleEntrustQty(Task *task);

	void processRspStockCalcAblePurchaseETFQty(Task *task);

	void processRspStockQryFreezeFundsDetail(Task *task);

	void processRspStockQryFreezeStockDetail(Task *task);

	void processRspStockQryTransferStockDetail(Task *task);

	void processRspStockQryTransferFundsDetail(Task *task);

	void processRspStockQryStockInfo(Task *task);

	void processRspStockQryStockStaticInfo(Task *task);

	void processRspStockQryTradeTime(Task *task);

	void processStockEntrustOrderRtn(Task *task);

	void processStockTradeRtn(Task *task);

	void processStockWithdrawOrderRtn(Task *task);

	void processRspSOPUserLogin(Task *task);

	void processRspSOPUserLogout(Task *task);

	void processRspSOPUserPasswordUpdate(Task *task);

	void processRspSOPEntrustOrder(Task *task);

	void processRspSOPQuoteEntrustOrder(Task *task);

	void processRspSOPGroupSplit(Task *task);

	void processRspSOPGroupExectueOrder(Task *task);

	void processRspSOPQryGroupPosition(Task *task);

	void processRspSOPLockOUnLockStock(Task *task);

	void processRspSOPWithdrawOrder(Task *task);

	void processRspSOPQryEntrustOrder(Task *task);

	void processRspSOPQrySerialTrade(Task *task);

	void processRspSOPQryPosition(Task *task);

	void processRspSOPQryCollateralPosition(Task *task);

	void processRspSOPQryCapitalAccountInfo(Task *task);

	void processRspSOPQryAccountInfo(Task *task);

	void processRspSOPQryShareholderInfo(Task *task);

	void processRspSOPCalcAbleEntrustQty(Task *task);

	void processRspSOPQryAbleLockStock(Task *task);

	void processRspSOPQryContactInfo(Task *task);

	void processRspSOPExectueOrder(Task *task);

	void processRspSOPQryExecAssiInfo(Task *task);

	void processRspSOPQryTradeTime(Task *task);

	void processRspSOPQryExchangeInfo(Task *task);

	void processRspSOPQryCommission(Task *task);

	void processRspSOPQryDeposit(Task *task);

	void processRspSOPQryContractObjectInfo(Task *task);

	void processSOPEntrustOrderRtn(Task *task);

	void processSOPTradeRtn(Task *task);

	void processSOPWithdrawOrderRtn(Task *task);

	void processSOPQuoteEntrustOrderRtn(Task *task);

	void processRspSOPCapitalTranInOut(Task *task);

	void processRspSOPCapitalDistributionRatio(Task *task);

	void processRspSOPFundTransBetweenNodes(Task *task);

	void processRspSOPModCapitalDistributionRatio(Task *task);

	void processRspFASLUserLogin(Task *task);

	void processRspFASLUserLogout(Task *task);

	void processRspFASLQryAbleFinInfo(Task *task);

	void processRspFASLQryAbleSloInfo(Task *task);

	void processRspFASLTransferCollateral(Task *task);

	void processRspFASLDirectRepayment(Task *task);

	void processRspFASLRepayStockTransfer(Task *task);

	void processRspFASLEntrustCrdtOrder(Task *task);

	void processRspFASLEntrustOrder(Task *task);

	void processRspFASLCalcAbleEntrustCrdtQty(Task *task);

	void processRspFASLQryCrdtFunds(Task *task);

	void processRspFASLQryCrdtContract(Task *task);

	void processRspFASLQryCrdtConChangeInfo(Task *task);

	void processRspFASLTransferFunds(Task *task);

	void processRspFASLTransferStock(Task *task);

	void processRspFASLQryAccountInfo(Task *task);

	void processRspFASLQryCapitalAccountInfo(Task *task);

	void processRspFASLQryShareholderInfo(Task *task);

	void processRspFASLQryPosition(Task *task);

	void processRspFASLQryEntrustOrder(Task *task);

	void processRspFASLQrySerialTrade(Task *task);

	void processRspFASLQryRealTimeTrade(Task *task);

	void processRspFASLQryFreezeFundsDetail(Task *task);

	void processRspFASLQryFreezeStockDetail(Task *task);

	void processRspFASLQryTransferFundsDetail(Task *task);

	void processRspFASLWithdrawOrder(Task *task);

	void processRspFASLQrySystemTime(Task *task);

	void processRspFASLQryTransferredContract(Task *task);

	void processRspFASLDesirableFundsOut(Task *task);

	void processRspFASLQryGuaranteedContract(Task *task);

	void processRspFASLQryUnderlyingContract(Task *task);

	void processRspFASLQryCentreFundAvlInfo(Task *task);

	void processRspFASLQryPlacingInterestsInfo(Task *task);

	void processRspFASLUserPasswordUpdate(Task *task);

	void processFASLEntrustOrderRtn(Task *task);

	void processFASLTradeRtn(Task *task);

	void processFASLWithdrawOrderRtn(Task *task);

	void processFASLLiabilitiesRtn(Task *task);

	void processRspStockETFEntrustOrder(Task *task);

	void processRspStockETFBasketOrder(Task *task);

	void processRspStockBondRepurchaseOrder(Task *task);

	void processRspStockBondInOutStockOrder(Task *task);

	void processRspStockIssueBusinessOrder(Task *task);

	void processRspStockLOFEntrustOrder(Task *task);

	void processRspStockAfterHoursPriceOrder(Task *task);

	void processRspStockNonTradingBusinessOrder(Task *task);

	void processRspStockSHMutualFundOrder(Task *task);

	void processRspStockCalcAblePurchaseETFBasketQty(Task *task);

	void processRspStockCalcAbleBondRepurchaseQty(Task *task);

	void processRspStockCalcAbleIssueBusinessQty(Task *task);

	void processRspStockCalcAblePurchaseLOFQty(Task *task);

	void processRspStockCalcAbleAfterHoursPriceQty(Task *task);

	void processRspStockCalcAbleNonTradingBusinessQty(Task *task);

	void processRspStockCalcAbleSHMutualFundQty(Task *task);

	//-------------------------------------------------------------------------------------
	//data：回调函数的数据字典
	//error：回调函数的错误字典
	//id：请求id
	//last：是否为最后返回
	//i：整数
	//-------------------------------------------------------------------------------------

	virtual void onFrontConnected() {};

	virtual void onFrontDisconnected(int reqid) {};

	virtual void onRtnNotice(const dict &data) {};

	virtual void onRspError(const dict &error) {};

	virtual void onRspStockUserLogin(const dict &data, const dict &error) {};

	virtual void onRspStockUserLogout(const dict &data, const dict &error) {};

	virtual void onRspStockUserPasswordUpdate(const dict &data, const dict &error) {};

	virtual void onRspStockEntrustOrder(const dict &data, const dict &error) {};

	virtual void onRspStockWithdrawOrder(const dict &data, const dict &error) {};

	virtual void onRspStockQryEntrustOrder(const dict &data, const dict &error, bool last) {};

	virtual void onRspStockQryRealTimeTrade(const dict &data, const dict &error, bool last) {};

	virtual void onRspStockQrySerialTrade(const dict &data, const dict &error, bool last) {};

	virtual void onRspStockQryPosition(const dict &data, const dict &error, bool last) {};

	virtual void onRspStockQryCapitalAccountInfo(const dict &data, const dict &error, bool last) {};

	virtual void onRspStockQryAccountInfo(const dict &data, const dict &error) {};

	virtual void onRspStockQryShareholderInfo(const dict &data, const dict &error, bool last) {};

	virtual void onRspStockTransferFunds(const dict &data, const dict &error) {};

	virtual void onRspStockEntrustBatchOrder(const dict &data, const dict &error) {};

	virtual void onRspStockWithdrawBatchOrder(const dict &data, const dict &error) {};

	virtual void onRspStockCalcAbleEntrustQty(const dict &data, const dict &error) {};

	virtual void onRspStockCalcAblePurchaseETFQty(const dict &data, const dict &error) {};

	virtual void onRspStockQryFreezeFundsDetail(const dict &data, const dict &error, bool last) {};

	virtual void onRspStockQryFreezeStockDetail(const dict &data, const dict &error, bool last) {};

	virtual void onRspStockQryTransferStockDetail(const dict &data, const dict &error, bool last) {};

	virtual void onRspStockQryTransferFundsDetail(const dict &data, const dict &error, bool last) {};

	virtual void onRspStockQryStockInfo(const dict &data, const dict &error, bool last) {};

	virtual void onRspStockQryStockStaticInfo(const dict &data, const dict &error, bool last) {};

	virtual void onRspStockQryTradeTime(const dict &data, const dict &error) {};

	virtual void onStockEntrustOrderRtn(const dict &data) {};

	virtual void onStockTradeRtn(const dict &data) {};

	virtual void onStockWithdrawOrderRtn(const dict &data) {};

	virtual void onRspSOPUserLogin(const dict &data, const dict &error) {};

	virtual void onRspSOPUserLogout(const dict &data, const dict &error) {};

	virtual void onRspSOPUserPasswordUpdate(const dict &data, const dict &error) {};

	virtual void onRspSOPEntrustOrder(const dict &data, const dict &error) {};

	virtual void onRspSOPQuoteEntrustOrder(const dict &data, const dict &error) {};

	virtual void onRspSOPGroupSplit(const dict &data, const dict &error) {};

	virtual void onRspSOPGroupExectueOrder(const dict &data, const dict &error) {};

	virtual void onRspSOPQryGroupPosition(const dict &data, const dict &error, bool last) {};

	virtual void onRspSOPLockOUnLockStock(const dict &data, const dict &error, bool last) {};

	virtual void onRspSOPWithdrawOrder(const dict &data, const dict &error) {};

	virtual void onRspSOPQryEntrustOrder(const dict &data, const dict &error, bool last) {};

	virtual void onRspSOPQrySerialTrade(const dict &data, const dict &error, bool last) {};

	virtual void onRspSOPQryPosition(const dict &data, const dict &error, bool last) {};

	virtual void onRspSOPQryCollateralPosition(const dict &data, const dict &error, bool last) {};

	virtual void onRspSOPQryCapitalAccountInfo(const dict &data, const dict &error) {};

	virtual void onRspSOPQryAccountInfo(const dict &data, const dict &error) {};

	virtual void onRspSOPQryShareholderInfo(const dict &data, const dict &error) {};

	virtual void onRspSOPCalcAbleEntrustQty(const dict &data, const dict &error) {};

	virtual void onRspSOPQryAbleLockStock(const dict &data, const dict &error, bool last) {};

	virtual void onRspSOPQryContactInfo(const dict &data, const dict &error, bool last) {};

	virtual void onRspSOPExectueOrder(const dict &data, const dict &error) {};

	virtual void onRspSOPQryExecAssiInfo(const dict &data, const dict &error, bool last) {};

	virtual void onRspSOPQryTradeTime(const dict &data, const dict &error, bool last) {};

	virtual void onRspSOPQryExchangeInfo(const dict &data, const dict &error, bool last) {};

	virtual void onRspSOPQryCommission(const dict &data, const dict &error, bool last) {};

	virtual void onRspSOPQryDeposit(const dict &data, const dict &error, bool last) {};

	virtual void onRspSOPQryContractObjectInfo(const dict &data, const dict &error, bool last) {};

	virtual void onSOPEntrustOrderRtn(const dict &data) {};

	virtual void onSOPTradeRtn(const dict &data) {};

	virtual void onSOPWithdrawOrderRtn(const dict &data) {};

	virtual void onSOPQuoteEntrustOrderRtn(const dict &data) {};

	virtual void onRspSOPCapitalTranInOut(const dict &data, const dict &error) {};

	virtual void onRspSOPCapitalDistributionRatio(const dict &data, const dict &error, bool last) {};

	virtual void onRspSOPFundTransBetweenNodes(const dict &data, const dict &error) {};

	virtual void onRspSOPModCapitalDistributionRatio(const dict &data, const dict &error) {};

	virtual void onRspFASLUserLogin(const dict &data, const dict &error) {};

	virtual void onRspFASLUserLogout(const dict &data, const dict &error) {};

	virtual void onRspFASLQryAbleFinInfo(const dict &data, const dict &error) {};

	virtual void onRspFASLQryAbleSloInfo(const dict &data, const dict &error, bool last) {};

	virtual void onRspFASLTransferCollateral(const dict &data, const dict &error) {};

	virtual void onRspFASLDirectRepayment(const dict &data, const dict &error) {};

	virtual void onRspFASLRepayStockTransfer(const dict &data, const dict &error) {};

	virtual void onRspFASLEntrustCrdtOrder(const dict &data, const dict &error) {};

	virtual void onRspFASLEntrustOrder(const dict &data, const dict &error) {};

	virtual void onRspFASLCalcAbleEntrustCrdtQty(const dict &data, const dict &error) {};

	virtual void onRspFASLQryCrdtFunds(const dict &data, const dict &error, bool last) {};

	virtual void onRspFASLQryCrdtContract(const dict &data, const dict &error, bool last) {};

	virtual void onRspFASLQryCrdtConChangeInfo(const dict &data, const dict &error, bool last) {};

	virtual void onRspFASLTransferFunds(const dict &data, const dict &error) {};

	virtual void onRspFASLTransferStock(const dict &data, const dict &error) {};

	virtual void onRspFASLQryAccountInfo(const dict &data, const dict &error) {};

	virtual void onRspFASLQryCapitalAccountInfo(const dict &data, const dict &error, bool last) {};

	virtual void onRspFASLQryShareholderInfo(const dict &data, const dict &error, bool last) {};

	virtual void onRspFASLQryPosition(const dict &data, const dict &error, bool last) {};

	virtual void onRspFASLQryEntrustOrder(const dict &data, const dict &error, bool last) {};

	virtual void onRspFASLQrySerialTrade(const dict &data, const dict &error, bool last) {};

	virtual void onRspFASLQryRealTimeTrade(const dict &data, const dict &error, bool last) {};

	virtual void onRspFASLQryFreezeFundsDetail(const dict &data, const dict &error, bool last) {};

	virtual void onRspFASLQryFreezeStockDetail(const dict &data, const dict &error, bool last) {};

	virtual void onRspFASLQryTransferFundsDetail(const dict &data, const dict &error, bool last) {};

	virtual void onRspFASLWithdrawOrder(const dict &data, const dict &error) {};

	virtual void onRspFASLQrySystemTime(const dict &data, const dict &error) {};

	virtual void onRspFASLQryTransferredContract(const dict &data, const dict &error, bool last) {};

	virtual void onRspFASLDesirableFundsOut(const dict &data, const dict &error) {};

	virtual void onRspFASLQryGuaranteedContract(const dict &data, const dict &error, bool last) {};

	virtual void onRspFASLQryUnderlyingContract(const dict &data, const dict &error, bool last) {};

	virtual void onRspFASLQryCentreFundAvlInfo(const dict &data, const dict &error, bool last) {};

	virtual void onRspFASLQryPlacingInterestsInfo(const dict &data, const dict &error, bool last) {};

	virtual void onRspFASLUserPasswordUpdate(const dict &data, const dict &error) {};

	virtual void onFASLEntrustOrderRtn(const dict &data) {};

	virtual void onFASLTradeRtn(const dict &data) {};

	virtual void onFASLWithdrawOrderRtn(const dict &data) {};

	virtual void onFASLLiabilitiesRtn(const dict &data) {};

	virtual void onRspStockETFEntrustOrder(const dict &data, const dict &error) {};

	virtual void onRspStockETFBasketOrder(const dict &data, const dict &error, bool last) {};

	virtual void onRspStockBondRepurchaseOrder(const dict &data, const dict &error) {};

	virtual void onRspStockBondInOutStockOrder(const dict &data, const dict &error) {};

	virtual void onRspStockIssueBusinessOrder(const dict &data, const dict &error) {};

	virtual void onRspStockLOFEntrustOrder(const dict &data, const dict &error) {};

	virtual void onRspStockAfterHoursPriceOrder(const dict &data, const dict &error) {};

	virtual void onRspStockNonTradingBusinessOrder(const dict &data, const dict &error) {};

	virtual void onRspStockSHMutualFundOrder(const dict &data, const dict &error) {};

	virtual void onRspStockCalcAblePurchaseETFBasketQty(const dict &data, const dict &error) {};

	virtual void onRspStockCalcAbleBondRepurchaseQty(const dict &data, const dict &error) {};

	virtual void onRspStockCalcAbleIssueBusinessQty(const dict &data, const dict &error) {};

	virtual void onRspStockCalcAblePurchaseLOFQty(const dict &data, const dict &error) {};

	virtual void onRspStockCalcAbleAfterHoursPriceQty(const dict &data, const dict &error) {};

	virtual void onRspStockCalcAbleNonTradingBusinessQty(const dict &data, const dict &error) {};

	virtual void onRspStockCalcAbleSHMutualFundQty(const dict &data, const dict &error) {};

	//-------------------------------------------------------------------------------------
	//req:主动函数的请求字典
	//-------------------------------------------------------------------------------------

	void createDFITCSECTraderApi(string pszLogAddr);

	void release();

	int init(string pszFrontAddress);

	int exit();

	int subscribePrivateTopic(int nResumeType);

	int reqStockUserLogin(const dict &req);

	int reqStockUserLogout(const dict &req);

	int reqStockUserPasswordUpdate(const dict &req);

	int reqStockEntrustOrder(const dict &req);

	int reqStockWithdrawOrder(const dict &req);

	int reqStockQryEntrustOrder(const dict &req);

	int reqStockQryRealTimeTrade(const dict &req);

	int reqStockQrySerialTrade(const dict &req);

	int reqStockQryPosition(const dict &req);

	int reqStockQryCapitalAccountInfo(const dict &req);

	int reqStockQryAccountInfo(const dict &req);

	int reqStockQryShareholderInfo(const dict &req);

	int reqStockTransferFunds(const dict &req);

	int reqStockEntrustBatchOrder(const dict &req);

	int reqStockWithdrawBatchOrder(const dict &req);

	int reqStockCalcAbleEntrustQty(const dict &req);

	int reqStockCalcAblePurchaseETFQty(const dict &req);

	int reqStockQryFreezeFundsDetail(const dict &req);

	int reqStockQryFreezeStockDetail(const dict &req);

	int reqStockQryTransferFundsDetail(const dict &req);

	int reqStockQryTransferStockDetail(const dict &req);

	int reqStockQryStockInfo(const dict &req);

	int reqStockQryStockStaticInfo(const dict &req);

	int reqStockQryTradeTime(const dict &req);

	int reqSOPUserLogin(const dict &req);

	int reqSOPUserLogout(const dict &req);

	int reqSOPUserPasswordUpdate(const dict &req);

	int reqSOPEntrustOrder(const dict &req);

	int reqSOPQuoteEntrustOrder(const dict &req);

	int reqSOPGroupSplit(const dict &req);

	int reqSOPGroupExectueOrder(const dict &req);

	int reqSOPQryGroupPosition(const dict &req);

	int reqSOPLockOUnLockStock(const dict &req);

	int reqSOPWithdrawOrder(const dict &req);

	int reqSOPQryEntrustOrder(const dict &req);

	int reqSOPQrySerialTrade(const dict &req);

	int reqSOPQryPosition(const dict &req);

	int reqSOPQryCollateralPosition(const dict &req);

	int reqSOPQryCapitalAccountInfo(const dict &req);

	int reqSOPQryAccountInfo(const dict &req);

	int reqSOPQryShareholderInfo(const dict &req);

	int reqSOPCalcAbleEntrustQty(const dict &req);

	int reqSOPQryAbleLockStock(const dict &req);

	int reqSOPQryContactInfo(const dict &req);

	int reqSOPExectueOrder(const dict &req);

	int reqSOPQryExecAssiInfo(const dict &req);

	int reqSOPQryTradeTime(const dict &req);

	int reqSOPQryExchangeInfo(const dict &req);

	int reqSOPQryCommission(const dict &req);

	int reqSOPQryDeposit(const dict &req);

	int reqSOPQryContractObjectInfo(const dict &req);

	int reqSOPCapitalTranInOut(const dict &req);

	int reqSOPCapitalDistributionRatio(const dict &req);

	int reqSOPFundTransBetweenNodes(const dict &req);

	int reqSOPModCapitalDistributionRatio(const dict &req);

	int reqFASLUserLogin(const dict &req);

	int reqFASLUserLogout(const dict &req);

	int reqFASLQryAbleFinInfo(const dict &req);

	int reqFASLQryAbleSloInfo(const dict &req);

	int reqFASLTransferCollateral(const dict &req);

	int reqFASLDirectRepayment(const dict &req);

	int reqFASLRepayStockTransfer(const dict &req);

	int reqFASLEntrustCrdtOrder(const dict &req);

	int reqFASLEntrustOrder(const dict &req);

	int reqFASLWithdrawOrder(const dict &req);

	int reqFASLCalcAbleEntrustCrdtQty(const dict &req);

	int reqFASLQryCrdtFunds(const dict &req);

	int reqFASLQryCrdtContract(const dict &req);

	int reqFASLQryCrdtConChangeInfo(const dict &req);

	int reqFASLTransferFunds(const dict &req);

	int reqFASLTransferStock(const dict &req);

	int reqFASLQryAccountInfo(const dict &req);

	int reqFASLQryCapitalAccountInfo(const dict &req);

	int reqFASLQryShareholderInfo(const dict &req);

	int reqFASLQryPosition(const dict &req);

	int reqFASLQryEntrustOrder(const dict &req);

	int reqFASLQrySerialTrade(const dict &req);

	int reqFASLQryRealTimeTrade(const dict &req);

	int reqFASLQryFreezeFundsDetail(const dict &req);

	int reqFASLQryFreezeStockDetail(const dict &req);

	int reqFASLQryTransferFundsDetail(const dict &req);

	int reqFASLQrySystemTime(const dict &req);

	int reqFASLQryTransferredContract(const dict &req);

	int reqFASLDesirableFundsOut(const dict &req);

	int reqFASLQryGuaranteedContract(const dict &req);

	int reqFASLQryUnderlyingContract(const dict &req);

	int reqFASLQryCentreFundAvlInfo(const dict &req);

	int reqFASLQryPlacingInterestsInfo(const dict &req);

	int reqFASLUserPasswordUpdate(const dict &req);

	int reqStockETFEntrustOrder(const dict &req);

	int reqStockETFBasketOrder(const dict &req);

	int reqStockBondRepurchaseOrder(const dict &req);

	int reqStockBondInOutStockOrder(const dict &req);

	int reqStockIssueBusinessOrder(const dict &req);

	int reqStockLOFEntrustOrder(const dict &req);

	int reqStockAfterHoursPriceOrder(const dict &req);

	int reqStockNonTradingBusinessOrder(const dict &req);

	int reqStockSHMutualFundOrder(const dict &req);

	int reqStockCalcAblePurchaseETFBasketQty(const dict &req);

	int reqStockCalcAbleBondRepurchaseQty(const dict &req);

	int reqStockCalcAbleIssueBusinessQty(const dict &req);

	int reqStockCalcAblePurchaseLOFQty(const dict &req);

	int reqStockCalcAbleAfterHoursPriceQty(const dict &req);

	int reqStockCalcAbleNonTradingBusinessQty(const dict &req);

	int reqStockCalcAbleSHMutualFundQty(const dict &req);

};

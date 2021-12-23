/**
 * 版权所有(C)2012-2016, 福建顶点软件股份有限公司
 * 文件名称：DFITCSECTraderApi.h
 * 文件说明：定义接口所需的数据接口
 * 当前版本：5.1.0.0
 * 作者：专业交易接口开发组
 * 发布日期：2019年11月
 */
#ifndef DFITCSECTRADERAPI_H_
#define DFITCSECTRADERAPI_H_

#include "DFITCSECApiStruct.h"
#ifdef WIN32
#ifndef AFX_EXT_CLASS
#define AFX_EXT_CLASS       _declspec(dllexport)
#endif

#ifdef DFITCSECAPI_EXPORTS
#define DFITCSEC_TRADER_API __declspec(dllexport)
#else 
#define DFITCSEC_TRADER_API __declspec(dllimport)
#endif
#else 
#define DFITCSEC_TRADER_API 
#endif

#ifndef NULL
#define NULL    0
#endif //NULL

class DFITCSECTraderSpi
{
public:
    /**
     * SEC-网络连接正常响应
     */
    virtual void OnFrontConnected(){};
    /**
     * SEC-网络连接不正常响应
     */
    virtual void OnFrontDisconnected(int nReason) {};
    /**
     * SEC-消息通知
     */
    virtual void OnRtnNotice(DFITCSECRspNoticeField *pNotice) {};
    /**
    * ERR-错误应答
    * @param pRspInfo:指针若非空，返回错误信息结构地址
    */
    virtual void OnRspError(DFITCSECRspInfoField *pRspInfo) {};
    /**
    * STOCK-登录响应
    * @param pData:指针若非空,返回用户登录响应信息结构体的地址,表明登录请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明登录请求失败
    */
    virtual void OnRspStockUserLogin(DFITCSECRspUserLoginField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * STOCK-登出响应
    * @param pData:指针若非空,返回用户登出响应信息结构体的地址,表明登出请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明登出请求失败
    */
    virtual void OnRspStockUserLogout(DFITCSECRspUserLogoutField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * STOCK-密码更新响应
    * @param pData:指针若非空,返回用户密码更新响应信息结构体的地址,表明密码更新请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明密码更新请求失败
    */
    virtual void OnRspStockUserPasswordUpdate(DFITCSECRspPasswordUpdateField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * STOCK-委托报单响应
    * @param pData:指针若非空,返回用户委托报单响应信息结构体的地址,表明报单请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明委托报单请求失败
    */
    virtual void OnRspStockEntrustOrder(DFITCStockRspEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * STOCK-委托撤单响应
    * @param pData:指针若非空,返回用户委托撤单响应信息结构体的地址,表明撤单请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明委托撤单请求失败
    */
    virtual void OnRspStockWithdrawOrder(DFITCSECRspWithdrawOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * STOCK-委托查询响应
    * @param pData:指针若非空,返回用户委托查询响应信息结构体的地址,表明查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明委托查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspStockQryEntrustOrder(DFITCStockRspQryEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * STOCK-实时成交查询响应
    * @param pData:指针若非空,返回用户实时成交查询响应信息结构体的地址,表明实时成交查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明实时成交查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspStockQryRealTimeTrade(DFITCStockRspQryRealTimeTradeField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * STOCK-分笔成交查询响应
    * @param pData:指针若非空,返回用户分笔成交查询响应信息结构体的地址,表明分笔成交查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明分笔成交查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspStockQrySerialTrade(DFITCStockRspQrySerialTradeField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * STOCK-持仓查询响应
    * @param pData:指针若非空,返回用户持仓查询响应信息结构体的地址,表明持仓查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明持仓查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspStockQryPosition(DFITCStockRspQryPositionField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * STOCK-资金账号查询响应
    * @param pData:指针若非空,返回用户资金账号查询响应信息结构体的地址,表明资金账号查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明资金账号查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspStockQryCapitalAccountInfo(DFITCStockRspQryCapitalAccountField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * STOCK-交易账号查询响应
    * @param pData:指针若非空,返回用户交易账号查询响应信息结构体的地址,表明交易账号查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明交易账号查询请求失败
    */
    virtual void OnRspStockQryAccountInfo(DFITCStockRspQryAccountField *pData, DFITCSECRspInfoField *pRspInfo) {}; 
    /**
    * STOCK-股东号查询响应
    * @param pData:指针若非空,返回用户股东号查询响应信息结构体的地址,表明股东号查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明股东号查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspStockQryShareholderInfo(DFITCStockRspQryShareholderField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {}; 
    /**
    * STOCK-资金调拨响应
    * @param pData:指针若非空,返回用户资金调拨响应信息结构体的地址,表明股资金调拨请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明资金调拨请求失败
    */
    virtual void OnRspStockTransferFunds(DFITCStockRspTransferFundsField *pData,DFITCSECRspInfoField *pRspInfo) {};
    /**
    * STOCK-批量委托响应
    * @param pData:指针若非空,返回用户批量委托响应信息结构体的地址,表明批量委托请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明批量委托请求失败
    */
    virtual void OnRspStockEntrustBatchOrder(DFITCStockRspEntrustBatchOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * STOCK-批量撤单响应
    * @param pData:指针若非空,返回用户批量撤单响应信息结构体的地址,表明批量撤单请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明批量撤单请求失败
    */
    virtual void OnRspStockWithdrawBatchOrder(DFITCStockRspWithdrawBatchOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * STOCK-计算可委托数量响应
    * @param pData:指针若非空,返回用户计算可委托数量响应信息结构体的地址,表明计算可委托数量请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明计算可委托数量请求失败
    */
    virtual void OnRspStockCalcAbleEntrustQty(DFITCStockRspCalcAbleEntrustQtyField *pData, DFITCSECRspInfoField *pRspInfo) {}; 
    /**
    * STOCK-计算申购ETF数量响应
    * @param pData:指针若非空,返回用户计算申购ETF数量响应信息结构体的地址,表明计算申购ETF数量请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明计算申购ETF数量请求失败
    */
    virtual void OnRspStockCalcAblePurchaseETFQty(DFITCStockRspCalcAblePurchaseETFQtyField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * STOCK-冻结资金明细查询响应
    * @param pData:指针若非空,返回用户冻结资金明细查询响应信息结构体的地址,表明冻结资金明细查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明冻结资金明细查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspStockQryFreezeFundsDetail(DFITCStockRspQryFreezeFundsDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {}; 
    /**
    * STOCK-冻结证券明细查询响应
    * @param pData:指针若非空,返回用户冻结证券明细查询响应信息结构体的地址,表明冻结证券明细查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明冻结证券明细查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspStockQryFreezeStockDetail(DFITCStockRspQryFreezeStockDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * STOCK-调拨证券明细查询响应
    * @param pData:指针若非空,返回用户调拨证券明细查询响应信息结构体的地址,表明调拨证券明细查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明调拨证券明细查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspStockQryTransferStockDetail(DFITCStockRspQryTransferStockDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * STOCK-调拨资金明细查询响应
    * @param pData:指针若非空,返回用户调拨资金明细查询响应信息结构体的地址,表明调拨资金明细查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明调拨资金明细查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspStockQryTransferFundsDetail(DFITCStockRspQryTransferFundsDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * STOCK-证券信息查询响应
    * @param pData:指针若非空,返回用户证券信息查询响应信息结构体的地址,表明证券信息查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明证券信息查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspStockQryStockInfo(DFITCStockRspQryStockField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * STOCK-证券静态信息查询响应
    * @param pData:指针若非空,返回用户证券静态信息查询响应信息结构体的地址,表明证券静态信息查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明证券静态信息查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspStockQryStockStaticInfo(DFITCStockRspQryStockStaticField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * STOCK-交易时间查询响应
    * @param pData:指针若非空,返回用户交易时间查询响应信息结构体的地址,表明交易时间查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明交易时间查询请求失败
    */
    virtual void OnRspStockQryTradeTime(DFITCStockRspQryTradeTimeField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * STOCK-委托回报响应
    * @param pData:返回委托回报结构体的地址
    */
    virtual void OnStockEntrustOrderRtn(DFITCStockEntrustOrderRtnField * pData){};
    /**
    * STOCK-成交回报响应
    * @param pData:返回成交回报结构体的地址
    */
    virtual void OnStockTradeRtn(DFITCStockTradeRtnField * pData){};
    /**
    * STOCK-撤单回报响应
    * @param pData:返回撤单回报结构体的地址
    */
    virtual void OnStockWithdrawOrderRtn(DFITCStockWithdrawOrderRtnField * pData){};
    
    /**
    * SOP-登录响应
    * @param pRspUserLogin:指针若非空,返回用户登录响应信息结构地址,表明登录请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明登录请求失败
    */
    virtual void OnRspSOPUserLogin(DFITCSECRspUserLoginField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
     * SOP-登出响应
     * @param pData:指针若非空,返回用户登出响应信息结构地址,表明登出请求成功
     * @param pRspInfo:指针若非空，返回错误信息地址，表明登出请求失败
     */
    virtual void OnRspSOPUserLogout(DFITCSECRspUserLogoutField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * SOP-用户口令更新响应
    * @param pData:指针若非空,返回用户口令更新响应信息结构地址,表明用户口令更新请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明用户口令更新请求失败
    */
    virtual void OnRspSOPUserPasswordUpdate(DFITCSECRspPasswordUpdateField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * SOP-报单响应
    * @param pData:指针若非空,返回用户报单响应信息结构地址,表明报单请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明报单请求失败
    */
    virtual void OnRspSOPEntrustOrder(DFITCSOPRspEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * SOP-做市商报单响应
    * @param pData:指针若非空,返回用户报价委托响应信息结构地址,表明做市商报单请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明做市商报单请求失败
    */
    virtual void OnRspSOPQuoteEntrustOrder(DFITCSOPRspQuoteEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * SOP-组合拆分委托响应
    * @param pData:指针若非空,返回用户组合拆分委托响应信息结构地址,表明组合拆分委托请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明组合拆分委托请求失败
    */
    virtual void OnRspSOPGroupSplit(DFITCSOPRspEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
     * SOP-期权组合行权委托响应
     * @param pData:指针若非空,返回用户期权组合行权委托响应信息结构地址,表明期权组合行权委托请求成功
     * @return pRspInfo:指针若非空，返回错误信息地址，表明期权组合行权委托请求失败，具体错误请对照error.xml  
     */
	virtual void OnRspSOPGroupExectueOrder(DFITCSOPRspGroupExectueOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * SOP-查询客户组合持仓明细响应
    * @param pData:指针若非空,返回用户查询客户组合持仓明细响应结构地址,表明查询客户组合持仓明细请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明查询客户组合持仓明细请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspSOPQryGroupPosition(DFITCSOPRspQryGroupPositionField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * SOP-证券锁定解锁响应
    * @param pData:指针若非空,返回用户证券锁定解锁响应信息结构地址,表明证券锁定解锁请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明证券锁定解锁请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspSOPLockOUnLockStock(DFITCSOPRspLockOUnLockStockField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {}; 
    /**
    * SOP-撤单响应
    * @param pData:指针若非空,返回用户撤单响应信息结构地址,表明撤单请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明撤单请求失败
    */
    virtual void OnRspSOPWithdrawOrder(DFITCSECRspWithdrawOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * SOP-委托查询响应
    * @param pData:指针若非空,返回用户委托查询响应信息结构地址,表明委托查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明委托查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspSOPQryEntrustOrder(DFITCSOPRspQryEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * SOP-分笔成交查询响应
    * @param pData:指针若非空,返回用户分笔成交查询响应信息结构地址,表明分笔成交查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明分笔成交查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspSOPQrySerialTrade(DFITCSOPRspQrySerialTradeField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * SOP-持仓查询响应
    * @param pData:指针若非空,返回用户持仓查询响应信息结构地址,表明持仓查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明持仓查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspSOPQryPosition(DFITCSOPRspQryPositionField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * SOP-客户担保持仓查询响应
    * @param pData:指针若非空,返回用户客户担保持仓查询响应信息结构地址,表明客户担保持仓查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户担保持仓查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspSOPQryCollateralPosition(DFITCSOPRspQryCollateralPositionField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * SOP-客户资金查询响应
    * @param pData:指针若非空,返回用户客户资金查询响应信息结构地址,表明客户客户资金查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户客户资金查询请求失败
    */
    virtual void OnRspSOPQryCapitalAccountInfo(DFITCSOPRspQryCapitalAccountField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * SOP-客户信息查询响应
    * @param pData:指针若非空,返回用户客户信息查询响应信息结构地址,表明客户客户信息查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户客户信息查询请求失败
    */
    virtual void OnRspSOPQryAccountInfo(DFITCSOPRspQryAccountField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * SOP-股东信息查询响应
    * @param pData:指针若非空,返回用户股东信息查询响应信息结构地址,表明客户股东信息查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户股东信息查询请求失败
    */
    virtual void OnRspSOPQryShareholderInfo(DFITCSOPRspQryShareholderField *pData, DFITCSECRspInfoField *pRspInfo) {}; 
    /**
    * SOP-可委托数量查询响应
    * @param pData:指针若非空,返回用户可委托数量查询响应信息结构地址,表明客户可委托数量查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户可委托数量查询请求失败
    */
    virtual void OnRspSOPCalcAbleEntrustQty(DFITCSOPRspCalcAbleEntrustQtyField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * SOP-客户可锁定证券查询响应
    * @param pData:指针若非空,返回用户客户可锁定证券查询响应信息结构地址,表明客户客户可锁定证券查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户客户可锁定证券查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspSOPQryAbleLockStock(DFITCSOPRspQryAbleLockStockField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {}; 
    /**
    * SOP-期权合约代码查询响应
    * @param pData:指针若非空,返回用户期权合约代码查询响应信息结构地址,表明客户期权合约代码查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户期权合约代码查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspSOPQryContactInfo(DFITCSOPRspQryContactField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {}; 
    /**
    * SOP-执行委托响应
    * @param pData:指针若非空,返回用户执行委托响应信息结构地址,表明客户执行委托请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户执行委托请求失败
    */
	virtual void OnRspSOPExectueOrder(DFITCSOPRspExectueOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * SOP-客户行权指派信息查询响应
    * @param pData:指针若非空,返回用户客户行权指派信息查询响应信息结构地址,表明客户客户行权指派信息查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户客户行权指派信息查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspSOPQryExecAssiInfo(DFITCSOPRspQryExecAssiInfoField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * SOP-查询交易时间响应
    * @param pData:指针若非空,返回用户查询交易时间响应信息结构地址,表明客户查询交易时间请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户查询交易时间请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspSOPQryTradeTime(DFITCSOPRspQryTradeTimeField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * SOP-获取所有交易所参数响应
    * @param pData:指针若非空,返回用户获取所有交易所参数响应信息结构地址,表明客户获取所有交易所参数请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户获取所有交易所参数请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspSOPQryExchangeInfo(DFITCSOPRspQryExchangeInfoField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * SOP-查询手续费参数响应
    * @param pData:指针若非空,返回用户查询手续费参数响应信息结构地址,表明客户查询手续费参数请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户查询手续费参数请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspSOPQryCommission(DFITCSOPRspQryCommissionField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * SOP-查询保证金率参数响应
    * @param pData:指针若非空,返回用户查询保证金率参数响应信息结构地址,表明客户查询保证金率参数请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户查询保证金率参数请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspSOPQryDeposit(DFITCSOPRspQryDepositField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * SOP-期权标的信息查询响应
    * @param pData:指针若非空,返回用户期权标的信息查询响应信息结构地址,表明客户期权标的信息查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户期权标的信息查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspSOPQryContractObjectInfo(DFITCSOPRspQryContractObjectField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * SOP-委托回报响应
    * @param pData:返回委托回报结构体的地址
    */
    virtual void OnSOPEntrustOrderRtn(DFITCSOPEntrustOrderRtnField * pData){};
    /**
    * SOP-成交回报响应
    * @param pData:返回成交回报结构体的地址
    */
    virtual void OnSOPTradeRtn(DFITCSOPTradeRtnField * pData){};
    /**
    * SOP-撤单回报响应
    * @param pData:返回撤单回报结构体的地址
    */
    virtual void OnSOPWithdrawOrderRtn(DFITCSOPWithdrawOrderRtnField * pData){};
	/**
	* SOP-做市委托回报响应
	* @param pData:返回做市双边报价委托回报结构体的地址
	*/
	virtual void OnSOPQuoteEntrustOrderRtn(DFITCSOPQuoteEntrustOrderRtnField * pData){};

	/**
	* SOP-资金调入调出响应
	* @param pData:指针若非空,返回资金调入调出响应信息结构地址,表明客户资金调入调出请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明资金调入调出请求失败
	*/
	virtual void OnRspSOPCapitalTranInOut(DFITCSOPRspCapitalTranInOutField *pData, DFITCSECRspInfoField *pRspInfo) {};
	
	/**
	* SOP-资金多节点分配比例查询响应
	* @param pData:指针若非空,返回资金多节点分配比例响应信息结构地址,表明客户资金多节点分配比例请求查询成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明资金多节点分配比例查询请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspSOPCapitalDistributionRatio(DFITCSOPRspQryCapitalDistributionRatioField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
	
	/**
	* SOP-节点间资金划拨响应
	* @param pData:指针若非空,返回节点间资金划拨响应信息结构地址,表明客户节点间资金划拨请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明节点间资金划拨请求失败
	*/
	virtual void OnRspSOPFundTransBetweenNodes(DFITCSOPRspFundTransBetweenNodesField *pData, DFITCSECRspInfoField *pRspInfo) {};
	
	/**
	* SOP-修改资金多节点分配比例响应
	* @param pData:指针若非空,返回设置资金多节点分配比例响应信息结构地址,表明设置客户资金多节点分配比例请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明设置资金多节点分配比例请求失败
	*/
	virtual void OnRspSOPModCapitalDistributionRatio(DFITCSOPRspModCapitalDistributionRatioField *pData, DFITCSECRspInfoField *pRspInfo) {};

    /**
    * FASL-登录响应
    * @param pData:指针若非空,返回用户融资融券登录响应信息结构地址,表明客户融资融券登录请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户融资融券登录请求失败
    */
    virtual void OnRspFASLUserLogin(DFITCSECRspUserLoginField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * FASL-登出响应
    * @param pData:指针若非空,返回用户融资融券登出响应信息结构地址,表明客户融资融券登出请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户融资融券登出请求失败
    */
    virtual void OnRspFASLUserLogout(DFITCSECRspUserLogoutField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * FASL-客户可融资信息响应
    * @param pData:指针若非空,返回用户客户可融资信息响应信息结构地址,表明客户客户可融资信息请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户客户可融资信息请求失败
    */
    virtual void OnRspFASLQryAbleFinInfo(DFITCFASLRspAbleFinInfoField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * FASL-客户可融券信息响应
    * @param pData:指针若非空,返回用户客户可融券信息响应信息结构地址,表明客户客户可融券信息请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户客户可融券信息请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspFASLQryAbleSloInfo(DFITCFASLRspAbleSloInfoField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * FASL-担保物划转响应
    * @param pData:指针若非空,返回用户担保物划转响应信息结构地址,表明客户担保物划转请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户担保物划转请求失败
    */
    virtual void OnRspFASLTransferCollateral(DFITCFASLRspTransferCollateralField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * FASL-直接还款响应
    * @param pData:指针若非空,返回用户直接还款响应信息结构地址,表明客户直接还款请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户直接还款请求失败
    */
    virtual void OnRspFASLDirectRepayment(DFITCFASLRspDirectRepaymentField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * FASL-还券划转响应
    * @param pData:指针若非空,返回用户还券划转响应信息结构地址,表明客户还券划转请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户还券划转请求失败
    */
    virtual void OnRspFASLRepayStockTransfer(DFITCFASLRspRepayStockTransferField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * FASL-信用交易响应
    * @param pData:指针若非空,返回用户信用交易响应信息结构地址,表明客户信用交易请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户信用交易请求失败
    */
    virtual void OnRspFASLEntrustCrdtOrder(DFITCFASLRspEntrustCrdtOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * FASL-融资融券交易响应
    * @param pData:指针若非空,返回用户融资融券交易响应信息结构地址,表明客户融资融券交易请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户融资融券交易请求失败
    */
    virtual void OnRspFASLEntrustOrder(DFITCFASLRspEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * FASL-信用可委托数量查询响应
    * @param pData:指针若非空,返回用户信用可委托数量查询响应信息结构地址,表明客户信用可委托数量查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户信用可委托数量查询请求失败
    */
    virtual void OnRspFASLCalcAbleEntrustCrdtQty(DFITCFASLRspCalcAbleEntrustCrdtQtyField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * FASL-查询信用资金响应
    * @param pData:指针若非空,返回用户查询信用资金响应信息结构地址,表明客户查询信用资金请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户查询信用资金请求失败
	  * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
	virtual void OnRspFASLQryCrdtFunds(DFITCFASLRspQryCrdtFundsField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * FASL-信用合约信息响应
    * @param pData:指针若非空,返回用户信用合约信息响应信息结构地址,表明客户信用合约信息请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户信用合约信息请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspFASLQryCrdtContract(DFITCFASLRspQryCrdtContractField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLat) {};
    /**
    * FASL-信用合约变动信息查询响应
    * @param pData:指针若非空,返回用户信用合约变动信息查询响应信息结构地址,表明客户信用合约变动信息查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户信用合约变动信息查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspFASLQryCrdtConChangeInfo(DFITCFASLRspQryCrdtConChangeInfoField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * FASL-资金调转响应
    * @param pData:指针若非空,返回用户资金调转响应信息结构地址,表明客户资金调转请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户资金调转请求失败
    */
	virtual void OnRspFASLTransferFunds(DFITCFASLRspTransferFundsField *pData, DFITCSECRspInfoField *pRspInfo) {};
	/**
	* FASL-证券调转响应
	* @param pData:指针若非空,返回用户证券调转响应信息结构地址,表明客户证券调转请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明客户证券调转请求失败
	*/
	virtual void OnRspFASLTransferStock(DFITCFASLRspTransferStockField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * FASL-客户信息查询响应
    * @param pData:指针若非空,返回用户客户信息查询响应信息结构地址,表明客户客户信息查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户客户信息查询请求失败
    */
	virtual void OnRspFASLQryAccountInfo(DFITCFASLRspQryAccountField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * FASL-客户资金查询响应
    * @param pData:指针若非空,返回用户客户资金查询响应信息结构地址,表明客户客户资金查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户客户资金查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
	virtual void OnRspFASLQryCapitalAccountInfo(DFITCFASLRspQryCapitalAccountField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * FASL-股东信息查询响应
    * @param pData:指针若非空,返回用户股东信息查询响应信息结构地址,表明客户股东信息查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户股东信息查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
	virtual void OnRspFASLQryShareholderInfo(DFITCFASLRspQryShareholderField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * FASL-持仓查询响应
    * @param pData:指针若非空,返回用户持仓查询响应信息结构地址,表明客户持仓查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户持仓查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
	virtual void OnRspFASLQryPosition(DFITCFASLRspQryPositionField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * FASL-委托查询响应
    * @param pData:指针若非空,返回用户委托查询响应信息结构地址,表明客户委托查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户委托查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
	virtual void OnRspFASLQryEntrustOrder(DFITCFASLRspQryEntrustOrderField * pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * FASL-分笔成交查询响应
    * @param pData:指针若非空,返回用户分笔成交查询响应信息结构地址,表明客户分笔成交查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户分笔成交查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
	virtual void OnRspFASLQrySerialTrade(DFITCFASLRspQrySerialTradeField * pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * FASL-实时成交查询响应
    * @param pData:指针若非空,返回用户实时成交查询响应信息结构地址,表明客户实时成交查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户实时成交查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
	virtual void OnRspFASLQryRealTimeTrade(DFITCFASLRspQryRealTimeTradeField * pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * FASL-资金冻结明细查询响应
    * @param pData:指针若非空,返回用户资金冻结明细查询响应信息结构地址,表明客户资金冻结明细查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户资金冻结明细查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
	virtual void OnRspFASLQryFreezeFundsDetail(DFITCFASLRspQryFreezeFundsDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * FASL-证券冻结明细查询响应
    * @param pData:指针若非空,返回用户证券冻结明细查询响应信息结构地址,表明客户证券冻结明细查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户证券冻结明细查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
	virtual void OnRspFASLQryFreezeStockDetail(DFITCFASLRspQryFreezeStockDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * FASL-资金调拨明细查询响应
    * @param pData:指针若非空,返回用户资金调拨明细查询响应信息结构地址,表明客户资金调拨明细查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户资金调拨明细查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
	virtual void OnRspFASLQryTransferFundsDetail(DFITCFASLRspQryTransferFundsDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * FASL-撤单响应
    * @param pData:指针若非空,返回用户撤单响应信息结构地址,表明撤单请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明撤单请求失败
    */
    virtual void OnRspFASLWithdrawOrder(DFITCFASLRspWithdrawOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * FASL-当前系统时间查询请求响应
    * @param pData:指针若非空,返回用户系统时间查询响应信息结构地址,表明系统时间查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明系统时间查询请求失败
    */
    virtual void OnRspFASLQrySystemTime(DFITCFASLRspQryTradeTimeField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * FASL-可转入担保证券查询请求响应
    * @param pData:指针若非空,返回可转入担保证券查询响应信息结构地址,表明可转入担保证券查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明可转入担保证券查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspFASLQryTransferredContract(DFITCFASLRspQryTransferredContractField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * FASL-客户可取资金调出请求响应
    * @param pData:指针若非空,返回客户可取资金调出响应信息结构地址,表明客户可取资金调出请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明客户可取资金调出请求失败
    */
    virtual void OnRspFASLDesirableFundsOut(DFITCFASLRspDesirableFundsOutField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * FASL-担保证券查询请求响应
    * @param pData:指针若非空,返回担保证券查询响应信息结构地址,表明担保证券查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明担保证券查询请求失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspFASLQryGuaranteedContract(DFITCFASLRspQryGuaranteedContractField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
    /**
    * FASL-标的证券查询请求响应
    * @param pData:指针若非空,返回标的证券查询响应信息结构地址,表明标的证券查询请求成功
    * @param pRspInfo:指针若非空，返回错误信息地址，表明标的证券查询失败
    * @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
    */
    virtual void OnRspFASLQryUnderlyingContract(DFITCFASLRspQryUnderlyingContractField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
	/**
	* FASL-集中交易资金查询请求响应
	* @param pData:指针若非空,返回集中交易资金查询响应信息结构地址,表明集中交易资金查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明标的证券查询失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryCentreFundAvlInfo(DFITCFASLRspQryCentreFundAvlField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
	/**
	* FASL-客户配售权益查询请求响应
	* @param pData:指针若非空,返回客户配售权益查询响应信息结构地址,表明客户配售权益查询请求成功
	* @param pRspInfo:指针若非空，返回错误信息地址，表明标的证券查询失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspFASLQryPlacingInterestsInfo(DFITCFASLRspQryPlacingInterestsField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};
	/**
	* FASL-密码更新响应
	* @param pData:指针若非空,返回用户密码更新响应信息结构体的地址,表明密码更新请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明密码更新请求失败
	*/
	virtual void OnRspFASLUserPasswordUpdate(DFITCSECRspPasswordUpdateField *pData, DFITCSECRspInfoField *pRspInfo) {};
    /**
    * FASL-委托回报响应
    * @param pData:返回委托回报结构体的地址
    */
	virtual void OnFASLEntrustOrderRtn(DFITCFaslEntrustOrderRtnField *pData){};
    /**
    * FASL-成交回报响应
    * @param pData:返回成交回报结构体的地址
    */
	virtual void OnFASLTradeRtn(DFITCFaslTradeRtnField *pData){};
    /**
    * FASL-撤单回报响应
    * @param pData:返回撤单回报结构体的地址
    */
    virtual void OnFASLWithdrawOrderRtn(DFITCFaslWithdrawOrderRtnField *pData){};
	/**
	* FASL-负债变动响应
	* @param pData:返回负债变动结构体的地址
	*/
	virtual void OnFASLLiabilitiesRtn(DFITCFaslLiabilitiesRtnField *pData){};

	//以下为STOCK新增业务的响应接口
	/**
	* STOCK-ETF申赎委托响应
	* @param pData:指针若非空,返回ETF申赎委托响应信息结构体的地址,表明ETF申赎委托请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明ETF申赎委托请求失败
	*/
	virtual void OnRspStockETFEntrustOrder(DFITCStockRspETFEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};

	/**
	* STOCK-ETF篮子股买卖响应
	* @param pData:指针若非空,返回ETF篮子股买卖响应信息结构体的地址,表明ETF篮子股买卖请求成功,pData->localOrderID小于0说明该成分股买卖失败。
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明ETF篮子股买卖请求失败
	* @param bIsLast:返回值表明是否是最后一笔响应信息(0-否,1-是)
	*/
	virtual void OnRspStockETFBasketOrder(DFITCStockRspETFBasketOrderField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast) {};

	/**
	* STOCK-债券回购响应
	* @param pData:指针若非空,返回债券回购响应信息结构体的地址,表明债券回购请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明债券回购请求失败
	*/
	virtual void OnRspStockBondRepurchaseOrder(DFITCStockRspBondRepurchaseOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};


	/**
	* STOCK-债券出入库响应
	* @param pData:指针若非空,返回债券出入库响应信息结构体的地址,表明债券出入库请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明委托报单请求失败
	*/
	virtual void OnRspStockBondInOutStockOrder(DFITCStockRspBondInOutStockOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};

	/**
	* STOCK-发行业务响应
	* @param pData:指针若非空,返回发行业务响应信息结构体的地址,表明发行业务请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明发行业务请求失败
	*/
	virtual void OnRspStockIssueBusinessOrder(DFITCStockRspIssueBusinessOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};


	/**
	* STOCK-LOF基金响应
	* @param pData:指针若非空,返回LOF基金响应信息结构体的地址,表明LOF基金请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明LOF基金请求失败
	*/
	virtual void OnRspStockLOFEntrustOrder(DFITCStockRspLOFEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};

	/**
	* STOCK-盘后定价响应
	* @param pData:指针若非空,返回盘后定价响应信息结构体的地址,表明盘后定价请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明盘后定价请求失败
	*/
	virtual void OnRspStockAfterHoursPriceOrder(DFITCStockRspAfterHoursPriceOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};

	/**
	* STOCK-非交易业务响应
	* @param pData:指针若非空,返回非交易业务响应信息结构体的地址,表明非交易业务请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明非交易业务请求失败
	*/
	virtual void OnRspStockNonTradingBusinessOrder(DFITCStockRspNonTradingBusinessOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};

	/**
	* STOCK-上海基金通响应
	* @param pData:指针若非空,返回上海基金通响应信息结构体的地址,表明上海基金通请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明上海基金通失败
	*/
	virtual void OnRspStockSHMutualFundOrder(DFITCStockRspSHMutualFundOrderField *pData, DFITCSECRspInfoField *pRspInfo) {};

	/**
	* STOCK-计算可买入ETF股票篮子数响应
	* @param pData:指针若非空,返回用户计算可买入ETF股票篮子数响应信息结构体的地址,表明计算可买入ETF股票篮子数请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明计算可买入ETF股票篮子数请求失败
	*/
	virtual void OnRspStockCalcAblePurchaseETFBasketQty(DFITCStockRspCalcAblePurchaseETFBasketQtyField *pData, DFITCSECRspInfoField *pRspInfo) {};
	
	/**
	* STOCK-计算债券回购可委托数量响应
	* @param pData:指针若非空,返回用户计算债券回购可委托数量响应信息结构体的地址,表明计算债券回购可委托数量请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明计算债券回购可委托数量请求失败
	*/
	virtual void OnRspStockCalcAbleBondRepurchaseQty(DFITCStockRspCalcAbleBondRepurchaseQtyField *pData, DFITCSECRspInfoField *pRspInfo) {};

	/**
	* STOCK-计算发行业务可认购数量响应
	* @param pData:指针若非空,返回用户计算发行业务可认购数量响应信息结构体的地址,表明计算发行业务可认购数量请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明计算发行业务可认购数量请求失败
	*/
	virtual void OnRspStockCalcAbleIssueBusinessQty(DFITCStockRspCalcAbleIssueBusinessQtyField *pData, DFITCSECRspInfoField *pRspInfo) {};

	/**
	* STOCK-计算LOF业务可委托数量响应
	* @param pData:指针若非空,返回用户计算LOF业务可委托数量响应信息结构体的地址,表明计算LOF业务可委托数量请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明计算LOF业务可委托数量请求失败
	*/
	virtual void OnRspStockCalcAblePurchaseLOFQty(DFITCStockRspCalcAblePurchaseLOFQtyField *pData, DFITCSECRspInfoField *pRspInfo) {};

	/**
	* STOCK-计算盘后定价可买卖数量响应
	* @param pData:指针若非空,返回用户计算盘后定价可买卖数量应信息结构体的地址,表明计算盘后定价可买卖数量请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明计算盘后定价可买卖数量请求失败
	*/
	virtual void OnRspStockCalcAbleAfterHoursPriceQty(DFITCStockRspCalcAbleAfterHoursPriceQtyField *pData, DFITCSECRspInfoField *pRspInfo) {};

	/**
	* STOCK-计算非交易业务可认购数量响应
	* @param pData:指针若非空,返回用户计算非交易业务可认购数量响应信息结构体的地址,表明计算非交易业务可认购数量请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明计算非交易业务可认购数量请求失败
	*/
	virtual void OnRspStockCalcAbleNonTradingBusinessQty(DFITCStockRspCalcAbleNonTradingBusinessQtyField *pData, DFITCSECRspInfoField *pRspInfo) {};

	/**
	* STOCK-计算上海基金业务可认购数量响应
	* @param pData:指针若非空,返回用户计算上海基金业务可认购数量响应信息结构体的地址,表明计算上海基金业务可认购数量请求成功
	* @param pRspInfo:指针若非空，返回错误信息结构体的地址，表明计算上海基金业务可认购数量请求失败
	*/
	virtual void OnRspStockCalcAbleSHMutualFundQty(DFITCStockRspCalcAbleSHMutualFundQtyField *pData, DFITCSECRspInfoField *pRspInfo) {};



};



class DFITCSEC_TRADER_API DFITCSECTraderApi
{
public:
     /**
      * 创建DFITCSECTraderApi接口对象
      * @ pszLogAddr log所在的路径，如果pszLogAddress为NULL，则不生成log。
      * @ pszPriFlowDir 私有流记录所在的路径，如果pszPriFlowDir为NULL，则默认将私有流记录在当前目录下。
      */
     static DFITCSECTraderApi *CreateDFITCSECTraderApi(const char* pszLogAddr = "", const char* pszPriFlowDir = "");
     /**
      * 释放DFITCSECTraderApi接口对象
      */
     virtual void Release() = 0;
     /**
      * 初始化 
      * @param pszFrontAddress:前置机地址
      *                  网络地址的格式为:"protocol://ipaddress:port",如"tcp://127.0.0.1:10920"
      *                  其中protocol的值必须为tcp。
      *                  ipaddress表示交易前置的IP,port表示交易前置的端口
      * @param pSpi:指向回调函数集的指针
	  * @param pAuthInfo 统一接入认证信息的指针,未启用统一接入认证，则不填
      * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml
      */
	 virtual int Init(const char *pszFrontAddress, DFITCSECTraderSpi *pSpi, DFITCSECAuthenticationField *pAuthInfo=NULL) = 0;
     /**
      * 订阅私有流
      * @param nResumeType: 私有流重传方式
      *         TERT_RESTART:从本交易日开始重传
      *         TERT_RESUME:从上次收到的续传
      *         TERT_QUICK:只传送登录后私有流的内容
      * @remark 该方法要在UserLogin方法前调用。若不调用则不会收到私有流的数据。
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int SubscribePrivateTopic(RESUME_TYPE nResumeType) = 0; 
     /**
      * STOCK-登录请求
      * @param p:指向用户登录请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockUserLogin(DFITCSECReqUserLoginField *p) = 0;    
     /**
      * STOCK-登出请求
      * @param p:指向用户登出请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockUserLogout(DFITCSECReqUserLogoutField *p) = 0;
     /**
      * STOCK-密码更新请求
      * @param p:指向用户密码更新请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockUserPasswordUpdate(DFITCSECReqPasswordUpdateField *p) = 0;
     /**
      * STOCK-委托请求
      * @param p:指向用户委托请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockEntrustOrder(DFITCStockReqEntrustOrderField *p) = 0;
     /**
      * STOCK-撤单请求
      * @param p:指向用户撤单请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockWithdrawOrder(DFITCSECReqWithdrawOrderField *p) = 0;
     /**
      * STOCK-委托查询请求
      * @param p:指向用户委托查询请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockQryEntrustOrder(DFITCStockReqQryEntrustOrderField *p) = 0;
     /**
      * STOCK-实时成交查询请求
      * @param p:指向用户实时成交查询请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockQryRealTimeTrade(DFITCStockReqQryRealTimeTradeField *p) = 0;
     /**
      * STOCK-分笔成交查询请求
      * @param p:指向用户分笔成交查询请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockQrySerialTrade(DFITCStockReqQrySerialTradeField *p) = 0;
     /**
      * STOCK-持仓查询请求
      * @param p:指向用户持仓查询请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockQryPosition(DFITCStockReqQryPositionField *p) = 0;
     /**
      * STOCK-资金账户查询请求
      * @param p:指向用户资金账户查询请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockQryCapitalAccountInfo(DFITCStockReqQryCapitalAccountField *p) = 0;
     /**
      * STOCK-账户查询请求
      * @param p:指向用户账户查询请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockQryAccountInfo(DFITCStockReqQryAccountField *p) = 0;
     /**
      * STOCK-股东查询请求
      * @param p:指向用户股东查询请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockQryShareholderInfo(DFITCStockReqQryShareholderField *p) = 0;
     /**
      * STOCK-调拨资金请求
      * @param p:指向用户调拨资金请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockTransferFunds(DFITCStockReqTransferFundsField *p) = 0;
     /**
      * STOCK-批量委托请求
      * @param p:指向用户批量委托请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockEntrustBatchOrder(DFITCStockReqEntrustBatchOrderField *p) = 0;
     /**
      * STOCK-批量撤单请求
      * @param p:指向用户批量撤单请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockWithdrawBatchOrder(DFITCStockReqWithdrawBatchOrderField *p) = 0;
     /**
      * STOCK-计算可委托数量请求
      * @param p:指向用户计算可委托数量请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockCalcAbleEntrustQty(DFITCStockReqCalcAbleEntrustQtyField *p) = 0;
     /**
      * STOCK-计算可认申赎ETF数量请求
      * @param p:指向用户计算可认申赎ETF篮子数请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockCalcAblePurchaseETFQty(DFITCStockReqCalcAblePurchaseETFQtyField *p) = 0;
     /**
      * STOCK-冻结资金明细查询请求
      * @param p:指向用户冻结资金明细查询请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockQryFreezeFundsDetail(DFITCStockReqQryFreezeFundsDetailField *p) = 0;
     /**
      * STOCK-冻结证券明细查询
      * @param p:指向用户冻结证券明细查询结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockQryFreezeStockDetail(DFITCStockReqQryFreezeStockDetailField *p) = 0;
     /**
      * STOCK-调拨资金明细查询请求
      * @param p:指向用户调拨资金明细查询请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockQryTransferFundsDetail(DFITCStockReqQryTransferFundsDetailField *p) = 0;
     /**
      * STOCK-调拨证券明细查询请求
      * @param p:指向用户调拨证券明细查询请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockQryTransferStockDetail(DFITCStockReqQryTransferStockDetailField *p) = 0; 
     /**
      * STOCK-股票查询请求
      * @param p:指向用户股票查询请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockQryStockInfo(DFITCStockReqQryStockField *p) = 0;
     /**
      * STOCK-股票静态信息查询请求
      * @param p:指向用户股票静态信息查询请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockQryStockStaticInfo(DFITCStockReqQryStockStaticField *p) = 0;
     /**
      * STOCK-交易时间查询请求
      * @param p:指向用户交易时间查询请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqStockQryTradeTime(DFITCStockReqQryTradeTimeField *p) = 0;
     /**
      * SOP-登录请求
      * @param p:指向用户登录请求结构的地址
      * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml
      */
     virtual int ReqSOPUserLogin(DFITCSECReqUserLoginField *p) = 0;
     /**
      * SOP-登出请求
      * @param p:指向用户登出请求结构的地址
      * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml
      */
     virtual int ReqSOPUserLogout(DFITCSECReqUserLogoutField *p) = 0;
     /**
      * SOP-交易密码更新请求
      * @param p:指向用户密码更新请求结构的地址
      * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml
      */
     virtual int ReqSOPUserPasswordUpdate(DFITCSECReqPasswordUpdateField *p) = 0;
    /**
     * SOP-报单请求
     * @param p:指向用户报单请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml
     */
    virtual int ReqSOPEntrustOrder(DFITCSOPReqEntrustOrderField *p) = 0;
    /**
     * SOP-做市商报单请求
     * @param p:指向用户做市商报单请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml
     */
    virtual int ReqSOPQuoteEntrustOrder(DFITCSOPReqQuoteEntrustOrderField *p) = 0;
    /**
     * SOP-持仓组合拆分委托请求
     * @param p:指向用户交易所持仓组合拆分委托请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml
     */
    virtual int ReqSOPGroupSplit(DFITCSOPReqGroupSplitField *p) = 0;
    /**
     * SOP-期权组合行权委托请求
     * @param p:指向用户期权组合行权委托请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
	virtual int ReqSOPGroupExectueOrder(DFITCSOPReqGroupExectueOrderField *p) = 0;
    /**
     * SOP-查询客户组合持仓明细请求
     * @param p:指向用户查询客户组合持仓明细请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml
     */
    virtual int ReqSOPQryGroupPosition(DFITCSOPReqQryGroupPositionField *p) = 0;
    /**
     * SOP-证券锁定解锁请求
     * @param p:指向用户证券锁定解锁请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqSOPLockOUnLockStock(DFITCSOPReqLockOUnLockStockField *p) = 0;
    /**
     * SOP-撤单请求
     * @param p:指向用户撤单请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqSOPWithdrawOrder(DFITCSECReqWithdrawOrderField *p) = 0;
    /**
     * SOP-当日委托查询请求
     * @param p:指向用户当日委托查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqSOPQryEntrustOrder(DFITCSOPReqQryEntrustOrderField *p) = 0;
    /**
     * SOP-分笔成交查询请求
     * @param p:指向用户分笔成交查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqSOPQrySerialTrade(DFITCSOPReqQrySerialTradeField *p) = 0;
    /**
     * SOP-持仓查询请求
     * @param p:指向用户持仓查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqSOPQryPosition(DFITCSOPReqQryPositionField *p) = 0;
    /**
     * SOP-担保物持仓查询请求
     * @param p:指向用户担保物持仓查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqSOPQryCollateralPosition(DFITCSOPReqQryCollateralPositionField *p) = 0;
    /**
     * SOP-资金信息查询请求
     * @param p:指向用户资金信息查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqSOPQryCapitalAccountInfo(DFITCSOPReqQryCapitalAccountField *p) = 0;
    /**
     * SOP-客户信息查询请求
     * @param p:指向用户客户信息查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqSOPQryAccountInfo(DFITCSOPReqQryAccountField *p) = 0;
    /**
     * SOP-股东信息查询请求
     * @param p:指向用户股东信息查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqSOPQryShareholderInfo(DFITCSOPReqQryShareholderField *p) = 0;
    /**
     * SOP-可委托数量计算请求
     * @param p:指向用户可委托数量计算请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqSOPCalcAbleEntrustQty(DFITCSOPReqCalcAbleEntrustQtyField *p) = 0;
    /**
     * SOP-可锁定证券数量查询请求
     * @param p:指向用户可锁定证券数量查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqSOPQryAbleLockStock(DFITCSOPReqQryAbleLockStockField *p) = 0;
    /**
     * SOP-期权合约代码查询请求
     * @param p:指向用户期权合约代码查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqSOPQryContactInfo(DFITCSOPReqQryContactField *p) = 0;
    /**
     * SOP-行权委托请求
     * @param p:指向用户行权委托请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
	virtual int ReqSOPExectueOrder(DFITCSOPReqExectueOrderField *p) = 0;
    /**
     * SOP-行权指派信息查询请求
     * @param p:指向用户行权指派信息查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqSOPQryExecAssiInfo(DFITCSOPReqQryExecAssiInfoField *p) = 0;
    /**
     * SOP-交易时间查询请求
     * @param p:指向用户交易时间查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqSOPQryTradeTime(DFITCSOPReqQryTradeTimeField *p) = 0;
    /**
     * SOP-交易所信息查询请求
     * @param p:指向用户交易所信息查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqSOPQryExchangeInfo(DFITCSOPReqQryExchangeInfoField *p) = 0;
    /**
     * SOP-手续费查询请求
     * @param p:指向用户手续费查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqSOPQryCommission(DFITCSOPReqQryCommissionField *p) = 0;
    /**
     * SOP-保证金查询请求
     * @param p:指向用户保证金查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqSOPQryDeposit(DFITCSOPReqQryDepositField *p) = 0;
    /**
     * SOP-标的信息查询请求
     * @param p:指向用户标的信息查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqSOPQryContractObjectInfo(DFITCSOPReqQryContractObjectField *p) = 0;

	/**
	* SOP-资金调入调出请求
	* @param p:指向用户资金调入调出请求结构的地址
	* @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml
	*/
	virtual int ReqSOPCapitalTranInOut(DFITCSOPReqCapitalTranInOutField *p) = 0;

	/**
	* SOP-资金多节点分配比例查询请求
	* @param p:指向用户资金多节点分配比例请求结构的地址
	* @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml
	*/
	virtual int ReqSOPCapitalDistributionRatio(DFITCSOPReqQryCapitalDistributionRatioField *p) = 0;

	/**
	* SOP-节点间资金调拨请求
	* @param p:指向用户节点间资金调拨请求结构的地址
	* @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml
	*/
	virtual int ReqSOPFundTransBetweenNodes(DFITCSOPReqFundTransBetweenNodesField *p) = 0;

	/**
	* SOP-修改资金多节点分配比例请求
	* @param p:指向用户设置资金多节点分配比例请求结构的地址
	* @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml
	*/
	virtual int ReqSOPModCapitalDistributionRatio(DFITCSOPReqModCapitalDistributionRatioField *p) = 0;

    /**
     * FASL-登录请求
     * @param p:指向用户登录请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqFASLUserLogin(DFITCSECReqUserLoginField *p) = 0;
    /**
     * FASL-登出请求
     * @param p:指向用户登出请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqFASLUserLogout(DFITCSECReqUserLogoutField *p) = 0;
    /**
     * FASL-客户可融资信息请求
     * @param p:指向用户客户可融资信息请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqFASLQryAbleFinInfo(DFITCFASLReqAbleFinInfoField *p) = 0;
    /**
     * FASL-客户可融券信息请求
     * @param p:指向用户客户可融券信息请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqFASLQryAbleSloInfo(DFITCFASLReqAbleSloInfoField *p) = 0;
    /**
     * FASL-担保物划转请求
     * @param p:指向用户担保物划转请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqFASLTransferCollateral(DFITCFASLReqTransferCollateralField *p) = 0;
    /**
     * FASL-直接还款请求
     * @param p:指向用户直接还款请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqFASLDirectRepayment(DFITCFASLReqDirectRepaymentField *p) = 0;
    /**
     * FASL-还券划转请求
     * @param p:指向用户还券划转请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqFASLRepayStockTransfer(DFITCFASLReqRepayStockTransferField *p) = 0;
    /**
     * FASL-信用交易请求
     * @param p:指向用户信用交易请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqFASLEntrustCrdtOrder(DFITCFASLReqEntrustCrdtOrderField *p) = 0;
    /**
     * FASL-融资融券交易请求
     * @param p:指向用户融资融券交易请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
	virtual int ReqFASLEntrustOrder(DFITCFASLReqEntrustOrderField *p) = 0;
    /**
     * FASL-撤单请求
     * @param p:指向用户撤单请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqFASLWithdrawOrder(DFITCFASLReqWithdrawOrderField *p) = 0;
    /**
     * FASL-信用可委托数量查询请求
     * @param p:指向用户信用可委托数量查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqFASLCalcAbleEntrustCrdtQty(DFITCFASLReqCalcAbleEntrustCrdtQtyField *p) = 0;
    /**
     * FASL-查询信用资金请求
     * @param p:指向用户查询信用资金请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqFASLQryCrdtFunds(DFITCFASLReqQryCrdtFundsField *p) = 0;
    /**
     * FASL-信用合约信息请求
     * @param p:指向用户信用合约信息请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqFASLQryCrdtContract(DFITCFASLReqQryCrdtContractField *p) = 0;
    /**
     * FASL-信用合约变动信息查询请求
     * @param p:指向用户信用合约变动信息查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqFASLQryCrdtConChangeInfo(DFITCFASLReqQryCrdtConChangeInfoField *p) = 0;
    /**
     * FASL-资金调转请求
     * @param p:指向用户资金调转请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
	virtual int ReqFASLTransferFunds(DFITCFASLReqTransferFundsField *p) = 0;
	/**
	 * FASL-证券调转请求
	 * @param p:指向用户证券调转请求结构的地址
	 * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml
	 */
	virtual int ReqFASLTransferStock(DFITCFASLReqTransferStockField *p) = 0;
    /**
     * FASL-客户信息查询请求
     * @param p:指向用户客户信息查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
	virtual int ReqFASLQryAccountInfo(DFITCFASLReqQryAccountField *p) = 0;
    /**
     * FASL-客户资金查询请求
     * @param p:指向用户客户资金查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
    virtual int ReqFASLQryCapitalAccountInfo(DFITCFASLReqQryCapitalAccountField *p) = 0;
    /**
     * FASL-股东信息查询请求
     * @param p:指向用户股东信息查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
	virtual int ReqFASLQryShareholderInfo(DFITCFASLReqQryShareholderField *p) = 0;
    /**
     * FASL-持仓查询请求
     * @param p:指向用户持仓查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
	virtual int ReqFASLQryPosition(DFITCFASLReqQryPositionField *p) = 0;
    /**
     * FASL-委托查询请求
     * @param p:指向用户委托查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
	virtual int ReqFASLQryEntrustOrder(DFITCFASLReqQryEntrustOrderField *p) = 0;
    /**
     * FASL-分笔成交查询请求
     * @param p:指向用户分笔成交查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
	virtual int ReqFASLQrySerialTrade(DFITCFASLReqQrySerialTradeField *p) = 0;
    /**
     * FASL-实时成交查询请求
     * @param p:指向用户实时成交查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
	virtual int ReqFASLQryRealTimeTrade(DFITCFASLReqQryRealTimeTradeField *p) = 0;
    /**
     * FASL-资金冻结明细查询请求
     * @param p:指向用户资金冻结明细查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
	virtual int ReqFASLQryFreezeFundsDetail(DFITCFASLReqQryFreezeFundsDetailField *p) = 0;
    /**
     * FASL-证券冻结明细查询请求
     * @param p:指向用户证券冻结明细查询请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
	virtual int ReqFASLQryFreezeStockDetail(DFITCFASLReqQryFreezeStockDetailField *p) = 0;
    /**
     * FASL-查询资金调拨明细请求
     * @param p:指向用户查询资金调拨明细请求结构的地址
     * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml  
     */
	virtual int ReqFASLQryTransferFundsDetail(DFITCFASLReqQryTransferFundsDetailField *p) = 0;
    /**
      * FASL-当前系统时间查询请求
      * @param p:指向用户交易时间查询请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqFASLQrySystemTime(DFITCFASLReqQryTradeTimeField *p) = 0;
    /**
      * FASL-可转入担保证券查询请求
      * @param p:指向可转入担保证券查询请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqFASLQryTransferredContract(DFITCFASLReqQryTransferredContractField *p) = 0;
    /**
      * FASL-客户可取资金调出请求
      * @param p:指向客户可取资金调出请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqFASLDesirableFundsOut(DFITCFASLReqDesirableFundsOutField *p) = 0;
    /**
      * FASL-担保证券查询请求
      * @param p:指向担保证券查询请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqFASLQryGuaranteedContract(DFITCFASLReqQryGuaranteedContractField *p) = 0;
    /**
      * FASL-标的证券查询请求
      * @param p:指向标的证券查询请求结构体的地址
      * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
      */
     virtual int ReqFASLQryUnderlyingContract(DFITCFASLReqQryUnderlyingContractField *p) = 0;

	 /**
	 * FASL-集中交易资金查询请求
	 * @param p:指向用户集中交易资金查询请求结构的地址
	 * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml
	 */
	 virtual int ReqFASLQryCentreFundAvlInfo(DFITCFASLReqQryCentreFundAvlField *p) = 0;

	 /**
	 * FASL-客户配售权益查询请求
	 * @param p:指向用户客户配售权益查询请求结构的地址
	 * @return 0表示请求发送成功，其他值表示请求发送失败，具体错误请对照error.xml
	 */
	 virtual int ReqFASLQryPlacingInterestsInfo(DFITCFASLReqQryPlacingInterestsField *p) = 0;

	 /**
	 * FASL-密码更新请求
	 * @param p:指向用户密码更新请求结构体的地址
	 * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
	 */
	 virtual int ReqFASLUserPasswordUpdate(DFITCSECReqPasswordUpdateField *p) = 0;

    /**
      * SOP-设置终端信息
      * @param p:指设置终端信息结构体的地址
      * @return : 0 表示设置成功，非0表示设置失败，具体错误请参考error.xml
      */
     virtual int SetTerminalInfo(DFITCTerminalInfoField* p) = 0;


	 //STOCK新增业务的请求接口 begin
	 /**
	 * STOCK-ETF申赎请求
	 * @param p:指向ETF申赎请求结构体的地址
	 * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
	 */
	 virtual int ReqStockETFEntrustOrder(DFITCStockReqETFEntrustOrderField *p) = 0;

	 /**
	 * STOCK-ETF篮子股买卖请求
	 * @param p:指向ETF篮子股买卖请求结构体的地址
	 * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
	 */
	 virtual int ReqStockETFBasketOrder(DFITCStockReqETFBasketOrderField *p) = 0;

	 /**
	 * STOCK-债券回购请求
	 * @param p:指向债券回购请求结构体的地址
	 * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
	 */
	 virtual int ReqStockBondRepurchaseOrder(DFITCStockReqBondRepurchaseOrderField *p) = 0;


	 /**
	 * STOCK-债券出入库请求
	 * @param p:指向债券出入库请求结构体的地址
	 * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
	 */
	 virtual int ReqStockBondInOutStockOrder(DFITCStockReqBondInOutStockOrderField *p) = 0;

	 /**
	 * STOCK-发行业务请求
	 *DFITCSEC_ED_RightsIssueContribution配股配债缴款
	 *DFITCSEC_ED_PlacingPurchase配售申购|债券配发
	 *DFITCSEC_ED_Buy首发增发买入
	 *DFITCSEC_ED_PlacingAbandon配售债券放弃
	 * @param p:指向发行业务请求结构体的地址
	 * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
	 */
	 virtual int ReqStockIssueBusinessOrder(DFITCStockReqIssueBusinessOrderField *p) = 0;


	 /**
	 * STOCK-LOF基金委托请求
	 * @param p:指向LOF基金请求结构体的地址
	 * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
	 */
	 virtual int ReqStockLOFEntrustOrder(DFITCStockReqLOFEntrustOrderField *p) = 0;


	 /**
	 * STOCK-盘后定价请求
	 * @param p:指向盘后定价请求结构体的地址
	 * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
	 */
	 virtual int ReqStockAfterHoursPriceOrder(DFITCStockReqAfterHoursPriceOrderField *p) = 0;

	 /**
	 * STOCK-非交易业务请求
	 * @param p:指向非交易业务请求结构体的地址
	 * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
	 */
	 virtual int ReqStockNonTradingBusinessOrder(DFITCStockReqNonTradingBusinessOrderField *p) = 0;

	 /**
	 * STOCK-上海基金通请求
	 * @param p:指向上海基金通请求结构体的地址
	 * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
	 */
	 virtual int ReqStockSHMutualFundOrder(DFITCStockReqSHMutualFundOrderField *p) = 0;

	 /**
	 * STOCK-计算可买入ETF股票篮子数请求
	 * @param p:指向计算可买入ETF股票篮子数结构体的地址
	 * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
	 */
	 virtual int ReqStockCalcAblePurchaseETFBasketQty(DFITCStockReqCalcAblePurchaseETFBasketQtyField *p) = 0;

	 /**
	 * STOCK-计算债券回购可委托数量请求
	 * @param p:指向计算债券回购可委托数量结构体的地址
	 * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
	 */
	 virtual int ReqStockCalcAbleBondRepurchaseQty(DFITCStockReqCalcAbleBondRepurchaseQtyField *p) = 0;

	 /**
	 * STOCK-计算发行业务可认购数量请求
	 * @param p:指向计算发行业务可认购数量结构体的地址
	 * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
	 */
	 virtual int ReqStockCalcAbleIssueBusinessQty(DFITCStockReqCalcAbleIssueBusinessQtyField *p) = 0;

	 /**
	 * STOCK-计算LOF业务可委托数量请求
	 * @param p:指向计算LOF业务可委托数量结构体的地址
	 * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
	 */
	 virtual int ReqStockCalcAblePurchaseLOFQty(DFITCStockReqCalcAblePurchaseLOFQtyField *p) = 0;

	 /**
	 * STOCK-计算盘后定价可买卖数量请求
	 * @param p:指向计算盘后定价可买卖数量结构体的地址
	 * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
	 */
	 virtual int ReqStockCalcAbleAfterHoursPriceQty(DFITCStockReqCalcAbleAfterHoursPriceQtyField *p) = 0;

	 /**
	 * STOCK-计算非交易业务可认购数量请求
	 * @param p:指向计算非交易业务可认购数量结构体的地址
	 * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
	 */
	 virtual int ReqStockCalcAbleNonTradingBusinessQty(DFITCStockReqCalcAbleNonTradingBusinessQtyField *p) = 0;

	 /**
	 * STOCK-计算上海基金业务可认购数量请求
	 * @param p:指向计算上海基金业务可认购数量结构体的地址
	 * @return : 0 表示请求发送成功，非 0 表示请求发送失败，具体错误请参考error.xml
	 */
	 virtual int ReqStockCalcAbleSHMutualFundQty(DFITCStockReqCalcAbleSHMutualFundQtyField *p) = 0;


	 //STOCK新增业务的请求接口 end

	 /**
	 * 设置扩展信息
	 * @param extendInfo[]:指针数组，每个指针指向一个扩展信息
	 * @param nCount:扩展信息个数
	 * @remark extendInfo[]数组元素1：操作站点char[257]。设置该信息要在UserLogin方法前调用。若不调用则不会设置该数据。
	 * @remark extendInfo[]数组元素2：预留。
	 * ...
	 * @remark extendInfo[]数组元素N：预留。
	 * @return : 0 表示设置成功，非0表示设置失败，具体错误请参考error.xml
	 */
	 virtual int setExtendInfo(char * extendInfo[], int nCount) = 0;

public:
    DFITCSECTraderApi();
    virtual ~DFITCSECTraderApi();
};

#endif

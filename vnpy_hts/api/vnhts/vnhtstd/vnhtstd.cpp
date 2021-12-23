// vnhtstd.cpp : 定义 DLL 应用程序的导出函数。
//


#include "vnhtstd.h"

///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------
void TdApi::OnFrontConnected()
{
	Task task = Task();
	task.task_name = ONFRONTCONNECTED;
	this->task_queue.push(task);
};

void TdApi::OnFrontDisconnected(int nReason)
{
	Task task = Task();
	task.task_name = ONFRONTDISCONNECTED;
	task.task_id = nReason;
	this->task_queue.push(task);
};

void TdApi::OnRtnNotice(DFITCSECRspNoticeField *pNotice)
{
	Task task = Task();
	task.task_name = ONRTNNOTICE;
	if (pNotice)
	{
		DFITCSECRspNoticeField *task_data = new DFITCSECRspNoticeField();
		*task_data = *pNotice;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspError(DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPERROR;
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockUserLogin(DFITCSECRspUserLoginField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKUSERLOGIN;
	if (pData)
	{
		DFITCSECRspUserLoginField *task_data = new DFITCSECRspUserLoginField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockUserLogout(DFITCSECRspUserLogoutField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKUSERLOGOUT;
	if (pData)
	{
		DFITCSECRspUserLogoutField *task_data = new DFITCSECRspUserLogoutField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockUserPasswordUpdate(DFITCSECRspPasswordUpdateField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKUSERPASSWORDUPDATE;
	if (pData)
	{
		DFITCSECRspPasswordUpdateField *task_data = new DFITCSECRspPasswordUpdateField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockEntrustOrder(DFITCStockRspEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKENTRUSTORDER;
	if (pData)
	{
		DFITCStockRspEntrustOrderField *task_data = new DFITCStockRspEntrustOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockWithdrawOrder(DFITCSECRspWithdrawOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKWITHDRAWORDER;
	if (pData)
	{
		DFITCSECRspWithdrawOrderField *task_data = new DFITCSECRspWithdrawOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockQryEntrustOrder(DFITCStockRspQryEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKQRYENTRUSTORDER;
	if (pData)
	{
		DFITCStockRspQryEntrustOrderField *task_data = new DFITCStockRspQryEntrustOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspStockQryRealTimeTrade(DFITCStockRspQryRealTimeTradeField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKQRYREALTIMETRADE;
	if (pData)
	{
		DFITCStockRspQryRealTimeTradeField *task_data = new DFITCStockRspQryRealTimeTradeField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspStockQrySerialTrade(DFITCStockRspQrySerialTradeField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKQRYSERIALTRADE;
	if (pData)
	{
		DFITCStockRspQrySerialTradeField *task_data = new DFITCStockRspQrySerialTradeField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspStockQryPosition(DFITCStockRspQryPositionField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKQRYPOSITION;
	if (pData)
	{
		DFITCStockRspQryPositionField *task_data = new DFITCStockRspQryPositionField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspStockQryCapitalAccountInfo(DFITCStockRspQryCapitalAccountField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKQRYCAPITALACCOUNTINFO;
	if (pData)
	{
		DFITCStockRspQryCapitalAccountField *task_data = new DFITCStockRspQryCapitalAccountField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspStockQryAccountInfo(DFITCStockRspQryAccountField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKQRYACCOUNTINFO;
	if (pData)
	{
		DFITCStockRspQryAccountField *task_data = new DFITCStockRspQryAccountField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockQryShareholderInfo(DFITCStockRspQryShareholderField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKQRYSHAREHOLDERINFO;
	if (pData)
	{
		DFITCStockRspQryShareholderField *task_data = new DFITCStockRspQryShareholderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspStockTransferFunds(DFITCStockRspTransferFundsField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKTRANSFERFUNDS;
	if (pData)
	{
		DFITCStockRspTransferFundsField *task_data = new DFITCStockRspTransferFundsField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockEntrustBatchOrder(DFITCStockRspEntrustBatchOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKENTRUSTBATCHORDER;
	if (pData)
	{
		DFITCStockRspEntrustBatchOrderField *task_data = new DFITCStockRspEntrustBatchOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockWithdrawBatchOrder(DFITCStockRspWithdrawBatchOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKWITHDRAWBATCHORDER;
	if (pData)
	{
		DFITCStockRspWithdrawBatchOrderField *task_data = new DFITCStockRspWithdrawBatchOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockCalcAbleEntrustQty(DFITCStockRspCalcAbleEntrustQtyField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKCALCABLEENTRUSTQTY;
	if (pData)
	{
		DFITCStockRspCalcAbleEntrustQtyField *task_data = new DFITCStockRspCalcAbleEntrustQtyField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockCalcAblePurchaseETFQty(DFITCStockRspCalcAblePurchaseETFQtyField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKCALCABLEPURCHASEETFQTY;
	if (pData)
	{
		DFITCStockRspCalcAblePurchaseETFQtyField *task_data = new DFITCStockRspCalcAblePurchaseETFQtyField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockQryFreezeFundsDetail(DFITCStockRspQryFreezeFundsDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKQRYFREEZEFUNDSDETAIL;
	if (pData)
	{
		DFITCStockRspQryFreezeFundsDetailField *task_data = new DFITCStockRspQryFreezeFundsDetailField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspStockQryFreezeStockDetail(DFITCStockRspQryFreezeStockDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKQRYFREEZESTOCKDETAIL;
	if (pData)
	{
		DFITCStockRspQryFreezeStockDetailField *task_data = new DFITCStockRspQryFreezeStockDetailField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspStockQryTransferStockDetail(DFITCStockRspQryTransferStockDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKQRYTRANSFERSTOCKDETAIL;
	if (pData)
	{
		DFITCStockRspQryTransferStockDetailField *task_data = new DFITCStockRspQryTransferStockDetailField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspStockQryTransferFundsDetail(DFITCStockRspQryTransferFundsDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKQRYTRANSFERFUNDSDETAIL;
	if (pData)
	{
		DFITCStockRspQryTransferFundsDetailField *task_data = new DFITCStockRspQryTransferFundsDetailField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspStockQryStockInfo(DFITCStockRspQryStockField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKQRYSTOCKINFO;
	if (pData)
	{
		DFITCStockRspQryStockField *task_data = new DFITCStockRspQryStockField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspStockQryStockStaticInfo(DFITCStockRspQryStockStaticField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKQRYSTOCKSTATICINFO;
	if (pData)
	{
		DFITCStockRspQryStockStaticField *task_data = new DFITCStockRspQryStockStaticField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspStockQryTradeTime(DFITCStockRspQryTradeTimeField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKQRYTRADETIME;
	if (pData)
	{
		DFITCStockRspQryTradeTimeField *task_data = new DFITCStockRspQryTradeTimeField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnStockEntrustOrderRtn(DFITCStockEntrustOrderRtnField * pData)
{
	Task task = Task();
	task.task_name = ONSTOCKENTRUSTORDERRTN;
	if (pData)
	{
		DFITCStockEntrustOrderRtnField *task_data = new DFITCStockEntrustOrderRtnField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnStockTradeRtn(DFITCStockTradeRtnField * pData)
{
	Task task = Task();
	task.task_name = ONSTOCKTRADERTN;
	if (pData)
	{
		DFITCStockTradeRtnField *task_data = new DFITCStockTradeRtnField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnStockWithdrawOrderRtn(DFITCStockWithdrawOrderRtnField * pData)
{
	Task task = Task();
	task.task_name = ONSTOCKWITHDRAWORDERRTN;
	if (pData)
	{
		DFITCStockWithdrawOrderRtnField *task_data = new DFITCStockWithdrawOrderRtnField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSOPUserLogin(DFITCSECRspUserLoginField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSOPUSERLOGIN;
	if (pData)
	{
		DFITCSECRspUserLoginField *task_data = new DFITCSECRspUserLoginField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSOPUserLogout(DFITCSECRspUserLogoutField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSOPUSERLOGOUT;
	if (pData)
	{
		DFITCSECRspUserLogoutField *task_data = new DFITCSECRspUserLogoutField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSOPUserPasswordUpdate(DFITCSECRspPasswordUpdateField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSOPUSERPASSWORDUPDATE;
	if (pData)
	{
		DFITCSECRspPasswordUpdateField *task_data = new DFITCSECRspPasswordUpdateField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSOPEntrustOrder(DFITCSOPRspEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSOPENTRUSTORDER;
	if (pData)
	{
		DFITCSOPRspEntrustOrderField *task_data = new DFITCSOPRspEntrustOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSOPQuoteEntrustOrder(DFITCSOPRspQuoteEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSOPQUOTEENTRUSTORDER;
	if (pData)
	{
		DFITCSOPRspQuoteEntrustOrderField *task_data = new DFITCSOPRspQuoteEntrustOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSOPGroupSplit(DFITCSOPRspEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSOPGROUPSPLIT;
	if (pData)
	{
		DFITCSOPRspEntrustOrderField *task_data = new DFITCSOPRspEntrustOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSOPGroupExectueOrder(DFITCSOPRspGroupExectueOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSOPGROUPEXECTUEORDER;
	if (pData)
	{
		DFITCSOPRspGroupExectueOrderField *task_data = new DFITCSOPRspGroupExectueOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSOPQryGroupPosition(DFITCSOPRspQryGroupPositionField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSOPQRYGROUPPOSITION;
	if (pData)
	{
		DFITCSOPRspQryGroupPositionField *task_data = new DFITCSOPRspQryGroupPositionField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspSOPLockOUnLockStock(DFITCSOPRspLockOUnLockStockField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSOPLOCKOUNLOCKSTOCK;
	if (pData)
	{
		DFITCSOPRspLockOUnLockStockField *task_data = new DFITCSOPRspLockOUnLockStockField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspSOPWithdrawOrder(DFITCSECRspWithdrawOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSOPWITHDRAWORDER;
	if (pData)
	{
		DFITCSECRspWithdrawOrderField *task_data = new DFITCSECRspWithdrawOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSOPQryEntrustOrder(DFITCSOPRspQryEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSOPQRYENTRUSTORDER;
	if (pData)
	{
		DFITCSOPRspQryEntrustOrderField *task_data = new DFITCSOPRspQryEntrustOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspSOPQrySerialTrade(DFITCSOPRspQrySerialTradeField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSOPQRYSERIALTRADE;
	if (pData)
	{
		DFITCSOPRspQrySerialTradeField *task_data = new DFITCSOPRspQrySerialTradeField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspSOPQryPosition(DFITCSOPRspQryPositionField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSOPQRYPOSITION;
	if (pData)
	{
		DFITCSOPRspQryPositionField *task_data = new DFITCSOPRspQryPositionField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspSOPQryCollateralPosition(DFITCSOPRspQryCollateralPositionField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSOPQRYCOLLATERALPOSITION;
	if (pData)
	{
		DFITCSOPRspQryCollateralPositionField *task_data = new DFITCSOPRspQryCollateralPositionField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspSOPQryCapitalAccountInfo(DFITCSOPRspQryCapitalAccountField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSOPQRYCAPITALACCOUNTINFO;
	if (pData)
	{
		DFITCSOPRspQryCapitalAccountField *task_data = new DFITCSOPRspQryCapitalAccountField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSOPQryAccountInfo(DFITCSOPRspQryAccountField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSOPQRYACCOUNTINFO;
	if (pData)
	{
		DFITCSOPRspQryAccountField *task_data = new DFITCSOPRspQryAccountField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSOPQryShareholderInfo(DFITCSOPRspQryShareholderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSOPQRYSHAREHOLDERINFO;
	if (pData)
	{
		DFITCSOPRspQryShareholderField *task_data = new DFITCSOPRspQryShareholderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSOPCalcAbleEntrustQty(DFITCSOPRspCalcAbleEntrustQtyField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSOPCALCABLEENTRUSTQTY;
	if (pData)
	{
		DFITCSOPRspCalcAbleEntrustQtyField *task_data = new DFITCSOPRspCalcAbleEntrustQtyField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSOPQryAbleLockStock(DFITCSOPRspQryAbleLockStockField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSOPQRYABLELOCKSTOCK;
	if (pData)
	{
		DFITCSOPRspQryAbleLockStockField *task_data = new DFITCSOPRspQryAbleLockStockField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspSOPQryContactInfo(DFITCSOPRspQryContactField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSOPQRYCONTACTINFO;
	if (pData)
	{
		DFITCSOPRspQryContactField *task_data = new DFITCSOPRspQryContactField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspSOPExectueOrder(DFITCSOPRspExectueOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSOPEXECTUEORDER;
	if (pData)
	{
		DFITCSOPRspExectueOrderField *task_data = new DFITCSOPRspExectueOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSOPQryExecAssiInfo(DFITCSOPRspQryExecAssiInfoField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSOPQRYEXECASSIINFO;
	if (pData)
	{
		DFITCSOPRspQryExecAssiInfoField *task_data = new DFITCSOPRspQryExecAssiInfoField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspSOPQryTradeTime(DFITCSOPRspQryTradeTimeField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSOPQRYTRADETIME;
	if (pData)
	{
		DFITCSOPRspQryTradeTimeField *task_data = new DFITCSOPRspQryTradeTimeField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspSOPQryExchangeInfo(DFITCSOPRspQryExchangeInfoField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSOPQRYEXCHANGEINFO;
	if (pData)
	{
		DFITCSOPRspQryExchangeInfoField *task_data = new DFITCSOPRspQryExchangeInfoField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspSOPQryCommission(DFITCSOPRspQryCommissionField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSOPQRYCOMMISSION;
	if (pData)
	{
		DFITCSOPRspQryCommissionField *task_data = new DFITCSOPRspQryCommissionField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspSOPQryDeposit(DFITCSOPRspQryDepositField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSOPQRYDEPOSIT;
	if (pData)
	{
		DFITCSOPRspQryDepositField *task_data = new DFITCSOPRspQryDepositField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspSOPQryContractObjectInfo(DFITCSOPRspQryContractObjectField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSOPQRYCONTRACTOBJECTINFO;
	if (pData)
	{
		DFITCSOPRspQryContractObjectField *task_data = new DFITCSOPRspQryContractObjectField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnSOPEntrustOrderRtn(DFITCSOPEntrustOrderRtnField * pData)
{
	Task task = Task();
	task.task_name = ONSOPENTRUSTORDERRTN;
	if (pData)
	{
		DFITCSOPEntrustOrderRtnField *task_data = new DFITCSOPEntrustOrderRtnField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnSOPTradeRtn(DFITCSOPTradeRtnField * pData)
{
	Task task = Task();
	task.task_name = ONSOPTRADERTN;
	if (pData)
	{
		DFITCSOPTradeRtnField *task_data = new DFITCSOPTradeRtnField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnSOPWithdrawOrderRtn(DFITCSOPWithdrawOrderRtnField * pData)
{
	Task task = Task();
	task.task_name = ONSOPWITHDRAWORDERRTN;
	if (pData)
	{
		DFITCSOPWithdrawOrderRtnField *task_data = new DFITCSOPWithdrawOrderRtnField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnSOPQuoteEntrustOrderRtn(DFITCSOPQuoteEntrustOrderRtnField * pData)
{
	Task task = Task();
	task.task_name = ONSOPQUOTEENTRUSTORDERRTN;
	if (pData)
	{
		DFITCSOPQuoteEntrustOrderRtnField *task_data = new DFITCSOPQuoteEntrustOrderRtnField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSOPCapitalTranInOut(DFITCSOPRspCapitalTranInOutField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSOPCAPITALTRANINOUT;
	if (pData)
	{
		DFITCSOPRspCapitalTranInOutField *task_data = new DFITCSOPRspCapitalTranInOutField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSOPCapitalDistributionRatio(DFITCSOPRspQryCapitalDistributionRatioField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSOPCAPITALDISTRIBUTIONRATIO;
	if (pData)
	{
		DFITCSOPRspQryCapitalDistributionRatioField *task_data = new DFITCSOPRspQryCapitalDistributionRatioField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspSOPFundTransBetweenNodes(DFITCSOPRspFundTransBetweenNodesField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSOPFUNDTRANSBETWEENNODES;
	if (pData)
	{
		DFITCSOPRspFundTransBetweenNodesField *task_data = new DFITCSOPRspFundTransBetweenNodesField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSOPModCapitalDistributionRatio(DFITCSOPRspModCapitalDistributionRatioField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSOPMODCAPITALDISTRIBUTIONRATIO;
	if (pData)
	{
		DFITCSOPRspModCapitalDistributionRatioField *task_data = new DFITCSOPRspModCapitalDistributionRatioField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFASLUserLogin(DFITCSECRspUserLoginField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPFASLUSERLOGIN;
	if (pData)
	{
		DFITCSECRspUserLoginField *task_data = new DFITCSECRspUserLoginField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFASLUserLogout(DFITCSECRspUserLogoutField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPFASLUSERLOGOUT;
	if (pData)
	{
		DFITCSECRspUserLogoutField *task_data = new DFITCSECRspUserLogoutField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryAbleFinInfo(DFITCFASLRspAbleFinInfoField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYABLEFININFO;
	if (pData)
	{
		DFITCFASLRspAbleFinInfoField *task_data = new DFITCFASLRspAbleFinInfoField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryAbleSloInfo(DFITCFASLRspAbleSloInfoField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYABLESLOINFO;
	if (pData)
	{
		DFITCFASLRspAbleSloInfoField *task_data = new DFITCFASLRspAbleSloInfoField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspFASLTransferCollateral(DFITCFASLRspTransferCollateralField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPFASLTRANSFERCOLLATERAL;
	if (pData)
	{
		DFITCFASLRspTransferCollateralField *task_data = new DFITCFASLRspTransferCollateralField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFASLDirectRepayment(DFITCFASLRspDirectRepaymentField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPFASLDIRECTREPAYMENT;
	if (pData)
	{
		DFITCFASLRspDirectRepaymentField *task_data = new DFITCFASLRspDirectRepaymentField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFASLRepayStockTransfer(DFITCFASLRspRepayStockTransferField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPFASLREPAYSTOCKTRANSFER;
	if (pData)
	{
		DFITCFASLRspRepayStockTransferField *task_data = new DFITCFASLRspRepayStockTransferField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFASLEntrustCrdtOrder(DFITCFASLRspEntrustCrdtOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPFASLENTRUSTCRDTORDER;
	if (pData)
	{
		DFITCFASLRspEntrustCrdtOrderField *task_data = new DFITCFASLRspEntrustCrdtOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFASLEntrustOrder(DFITCFASLRspEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPFASLENTRUSTORDER;
	if (pData)
	{
		DFITCFASLRspEntrustOrderField *task_data = new DFITCFASLRspEntrustOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFASLCalcAbleEntrustCrdtQty(DFITCFASLRspCalcAbleEntrustCrdtQtyField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPFASLCALCABLEENTRUSTCRDTQTY;
	if (pData)
	{
		DFITCFASLRspCalcAbleEntrustCrdtQtyField *task_data = new DFITCFASLRspCalcAbleEntrustCrdtQtyField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryCrdtFunds(DFITCFASLRspQryCrdtFundsField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYCRDTFUNDS;
	if (pData)
	{
		DFITCFASLRspQryCrdtFundsField *task_data = new DFITCFASLRspQryCrdtFundsField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryCrdtContract(DFITCFASLRspQryCrdtContractField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLat)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYCRDTCONTRACT;
	if (pData)
	{
		DFITCFASLRspQryCrdtContractField *task_data = new DFITCFASLRspQryCrdtContractField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLat;
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryCrdtConChangeInfo(DFITCFASLRspQryCrdtConChangeInfoField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYCRDTCONCHANGEINFO;
	if (pData)
	{
		DFITCFASLRspQryCrdtConChangeInfoField *task_data = new DFITCFASLRspQryCrdtConChangeInfoField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspFASLTransferFunds(DFITCFASLRspTransferFundsField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPFASLTRANSFERFUNDS;
	if (pData)
	{
		DFITCFASLRspTransferFundsField *task_data = new DFITCFASLRspTransferFundsField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFASLTransferStock(DFITCFASLRspTransferStockField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPFASLTRANSFERSTOCK;
	if (pData)
	{
		DFITCFASLRspTransferStockField *task_data = new DFITCFASLRspTransferStockField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryAccountInfo(DFITCFASLRspQryAccountField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYACCOUNTINFO;
	if (pData)
	{
		DFITCFASLRspQryAccountField *task_data = new DFITCFASLRspQryAccountField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryCapitalAccountInfo(DFITCFASLRspQryCapitalAccountField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYCAPITALACCOUNTINFO;
	if (pData)
	{
		DFITCFASLRspQryCapitalAccountField *task_data = new DFITCFASLRspQryCapitalAccountField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryShareholderInfo(DFITCFASLRspQryShareholderField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYSHAREHOLDERINFO;
	if (pData)
	{
		DFITCFASLRspQryShareholderField *task_data = new DFITCFASLRspQryShareholderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryPosition(DFITCFASLRspQryPositionField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYPOSITION;
	if (pData)
	{
		DFITCFASLRspQryPositionField *task_data = new DFITCFASLRspQryPositionField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryEntrustOrder(DFITCFASLRspQryEntrustOrderField * pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYENTRUSTORDER;
	if (pData)
	{
		DFITCFASLRspQryEntrustOrderField *task_data = new DFITCFASLRspQryEntrustOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQrySerialTrade(DFITCFASLRspQrySerialTradeField * pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYSERIALTRADE;
	if (pData)
	{
		DFITCFASLRspQrySerialTradeField *task_data = new DFITCFASLRspQrySerialTradeField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryRealTimeTrade(DFITCFASLRspQryRealTimeTradeField * pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYREALTIMETRADE;
	if (pData)
	{
		DFITCFASLRspQryRealTimeTradeField *task_data = new DFITCFASLRspQryRealTimeTradeField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryFreezeFundsDetail(DFITCFASLRspQryFreezeFundsDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYFREEZEFUNDSDETAIL;
	if (pData)
	{
		DFITCFASLRspQryFreezeFundsDetailField *task_data = new DFITCFASLRspQryFreezeFundsDetailField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryFreezeStockDetail(DFITCFASLRspQryFreezeStockDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYFREEZESTOCKDETAIL;
	if (pData)
	{
		DFITCFASLRspQryFreezeStockDetailField *task_data = new DFITCFASLRspQryFreezeStockDetailField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryTransferFundsDetail(DFITCFASLRspQryTransferFundsDetailField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYTRANSFERFUNDSDETAIL;
	if (pData)
	{
		DFITCFASLRspQryTransferFundsDetailField *task_data = new DFITCFASLRspQryTransferFundsDetailField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspFASLWithdrawOrder(DFITCFASLRspWithdrawOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPFASLWITHDRAWORDER;
	if (pData)
	{
		DFITCFASLRspWithdrawOrderField *task_data = new DFITCFASLRspWithdrawOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQrySystemTime(DFITCFASLRspQryTradeTimeField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYSYSTEMTIME;
	if (pData)
	{
		DFITCFASLRspQryTradeTimeField *task_data = new DFITCFASLRspQryTradeTimeField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryTransferredContract(DFITCFASLRspQryTransferredContractField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYTRANSFERREDCONTRACT;
	if (pData)
	{
		DFITCFASLRspQryTransferredContractField *task_data = new DFITCFASLRspQryTransferredContractField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspFASLDesirableFundsOut(DFITCFASLRspDesirableFundsOutField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPFASLDESIRABLEFUNDSOUT;
	if (pData)
	{
		DFITCFASLRspDesirableFundsOutField *task_data = new DFITCFASLRspDesirableFundsOutField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryGuaranteedContract(DFITCFASLRspQryGuaranteedContractField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYGUARANTEEDCONTRACT;
	if (pData)
	{
		DFITCFASLRspQryGuaranteedContractField *task_data = new DFITCFASLRspQryGuaranteedContractField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryUnderlyingContract(DFITCFASLRspQryUnderlyingContractField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYUNDERLYINGCONTRACT;
	if (pData)
	{
		DFITCFASLRspQryUnderlyingContractField *task_data = new DFITCFASLRspQryUnderlyingContractField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryCentreFundAvlInfo(DFITCFASLRspQryCentreFundAvlField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYCENTREFUNDAVLINFO;
	if (pData)
	{
		DFITCFASLRspQryCentreFundAvlField *task_data = new DFITCFASLRspQryCentreFundAvlField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspFASLQryPlacingInterestsInfo(DFITCFASLRspQryPlacingInterestsField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFASLQRYPLACINGINTERESTSINFO;
	if (pData)
	{
		DFITCFASLRspQryPlacingInterestsField *task_data = new DFITCFASLRspQryPlacingInterestsField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspFASLUserPasswordUpdate(DFITCSECRspPasswordUpdateField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPFASLUSERPASSWORDUPDATE;
	if (pData)
	{
		DFITCSECRspPasswordUpdateField *task_data = new DFITCSECRspPasswordUpdateField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnFASLEntrustOrderRtn(DFITCFaslEntrustOrderRtnField *pData)
{
	Task task = Task();
	task.task_name = ONFASLENTRUSTORDERRTN;
	if (pData)
	{
		DFITCFaslEntrustOrderRtnField *task_data = new DFITCFaslEntrustOrderRtnField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnFASLTradeRtn(DFITCFaslTradeRtnField *pData)
{
	Task task = Task();
	task.task_name = ONFASLTRADERTN;
	if (pData)
	{
		DFITCFaslTradeRtnField *task_data = new DFITCFaslTradeRtnField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnFASLWithdrawOrderRtn(DFITCFaslWithdrawOrderRtnField *pData)
{
	Task task = Task();
	task.task_name = ONFASLWITHDRAWORDERRTN;
	if (pData)
	{
		DFITCFaslWithdrawOrderRtnField *task_data = new DFITCFaslWithdrawOrderRtnField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnFASLLiabilitiesRtn(DFITCFaslLiabilitiesRtnField *pData)
{
	Task task = Task();
	task.task_name = ONFASLLIABILITIESRTN;
	if (pData)
	{
		DFITCFaslLiabilitiesRtnField *task_data = new DFITCFaslLiabilitiesRtnField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockETFEntrustOrder(DFITCStockRspETFEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKETFENTRUSTORDER;
	if (pData)
	{
		DFITCStockRspETFEntrustOrderField *task_data = new DFITCStockRspETFEntrustOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockETFBasketOrder(DFITCStockRspETFBasketOrderField *pData, DFITCSECRspInfoField *pRspInfo, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKETFBASKETORDER;
	if (pData)
	{
		DFITCStockRspETFBasketOrderField *task_data = new DFITCStockRspETFBasketOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspStockBondRepurchaseOrder(DFITCStockRspBondRepurchaseOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKBONDREPURCHASEORDER;
	if (pData)
	{
		DFITCStockRspBondRepurchaseOrderField *task_data = new DFITCStockRspBondRepurchaseOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockBondInOutStockOrder(DFITCStockRspBondInOutStockOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKBONDINOUTSTOCKORDER;
	if (pData)
	{
		DFITCStockRspBondInOutStockOrderField *task_data = new DFITCStockRspBondInOutStockOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockIssueBusinessOrder(DFITCStockRspIssueBusinessOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKISSUEBUSINESSORDER;
	if (pData)
	{
		DFITCStockRspIssueBusinessOrderField *task_data = new DFITCStockRspIssueBusinessOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockLOFEntrustOrder(DFITCStockRspLOFEntrustOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKLOFENTRUSTORDER;
	if (pData)
	{
		DFITCStockRspLOFEntrustOrderField *task_data = new DFITCStockRspLOFEntrustOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockAfterHoursPriceOrder(DFITCStockRspAfterHoursPriceOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKAFTERHOURSPRICEORDER;
	if (pData)
	{
		DFITCStockRspAfterHoursPriceOrderField *task_data = new DFITCStockRspAfterHoursPriceOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockNonTradingBusinessOrder(DFITCStockRspNonTradingBusinessOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKNONTRADINGBUSINESSORDER;
	if (pData)
	{
		DFITCStockRspNonTradingBusinessOrderField *task_data = new DFITCStockRspNonTradingBusinessOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockSHMutualFundOrder(DFITCStockRspSHMutualFundOrderField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKSHMUTUALFUNDORDER;
	if (pData)
	{
		DFITCStockRspSHMutualFundOrderField *task_data = new DFITCStockRspSHMutualFundOrderField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockCalcAblePurchaseETFBasketQty(DFITCStockRspCalcAblePurchaseETFBasketQtyField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKCALCABLEPURCHASEETFBASKETQTY;
	if (pData)
	{
		DFITCStockRspCalcAblePurchaseETFBasketQtyField *task_data = new DFITCStockRspCalcAblePurchaseETFBasketQtyField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockCalcAbleBondRepurchaseQty(DFITCStockRspCalcAbleBondRepurchaseQtyField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKCALCABLEBONDREPURCHASEQTY;
	if (pData)
	{
		DFITCStockRspCalcAbleBondRepurchaseQtyField *task_data = new DFITCStockRspCalcAbleBondRepurchaseQtyField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockCalcAbleIssueBusinessQty(DFITCStockRspCalcAbleIssueBusinessQtyField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKCALCABLEISSUEBUSINESSQTY;
	if (pData)
	{
		DFITCStockRspCalcAbleIssueBusinessQtyField *task_data = new DFITCStockRspCalcAbleIssueBusinessQtyField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockCalcAblePurchaseLOFQty(DFITCStockRspCalcAblePurchaseLOFQtyField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKCALCABLEPURCHASELOFQTY;
	if (pData)
	{
		DFITCStockRspCalcAblePurchaseLOFQtyField *task_data = new DFITCStockRspCalcAblePurchaseLOFQtyField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockCalcAbleAfterHoursPriceQty(DFITCStockRspCalcAbleAfterHoursPriceQtyField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKCALCABLEAFTERHOURSPRICEQTY;
	if (pData)
	{
		DFITCStockRspCalcAbleAfterHoursPriceQtyField *task_data = new DFITCStockRspCalcAbleAfterHoursPriceQtyField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockCalcAbleNonTradingBusinessQty(DFITCStockRspCalcAbleNonTradingBusinessQtyField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKCALCABLENONTRADINGBUSINESSQTY;
	if (pData)
	{
		DFITCStockRspCalcAbleNonTradingBusinessQtyField *task_data = new DFITCStockRspCalcAbleNonTradingBusinessQtyField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspStockCalcAbleSHMutualFundQty(DFITCStockRspCalcAbleSHMutualFundQtyField *pData, DFITCSECRspInfoField *pRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPSTOCKCALCABLESHMUTUALFUNDQTY;
	if (pData)
	{
		DFITCStockRspCalcAbleSHMutualFundQtyField *task_data = new DFITCStockRspCalcAbleSHMutualFundQtyField();
		*task_data = *pData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		DFITCSECRspInfoField *task_error = new DFITCSECRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

///-------------------------------------------------------------------------------------
///工作线程从队列中取出数据，转化为python对象后，进行推送
///-------------------------------------------------------------------------------------

void TdApi::processTask()
{
	try
	{
		while (this->active)
		{
			Task task = this->task_queue.pop();
			switch (task.task_name)
			{
			case ONFRONTCONNECTED:
			{
				this->processFrontConnected(&task);
				break;
			}

			case ONFRONTDISCONNECTED:
			{
				this->processFrontDisconnected(&task);
				break;
			}

			case ONRTNNOTICE:
			{
				this->processRtnNotice(&task);
				break;
			}

			case ONRSPERROR:
			{
				this->processRspError(&task);
				break;
			}

			case ONRSPSTOCKUSERLOGIN:
			{
				this->processRspStockUserLogin(&task);
				break;
			}

			case ONRSPSTOCKUSERLOGOUT:
			{
				this->processRspStockUserLogout(&task);
				break;
			}

			case ONRSPSTOCKUSERPASSWORDUPDATE:
			{
				this->processRspStockUserPasswordUpdate(&task);
				break;
			}

			case ONRSPSTOCKENTRUSTORDER:
			{
				this->processRspStockEntrustOrder(&task);
				break;
			}

			case ONRSPSTOCKWITHDRAWORDER:
			{
				this->processRspStockWithdrawOrder(&task);
				break;
			}

			case ONRSPSTOCKQRYENTRUSTORDER:
			{
				this->processRspStockQryEntrustOrder(&task);
				break;
			}

			case ONRSPSTOCKQRYREALTIMETRADE:
			{
				this->processRspStockQryRealTimeTrade(&task);
				break;
			}

			case ONRSPSTOCKQRYSERIALTRADE:
			{
				this->processRspStockQrySerialTrade(&task);
				break;
			}

			case ONRSPSTOCKQRYPOSITION:
			{
				this->processRspStockQryPosition(&task);
				break;
			}

			case ONRSPSTOCKQRYCAPITALACCOUNTINFO:
			{
				this->processRspStockQryCapitalAccountInfo(&task);
				break;
			}

			case ONRSPSTOCKQRYACCOUNTINFO:
			{
				this->processRspStockQryAccountInfo(&task);
				break;
			}

			case ONRSPSTOCKQRYSHAREHOLDERINFO:
			{
				this->processRspStockQryShareholderInfo(&task);
				break;
			}

			case ONRSPSTOCKTRANSFERFUNDS:
			{
				this->processRspStockTransferFunds(&task);
				break;
			}

			case ONRSPSTOCKENTRUSTBATCHORDER:
			{
				this->processRspStockEntrustBatchOrder(&task);
				break;
			}

			case ONRSPSTOCKWITHDRAWBATCHORDER:
			{
				this->processRspStockWithdrawBatchOrder(&task);
				break;
			}

			case ONRSPSTOCKCALCABLEENTRUSTQTY:
			{
				this->processRspStockCalcAbleEntrustQty(&task);
				break;
			}

			case ONRSPSTOCKCALCABLEPURCHASEETFQTY:
			{
				this->processRspStockCalcAblePurchaseETFQty(&task);
				break;
			}

			case ONRSPSTOCKQRYFREEZEFUNDSDETAIL:
			{
				this->processRspStockQryFreezeFundsDetail(&task);
				break;
			}

			case ONRSPSTOCKQRYFREEZESTOCKDETAIL:
			{
				this->processRspStockQryFreezeStockDetail(&task);
				break;
			}

			case ONRSPSTOCKQRYTRANSFERSTOCKDETAIL:
			{
				this->processRspStockQryTransferStockDetail(&task);
				break;
			}

			case ONRSPSTOCKQRYTRANSFERFUNDSDETAIL:
			{
				this->processRspStockQryTransferFundsDetail(&task);
				break;
			}

			case ONRSPSTOCKQRYSTOCKINFO:
			{
				this->processRspStockQryStockInfo(&task);
				break;
			}

			case ONRSPSTOCKQRYSTOCKSTATICINFO:
			{
				this->processRspStockQryStockStaticInfo(&task);
				break;
			}

			case ONRSPSTOCKQRYTRADETIME:
			{
				this->processRspStockQryTradeTime(&task);
				break;
			}

			case ONSTOCKENTRUSTORDERRTN:
			{
				this->processStockEntrustOrderRtn(&task);
				break;
			}

			case ONSTOCKTRADERTN:
			{
				this->processStockTradeRtn(&task);
				break;
			}

			case ONSTOCKWITHDRAWORDERRTN:
			{
				this->processStockWithdrawOrderRtn(&task);
				break;
			}

			case ONRSPSOPUSERLOGIN:
			{
				this->processRspSOPUserLogin(&task);
				break;
			}

			case ONRSPSOPUSERLOGOUT:
			{
				this->processRspSOPUserLogout(&task);
				break;
			}

			case ONRSPSOPUSERPASSWORDUPDATE:
			{
				this->processRspSOPUserPasswordUpdate(&task);
				break;
			}

			case ONRSPSOPENTRUSTORDER:
			{
				this->processRspSOPEntrustOrder(&task);
				break;
			}

			case ONRSPSOPQUOTEENTRUSTORDER:
			{
				this->processRspSOPQuoteEntrustOrder(&task);
				break;
			}

			case ONRSPSOPGROUPSPLIT:
			{
				this->processRspSOPGroupSplit(&task);
				break;
			}

			case ONRSPSOPGROUPEXECTUEORDER:
			{
				this->processRspSOPGroupExectueOrder(&task);
				break;
			}

			case ONRSPSOPQRYGROUPPOSITION:
			{
				this->processRspSOPQryGroupPosition(&task);
				break;
			}

			case ONRSPSOPLOCKOUNLOCKSTOCK:
			{
				this->processRspSOPLockOUnLockStock(&task);
				break;
			}

			case ONRSPSOPWITHDRAWORDER:
			{
				this->processRspSOPWithdrawOrder(&task);
				break;
			}

			case ONRSPSOPQRYENTRUSTORDER:
			{
				this->processRspSOPQryEntrustOrder(&task);
				break;
			}

			case ONRSPSOPQRYSERIALTRADE:
			{
				this->processRspSOPQrySerialTrade(&task);
				break;
			}

			case ONRSPSOPQRYPOSITION:
			{
				this->processRspSOPQryPosition(&task);
				break;
			}

			case ONRSPSOPQRYCOLLATERALPOSITION:
			{
				this->processRspSOPQryCollateralPosition(&task);
				break;
			}

			case ONRSPSOPQRYCAPITALACCOUNTINFO:
			{
				this->processRspSOPQryCapitalAccountInfo(&task);
				break;
			}

			case ONRSPSOPQRYACCOUNTINFO:
			{
				this->processRspSOPQryAccountInfo(&task);
				break;
			}

			case ONRSPSOPQRYSHAREHOLDERINFO:
			{
				this->processRspSOPQryShareholderInfo(&task);
				break;
			}

			case ONRSPSOPCALCABLEENTRUSTQTY:
			{
				this->processRspSOPCalcAbleEntrustQty(&task);
				break;
			}

			case ONRSPSOPQRYABLELOCKSTOCK:
			{
				this->processRspSOPQryAbleLockStock(&task);
				break;
			}

			case ONRSPSOPQRYCONTACTINFO:
			{
				this->processRspSOPQryContactInfo(&task);
				break;
			}

			case ONRSPSOPEXECTUEORDER:
			{
				this->processRspSOPExectueOrder(&task);
				break;
			}

			case ONRSPSOPQRYEXECASSIINFO:
			{
				this->processRspSOPQryExecAssiInfo(&task);
				break;
			}

			case ONRSPSOPQRYTRADETIME:
			{
				this->processRspSOPQryTradeTime(&task);
				break;
			}

			case ONRSPSOPQRYEXCHANGEINFO:
			{
				this->processRspSOPQryExchangeInfo(&task);
				break;
			}

			case ONRSPSOPQRYCOMMISSION:
			{
				this->processRspSOPQryCommission(&task);
				break;
			}

			case ONRSPSOPQRYDEPOSIT:
			{
				this->processRspSOPQryDeposit(&task);
				break;
			}

			case ONRSPSOPQRYCONTRACTOBJECTINFO:
			{
				this->processRspSOPQryContractObjectInfo(&task);
				break;
			}

			case ONSOPENTRUSTORDERRTN:
			{
				this->processSOPEntrustOrderRtn(&task);
				break;
			}

			case ONSOPTRADERTN:
			{
				this->processSOPTradeRtn(&task);
				break;
			}

			case ONSOPWITHDRAWORDERRTN:
			{
				this->processSOPWithdrawOrderRtn(&task);
				break;
			}

			case ONSOPQUOTEENTRUSTORDERRTN:
			{
				this->processSOPQuoteEntrustOrderRtn(&task);
				break;
			}

			case ONRSPSOPCAPITALTRANINOUT:
			{
				this->processRspSOPCapitalTranInOut(&task);
				break;
			}

			case ONRSPSOPCAPITALDISTRIBUTIONRATIO:
			{
				this->processRspSOPCapitalDistributionRatio(&task);
				break;
			}

			case ONRSPSOPFUNDTRANSBETWEENNODES:
			{
				this->processRspSOPFundTransBetweenNodes(&task);
				break;
			}

			case ONRSPSOPMODCAPITALDISTRIBUTIONRATIO:
			{
				this->processRspSOPModCapitalDistributionRatio(&task);
				break;
			}

			case ONRSPFASLUSERLOGIN:
			{
				this->processRspFASLUserLogin(&task);
				break;
			}

			case ONRSPFASLUSERLOGOUT:
			{
				this->processRspFASLUserLogout(&task);
				break;
			}

			case ONRSPFASLQRYABLEFININFO:
			{
				this->processRspFASLQryAbleFinInfo(&task);
				break;
			}

			case ONRSPFASLQRYABLESLOINFO:
			{
				this->processRspFASLQryAbleSloInfo(&task);
				break;
			}

			case ONRSPFASLTRANSFERCOLLATERAL:
			{
				this->processRspFASLTransferCollateral(&task);
				break;
			}

			case ONRSPFASLDIRECTREPAYMENT:
			{
				this->processRspFASLDirectRepayment(&task);
				break;
			}

			case ONRSPFASLREPAYSTOCKTRANSFER:
			{
				this->processRspFASLRepayStockTransfer(&task);
				break;
			}

			case ONRSPFASLENTRUSTCRDTORDER:
			{
				this->processRspFASLEntrustCrdtOrder(&task);
				break;
			}

			case ONRSPFASLENTRUSTORDER:
			{
				this->processRspFASLEntrustOrder(&task);
				break;
			}

			case ONRSPFASLCALCABLEENTRUSTCRDTQTY:
			{
				this->processRspFASLCalcAbleEntrustCrdtQty(&task);
				break;
			}

			case ONRSPFASLQRYCRDTFUNDS:
			{
				this->processRspFASLQryCrdtFunds(&task);
				break;
			}

			case ONRSPFASLQRYCRDTCONTRACT:
			{
				this->processRspFASLQryCrdtContract(&task);
				break;
			}

			case ONRSPFASLQRYCRDTCONCHANGEINFO:
			{
				this->processRspFASLQryCrdtConChangeInfo(&task);
				break;
			}

			case ONRSPFASLTRANSFERFUNDS:
			{
				this->processRspFASLTransferFunds(&task);
				break;
			}

			case ONRSPFASLTRANSFERSTOCK:
			{
				this->processRspFASLTransferStock(&task);
				break;
			}

			case ONRSPFASLQRYACCOUNTINFO:
			{
				this->processRspFASLQryAccountInfo(&task);
				break;
			}

			case ONRSPFASLQRYCAPITALACCOUNTINFO:
			{
				this->processRspFASLQryCapitalAccountInfo(&task);
				break;
			}

			case ONRSPFASLQRYSHAREHOLDERINFO:
			{
				this->processRspFASLQryShareholderInfo(&task);
				break;
			}

			case ONRSPFASLQRYPOSITION:
			{
				this->processRspFASLQryPosition(&task);
				break;
			}

			case ONRSPFASLQRYENTRUSTORDER:
			{
				this->processRspFASLQryEntrustOrder(&task);
				break;
			}

			case ONRSPFASLQRYSERIALTRADE:
			{
				this->processRspFASLQrySerialTrade(&task);
				break;
			}

			case ONRSPFASLQRYREALTIMETRADE:
			{
				this->processRspFASLQryRealTimeTrade(&task);
				break;
			}

			case ONRSPFASLQRYFREEZEFUNDSDETAIL:
			{
				this->processRspFASLQryFreezeFundsDetail(&task);
				break;
			}

			case ONRSPFASLQRYFREEZESTOCKDETAIL:
			{
				this->processRspFASLQryFreezeStockDetail(&task);
				break;
			}

			case ONRSPFASLQRYTRANSFERFUNDSDETAIL:
			{
				this->processRspFASLQryTransferFundsDetail(&task);
				break;
			}

			case ONRSPFASLWITHDRAWORDER:
			{
				this->processRspFASLWithdrawOrder(&task);
				break;
			}

			case ONRSPFASLQRYSYSTEMTIME:
			{
				this->processRspFASLQrySystemTime(&task);
				break;
			}

			case ONRSPFASLQRYTRANSFERREDCONTRACT:
			{
				this->processRspFASLQryTransferredContract(&task);
				break;
			}

			case ONRSPFASLDESIRABLEFUNDSOUT:
			{
				this->processRspFASLDesirableFundsOut(&task);
				break;
			}

			case ONRSPFASLQRYGUARANTEEDCONTRACT:
			{
				this->processRspFASLQryGuaranteedContract(&task);
				break;
			}

			case ONRSPFASLQRYUNDERLYINGCONTRACT:
			{
				this->processRspFASLQryUnderlyingContract(&task);
				break;
			}

			case ONRSPFASLQRYCENTREFUNDAVLINFO:
			{
				this->processRspFASLQryCentreFundAvlInfo(&task);
				break;
			}

			case ONRSPFASLQRYPLACINGINTERESTSINFO:
			{
				this->processRspFASLQryPlacingInterestsInfo(&task);
				break;
			}

			case ONRSPFASLUSERPASSWORDUPDATE:
			{
				this->processRspFASLUserPasswordUpdate(&task);
				break;
			}

			case ONFASLENTRUSTORDERRTN:
			{
				this->processFASLEntrustOrderRtn(&task);
				break;
			}

			case ONFASLTRADERTN:
			{
				this->processFASLTradeRtn(&task);
				break;
			}

			case ONFASLWITHDRAWORDERRTN:
			{
				this->processFASLWithdrawOrderRtn(&task);
				break;
			}

			case ONFASLLIABILITIESRTN:
			{
				this->processFASLLiabilitiesRtn(&task);
				break;
			}

			case ONRSPSTOCKETFENTRUSTORDER:
			{
				this->processRspStockETFEntrustOrder(&task);
				break;
			}

			case ONRSPSTOCKETFBASKETORDER:
			{
				this->processRspStockETFBasketOrder(&task);
				break;
			}

			case ONRSPSTOCKBONDREPURCHASEORDER:
			{
				this->processRspStockBondRepurchaseOrder(&task);
				break;
			}

			case ONRSPSTOCKBONDINOUTSTOCKORDER:
			{
				this->processRspStockBondInOutStockOrder(&task);
				break;
			}

			case ONRSPSTOCKISSUEBUSINESSORDER:
			{
				this->processRspStockIssueBusinessOrder(&task);
				break;
			}

			case ONRSPSTOCKLOFENTRUSTORDER:
			{
				this->processRspStockLOFEntrustOrder(&task);
				break;
			}

			case ONRSPSTOCKAFTERHOURSPRICEORDER:
			{
				this->processRspStockAfterHoursPriceOrder(&task);
				break;
			}

			case ONRSPSTOCKNONTRADINGBUSINESSORDER:
			{
				this->processRspStockNonTradingBusinessOrder(&task);
				break;
			}

			case ONRSPSTOCKSHMUTUALFUNDORDER:
			{
				this->processRspStockSHMutualFundOrder(&task);
				break;
			}

			case ONRSPSTOCKCALCABLEPURCHASEETFBASKETQTY:
			{
				this->processRspStockCalcAblePurchaseETFBasketQty(&task);
				break;
			}

			case ONRSPSTOCKCALCABLEBONDREPURCHASEQTY:
			{
				this->processRspStockCalcAbleBondRepurchaseQty(&task);
				break;
			}

			case ONRSPSTOCKCALCABLEISSUEBUSINESSQTY:
			{
				this->processRspStockCalcAbleIssueBusinessQty(&task);
				break;
			}

			case ONRSPSTOCKCALCABLEPURCHASELOFQTY:
			{
				this->processRspStockCalcAblePurchaseLOFQty(&task);
				break;
			}

			case ONRSPSTOCKCALCABLEAFTERHOURSPRICEQTY:
			{
				this->processRspStockCalcAbleAfterHoursPriceQty(&task);
				break;
			}

			case ONRSPSTOCKCALCABLENONTRADINGBUSINESSQTY:
			{
				this->processRspStockCalcAbleNonTradingBusinessQty(&task);
				break;
			}

			case ONRSPSTOCKCALCABLESHMUTUALFUNDQTY:
			{
				this->processRspStockCalcAbleSHMutualFundQty(&task);
				break;
			}
			};
		}
	}
	catch (const TerminatedError&)
	{
	}

};
void TdApi::processFrontConnected(Task *task)
{
	gil_scoped_acquire acquire;
	this->onFrontConnected();
};

void TdApi::processFrontDisconnected(Task *task)
{
	gil_scoped_acquire acquire;
	this->onFrontDisconnected(task->task_id);
};

void TdApi::processRtnNotice(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSECRspNoticeField *task_data = (DFITCSECRspNoticeField*)task->task_data;
		data["noticeMsg"] = toUtf(task_data->noticeMsg);
		delete task_data;
	}
	this->onRtnNotice(data);
};

void TdApi::processRspError(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspError(error);
};

void TdApi::processRspStockUserLogin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSECRspUserLoginField *task_data = (DFITCSECRspUserLoginField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["sessionID"] = task_data->sessionID;
		data["frontID"] = task_data->frontID;
		data["localOrderID"] = task_data->localOrderID;
		data["loginTime"] = toUtf(task_data->loginTime);
		data["tradingDay"] = task_data->tradingDay;
		data["result"] = task_data->result;
		data["rtnMsg"] = toUtf(task_data->rtnMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockUserLogin(data, error);
};

void TdApi::processRspStockUserLogout(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSECRspUserLogoutField *task_data = (DFITCSECRspUserLogoutField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["result"] = task_data->result;
		data["rtnMsg"] = toUtf(task_data->rtnMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockUserLogout(data, error);
};

void TdApi::processRspStockUserPasswordUpdate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSECRspPasswordUpdateField *task_data = (DFITCSECRspPasswordUpdateField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["passwordType"] = task_data->passwordType;
		data["result"] = task_data->result;
		data["rtnMsg"] = toUtf(task_data->rtnMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockUserPasswordUpdate(data, error);
};

void TdApi::processRspStockEntrustOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspEntrustOrderField *task_data = (DFITCStockRspEntrustOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustBatchID"] = task_data->entrustBatchID;
		data["entrustMsg"] = toUtf(task_data->entrustMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockEntrustOrder(data, error);
};

void TdApi::processRspStockWithdrawOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSECRspWithdrawOrderField *task_data = (DFITCSECRspWithdrawOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["cancelMsg"] = toUtf(task_data->cancelMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockWithdrawOrder(data, error);
};

void TdApi::processRspStockQryEntrustOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspQryEntrustOrderField *task_data = (DFITCStockRspQryEntrustOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["offerShareholderID"] = toUtf(task_data->offerShareholderID);
		data["currency"] = toUtf(task_data->currency);
		data["turnover"] = task_data->turnover;
		data["tradePrice"] = task_data->tradePrice;
		data["tradeTime"] = toUtf(task_data->tradeTime);
		data["tradeQty"] = task_data->tradeQty;
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["clearFunds"] = task_data->clearFunds;
		data["entrustType"] = task_data->entrustType;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustPrice"] = task_data->entrustPrice;
		data["entrustDirection"] = task_data->entrustDirection;
		data["entrustQty"] = task_data->entrustQty;
		data["securityID"] = toUtf(task_data->securityID);
		data["securityType"] = toUtf(task_data->securityType);
		data["securityName"] = toUtf(task_data->securityName);
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["declareTime"] = toUtf(task_data->declareTime);
		data["declareResult"] = task_data->declareResult;
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["freezeFunds"] = task_data->freezeFunds;
		data["accountID"] = toUtf(task_data->accountID);
		data["noteMsg"] = toUtf(task_data->noteMsg);
		data["withdrawQty"] = task_data->withdrawQty;
		data["declareOrderID"] = toUtf(task_data->declareOrderID);
		data["orderType"] = task_data->orderType;
		data["entrustBatchID"] = task_data->entrustBatchID;
		data["freezeFundsSerialID"] = task_data->freezeFundsSerialID;
		data["freezeStockSerialID"] = task_data->freezeStockSerialID;
		data["declareDate"] = task_data->declareDate;
		data["declareSerialID"] = task_data->declareSerialID;
		data["entrustDate"] = task_data->entrustDate;
		data["incQryIndex"] = toUtf(task_data->incQryIndex);
		data["ipAddr"] = toUtf(task_data->ipAddr);
		data["macAddr"] = toUtf(task_data->macAddr);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockQryEntrustOrder(data, error, task->task_last);
};

void TdApi::processRspStockQryRealTimeTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspQryRealTimeTradeField *task_data = (DFITCStockRspQryRealTimeTradeField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["spdOrderID"] = task_data->spdOrderID;
		data["declareOrderID"] = toUtf(task_data->declareOrderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["entrustDirection"] = task_data->entrustDirection;
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["securityID"] = toUtf(task_data->securityID);
		data["securityName"] = toUtf(task_data->securityName);
		data["entrustQty"] = task_data->entrustQty;
		data["entrustPrice"] = task_data->entrustPrice;
		data["withdrawQty"] = task_data->withdrawQty;
		data["tradeQty"] = task_data->tradeQty;
		data["turnover"] = task_data->turnover;
		data["tradePrice"] = task_data->tradePrice;
		data["tradeTime"] = toUtf(task_data->tradeTime);
		data["currency"] = toUtf(task_data->currency);
		data["clearFunds"] = task_data->clearFunds;
		data["entrustBatchID"] = task_data->entrustBatchID;
		data["orderType"] = task_data->orderType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockQryRealTimeTrade(data, error, task->task_last);
};

void TdApi::processRspStockQrySerialTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspQrySerialTradeField *task_data = (DFITCStockRspQrySerialTradeField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["currency"] = toUtf(task_data->currency);
		data["tradeID"] = toUtf(task_data->tradeID);
		data["turnover"] = task_data->turnover;
		data["tradePrice"] = task_data->tradePrice;
		data["tradeQty"] = task_data->tradeQty;
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["clearFunds"] = task_data->clearFunds;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustDirection"] = task_data->entrustDirection;
		data["securityID"] = toUtf(task_data->securityID);
		data["securityType"] = toUtf(task_data->securityType);
		data["securityName"] = toUtf(task_data->securityName);
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["commission"] = task_data->commission;
		data["rtnSerialID"] = task_data->rtnSerialID;
		data["interestQuote"] = task_data->interestQuote;
		data["declareOrderID"] = toUtf(task_data->declareOrderID);
		data["incQryIndex"] = toUtf(task_data->incQryIndex);
		data["interest"] = task_data->interest;
		data["tradeTime"] = toUtf(task_data->tradeTime);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockQrySerialTrade(data, error, task->task_last);
};

void TdApi::processRspStockQryPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspQryPositionField *task_data = (DFITCStockRspQryPositionField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["currency"] = toUtf(task_data->currency);
		data["sellTurnover"] = task_data->sellTurnover;
		data["sellTradeQty"] = task_data->sellTradeQty;
		data["sellEntrustQty"] = task_data->sellEntrustQty;
		data["buyTurnover"] = task_data->buyTurnover;
		data["buyTradeQty"] = task_data->buyTradeQty;
		data["buyEntrustQty"] = task_data->buyEntrustQty;
		data["nonCirculateQty"] = task_data->nonCirculateQty;
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["openDate"] = task_data->openDate;
		data["ableSellQty"] = task_data->ableSellQty;
		data["securityID"] = toUtf(task_data->securityID);
		data["securityType"] = toUtf(task_data->securityType);
		data["securityName"] = toUtf(task_data->securityName);
		data["securityQty"] = task_data->securityQty;
		data["position"] = task_data->position;
		data["unSettleQty"] = task_data->unSettleQty;
		data["changeDate"] = task_data->changeDate;
		data["ablePurchaseQty"] = task_data->ablePurchaseQty;
		data["ableRedemptionQty"] = task_data->ableRedemptionQty;
		data["freezeQty"] = task_data->freezeQty;
		data["offsetSQty"] = task_data->offsetSQty;
		data["offsetBQty"] = task_data->offsetBQty;
		data["purchaseTradeQty"] = task_data->purchaseTradeQty;
		data["redemptionTradeQty"] = task_data->redemptionTradeQty;
		data["tradeUnit"] = task_data->tradeUnit;
		data["totalSellQty"] = task_data->totalSellQty;
		data["totalBuyQty"] = task_data->totalBuyQty;
		data["rationedSharesQty"] = task_data->rationedSharesQty;
		data["purchaseQty"] = task_data->purchaseQty;
		data["dilutedFloatProfitLoss"] = task_data->dilutedFloatProfitLoss;
		data["dilutedBreakevenPrice"] = task_data->dilutedBreakevenPrice;
		data["dilutedCost"] = task_data->dilutedCost;
		data["avgPositionPrice"] = task_data->avgPositionPrice;
		data["floatProfitLoss"] = task_data->floatProfitLoss;
		data["dividend"] = task_data->dividend;
		data["totalFloatProfitLoss"] = task_data->totalFloatProfitLoss;
		data["sellAmount"] = task_data->sellAmount;
		data["buyAmount"] = task_data->buyAmount;
		data["buyAvgPrice"] = task_data->buyAvgPrice;
		data["rationedSharesAmount"] = task_data->rationedSharesAmount;
		data["latestMarket"] = task_data->latestMarket;
		data["breakevenPrice"] = task_data->breakevenPrice;
		data["latestPrice"] = task_data->latestPrice;
		data["nonCirculateMarket"] = task_data->nonCirculateMarket;
		data["interestQuote"] = task_data->interestQuote;
		data["preClosePrice"] = task_data->preClosePrice;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockQryPosition(data, error, task->task_last);
};

void TdApi::processRspStockQryCapitalAccountInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspQryCapitalAccountField *task_data = (DFITCStockRspQryCapitalAccountField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["currency"] = toUtf(task_data->currency);
		data["availableFunds"] = task_data->availableFunds;
		data["t2AvailableFunds"] = task_data->t2AvailableFunds;
		data["anticipatedInterest"] = task_data->anticipatedInterest;
		data["accountBalance"] = task_data->accountBalance;
		data["accountStatus"] = task_data->accountStatus;
		data["accountID"] = toUtf(task_data->accountID);
		data["freezeFunds"] = task_data->freezeFunds;
		data["t2FreezeFunds"] = task_data->t2FreezeFunds;
		data["branchID"] = toUtf(task_data->branchID);
		data["totalFunds"] = task_data->totalFunds;
		data["totalMarket"] = task_data->totalMarket;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockQryCapitalAccountInfo(data, error, task->task_last);
};

void TdApi::processRspStockQryAccountInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspQryAccountField *task_data = (DFITCStockRspQryAccountField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["tel"] = toUtf(task_data->tel);
		data["accountID"] = toUtf(task_data->accountID);
		data["accountName"] = toUtf(task_data->accountName);
		data["accountIdentityID"] = toUtf(task_data->accountIdentityID);
		data["accountIdentityType"] = task_data->accountIdentityType;
		data["branchID"] = toUtf(task_data->branchID);
		data["mobile"] = toUtf(task_data->mobile);
		data["entrustType"] = task_data->entrustType;
		data["accountStatus"] = task_data->accountStatus;
		data["pwdSynFlag"] = task_data->pwdSynFlag;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockQryAccountInfo(data, error);
};

void TdApi::processRspStockQryShareholderInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspQryShareholderField *task_data = (DFITCStockRspQryShareholderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["account"] = toUtf(task_data->account);
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["shareholderSpecProp"] = task_data->shareholderSpecProp;
		data["tradePermissions"] = task_data->tradePermissions;
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["shareholderStatus"] = task_data->shareholderStatus;
		data["mainAccountFlag"] = task_data->mainAccountFlag;
		data["shareholderCtlProp"] = task_data->shareholderCtlProp;
		data["branchID"] = toUtf(task_data->branchID);
		data["shareholderType"] = task_data->shareholderType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockQryShareholderInfo(data, error, task->task_last);
};

void TdApi::processRspStockTransferFunds(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspTransferFundsField *task_data = (DFITCStockRspTransferFundsField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["serialID"] = task_data->serialID;
		data["accountBanlance"] = task_data->accountBanlance;
		data["availableFunds"] = task_data->availableFunds;
		data["t2AvailableFunds"] = task_data->t2AvailableFunds;
		data["fundsTransFlag"] = task_data->fundsTransFlag;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockTransferFunds(data, error);
};

void TdApi::processRspStockEntrustBatchOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspEntrustBatchOrderField *task_data = (DFITCStockRspEntrustBatchOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["orderRangeID"] = toUtf(task_data->orderRangeID);
		data["entrustBatchID"] = task_data->entrustBatchID;
		data["sucEntrustCount"] = task_data->sucEntrustCount;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockEntrustBatchOrder(data, error);
};

void TdApi::processRspStockWithdrawBatchOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspWithdrawBatchOrderField *task_data = (DFITCStockRspWithdrawBatchOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["result"] = task_data->result;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockWithdrawBatchOrder(data, error);
};

void TdApi::processRspStockCalcAbleEntrustQty(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspCalcAbleEntrustQtyField *task_data = (DFITCStockRspCalcAbleEntrustQtyField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["ableEntrustQty"] = task_data->ableEntrustQty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockCalcAbleEntrustQty(data, error);
};

void TdApi::processRspStockCalcAblePurchaseETFQty(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspCalcAblePurchaseETFQtyField *task_data = (DFITCStockRspCalcAblePurchaseETFQtyField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["ablePurchaseETFQty"] = task_data->ablePurchaseETFQty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockCalcAblePurchaseETFQty(data, error);
};

void TdApi::processRspStockQryFreezeFundsDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspQryFreezeFundsDetailField *task_data = (DFITCStockRspQryFreezeFundsDetailField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["currency"] = toUtf(task_data->currency);
		data["fundsFreezeType"] = task_data->fundsFreezeType;
		data["accountName"] = toUtf(task_data->accountName);
		data["summaryMsg"] = toUtf(task_data->summaryMsg);
		data["serialID"] = task_data->serialID;
		data["operatorFunds"] = task_data->operatorFunds;
		data["operatorTime"] = toUtf(task_data->operatorTime);
		data["branchID"] = toUtf(task_data->branchID);
		data["operatorDate"] = task_data->operatorDate;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockQryFreezeFundsDetail(data, error, task->task_last);
};

void TdApi::processRspStockQryFreezeStockDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspQryFreezeStockDetailField *task_data = (DFITCStockRspQryFreezeStockDetailField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["stockFreezeType"] = task_data->stockFreezeType;
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["accountName"] = toUtf(task_data->accountName);
		data["securityID"] = toUtf(task_data->securityID);
		data["securityType"] = toUtf(task_data->securityType);
		data["securityName"] = toUtf(task_data->securityName);
		data["summaryMsg"] = toUtf(task_data->summaryMsg);
		data["serialID"] = task_data->serialID;
		data["operatorTime"] = toUtf(task_data->operatorTime);
		data["branchID"] = toUtf(task_data->branchID);
		data["operatorDate"] = task_data->operatorDate;
		data["operatorQty"] = task_data->operatorQty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockQryFreezeStockDetail(data, error, task->task_last);
};

void TdApi::processRspStockQryTransferStockDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspQryTransferStockDetailField *task_data = (DFITCStockRspQryTransferStockDetailField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["accountName"] = toUtf(task_data->accountName);
		data["branchID"] = toUtf(task_data->branchID);
		data["operatorDate"] = task_data->operatorDate;
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["stockFreezeType"] = task_data->stockFreezeType;
		data["securityID"] = toUtf(task_data->securityID);
		data["serialID"] = task_data->serialID;
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["summaryMsg"] = toUtf(task_data->summaryMsg);
		data["operatorTime"] = toUtf(task_data->operatorTime);
		data["operatorQty"] = task_data->operatorQty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockQryTransferStockDetail(data, error, task->task_last);
};

void TdApi::processRspStockQryTransferFundsDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspQryTransferFundsDetailField *task_data = (DFITCStockRspQryTransferFundsDetailField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["currency"] = toUtf(task_data->currency);
		data["fundsFreezeType"] = task_data->fundsFreezeType;
		data["accountName"] = toUtf(task_data->accountName);
		data["summaryMsg"] = toUtf(task_data->summaryMsg);
		data["serialID"] = task_data->serialID;
		data["operatorFunds"] = task_data->operatorFunds;
		data["operatorTime"] = toUtf(task_data->operatorTime);
		data["branchID"] = toUtf(task_data->branchID);
		data["operatorDate"] = task_data->operatorDate;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockQryTransferFundsDetail(data, error, task->task_last);
};

void TdApi::processRspStockQryStockInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspQryStockField *task_data = (DFITCStockRspQryStockField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["stopFlag"] = task_data->stopFlag;
		data["latestPrice"] = task_data->latestPrice;
		data["preClosePrice"] = task_data->preClosePrice;
		data["openPrice"] = task_data->openPrice;
		data["tradeQty"] = task_data->tradeQty;
		data["turnover"] = task_data->turnover;
		data["priceHigher"] = task_data->priceHigher;
		data["priceLower"] = task_data->priceLower;
		data["bidPrice1"] = task_data->bidPrice1;
		data["bidQty1"] = task_data->bidQty1;
		data["askPrice1"] = task_data->askPrice1;
		data["askQty1"] = task_data->askQty1;
		data["bidPrice2"] = task_data->bidPrice2;
		data["bidQty2"] = task_data->bidQty2;
		data["askPrice2"] = task_data->askPrice2;
		data["askQty2"] = task_data->askQty2;
		data["bidPrice3"] = task_data->bidPrice3;
		data["bidQty3"] = task_data->bidQty3;
		data["askPrice3"] = task_data->askPrice3;
		data["askQty3"] = task_data->askQty3;
		data["bidPrice4"] = task_data->bidPrice4;
		data["bidQty4"] = task_data->bidQty4;
		data["askPrice4"] = task_data->askPrice4;
		data["askQty4"] = task_data->askQty4;
		data["bidPrice5"] = task_data->bidPrice5;
		data["bidQty5"] = task_data->bidQty5;
		data["askPrice5"] = task_data->askPrice5;
		data["askQty5"] = task_data->askQty5;
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["interestQuote"] = task_data->interestQuote;
		data["securityFaceValue"] = task_data->securityFaceValue;
		data["bidTradeFlag"] = task_data->bidTradeFlag;
		data["tradeUnit"] = task_data->tradeUnit;
		data["businessLimit"] = task_data->businessLimit;
		data["securityType"] = toUtf(task_data->securityType);
		data["securityName"] = toUtf(task_data->securityName);
		data["upperLimitPrice"] = task_data->upperLimitPrice;
		data["lowerLimitPrice"] = task_data->lowerLimitPrice;
		data["currency"] = toUtf(task_data->currency);
		data["orderLimits"] = toUtf(task_data->orderLimits);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockQryStockInfo(data, error, task->task_last);
};

void TdApi::processRspStockQryStockStaticInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspQryStockStaticField *task_data = (DFITCStockRspQryStockStaticField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["stopFlag"] = task_data->stopFlag;
		data["preClosePrice"] = task_data->preClosePrice;
		data["openPrice"] = task_data->openPrice;
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["interestQuote"] = task_data->interestQuote;
		data["securityFaceValue"] = task_data->securityFaceValue;
		data["bidTradeFlag"] = task_data->bidTradeFlag;
		data["tradeUnit"] = task_data->tradeUnit;
		data["businessLimit"] = task_data->businessLimit;
		data["securityType"] = toUtf(task_data->securityType);
		data["securityName"] = toUtf(task_data->securityName);
		data["upperLimitPrice"] = task_data->upperLimitPrice;
		data["lowerLimitPrice"] = task_data->lowerLimitPrice;
		data["currency"] = toUtf(task_data->currency);
		data["orderLimits"] = toUtf(task_data->orderLimits);
		data["incQryIndex"] = toUtf(task_data->incQryIndex);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockQryStockStaticInfo(data, error, task->task_last);
};

void TdApi::processRspStockQryTradeTime(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspQryTradeTimeField *task_data = (DFITCStockRspQryTradeTimeField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["sysTradingDay"] = task_data->sysTradingDay;
		data["sysTime"] = toUtf(task_data->sysTime);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockQryTradeTime(data, error);
};

void TdApi::processStockEntrustOrderRtn(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockEntrustOrderRtnField *task_data = (DFITCStockEntrustOrderRtnField*)task->task_data;
		data["localOrderID"] = task_data->localOrderID;
		data["accountID"] = toUtf(task_data->accountID);
		data["sessionID"] = task_data->sessionID;
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["currency"] = toUtf(task_data->currency);
		data["securityID"] = toUtf(task_data->securityID);
		data["securityType"] = toUtf(task_data->securityType);
		data["withdrawQty"] = task_data->withdrawQty;
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["freezeFunds"] = task_data->freezeFunds;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustDirection"] = task_data->entrustDirection;
		data["declareResult"] = task_data->declareResult;
		data["noteMsg"] = toUtf(task_data->noteMsg);
		data["entrustQty"] = task_data->entrustQty;
		data["orderConfirmFlag"] = task_data->orderConfirmFlag;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["entrustPrice"] = task_data->entrustPrice;
		data["orderType"] = task_data->orderType;
		delete task_data;
	}
	this->onStockEntrustOrderRtn(data);
};

void TdApi::processStockTradeRtn(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockTradeRtnField *task_data = (DFITCStockTradeRtnField*)task->task_data;
		data["localOrderID"] = task_data->localOrderID;
		data["accountID"] = toUtf(task_data->accountID);
		data["sessionID"] = task_data->sessionID;
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["currency"] = toUtf(task_data->currency);
		data["securityID"] = toUtf(task_data->securityID);
		data["securityType"] = toUtf(task_data->securityType);
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["tradeID"] = toUtf(task_data->tradeID);
		data["tradeTime"] = toUtf(task_data->tradeTime);
		data["withdrawQty"] = task_data->withdrawQty;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustDirection"] = task_data->entrustDirection;
		data["clearFunds"] = task_data->clearFunds;
		data["totalTradeQty"] = task_data->totalTradeQty;
		data["totalTurnover"] = task_data->totalTurnover;
		data["tradeQty"] = task_data->tradeQty;
		data["tradePrice"] = task_data->tradePrice;
		data["turnover"] = task_data->turnover;
		data["entrustQty"] = task_data->entrustQty;
		data["declareResult"] = task_data->declareResult;
		data["noteMsg"] = toUtf(task_data->noteMsg);
		delete task_data;
	}
	this->onStockTradeRtn(data);
};

void TdApi::processStockWithdrawOrderRtn(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockWithdrawOrderRtnField *task_data = (DFITCStockWithdrawOrderRtnField*)task->task_data;
		data["localOrderID"] = task_data->localOrderID;
		data["accountID"] = toUtf(task_data->accountID);
		data["sessionID"] = task_data->sessionID;
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["currency"] = toUtf(task_data->currency);
		data["securityID"] = toUtf(task_data->securityID);
		data["securityType"] = toUtf(task_data->securityType);
		data["withdrawQty"] = task_data->withdrawQty;
		data["tradeQty"] = task_data->tradeQty;
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["freezeFunds"] = task_data->freezeFunds;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustDirection"] = task_data->entrustDirection;
		data["entrustQty"] = task_data->entrustQty;
		data["declareResult"] = task_data->declareResult;
		data["noteMsg"] = toUtf(task_data->noteMsg);
		delete task_data;
	}
	this->onStockWithdrawOrderRtn(data);
};

void TdApi::processRspSOPUserLogin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSECRspUserLoginField *task_data = (DFITCSECRspUserLoginField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["sessionID"] = task_data->sessionID;
		data["frontID"] = task_data->frontID;
		data["localOrderID"] = task_data->localOrderID;
		data["loginTime"] = toUtf(task_data->loginTime);
		data["tradingDay"] = task_data->tradingDay;
		data["result"] = task_data->result;
		data["rtnMsg"] = toUtf(task_data->rtnMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPUserLogin(data, error);
};

void TdApi::processRspSOPUserLogout(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSECRspUserLogoutField *task_data = (DFITCSECRspUserLogoutField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["result"] = task_data->result;
		data["rtnMsg"] = toUtf(task_data->rtnMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPUserLogout(data, error);
};

void TdApi::processRspSOPUserPasswordUpdate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSECRspPasswordUpdateField *task_data = (DFITCSECRspPasswordUpdateField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["passwordType"] = task_data->passwordType;
		data["result"] = task_data->result;
		data["rtnMsg"] = toUtf(task_data->rtnMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPUserPasswordUpdate(data, error);
};

void TdApi::processRspSOPEntrustOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspEntrustOrderField *task_data = (DFITCSOPRspEntrustOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["freezeFunds"] = task_data->freezeFunds;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPEntrustOrder(data, error);
};

void TdApi::processRspSOPQuoteEntrustOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspQuoteEntrustOrderField *task_data = (DFITCSOPRspQuoteEntrustOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["freezeFunds"] = task_data->freezeFunds;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPQuoteEntrustOrder(data, error);
};

void TdApi::processRspSOPGroupSplit(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspEntrustOrderField *task_data = (DFITCSOPRspEntrustOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["freezeFunds"] = task_data->freezeFunds;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPGroupSplit(data, error);
};

void TdApi::processRspSOPGroupExectueOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspGroupExectueOrderField *task_data = (DFITCSOPRspGroupExectueOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["freezeFunds"] = task_data->freezeFunds;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPGroupExectueOrder(data, error);
};

void TdApi::processRspSOPQryGroupPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspQryGroupPositionField *task_data = (DFITCSOPRspQryGroupPositionField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["subAccountID"] = toUtf(task_data->subAccountID);
		data["currency"] = toUtf(task_data->currency);
		data["capitalID"] = toUtf(task_data->capitalID);
		data["groupType"] = task_data->groupType;
		data["groupCode"] = toUtf(task_data->groupCode);
		data["groupQty"] = task_data->groupQty;
		data["enableSplitQty"] = task_data->enableSplitQty;
		data["splitEntrustQty"] = task_data->splitEntrustQty;
		data["splitTradeQty"] = task_data->splitTradeQty;
		data["groupDeposit"] = task_data->groupDeposit;
		data["securityOptionID1"] = toUtf(task_data->securityOptionID1);
		data["securityOptionID2"] = toUtf(task_data->securityOptionID2);
		data["securityOptionID3"] = toUtf(task_data->securityOptionID3);
		data["securityOptionID4"] = toUtf(task_data->securityOptionID4);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPQryGroupPosition(data, error, task->task_last);
};

void TdApi::processRspSOPLockOUnLockStock(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspLockOUnLockStockField *task_data = (DFITCSOPRspLockOUnLockStockField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["freezeFunds"] = task_data->freezeFunds;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPLockOUnLockStock(data, error, task->task_last);
};

void TdApi::processRspSOPWithdrawOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSECRspWithdrawOrderField *task_data = (DFITCSECRspWithdrawOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["cancelMsg"] = toUtf(task_data->cancelMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPWithdrawOrder(data, error);
};

void TdApi::processRspSOPQryEntrustOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspQryEntrustOrderField *task_data = (DFITCSOPRspQryEntrustOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["spdOrderID"] = task_data->spdOrderID;
		data["withdrawOrderID"] = toUtf(task_data->withdrawOrderID);
		data["declareOrderID"] = toUtf(task_data->declareOrderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["entrustDirection"] = task_data->entrustDirection;
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["securityOptionID"] = toUtf(task_data->securityOptionID);
		data["optType"] = task_data->optType;
		data["openCloseFlag"] = task_data->openCloseFlag;
		data["coveredFlag"] = task_data->coveredFlag;
		data["entrustQty"] = task_data->entrustQty;
		data["entrustPrice"] = task_data->entrustPrice;
		data["entrustDate"] = task_data->entrustDate;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["offerShareholderID"] = toUtf(task_data->offerShareholderID);
		data["declareDate"] = task_data->declareDate;
		data["declareTime"] = toUtf(task_data->declareTime);
		data["declareSerialID"] = task_data->declareSerialID;
		data["declareResult"] = task_data->declareResult;
		data["noteMsg"] = toUtf(task_data->noteMsg);
		data["withdrawQty"] = task_data->withdrawQty;
		data["tradeQty"] = task_data->tradeQty;
		data["turnover"] = task_data->turnover;
		data["tradePrice"] = task_data->tradePrice;
		data["currency"] = toUtf(task_data->currency);
		data["freezeFunds"] = task_data->freezeFunds;
		data["clearFunds"] = task_data->clearFunds;
		data["entrustType"] = task_data->entrustType;
		data["macAddr"] = toUtf(task_data->macAddr);
		data["ipAddr"] = toUtf(task_data->ipAddr);
		data["entrustBatchID"] = task_data->entrustBatchID;
		data["orderType"] = task_data->orderType;
		data["incQryIndex"] = toUtf(task_data->incQryIndex);
		data["capitalID"] = toUtf(task_data->capitalID);
		data["orderExpiryDate"] = task_data->orderExpiryDate;
		data["devID"] = toUtf(task_data->devID);
		data["devDecInfo"] = toUtf(task_data->devDecInfo);
		data["groupType"] = task_data->groupType;
		data["groupCode"] = toUtf(task_data->groupCode);
		data["securityOptionID1"] = toUtf(task_data->securityOptionID1);
		data["securityOptionID2"] = toUtf(task_data->securityOptionID2);
		data["securityOptionID3"] = toUtf(task_data->securityOptionID3);
		data["securityOptionID4"] = toUtf(task_data->securityOptionID4);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPQryEntrustOrder(data, error, task->task_last);
};

void TdApi::processRspSOPQrySerialTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspQrySerialTradeField *task_data = (DFITCSOPRspQrySerialTradeField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["rtnSerialID"] = task_data->rtnSerialID;
		data["securityID"] = toUtf(task_data->securityID);
		data["entrustDirection"] = task_data->entrustDirection;
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["declareOrderID"] = toUtf(task_data->declareOrderID);
		data["currency"] = toUtf(task_data->currency);
		data["tradeID"] = toUtf(task_data->tradeID);
		data["tradeTime"] = toUtf(task_data->tradeTime);
		data["tradeQty"] = task_data->tradeQty;
		data["openCloseFlag"] = task_data->openCloseFlag;
		data["coveredFlag"] = task_data->coveredFlag;
		data["spdOrderID"] = task_data->spdOrderID;
		data["turnover"] = task_data->turnover;
		data["tradePrice"] = task_data->tradePrice;
		data["clearFunds"] = task_data->clearFunds;
		data["rotationTime"] = toUtf(task_data->rotationTime);
		data["incQryIndex"] = toUtf(task_data->incQryIndex);
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["capitalID"] = toUtf(task_data->capitalID);
		data["devID"] = toUtf(task_data->devID);
		data["devDecInfo"] = toUtf(task_data->devDecInfo);
		data["groupType"] = task_data->groupType;
		data["groupCode"] = toUtf(task_data->groupCode);
		data["securityOptionID1"] = toUtf(task_data->securityOptionID1);
		data["securityOptionID2"] = toUtf(task_data->securityOptionID2);
		data["securityOptionID3"] = toUtf(task_data->securityOptionID3);
		data["securityOptionID4"] = toUtf(task_data->securityOptionID4);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPQrySerialTrade(data, error, task->task_last);
};

void TdApi::processRspSOPQryPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspQryPositionField *task_data = (DFITCSOPRspQryPositionField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["subAccountID"] = toUtf(task_data->subAccountID);
		data["securityOptionID"] = toUtf(task_data->securityOptionID);
		data["contractID"] = toUtf(task_data->contractID);
		data["contractName"] = toUtf(task_data->contractName);
		data["entrustDirection"] = task_data->entrustDirection;
		data["coveredFlag"] = task_data->coveredFlag;
		data["executeDate"] = task_data->executeDate;
		data["totalQty"] = task_data->totalQty;
		data["availableQty"] = task_data->availableQty;
		data["latestPrice"] = task_data->latestPrice;
		data["optionMarket"] = task_data->optionMarket;
		data["freezeQty"] = task_data->freezeQty;
		data["executeQty"] = task_data->executeQty;
		data["openEntrustQty"] = task_data->openEntrustQty;
		data["openTradeQty"] = task_data->openTradeQty;
		data["prePosition"] = task_data->prePosition;
		data["closeEntrustQty"] = task_data->closeEntrustQty;
		data["closeTradeQty"] = task_data->closeTradeQty;
		data["deposit"] = task_data->deposit;
		data["openDeposit"] = task_data->openDeposit;
		data["closeDeposit"] = task_data->closeDeposit;
		data["exchangeDeposit"] = task_data->exchangeDeposit;
		data["exchangeOpenDeposit"] = task_data->exchangeOpenDeposit;
		data["exchangeCloseDeposit"] = task_data->exchangeCloseDeposit;
		data["openAvgPrice"] = task_data->openAvgPrice;
		data["optType"] = task_data->optType;
		data["contractObjectType"] = task_data->contractObjectType;
		data["contractUnit"] = task_data->contractUnit;
		data["currency"] = toUtf(task_data->currency);
		data["totalTradeCost"] = task_data->totalTradeCost;
		data["tradeCost"] = task_data->tradeCost;
		data["realizeProfitLoss"] = task_data->realizeProfitLoss;
		data["profitLoss"] = task_data->profitLoss;
		data["adjustRemind"] = task_data->adjustRemind;
		data["expireRemind"] = task_data->expireRemind;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPQryPosition(data, error, task->task_last);
};

void TdApi::processRspSOPQryCollateralPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspQryCollateralPositionField *task_data = (DFITCSOPRspQryCollateralPositionField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["accountID"] = toUtf(task_data->accountID);
		data["securityID"] = toUtf(task_data->securityID);
		data["securityName"] = toUtf(task_data->securityName);
		data["availableQty"] = task_data->availableQty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPQryCollateralPosition(data, error, task->task_last);
};

void TdApi::processRspSOPQryCapitalAccountInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspQryCapitalAccountField *task_data = (DFITCSOPRspQryCapitalAccountField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["branchID"] = toUtf(task_data->branchID);
		data["currency"] = toUtf(task_data->currency);
		data["accountBanlance"] = task_data->accountBanlance;
		data["availableFunds"] = task_data->availableFunds;
		data["freezeFunds"] = task_data->freezeFunds;
		data["anticipatedInterest"] = task_data->anticipatedInterest;
		data["usedDeposit"] = task_data->usedDeposit;
		data["accountStatus"] = task_data->accountStatus;
		data["totalFunds"] = task_data->totalFunds;
		data["totalMarket"] = task_data->totalMarket;
		data["cashAssets"] = task_data->cashAssets;
		data["execGuaranteeRatio"] = task_data->execGuaranteeRatio;
		data["buyLimits"] = task_data->buyLimits;
		data["desirableFunds"] = task_data->desirableFunds;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPQryCapitalAccountInfo(data, error);
};

void TdApi::processRspSOPQryAccountInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspQryAccountField *task_data = (DFITCSOPRspQryAccountField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["accountName"] = toUtf(task_data->accountName);
		data["accountFullName"] = toUtf(task_data->accountFullName);
		data["branchID"] = toUtf(task_data->branchID);
		data["identityType"] = task_data->identityType;
		data["accountIdentityID"] = toUtf(task_data->accountIdentityID);
		data["tel"] = toUtf(task_data->tel);
		data["mobile"] = toUtf(task_data->mobile);
		data["accountType"] = task_data->accountType;
		data["accountProp"] = task_data->accountProp;
		data["tradePermissions"] = task_data->tradePermissions;
		data["entrustType"] = task_data->entrustType;
		data["accountStatus"] = task_data->accountStatus;
		data["pwdSynFlag"] = task_data->pwdSynFlag;
		data["accountNodeID"] = task_data->accountNodeID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPQryAccountInfo(data, error);
};

void TdApi::processRspSOPQryShareholderInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspQryShareholderField *task_data = (DFITCSOPRspQryShareholderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["branchID"] = toUtf(task_data->branchID);
		data["currency"] = toUtf(task_data->currency);
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["tradePermissions"] = task_data->tradePermissions;
		data["shareholderSpecProp"] = task_data->shareholderSpecProp;
		data["shareholderCtlProp"] = task_data->shareholderCtlProp;
		data["shareholderStatus"] = task_data->shareholderStatus;
		data["mainAccountFlag"] = task_data->mainAccountFlag;
		data["exchangeID"] = toUtf(task_data->exchangeID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPQryShareholderInfo(data, error);
};

void TdApi::processRspSOPCalcAbleEntrustQty(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspCalcAbleEntrustQtyField *task_data = (DFITCSOPRspCalcAbleEntrustQtyField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityOptionID"] = toUtf(task_data->securityOptionID);
		data["entrustQty"] = task_data->entrustQty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPCalcAbleEntrustQty(data, error);
};

void TdApi::processRspSOPQryAbleLockStock(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspQryAbleLockStockField *task_data = (DFITCSOPRspQryAbleLockStockField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["securityName"] = toUtf(task_data->securityName);
		data["securityQty"] = task_data->securityQty;
		data["position"] = task_data->position;
		data["avgPositionPrice"] = task_data->avgPositionPrice;
		data["dilutedCost"] = task_data->dilutedCost;
		data["breakevenPrice"] = task_data->breakevenPrice;
		data["dilutedBreakevenPrice"] = task_data->dilutedBreakevenPrice;
		data["ableSellQty"] = task_data->ableSellQty;
		data["latestMarket"] = task_data->latestMarket;
		data["latestPrice"] = task_data->latestPrice;
		data["floatProfitLoss"] = task_data->floatProfitLoss;
		data["dilutedFloatProfitLoss"] = task_data->dilutedFloatProfitLoss;
		data["tradeUnit"] = task_data->tradeUnit;
		data["openBuyQty"] = task_data->openBuyQty;
		data["openSellQty"] = task_data->openSellQty;
		data["buyUnSettleQty"] = task_data->buyUnSettleQty;
		data["sellUnSettleQty"] = task_data->sellUnSettleQty;
		data["openEntrustSellQty"] = task_data->openEntrustSellQty;
		data["ableLockQty"] = task_data->ableLockQty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPQryAbleLockStock(data, error, task->task_last);
};

void TdApi::processRspSOPQryContactInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspQryContactField *task_data = (DFITCSOPRspQryContactField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityOptionID"] = toUtf(task_data->securityOptionID);
		data["contractID"] = toUtf(task_data->contractID);
		data["contractName"] = toUtf(task_data->contractName);
		data["securityID"] = toUtf(task_data->securityID);
		data["contractObjectType"] = task_data->contractObjectType;
		data["execType"] = task_data->execType;
		data["deliType"] = task_data->deliType;
		data["optType"] = task_data->optType;
		data["contactUnit"] = task_data->contactUnit;
		data["latestPrice"] = task_data->latestPrice;
		data["beginTradingDay"] = task_data->beginTradingDay;
		data["endTradingDay"] = task_data->endTradingDay;
		data["execDate"] = task_data->execDate;
		data["endDate"] = task_data->endDate;
		data["positionUpLimit"] = task_data->positionUpLimit;
		data["priceUpLimit"] = task_data->priceUpLimit;
		data["priceDownLimit"] = task_data->priceDownLimit;
		data["priceHigher"] = task_data->priceHigher;
		data["priceLower"] = task_data->priceLower;
		data["entrustUpLimit"] = task_data->entrustUpLimit;
		data["entrustDownLimit"] = task_data->entrustDownLimit;
		data["entrustUpLimitMarketPri"] = task_data->entrustUpLimitMarketPri;
		data["entrustDownLimitMarketPri"] = task_data->entrustDownLimitMarketPri;
		data["openLimit"] = task_data->openLimit;
		data["stockTradeFlag"] = task_data->stockTradeFlag;
		data["depositUnit"] = task_data->depositUnit;
		data["depositRatioC"] = task_data->depositRatioC;
		data["depositRatioE"] = task_data->depositRatioE;
		data["preClosePrice"] = task_data->preClosePrice;
		data["closePrice"] = task_data->closePrice;
		data["preSettlePrice"] = task_data->preSettlePrice;
		data["openPrice"] = task_data->openPrice;
		data["tradeQty"] = task_data->tradeQty;
		data["turnover"] = task_data->turnover;
		data["settlePrice"] = task_data->settlePrice;
		data["endCashSettlePrice"] = task_data->endCashSettlePrice;
		data["handQty"] = task_data->handQty;
		data["unClosePositionQty"] = task_data->unClosePositionQty;
		data["approachExpireFlag"] = task_data->approachExpireFlag;
		data["tempAdjustFlag"] = task_data->tempAdjustFlag;
		data["stockListFlag"] = toUtf(task_data->stockListFlag);
		data["execPrice"] = task_data->execPrice;
		data["bidPrice1"] = task_data->bidPrice1;
		data["bidQty1"] = task_data->bidQty1;
		data["bidPrice2"] = task_data->bidPrice2;
		data["bidQty2"] = task_data->bidQty2;
		data["bidPrice3"] = task_data->bidPrice3;
		data["bidQty3"] = task_data->bidQty3;
		data["bidPrice4"] = task_data->bidPrice4;
		data["bidQty4"] = task_data->bidQty4;
		data["bidPrice5"] = task_data->bidPrice5;
		data["bidQty5"] = task_data->bidQty5;
		data["askPrice1"] = task_data->askPrice1;
		data["askQty1"] = task_data->askQty1;
		data["askPrice2"] = task_data->askPrice2;
		data["askQty2"] = task_data->askQty2;
		data["askPrice3"] = task_data->askPrice3;
		data["askQty3"] = task_data->askQty3;
		data["askPrice4"] = task_data->askPrice4;
		data["askQty4"] = task_data->askQty4;
		data["askPrice5"] = task_data->askPrice5;
		data["askQty5"] = task_data->askQty5;
		data["optionIndex"] = toUtf(task_data->optionIndex);
		data["miniPriceChange"] = task_data->miniPriceChange;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPQryContactInfo(data, error, task->task_last);
};

void TdApi::processRspSOPExectueOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspExectueOrderField *task_data = (DFITCSOPRspExectueOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["freezeFunds"] = task_data->freezeFunds;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPExectueOrder(data, error);
};

void TdApi::processRspSOPQryExecAssiInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspQryExecAssiInfoField *task_data = (DFITCSOPRspQryExecAssiInfoField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["tradeDate"] = task_data->tradeDate;
		data["branchID"] = toUtf(task_data->branchID);
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["subAccountID"] = toUtf(task_data->subAccountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["currency"] = toUtf(task_data->currency);
		data["optType"] = task_data->optType;
		data["contractObjectType"] = task_data->contractObjectType;
		data["coveredFlag"] = task_data->coveredFlag;
		data["securityOptionID"] = toUtf(task_data->securityOptionID);
		data["entrustDirection"] = task_data->entrustDirection;
		data["securityID"] = toUtf(task_data->securityID);
		data["seatID"] = toUtf(task_data->seatID);
		data["execPrice"] = task_data->execPrice;
		data["execQty"] = task_data->execQty;
		data["tradeQty"] = task_data->tradeQty;
		data["clearFunds"] = task_data->clearFunds;
		data["settleFunds"] = task_data->settleFunds;
		data["commission"] = task_data->commission;
		data["stampTax"] = task_data->stampTax;
		data["transferFee"] = task_data->transferFee;
		data["fee3"] = task_data->fee3;
		data["fee4"] = task_data->fee4;
		data["summaryMsg"] = toUtf(task_data->summaryMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPQryExecAssiInfo(data, error, task->task_last);
};

void TdApi::processRspSOPQryTradeTime(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspQryTradeTimeField *task_data = (DFITCSOPRspQryTradeTimeField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["sysTradingDay"] = task_data->sysTradingDay;
		data["sysTime"] = toUtf(task_data->sysTime);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPQryTradeTime(data, error, task->task_last);
};

void TdApi::processRspSOPQryExchangeInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspQryExchangeInfoField *task_data = (DFITCSOPRspQryExchangeInfoField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["exchangeName"] = toUtf(task_data->exchangeName);
		data["callauctionBegining"] = toUtf(task_data->callauctionBegining);
		data["callauctionEnding"] = toUtf(task_data->callauctionEnding);
		data["morningOpening"] = toUtf(task_data->morningOpening);
		data["morningClosing"] = toUtf(task_data->morningClosing);
		data["afternoonOpening"] = toUtf(task_data->afternoonOpening);
		data["afternoonClosing"] = toUtf(task_data->afternoonClosing);
		data["execOpening"] = toUtf(task_data->execOpening);
		data["execClosing"] = toUtf(task_data->execClosing);
		data["nightTradeFlag"] = task_data->nightTradeFlag;
		data["nightOpening"] = toUtf(task_data->nightOpening);
		data["nightClosing"] = toUtf(task_data->nightClosing);
		data["stockTradeStatus"] = task_data->stockTradeStatus;
		data["currency"] = toUtf(task_data->currency);
		data["tradingDayFlag"] = task_data->tradingDayFlag;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPQryExchangeInfo(data, error, task->task_last);
};

void TdApi::processRspSOPQryCommission(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspQryCommissionField *task_data = (DFITCSOPRspQryCommissionField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["refType"] = task_data->refType;
		data["contractObjectType"] = task_data->contractObjectType;
		data["securityID"] = toUtf(task_data->securityID);
		data["openCloseFlag"] = task_data->openCloseFlag;
		data["entrustDirection"] = task_data->entrustDirection;
		data["level"] = task_data->level;
		data["costRatio1"] = task_data->costRatio1;
		data["unitCost1"] = task_data->unitCost1;
		data["costUpLimit1"] = task_data->costUpLimit1;
		data["costDonwLimit1"] = task_data->costDonwLimit1;
		data["costRatio2"] = task_data->costRatio2;
		data["unitCost2"] = task_data->unitCost2;
		data["costUpLimit2"] = task_data->costUpLimit2;
		data["costDonwLimit2"] = task_data->costDonwLimit2;
		data["costRatio3"] = task_data->costRatio3;
		data["unitCost3"] = task_data->unitCost3;
		data["costRatio4"] = task_data->costRatio4;
		data["unitCost4"] = task_data->unitCost4;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPQryCommission(data, error, task->task_last);
};

void TdApi::processRspSOPQryDeposit(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspQryDepositField *task_data = (DFITCSOPRspQryDepositField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["refType"] = task_data->refType;
		data["securityObjectType"] = task_data->securityObjectType;
		data["securityID"] = toUtf(task_data->securityID);
		data["depositRateC"] = task_data->depositRateC;
		data["depositRateE"] = task_data->depositRateE;
		data["depositUnit"] = task_data->depositUnit;
		data["calcType"] = task_data->calcType;
		data["level"] = task_data->level;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPQryDeposit(data, error, task->task_last);
};

void TdApi::processRspSOPQryContractObjectInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspQryContractObjectField *task_data = (DFITCSOPRspQryContractObjectField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityName"] = toUtf(task_data->securityName);
		data["securityID"] = toUtf(task_data->securityID);
		data["contractObjectType"] = task_data->contractObjectType;
		data["contractObjectStatus"] = task_data->contractObjectStatus;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPQryContractObjectInfo(data, error, task->task_last);
};

void TdApi::processSOPEntrustOrderRtn(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPEntrustOrderRtnField *task_data = (DFITCSOPEntrustOrderRtnField*)task->task_data;
		data["localOrderID"] = task_data->localOrderID;
		data["accountID"] = toUtf(task_data->accountID);
		data["sessionID"] = task_data->sessionID;
		data["branchID"] = toUtf(task_data->branchID);
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["currency"] = toUtf(task_data->currency);
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustDirection"] = task_data->entrustDirection;
		data["openCloseFlag"] = task_data->openCloseFlag;
		data["entrustPrice"] = task_data->entrustPrice;
		data["entrustQty"] = task_data->entrustQty;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["coveredFlag"] = task_data->coveredFlag;
		data["orderType"] = task_data->orderType;
		data["orderExpiryDate"] = task_data->orderExpiryDate;
		data["orderCategory"] = task_data->orderCategory;
		data["declareResult"] = task_data->declareResult;
		data["noteMsg"] = toUtf(task_data->noteMsg);
		data["devID"] = toUtf(task_data->devID);
		data["devDecInfo"] = toUtf(task_data->devDecInfo);
		data["groupType"] = task_data->groupType;
		data["groupCode"] = toUtf(task_data->groupCode);
		data["securityOptionID1"] = toUtf(task_data->securityOptionID1);
		data["securityOptionID2"] = toUtf(task_data->securityOptionID2);
		data["securityOptionID3"] = toUtf(task_data->securityOptionID3);
		data["securityOptionID4"] = toUtf(task_data->securityOptionID4);
		delete task_data;
	}
	this->onSOPEntrustOrderRtn(data);
};

void TdApi::processSOPTradeRtn(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPTradeRtnField *task_data = (DFITCSOPTradeRtnField*)task->task_data;
		data["localOrderID"] = task_data->localOrderID;
		data["accountID"] = toUtf(task_data->accountID);
		data["sessionID"] = task_data->sessionID;
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["currency"] = toUtf(task_data->currency);
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustDirection"] = task_data->entrustDirection;
		data["openCloseFlag"] = task_data->openCloseFlag;
		data["coveredFlag"] = task_data->coveredFlag;
		data["orderCategory"] = task_data->orderCategory;
		data["tradePrice"] = task_data->tradePrice;
		data["tradeQty"] = task_data->tradeQty;
		data["tradeID"] = toUtf(task_data->tradeID);
		data["rtnSerialID"] = task_data->rtnSerialID;
		data["declareOrderID"] = toUtf(task_data->declareOrderID);
		data["declareResult"] = task_data->declareResult;
		data["noteMsg"] = toUtf(task_data->noteMsg);
		data["devID"] = toUtf(task_data->devID);
		data["devDecInfo"] = toUtf(task_data->devDecInfo);
		data["tradeTime"] = toUtf(task_data->tradeTime);
		data["groupCode"] = toUtf(task_data->groupCode);
		data["groupType"] = task_data->groupType;
		data["securityOptionID1"] = toUtf(task_data->securityOptionID1);
		data["securityOptionID2"] = toUtf(task_data->securityOptionID2);
		data["securityOptionID3"] = toUtf(task_data->securityOptionID3);
		data["securityOptionID4"] = toUtf(task_data->securityOptionID4);
		delete task_data;
	}
	this->onSOPTradeRtn(data);
};

void TdApi::processSOPWithdrawOrderRtn(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPWithdrawOrderRtnField *task_data = (DFITCSOPWithdrawOrderRtnField*)task->task_data;
		data["localOrderID"] = task_data->localOrderID;
		data["accountID"] = toUtf(task_data->accountID);
		data["sessionID"] = task_data->sessionID;
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["currency"] = toUtf(task_data->currency);
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustDirection"] = task_data->entrustDirection;
		data["openCloseFlag"] = task_data->openCloseFlag;
		data["withdrawQty"] = task_data->withdrawQty;
		data["tradeQty"] = task_data->tradeQty;
		data["declareResult"] = task_data->declareResult;
		data["noteMsg"] = toUtf(task_data->noteMsg);
		data["wdUnFreezeFunds"] = task_data->wdUnFreezeFunds;
		data["devID"] = toUtf(task_data->devID);
		data["devDecInfo"] = toUtf(task_data->devDecInfo);
		data["groupCode"] = toUtf(task_data->groupCode);
		data["securityOptionID1"] = toUtf(task_data->securityOptionID1);
		data["securityOptionID2"] = toUtf(task_data->securityOptionID2);
		delete task_data;
	}
	this->onSOPWithdrawOrderRtn(data);
};

void TdApi::processSOPQuoteEntrustOrderRtn(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPQuoteEntrustOrderRtnField *task_data = (DFITCSOPQuoteEntrustOrderRtnField*)task->task_data;
		data["localOrderID"] = task_data->localOrderID;
		data["accountID"] = toUtf(task_data->accountID);
		data["sessionID"] = task_data->sessionID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["branchID"] = toUtf(task_data->branchID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["subAccountID"] = toUtf(task_data->subAccountID);
		data["securityID"] = toUtf(task_data->securityID);
		data["trusteeshipUnit"] = toUtf(task_data->trusteeshipUnit);
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["tradeID"] = toUtf(task_data->tradeID);
		data["tradeTime"] = toUtf(task_data->tradeTime);
		data["currency"] = toUtf(task_data->currency);
		data["withdrawOrderID"] = task_data->withdrawOrderID;
		data["devID"] = toUtf(task_data->devID);
		data["devDecInfo"] = toUtf(task_data->devDecInfo);
		data["bidEntrustDirection"] = task_data->bidEntrustDirection;
		data["bidOpenCloseFlag"] = task_data->bidOpenCloseFlag;
		data["bidCoveredFlag"] = task_data->bidCoveredFlag;
		data["bidQty"] = task_data->bidQty;
		data["bidPrice"] = task_data->bidPrice;
		data["bidTransactionAmount"] = task_data->bidTransactionAmount;
		data["bidDeclareResult"] = task_data->bidDeclareResult;
		data["bidNoteMsg"] = toUtf(task_data->bidNoteMsg);
		data["askEntrustDirection"] = task_data->askEntrustDirection;
		data["askOpenCloseFlag"] = task_data->askOpenCloseFlag;
		data["askCoveredFlag"] = task_data->askCoveredFlag;
		data["askQty"] = task_data->askQty;
		data["askPrice"] = task_data->askPrice;
		data["askTransactionAmount"] = task_data->askTransactionAmount;
		data["askDeclareResult"] = task_data->askDeclareResult;
		data["askNoteMsg"] = toUtf(task_data->askNoteMsg);
		delete task_data;
	}
	this->onSOPQuoteEntrustOrderRtn(data);
};

void TdApi::processRspSOPCapitalTranInOut(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspCapitalTranInOutField *task_data = (DFITCSOPRspCapitalTranInOutField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["serialID"] = toUtf(task_data->serialID);
		data["accountBanlance"] = task_data->accountBanlance;
		data["availableFunds"] = task_data->availableFunds;
		data["t2AvailableFunds"] = task_data->t2AvailableFunds;
		data["desirableFunds"] = task_data->desirableFunds;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPCapitalTranInOut(data, error);
};

void TdApi::processRspSOPCapitalDistributionRatio(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspQryCapitalDistributionRatioField *task_data = (DFITCSOPRspQryCapitalDistributionRatioField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["capitalID"] = toUtf(task_data->capitalID);
		data["currency"] = toUtf(task_data->currency);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["nodeID"] = task_data->nodeID;
		data["distributionRatio"] = task_data->distributionRatio;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPCapitalDistributionRatio(data, error, task->task_last);
};

void TdApi::processRspSOPFundTransBetweenNodes(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspFundTransBetweenNodesField *task_data = (DFITCSOPRspFundTransBetweenNodesField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["serialID"] = toUtf(task_data->serialID);
		data["rtnMsg"] = toUtf(task_data->rtnMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPFundTransBetweenNodes(data, error);
};

void TdApi::processRspSOPModCapitalDistributionRatio(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSOPRspModCapitalDistributionRatioField *task_data = (DFITCSOPRspModCapitalDistributionRatioField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["rtnMsg"] = toUtf(task_data->rtnMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspSOPModCapitalDistributionRatio(data, error);
};

void TdApi::processRspFASLUserLogin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSECRspUserLoginField *task_data = (DFITCSECRspUserLoginField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["sessionID"] = task_data->sessionID;
		data["frontID"] = task_data->frontID;
		data["localOrderID"] = task_data->localOrderID;
		data["loginTime"] = toUtf(task_data->loginTime);
		data["tradingDay"] = task_data->tradingDay;
		data["result"] = task_data->result;
		data["rtnMsg"] = toUtf(task_data->rtnMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLUserLogin(data, error);
};

void TdApi::processRspFASLUserLogout(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSECRspUserLogoutField *task_data = (DFITCSECRspUserLogoutField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["result"] = task_data->result;
		data["rtnMsg"] = toUtf(task_data->rtnMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLUserLogout(data, error);
};

void TdApi::processRspFASLQryAbleFinInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspAbleFinInfoField *task_data = (DFITCFASLRspAbleFinInfoField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["sourceContract"] = task_data->sourceContract;
		data["contractNO"] = toUtf(task_data->contractNO);
		data["positionSize"] = task_data->positionSize;
		data["meltOutFunds"] = task_data->meltOutFunds;
		data["subscribeFunds"] = task_data->subscribeFunds;
		data["meltOutFreezeFunds"] = task_data->meltOutFreezeFunds;
		data["repayFunds"] = task_data->repayFunds;
		data["temFreezeFunds"] = task_data->temFreezeFunds;
		data["availableFunds"] = task_data->availableFunds;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryAbleFinInfo(data, error);
};

void TdApi::processRspFASLQryAbleSloInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspAbleSloInfoField *task_data = (DFITCFASLRspAbleSloInfoField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["securityID"] = toUtf(task_data->securityID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["ableSloQty"] = task_data->ableSloQty;
		data["securityName"] = toUtf(task_data->securityName);
		data["sellEntrustQty"] = task_data->sellEntrustQty;
		data["tradeQty"] = task_data->tradeQty;
		data["sloDepositRatio"] = task_data->sloDepositRatio;
		data["securityQty"] = task_data->securityQty;
		data["stockTradeStatus"] = task_data->stockTradeStatus;
		data["sourceContract"] = task_data->sourceContract;
		data["freezeQty"] = task_data->freezeQty;
		data["repayQty"] = task_data->repayQty;
		data["meltOutQty"] = task_data->meltOutQty;
		data["subscribeQty"] = task_data->subscribeQty;
		data["rowIndex"] = task_data->rowIndex;
		data["exchangRate"] = task_data->exchangRate;
		data["drawOutRepayQty"] = task_data->drawOutRepayQty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryAbleSloInfo(data, error, task->task_last);
};

void TdApi::processRspFASLTransferCollateral(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspTransferCollateralField *task_data = (DFITCFASLRspTransferCollateralField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["spdOrderID"] = task_data->spdOrderID;
		data["localOrderID"] = task_data->localOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["entrustMsg"] = toUtf(task_data->entrustMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLTransferCollateral(data, error);
};

void TdApi::processRspFASLDirectRepayment(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspDirectRepaymentField *task_data = (DFITCFASLRspDirectRepaymentField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["realRepayFunds"] = task_data->realRepayFunds;
		data["spdOrderID"] = task_data->spdOrderID;
		data["localOrderID"] = task_data->localOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLDirectRepayment(data, error);
};

void TdApi::processRspFASLRepayStockTransfer(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspRepayStockTransferField *task_data = (DFITCFASLRspRepayStockTransferField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["spdOrderID"] = task_data->spdOrderID;
		data["localOrderID"] = task_data->localOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLRepayStockTransfer(data, error);
};

void TdApi::processRspFASLEntrustCrdtOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspEntrustCrdtOrderField *task_data = (DFITCFASLRspEntrustCrdtOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["spdOrderID"] = task_data->spdOrderID;
		data["localOrderID"] = task_data->localOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["freezeFunds"] = task_data->freezeFunds;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLEntrustCrdtOrder(data, error);
};

void TdApi::processRspFASLEntrustOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspEntrustOrderField *task_data = (DFITCFASLRspEntrustOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["freezeFunds"] = task_data->freezeFunds;
		data["contractNO"] = toUtf(task_data->contractNO);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLEntrustOrder(data, error);
};

void TdApi::processRspFASLCalcAbleEntrustCrdtQty(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspCalcAbleEntrustCrdtQtyField *task_data = (DFITCFASLRspCalcAbleEntrustCrdtQtyField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["totalRepayQty"] = task_data->totalRepayQty;
		data["entrustQty"] = task_data->entrustQty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLCalcAbleEntrustCrdtQty(data, error);
};

void TdApi::processRspFASLQryCrdtFunds(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQryCrdtFundsField *task_data = (DFITCFASLRspQryCrdtFundsField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["availableDeposit"] = task_data->availableDeposit;
		data["maintGuaranteeRatio"] = task_data->maintGuaranteeRatio;
		data["antiMaintGuaranteeRatio"] = task_data->antiMaintGuaranteeRatio;
		data["accountBanlance"] = task_data->accountBanlance;
		data["availableFunds"] = task_data->availableFunds;
		data["clearFunds"] = task_data->clearFunds;
		data["stockMarket"] = task_data->stockMarket;
		data["guaranteeStockSubMarket"] = task_data->guaranteeStockSubMarket;
		data["guaranteeStockMarket"] = task_data->guaranteeStockMarket;
		data["tradeFinLiabilities"] = task_data->tradeFinLiabilities;
		data["tradeSloLiabilities"] = task_data->tradeSloLiabilities;
		data["orderFinLiabilities"] = task_data->orderFinLiabilities;
		data["orderSloLiabilities"] = task_data->orderSloLiabilities;
		data["sloOrderRepay"] = task_data->sloOrderRepay;
		data["fundsBalance"] = task_data->fundsBalance;
		data["closeFunds"] = task_data->closeFunds;
		data["activeCloseFunds"] = task_data->activeCloseFunds;
		data["ableWithdrawalAssetsStand"] = task_data->ableWithdrawalAssetsStand;
		data["totalAssets"] = task_data->totalAssets;
		data["totalLiabilities"] = task_data->totalLiabilities;
		data["netAssets"] = task_data->netAssets;
		data["anticipatedInterest"] = task_data->anticipatedInterest;
		data["finProfitLoss"] = task_data->finProfitLoss;
		data["sloProfitLoss"] = task_data->sloProfitLoss;
		data["sloFunds"] = task_data->sloFunds;
		data["finCost"] = task_data->finCost;
		data["sloCost"] = task_data->sloCost;
		data["finUsedDeposit"] = task_data->finUsedDeposit;
		data["sloUsedDeposit"] = task_data->sloUsedDeposit;
		data["finAntiInterest"] = task_data->finAntiInterest;
		data["sloAntiInterest"] = task_data->sloAntiInterest;
		data["contractEndDate"] = task_data->contractEndDate;
		data["finUsedLimits"] = task_data->finUsedLimits;
		data["sloUsedLimits"] = task_data->sloUsedLimits;
		data["finCreditLimits"] = task_data->finCreditLimits;
		data["sloCreditLimits"] = task_data->sloCreditLimits;
		data["ableBuyCollateralFunds"] = task_data->ableBuyCollateralFunds;
		data["sloAvailableFunds"] = task_data->sloAvailableFunds;
		data["cashAssets"] = task_data->cashAssets;
		data["finContractFunds"] = task_data->finContractFunds;
		data["contractObjectMarket"] = task_data->contractObjectMarket;
		data["otherCharges"] = task_data->otherCharges;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryCrdtFunds(data, error, task->task_last);
};

void TdApi::processRspFASLQryCrdtContract(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQryCrdtContractField *task_data = (DFITCFASLRspQryCrdtContractField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["specifycontractNO"] = toUtf(task_data->specifycontractNO);
		data["operatorDate"] = task_data->operatorDate;
		data["endDate"] = task_data->endDate;
		data["spdOrderID"] = task_data->spdOrderID;
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["securityName"] = toUtf(task_data->securityName);
		data["repaidInterest"] = task_data->repaidInterest;
		data["crdtConStatus"] = task_data->crdtConStatus;
		data["entrustQty"] = task_data->entrustQty;
		data["conInitQty"] = task_data->conInitQty;
		data["conInitFunds"] = task_data->conInitFunds;
		data["conInitCost"] = task_data->conInitCost;
		data["contractNO3"] = toUtf(task_data->contractNO3);
		data["sourceContract"] = task_data->sourceContract;
		data["contractNO"] = toUtf(task_data->contractNO);
		data["contractNO2"] = toUtf(task_data->contractNO2);
		data["operatorTime"] = toUtf(task_data->operatorTime);
		data["tradingDate"] = task_data->tradingDate;
		data["timeLimit"] = task_data->timeLimit;
		data["dueDate"] = task_data->dueDate;
		data["realtimeFunds"] = task_data->realtimeFunds;
		data["contractNOIndex"] = toUtf(task_data->contractNOIndex);
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["contractType"] = task_data->contractType;
		data["entrustPrice"] = task_data->entrustPrice;
		data["tradeQty"] = task_data->tradeQty;
		data["turnover"] = task_data->turnover;
		data["tradePrice"] = task_data->tradePrice;
		data["conCost"] = task_data->conCost;
		data["repayFunds"] = task_data->repayFunds;
		data["repayCost"] = task_data->repayCost;
		data["repayPenaltyInterest"] = task_data->repayPenaltyInterest;
		data["repayQty"] = task_data->repayQty;
		data["conInitInterest"] = task_data->conInitInterest;
		data["conInitPenaltyInterest"] = task_data->conInitPenaltyInterest;
		data["realtimeConCost"] = task_data->realtimeConCost;
		data["realtimeInterest"] = task_data->realtimeInterest;
		data["realtimePenaltyInterest"] = task_data->realtimePenaltyInterest;
		data["realtimeQty"] = task_data->realtimeQty;
		data["ratio"] = task_data->ratio;
		data["penaltyInterestRatio"] = task_data->penaltyInterestRatio;
		data["interestBase"] = task_data->interestBase;
		data["segmentInterest"] = task_data->segmentInterest;
		data["anticipatedInterest"] = task_data->anticipatedInterest;
		data["penaltyInterestBase"] = task_data->penaltyInterestBase;
		data["anticipatedPenaltyInterest"] = task_data->anticipatedPenaltyInterest;
		data["depositRatio"] = task_data->depositRatio;
		data["exhibitionTimes"] = task_data->exhibitionTimes;
		data["usedLimitsFreezeFlag"] = task_data->usedLimitsFreezeFlag;
		data["compensateQty"] = task_data->compensateQty;
		data["compensateFunds"] = task_data->compensateFunds;
		data["interestSettlementMethod"] = task_data->interestSettlementMethod;
		data["arrearsFlag"] = task_data->arrearsFlag;
		data["outstandingSecuritiesFlag"] = task_data->outstandingSecuritiesFlag;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryCrdtContract(data, error, task->task_last);
};

void TdApi::processRspFASLQryCrdtConChangeInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQryCrdtConChangeInfoField *task_data = (DFITCFASLRspQryCrdtConChangeInfoField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["serialNO"] = task_data->serialNO;
		data["conChangeNO"] = toUtf(task_data->conChangeNO);
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["rtnSerialID"] = task_data->rtnSerialID;
		data["securityID"] = toUtf(task_data->securityID);
		data["entrustDirection"] = task_data->entrustDirection;
		data["operatorFunds"] = task_data->operatorFunds;
		data["operatorTime"] = toUtf(task_data->operatorTime);
		data["operatorQty"] = task_data->operatorQty;
		data["operatorDate"] = task_data->operatorDate;
		data["tradeDate"] = task_data->tradeDate;
		data["changeType"] = task_data->changeType;
		data["contractType"] = task_data->contractType;
		data["clearFlag"] = task_data->clearFlag;
		data["postContractFunds"] = task_data->postContractFunds;
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["changeNote"] = toUtf(task_data->changeNote);
		data["contractNO"] = toUtf(task_data->contractNO);
		data["spdOrderID"] = task_data->spdOrderID;
		data["contractExchangeID"] = toUtf(task_data->contractExchangeID);
		data["contractSecurityID"] = toUtf(task_data->contractSecurityID);
		data["postConQty"] = task_data->postConQty;
		data["operatorInterest"] = task_data->operatorInterest;
		data["postInterest"] = task_data->postInterest;
		data["operatorPenaltyInterest"] = task_data->operatorPenaltyInterest;
		data["postPenaltyInterest"] = task_data->postPenaltyInterest;
		data["designatedRepaymentFlag"] = task_data->designatedRepaymentFlag;
		data["forceClosePositionFlag"] = task_data->forceClosePositionFlag;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryCrdtConChangeInfo(data, error, task->task_last);
};

void TdApi::processRspFASLTransferFunds(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspTransferFundsField *task_data = (DFITCFASLRspTransferFundsField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["serialID"] = task_data->serialID;
		data["accountBanlance"] = task_data->accountBanlance;
		data["availableFunds"] = task_data->availableFunds;
		data["fundsTransFlag"] = task_data->fundsTransFlag;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLTransferFunds(data, error);
};

void TdApi::processRspFASLTransferStock(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspTransferStockField *task_data = (DFITCFASLRspTransferStockField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["serialID"] = task_data->serialID;
		data["returnMsg"] = toUtf(task_data->returnMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLTransferStock(data, error);
};

void TdApi::processRspFASLQryAccountInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQryAccountField *task_data = (DFITCFASLRspQryAccountField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["accountName"] = toUtf(task_data->accountName);
		data["accountIdentityID"] = toUtf(task_data->accountIdentityID);
		data["accountIdentityType"] = task_data->accountIdentityType;
		data["branchID"] = toUtf(task_data->branchID);
		data["mobile"] = toUtf(task_data->mobile);
		data["entrustType"] = task_data->entrustType;
		data["accountStatus"] = task_data->accountStatus;
		data["pwdSynFlag"] = task_data->pwdSynFlag;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryAccountInfo(data, error);
};

void TdApi::processRspFASLQryCapitalAccountInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQryCapitalAccountField *task_data = (DFITCFASLRspQryCapitalAccountField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["currency"] = toUtf(task_data->currency);
		data["availableFunds"] = task_data->availableFunds;
		data["t2AvailableFunds"] = task_data->t2AvailableFunds;
		data["anticipatedInterest"] = task_data->anticipatedInterest;
		data["accountBalance"] = task_data->accountBalance;
		data["accountStatus"] = task_data->accountStatus;
		data["accountID"] = toUtf(task_data->accountID);
		data["capitalID"] = toUtf(task_data->capitalID);
		data["freezeFunds"] = task_data->freezeFunds;
		data["t2FreezeFunds"] = task_data->t2FreezeFunds;
		data["totalFunds"] = task_data->totalFunds;
		data["totalMarket"] = task_data->totalMarket;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryCapitalAccountInfo(data, error, task->task_last);
};

void TdApi::processRspFASLQryShareholderInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQryShareholderField *task_data = (DFITCFASLRspQryShareholderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["account"] = toUtf(task_data->account);
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["shareholderSpecProp"] = task_data->shareholderSpecProp;
		data["tradePermissions"] = task_data->tradePermissions;
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["shareholderStatus"] = task_data->shareholderStatus;
		data["mainAccountFlag"] = task_data->mainAccountFlag;
		data["shareholderCtlProp"] = task_data->shareholderCtlProp;
		data["shareholderType"] = task_data->shareholderType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryShareholderInfo(data, error, task->task_last);
};

void TdApi::processRspFASLQryPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQryPositionField *task_data = (DFITCFASLRspQryPositionField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["currency"] = toUtf(task_data->currency);
		data["sellTurnover"] = task_data->sellTurnover;
		data["sellTradeQty"] = task_data->sellTradeQty;
		data["sellEntrustQty"] = task_data->sellEntrustQty;
		data["buyTurnover"] = task_data->buyTurnover;
		data["buyTradeQty"] = task_data->buyTradeQty;
		data["buyEntrustQty"] = task_data->buyEntrustQty;
		data["nonCirculateQty"] = task_data->nonCirculateQty;
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["openDate"] = task_data->openDate;
		data["ableSellQty"] = task_data->ableSellQty;
		data["securityID"] = toUtf(task_data->securityID);
		data["securityType"] = toUtf(task_data->securityType);
		data["securityName"] = toUtf(task_data->securityName);
		data["securityQty"] = task_data->securityQty;
		data["position"] = task_data->position;
		data["unSettleQty"] = task_data->unSettleQty;
		data["changeDate"] = task_data->changeDate;
		data["ablePurchaseQty"] = task_data->ablePurchaseQty;
		data["ableRedemptionQty"] = task_data->ableRedemptionQty;
		data["freezeQty"] = task_data->freezeQty;
		data["offsetSQty"] = task_data->offsetSQty;
		data["offsetBQty"] = task_data->offsetBQty;
		data["purchaseTradeQty"] = task_data->purchaseTradeQty;
		data["redemptionTradeQty"] = task_data->redemptionTradeQty;
		data["tradeUnit"] = task_data->tradeUnit;
		data["totalSellQty"] = task_data->totalSellQty;
		data["totalBuyQty"] = task_data->totalBuyQty;
		data["rationedSharesQty"] = task_data->rationedSharesQty;
		data["purchaseQty"] = task_data->purchaseQty;
		data["dilutedFloatProfitLoss"] = task_data->dilutedFloatProfitLoss;
		data["dilutedBreakevenPrice"] = task_data->dilutedBreakevenPrice;
		data["dilutedCost"] = task_data->dilutedCost;
		data["avgPositionPrice"] = task_data->avgPositionPrice;
		data["floatProfitLoss"] = task_data->floatProfitLoss;
		data["dividend"] = task_data->dividend;
		data["totalFloatProfitLoss"] = task_data->totalFloatProfitLoss;
		data["sellAmount"] = task_data->sellAmount;
		data["buyAmount"] = task_data->buyAmount;
		data["buyAvgPrice"] = task_data->buyAvgPrice;
		data["rationedSharesAmount"] = task_data->rationedSharesAmount;
		data["latestMarket"] = task_data->latestMarket;
		data["breakevenPrice"] = task_data->breakevenPrice;
		data["latestPrice"] = task_data->latestPrice;
		data["nonCirculateMarket"] = task_data->nonCirculateMarket;
		data["interestQuote"] = task_data->interestQuote;
		data["preClosePrice"] = task_data->preClosePrice;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryPosition(data, error, task->task_last);
};

void TdApi::processRspFASLQryEntrustOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQryEntrustOrderField *task_data = (DFITCFASLRspQryEntrustOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["offerShareholderID"] = toUtf(task_data->offerShareholderID);
		data["currency"] = toUtf(task_data->currency);
		data["turnover"] = task_data->turnover;
		data["tradePrice"] = task_data->tradePrice;
		data["tradeTime"] = toUtf(task_data->tradeTime);
		data["tradeQty"] = task_data->tradeQty;
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["clearFunds"] = task_data->clearFunds;
		data["entrustType"] = task_data->entrustType;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustPrice"] = task_data->entrustPrice;
		data["entrustDirection"] = task_data->entrustDirection;
		data["entrustQty"] = task_data->entrustQty;
		data["securityID"] = toUtf(task_data->securityID);
		data["securityType"] = toUtf(task_data->securityType);
		data["securityName"] = toUtf(task_data->securityName);
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["declareTime"] = toUtf(task_data->declareTime);
		data["declareResult"] = task_data->declareResult;
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["freezeFunds"] = task_data->freezeFunds;
		data["accountID"] = toUtf(task_data->accountID);
		data["noteMsg"] = toUtf(task_data->noteMsg);
		data["withdrawQty"] = task_data->withdrawQty;
		data["declareOrderID"] = toUtf(task_data->declareOrderID);
		data["orderType"] = task_data->orderType;
		data["freezeFundsSerialID"] = task_data->freezeFundsSerialID;
		data["freezeStockSerialID"] = task_data->freezeStockSerialID;
		data["declareDate"] = task_data->declareDate;
		data["declareSerialID"] = task_data->declareSerialID;
		data["entrustDate"] = task_data->entrustDate;
		data["incQryIndex"] = toUtf(task_data->incQryIndex);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryEntrustOrder(data, error, task->task_last);
};

void TdApi::processRspFASLQrySerialTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQrySerialTradeField *task_data = (DFITCFASLRspQrySerialTradeField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["currency"] = toUtf(task_data->currency);
		data["tradeID"] = toUtf(task_data->tradeID);
		data["turnover"] = task_data->turnover;
		data["tradePrice"] = task_data->tradePrice;
		data["tradeQty"] = task_data->tradeQty;
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["clearFunds"] = task_data->clearFunds;
		data["spdOrderID"] = task_data->spdOrderID;
		data["securityID"] = toUtf(task_data->securityID);
		data["securityType"] = toUtf(task_data->securityType);
		data["securityName"] = toUtf(task_data->securityName);
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["commission"] = task_data->commission;
		data["rtnSerialID"] = task_data->rtnSerialID;
		data["interestQuote"] = task_data->interestQuote;
		data["declareOrderID"] = toUtf(task_data->declareOrderID);
		data["incQryIndex"] = toUtf(task_data->incQryIndex);
		data["interest"] = task_data->interest;
		data["tradeTime"] = toUtf(task_data->tradeTime);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQrySerialTrade(data, error, task->task_last);
};

void TdApi::processRspFASLQryRealTimeTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQryRealTimeTradeField *task_data = (DFITCFASLRspQryRealTimeTradeField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["spdOrderID"] = task_data->spdOrderID;
		data["declareOrderID"] = toUtf(task_data->declareOrderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["securityID"] = toUtf(task_data->securityID);
		data["securityName"] = toUtf(task_data->securityName);
		data["entrustQty"] = task_data->entrustQty;
		data["entrustPrice"] = task_data->entrustPrice;
		data["withdrawQty"] = task_data->withdrawQty;
		data["tradeQty"] = task_data->tradeQty;
		data["turnover"] = task_data->turnover;
		data["tradePrice"] = task_data->tradePrice;
		data["tradeTime"] = toUtf(task_data->tradeTime);
		data["currency"] = toUtf(task_data->currency);
		data["clearFunds"] = task_data->clearFunds;
		data["orderType"] = task_data->orderType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryRealTimeTrade(data, error, task->task_last);
};

void TdApi::processRspFASLQryFreezeFundsDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQryFreezeFundsDetailField *task_data = (DFITCFASLRspQryFreezeFundsDetailField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["currency"] = toUtf(task_data->currency);
		data["fundsFreezeType"] = task_data->fundsFreezeType;
		data["summaryMsg"] = toUtf(task_data->summaryMsg);
		data["serialID"] = task_data->serialID;
		data["operatorFunds"] = task_data->operatorFunds;
		data["operatorTime"] = toUtf(task_data->operatorTime);
		data["operatorDate"] = task_data->operatorDate;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryFreezeFundsDetail(data, error, task->task_last);
};

void TdApi::processRspFASLQryFreezeStockDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQryFreezeStockDetailField *task_data = (DFITCFASLRspQryFreezeStockDetailField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["stockFreezeType"] = task_data->stockFreezeType;
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["serialID"] = task_data->serialID;
		data["operatorTime"] = toUtf(task_data->operatorTime);
		data["operatorDate"] = task_data->operatorDate;
		data["operatorQty"] = task_data->operatorQty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryFreezeStockDetail(data, error, task->task_last);
};

void TdApi::processRspFASLQryTransferFundsDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQryTransferFundsDetailField *task_data = (DFITCFASLRspQryTransferFundsDetailField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["capitalID"] = toUtf(task_data->capitalID);
		data["currency"] = toUtf(task_data->currency);
		data["fundsFreezeType"] = task_data->fundsFreezeType;
		data["summaryMsg"] = toUtf(task_data->summaryMsg);
		data["serialID"] = toUtf(task_data->serialID);
		data["operatorFunds"] = task_data->operatorFunds;
		data["operatorTime"] = toUtf(task_data->operatorTime);
		data["operatorDate"] = task_data->operatorDate;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryTransferFundsDetail(data, error, task->task_last);
};

void TdApi::processRspFASLWithdrawOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspWithdrawOrderField *task_data = (DFITCFASLRspWithdrawOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLWithdrawOrder(data, error);
};

void TdApi::processRspFASLQrySystemTime(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQryTradeTimeField *task_data = (DFITCFASLRspQryTradeTimeField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["sysTradingDay"] = task_data->sysTradingDay;
		data["sysTime"] = toUtf(task_data->sysTime);
		data["sysWeek"] = task_data->sysWeek;
		data["sysMillisecond"] = task_data->sysMillisecond;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQrySystemTime(data, error);
};

void TdApi::processRspFASLQryTransferredContract(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQryTransferredContractField *task_data = (DFITCFASLRspQryTransferredContractField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["capitalID"] = toUtf(task_data->capitalID);
		data["securityID"] = toUtf(task_data->securityID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["ableSellQty"] = task_data->ableSellQty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryTransferredContract(data, error, task->task_last);
};

void TdApi::processRspFASLDesirableFundsOut(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspDesirableFundsOutField *task_data = (DFITCFASLRspDesirableFundsOutField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["serialID"] = task_data->serialID;
		data["accountBanlance"] = task_data->accountBanlance;
		data["availableFunds"] = task_data->availableFunds;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLDesirableFundsOut(data, error);
};

void TdApi::processRspFASLQryGuaranteedContract(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQryGuaranteedContractField *task_data = (DFITCFASLRspQryGuaranteedContractField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["exchangRate"] = task_data->exchangRate;
		data["status"] = task_data->status;
		data["accountType"] = task_data->accountType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryGuaranteedContract(data, error, task->task_last);
};

void TdApi::processRspFASLQryUnderlyingContract(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQryUnderlyingContractField *task_data = (DFITCFASLRspQryUnderlyingContractField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["securityName"] = toUtf(task_data->securityName);
		data["status"] = task_data->status;
		data["securityProp"] = task_data->securityProp;
		data["otherProp"] = task_data->otherProp;
		data["exchangRate"] = task_data->exchangRate;
		data["financeDepositRatio"] = task_data->financeDepositRatio;
		data["securityDepositRatio"] = task_data->securityDepositRatio;
		data["exhibitionTimes"] = task_data->exhibitionTimes;
		data["marketFinanceBalance"] = task_data->marketFinanceBalance;
		data["marketSecurityBalance"] = task_data->marketSecurityBalance;
		data["marketFinanceQty"] = task_data->marketFinanceQty;
		data["marketSecurityQty"] = task_data->marketSecurityQty;
		data["exchangeFinanceRatio"] = task_data->exchangeFinanceRatio;
		data["exchangeSecurityRatio"] = task_data->exchangeSecurityRatio;
		data["exchangeexchangRate"] = task_data->exchangeexchangRate;
		data["outStatus"] = task_data->outStatus;
		data["registerDate"] = task_data->registerDate;
		data["modifyDate"] = task_data->modifyDate;
		data["checkFairPriceFlag"] = task_data->checkFairPriceFlag;
		data["fairPrice"] = task_data->fairPrice;
		data["stockSector"] = task_data->stockSector;
		data["financeStatus"] = task_data->financeStatus;
		data["securityStatus"] = task_data->securityStatus;
		data["guaranteeStatus"] = task_data->guaranteeStatus;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryUnderlyingContract(data, error, task->task_last);
};

void TdApi::processRspFASLQryCentreFundAvlInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQryCentreFundAvlField *task_data = (DFITCFASLRspQryCentreFundAvlField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["capitalID"] = toUtf(task_data->capitalID);
		data["currency"] = toUtf(task_data->currency);
		data["accountBalance"] = task_data->accountBalance;
		data["availableFunds"] = task_data->availableFunds;
		data["freezeFunds"] = task_data->freezeFunds;
		data["withdrawalFunds"] = task_data->withdrawalFunds;
		data["totalAssets"] = task_data->totalAssets;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryCentreFundAvlInfo(data, error, task->task_last);
};

void TdApi::processRspFASLQryPlacingInterestsInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFASLRspQryPlacingInterestsField *task_data = (DFITCFASLRspQryPlacingInterestsField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["winningLotsQty"] = task_data->winningLotsQty;
		data["satibablePurchaseQty"] = task_data->satibablePurchaseQty;
		data["clearDate"] = task_data->clearDate;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLQryPlacingInterestsInfo(data, error, task->task_last);
};

void TdApi::processRspFASLUserPasswordUpdate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCSECRspPasswordUpdateField *task_data = (DFITCSECRspPasswordUpdateField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["passwordType"] = task_data->passwordType;
		data["result"] = task_data->result;
		data["rtnMsg"] = toUtf(task_data->rtnMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspFASLUserPasswordUpdate(data, error);
};

void TdApi::processFASLEntrustOrderRtn(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFaslEntrustOrderRtnField *task_data = (DFITCFaslEntrustOrderRtnField*)task->task_data;
		data["localOrderID"] = task_data->localOrderID;
		data["accountID"] = toUtf(task_data->accountID);
		data["sessionID"] = task_data->sessionID;
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["currency"] = toUtf(task_data->currency);
		data["securityID"] = toUtf(task_data->securityID);
		data["securityType"] = toUtf(task_data->securityType);
		data["withdrawQty"] = task_data->withdrawQty;
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["freezeFunds"] = task_data->freezeFunds;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustDirection"] = task_data->entrustDirection;
		data["declareResult"] = task_data->declareResult;
		data["noteMsg"] = toUtf(task_data->noteMsg);
		data["entrustQty"] = task_data->entrustQty;
		data["orderConfirmFlag"] = task_data->orderConfirmFlag;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["entrustPrice"] = task_data->entrustPrice;
		data["orderType"] = task_data->orderType;
		delete task_data;
	}
	this->onFASLEntrustOrderRtn(data);
};

void TdApi::processFASLTradeRtn(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFaslTradeRtnField *task_data = (DFITCFaslTradeRtnField*)task->task_data;
		data["localOrderID"] = task_data->localOrderID;
		data["accountID"] = toUtf(task_data->accountID);
		data["sessionID"] = task_data->sessionID;
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["currency"] = toUtf(task_data->currency);
		data["securityID"] = toUtf(task_data->securityID);
		data["securityType"] = toUtf(task_data->securityType);
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["tradeID"] = toUtf(task_data->tradeID);
		data["tradeTime"] = toUtf(task_data->tradeTime);
		data["withdrawQty"] = task_data->withdrawQty;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustDirection"] = task_data->entrustDirection;
		data["clearFunds"] = task_data->clearFunds;
		data["totalTradeQty"] = task_data->totalTradeQty;
		data["totalTurnover"] = task_data->totalTurnover;
		data["tradeQty"] = task_data->tradeQty;
		data["tradePrice"] = task_data->tradePrice;
		data["turnover"] = task_data->turnover;
		data["entrustQty"] = task_data->entrustQty;
		data["declareResult"] = task_data->declareResult;
		data["noteMsg"] = toUtf(task_data->noteMsg);
		delete task_data;
	}
	this->onFASLTradeRtn(data);
};

void TdApi::processFASLWithdrawOrderRtn(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFaslWithdrawOrderRtnField *task_data = (DFITCFaslWithdrawOrderRtnField*)task->task_data;
		data["localOrderID"] = task_data->localOrderID;
		data["accountID"] = toUtf(task_data->accountID);
		data["sessionID"] = task_data->sessionID;
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["currency"] = toUtf(task_data->currency);
		data["securityID"] = toUtf(task_data->securityID);
		data["securityType"] = toUtf(task_data->securityType);
		data["withdrawQty"] = task_data->withdrawQty;
		data["tradeQty"] = task_data->tradeQty;
		data["withdrawFlag"] = toUtf(task_data->withdrawFlag);
		data["freezeFunds"] = task_data->freezeFunds;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustDirection"] = task_data->entrustDirection;
		data["entrustQty"] = task_data->entrustQty;
		data["declareResult"] = task_data->declareResult;
		data["noteMsg"] = toUtf(task_data->noteMsg);
		delete task_data;
	}
	this->onFASLWithdrawOrderRtn(data);
};

void TdApi::processFASLLiabilitiesRtn(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCFaslLiabilitiesRtnField *task_data = (DFITCFaslLiabilitiesRtnField*)task->task_data;
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["sessionID"] = task_data->sessionID;
		data["accountID"] = toUtf(task_data->accountID);
		data["specifycontractNO"] = toUtf(task_data->specifycontractNO);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["contractType"] = task_data->contractType;
		data["clearFlag"] = task_data->clearFlag;
		data["changeType"] = task_data->changeType;
		data["status"] = task_data->status;
		data["operatorQty"] = task_data->operatorQty;
		data["operateFunds"] = task_data->operateFunds;
		data["operatorInterest"] = task_data->operatorInterest;
		data["operatorCost"] = task_data->operatorCost;
		data["commission"] = task_data->commission;
		data["changeNote"] = toUtf(task_data->changeNote);
		data["contractNO"] = toUtf(task_data->contractNO);
		data["endDate"] = task_data->endDate;
		data["depositRatio"] = task_data->depositRatio;
		data["ratio"] = task_data->ratio;
		data["postInterest"] = task_data->postInterest;
		data["operatorDate"] = task_data->operatorDate;
		data["usedLimitsFreezeFlag"] = task_data->usedLimitsFreezeFlag;
		data["shareholderID"] = toUtf(task_data->shareholderID);
		data["contracttimeLimit"] = task_data->contracttimeLimit;
		delete task_data;
	}
	this->onFASLLiabilitiesRtn(data);
};

void TdApi::processRspStockETFEntrustOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspETFEntrustOrderField *task_data = (DFITCStockRspETFEntrustOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["freezeFunds"] = task_data->freezeFunds;
		data["entrustBatchID"] = task_data->entrustBatchID;
		data["entrustMsg"] = toUtf(task_data->entrustMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockETFEntrustOrder(data, error);
};

void TdApi::processRspStockETFBasketOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspETFBasketOrderField *task_data = (DFITCStockRspETFBasketOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustBatchID"] = task_data->entrustBatchID;
		data["entrustMsg"] = toUtf(task_data->entrustMsg);
		data["componentStocksID"] = toUtf(task_data->componentStocksID);
		data["totalCount"] = task_data->totalCount;
		data["succCount"] = task_data->succCount;
		data["failCount"] = task_data->failCount;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockETFBasketOrder(data, error, task->task_last);
};

void TdApi::processRspStockBondRepurchaseOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspBondRepurchaseOrderField *task_data = (DFITCStockRspBondRepurchaseOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["freezeFunds"] = task_data->freezeFunds;
		data["entrustBatchID"] = task_data->entrustBatchID;
		data["entrustMsg"] = toUtf(task_data->entrustMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockBondRepurchaseOrder(data, error);
};

void TdApi::processRspStockBondInOutStockOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspBondInOutStockOrderField *task_data = (DFITCStockRspBondInOutStockOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["freezeFunds"] = task_data->freezeFunds;
		data["entrustBatchID"] = task_data->entrustBatchID;
		data["entrustMsg"] = toUtf(task_data->entrustMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockBondInOutStockOrder(data, error);
};

void TdApi::processRspStockIssueBusinessOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspIssueBusinessOrderField *task_data = (DFITCStockRspIssueBusinessOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["freezeFunds"] = task_data->freezeFunds;
		data["entrustBatchID"] = task_data->entrustBatchID;
		data["entrustMsg"] = toUtf(task_data->entrustMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockIssueBusinessOrder(data, error);
};

void TdApi::processRspStockLOFEntrustOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspLOFEntrustOrderField *task_data = (DFITCStockRspLOFEntrustOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["freezeFunds"] = task_data->freezeFunds;
		data["entrustBatchID"] = task_data->entrustBatchID;
		data["entrustMsg"] = toUtf(task_data->entrustMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockLOFEntrustOrder(data, error);
};

void TdApi::processRspStockAfterHoursPriceOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspAfterHoursPriceOrderField *task_data = (DFITCStockRspAfterHoursPriceOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["freezeFunds"] = task_data->freezeFunds;
		data["entrustBatchID"] = task_data->entrustBatchID;
		data["entrustMsg"] = toUtf(task_data->entrustMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockAfterHoursPriceOrder(data, error);
};

void TdApi::processRspStockNonTradingBusinessOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspNonTradingBusinessOrderField *task_data = (DFITCStockRspNonTradingBusinessOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["freezeFunds"] = task_data->freezeFunds;
		data["entrustMsg"] = toUtf(task_data->entrustMsg);
		data["entrustBatchID"] = task_data->entrustBatchID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockNonTradingBusinessOrder(data, error);
};

void TdApi::processRspStockSHMutualFundOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspSHMutualFundOrderField *task_data = (DFITCStockRspSHMutualFundOrderField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["localOrderID"] = task_data->localOrderID;
		data["spdOrderID"] = task_data->spdOrderID;
		data["entrustTime"] = toUtf(task_data->entrustTime);
		data["freezeFunds"] = task_data->freezeFunds;
		data["entrustBatchID"] = task_data->entrustBatchID;
		data["entrustMsg"] = toUtf(task_data->entrustMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockSHMutualFundOrder(data, error);
};

void TdApi::processRspStockCalcAblePurchaseETFBasketQty(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspCalcAblePurchaseETFBasketQtyField *task_data = (DFITCStockRspCalcAblePurchaseETFBasketQtyField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["ablePurchaseETFQty"] = task_data->ablePurchaseETFQty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockCalcAblePurchaseETFBasketQty(data, error);
};

void TdApi::processRspStockCalcAbleBondRepurchaseQty(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspCalcAbleBondRepurchaseQtyField *task_data = (DFITCStockRspCalcAbleBondRepurchaseQtyField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["ableEntrustQty"] = task_data->ableEntrustQty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockCalcAbleBondRepurchaseQty(data, error);
};

void TdApi::processRspStockCalcAbleIssueBusinessQty(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspCalcAbleIssueBusinessQtyField *task_data = (DFITCStockRspCalcAbleIssueBusinessQtyField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["ableEntrustQty"] = task_data->ableEntrustQty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockCalcAbleIssueBusinessQty(data, error);
};

void TdApi::processRspStockCalcAblePurchaseLOFQty(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspCalcAblePurchaseLOFQtyField *task_data = (DFITCStockRspCalcAblePurchaseLOFQtyField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["ableEntrustQty"] = task_data->ableEntrustQty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockCalcAblePurchaseLOFQty(data, error);
};

void TdApi::processRspStockCalcAbleAfterHoursPriceQty(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspCalcAbleAfterHoursPriceQtyField *task_data = (DFITCStockRspCalcAbleAfterHoursPriceQtyField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["ableEntrustQty"] = task_data->ableEntrustQty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockCalcAbleAfterHoursPriceQty(data, error);
};

void TdApi::processRspStockCalcAbleNonTradingBusinessQty(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspCalcAbleNonTradingBusinessQtyField *task_data = (DFITCStockRspCalcAbleNonTradingBusinessQtyField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["ableEntrustQty"] = task_data->ableEntrustQty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockCalcAbleNonTradingBusinessQty(data, error);
};

void TdApi::processRspStockCalcAbleSHMutualFundQty(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		DFITCStockRspCalcAbleSHMutualFundQtyField *task_data = (DFITCStockRspCalcAbleSHMutualFundQtyField*)task->task_data;
		data["requestID"] = task_data->requestID;
		data["accountID"] = toUtf(task_data->accountID);
		data["exchangeID"] = toUtf(task_data->exchangeID);
		data["securityID"] = toUtf(task_data->securityID);
		data["ableEntrustQty"] = task_data->ableEntrustQty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		DFITCSECRspInfoField *task_error = (DFITCSECRspInfoField*)task->task_error;
		error["requestID"] = task_error->requestID;
		error["sessionID"] = task_error->sessionID;
		error["accountID"] = toUtf(task_error->accountID);
		error["errorID"] = task_error->errorID;
		error["localOrderID"] = task_error->localOrderID;
		error["spdOrderID"] = task_error->spdOrderID;
		error["errorMsg"] = toUtf(task_error->errorMsg);
		delete task_error;
	}
	this->onRspStockCalcAbleSHMutualFundQty(data, error);
};

///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------


void TdApi::createDFITCSECTraderApi(string pszLogAddr)
{
	this->api = DFITCSECTraderApi::CreateDFITCSECTraderApi(pszLogAddr.c_str(), pszLogAddr.c_str());
};

void TdApi::release()
{
	this->api->Release();
};


int TdApi::init(string pszFrontAddress)
{
	this->active = true;
	this->task_thread = thread(&TdApi::processTask, this);
	int i = this->api->Init(pszFrontAddress.c_str(), this);
	return i;
};


int TdApi::exit()
{
	this->active = false;
	this->task_queue.terminate();
	this->task_thread.join();
	this->api->Release();
	this->api = NULL;
	return 1;
};

int TdApi::subscribePrivateTopic(int nResumeType)
{
	int i = this->api->SubscribePrivateTopic((RESUME_TYPE)nResumeType);
	return i;
}

int TdApi::reqStockUserLogin(const dict &req)
{
	DFITCSECReqUserLoginField myreq = DFITCSECReqUserLoginField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "password", myreq.password);
	getInt(req, "compressflag", &myreq.compressflag);
	getString(req, "authenticCode", myreq.authenticCode);
	getString(req, "appID", myreq.appID);
	getInt(req, "collectInterType", &myreq.collectInterType);
	getString(req, "exchangeID", myreq.exchangeID);
	int i = this->api->ReqStockUserLogin(&myreq);
	return i;
};

int TdApi::reqStockUserLogout(const dict &req)
{
	DFITCSECReqUserLogoutField myreq = DFITCSECReqUserLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	int i = this->api->ReqStockUserLogout(&myreq);
	return i;
};

int TdApi::reqStockUserPasswordUpdate(const dict &req)
{
	DFITCSECReqPasswordUpdateField myreq = DFITCSECReqPasswordUpdateField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "oldPassword", myreq.oldPassword);
	getString(req, "newPassword", myreq.newPassword);
	getInt(req, "passwordType", &myreq.passwordType);
	int i = this->api->ReqStockUserPasswordUpdate(&myreq);
	return i;
};

int TdApi::reqStockEntrustOrder(const dict &req)
{
	DFITCStockReqEntrustOrderField myreq = DFITCStockReqEntrustOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "accountID", myreq.accountID);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "entrustQty", &myreq.entrustQty);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "orderType", &myreq.orderType);
	getInt(req, "entrustBatchID", &myreq.entrustBatchID);
	getString(req, "eachSeatID", myreq.eachSeatID);
	getInt(req, "hkEntrustLimit", &myreq.hkEntrustLimit);
	getInt(req, "hkOrderType", &myreq.hkOrderType);
	int i = this->api->ReqStockEntrustOrder(&myreq);
	return i;
};

int TdApi::reqStockWithdrawOrder(const dict &req)
{
	DFITCSECReqWithdrawOrderField myreq = DFITCSECReqWithdrawOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "spdOrderID", &myreq.spdOrderID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getInt64(req, "sessionID", &myreq.sessionID);
	int i = this->api->ReqStockWithdrawOrder(&myreq);
	return i;
};

int TdApi::reqStockQryEntrustOrder(const dict &req)
{
	DFITCStockReqQryEntrustOrderField myreq = DFITCStockReqQryEntrustOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "spdOrderID", &myreq.spdOrderID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustBatchID", &myreq.entrustBatchID);
	getInt(req, "entrustQryFlag", &myreq.entrustQryFlag);
	getString(req, "withdrawFlag", myreq.withdrawFlag);
	getString(req, "incQryIndex", myreq.incQryIndex);
	int i = this->api->ReqStockQryEntrustOrder(&myreq);
	return i;
};

int TdApi::reqStockQryRealTimeTrade(const dict &req)
{
	DFITCStockReqQryRealTimeTradeField myreq = DFITCStockReqQryRealTimeTradeField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustBatchID", &myreq.entrustBatchID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "spdOrderID", &myreq.spdOrderID);
	getInt(req, "queryFlag", &myreq.queryFlag);
	int i = this->api->ReqStockQryRealTimeTrade(&myreq);
	return i;
};

int TdApi::reqStockQrySerialTrade(const dict &req)
{
	DFITCStockReqQrySerialTradeField myreq = DFITCStockReqQrySerialTradeField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "spdOrderID", &myreq.spdOrderID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustBatchID", &myreq.entrustBatchID);
	getInt(req, "tradeQryFlag", &myreq.tradeQryFlag);
	getString(req, "incQryIndex", myreq.incQryIndex);
	int i = this->api->ReqStockQrySerialTrade(&myreq);
	return i;
};

int TdApi::reqStockQryPosition(const dict &req)
{
	DFITCStockReqQryPositionField myreq = DFITCStockReqQryPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "posiQryFlag", &myreq.posiQryFlag);
	int i = this->api->ReqStockQryPosition(&myreq);
	return i;
};

int TdApi::reqStockQryCapitalAccountInfo(const dict &req)
{
	DFITCStockReqQryCapitalAccountField myreq = DFITCStockReqQryCapitalAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "FundsQryFlag", &myreq.FundsQryFlag);
	int i = this->api->ReqStockQryCapitalAccountInfo(&myreq);
	return i;
};

int TdApi::reqStockQryAccountInfo(const dict &req)
{
	DFITCStockReqQryAccountField myreq = DFITCStockReqQryAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	int i = this->api->ReqStockQryAccountInfo(&myreq);
	return i;
};

int TdApi::reqStockQryShareholderInfo(const dict &req)
{
	DFITCStockReqQryShareholderField myreq = DFITCStockReqQryShareholderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	int i = this->api->ReqStockQryShareholderInfo(&myreq);
	return i;
};

int TdApi::reqStockTransferFunds(const dict &req)
{
	DFITCStockReqTransferFundsField myreq = DFITCStockReqTransferFundsField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "currency", myreq.currency);
	getString(req, "summaryMsg", myreq.summaryMsg);
	getDouble(req, "operateFunds", &myreq.operateFunds);
	getInt(req, "fundsTransFlag", &myreq.fundsTransFlag);
	int i = this->api->ReqStockTransferFunds(&myreq);
	return i;
};

int TdApi::reqStockEntrustBatchOrder(const dict &req)
{
	DFITCStockReqEntrustBatchOrderField myreq = DFITCStockReqEntrustBatchOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "entrustCount", &myreq.entrustCount);
	getString(req, "entrustDetail", myreq.entrustDetail);
	getInt(req, "entrustBatchID", &myreq.entrustBatchID);
	int i = this->api->ReqStockEntrustBatchOrder(&myreq);
	return i;
};

int TdApi::reqStockWithdrawBatchOrder(const dict &req)
{
	DFITCStockReqWithdrawBatchOrderField myreq = DFITCStockReqWithdrawBatchOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "orderRangeID", myreq.orderRangeID);
	getInt(req, "entrustBatchID", &myreq.entrustBatchID);
	int i = this->api->ReqStockWithdrawBatchOrder(&myreq);
	return i;
};

int TdApi::reqStockCalcAbleEntrustQty(const dict &req)
{
	DFITCStockReqCalcAbleEntrustQtyField myreq = DFITCStockReqCalcAbleEntrustQtyField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "accountID", myreq.accountID);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "orderType", &myreq.orderType);
	int i = this->api->ReqStockCalcAbleEntrustQty(&myreq);
	return i;
};

int TdApi::reqStockCalcAblePurchaseETFQty(const dict &req)
{
	DFITCStockReqCalcAblePurchaseETFQtyField myreq = DFITCStockReqCalcAblePurchaseETFQtyField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "orderType", &myreq.orderType);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	int i = this->api->ReqStockCalcAblePurchaseETFQty(&myreq);
	return i;
};

int TdApi::reqStockQryFreezeFundsDetail(const dict &req)
{
	DFITCStockReqQryFreezeFundsDetailField myreq = DFITCStockReqQryFreezeFundsDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "currency", myreq.currency);
	getInt(req, "fundsFreezeType", &myreq.fundsFreezeType);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "serialID", &myreq.serialID);
	int i = this->api->ReqStockQryFreezeFundsDetail(&myreq);
	return i;
};

int TdApi::reqStockQryFreezeStockDetail(const dict &req)
{
	DFITCStockReqQryFreezeStockDetailField myreq = DFITCStockReqQryFreezeStockDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getInt(req, "stockFreezeType", &myreq.stockFreezeType);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "serialID", &myreq.serialID);
	int i = this->api->ReqStockQryFreezeStockDetail(&myreq);
	return i;
};

int TdApi::reqStockQryTransferFundsDetail(const dict &req)
{
	DFITCStockReqQryTransferFundsDetailField myreq = DFITCStockReqQryTransferFundsDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "currency", myreq.currency);
	getInt(req, "fundsFreezeType", &myreq.fundsFreezeType);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "serialID", &myreq.serialID);
	int i = this->api->ReqStockQryTransferFundsDetail(&myreq);
	return i;
};

int TdApi::reqStockQryTransferStockDetail(const dict &req)
{
	DFITCStockReqQryTransferStockDetailField myreq = DFITCStockReqQryTransferStockDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getInt(req, "stockFreezeType", &myreq.stockFreezeType);
	getString(req, "incQryIndex", myreq.incQryIndex);
	getInt(req, "serialID", &myreq.serialID);
	int i = this->api->ReqStockQryTransferStockDetail(&myreq);
	return i;
};

int TdApi::reqStockQryStockInfo(const dict &req)
{
	DFITCStockReqQryStockField myreq = DFITCStockReqQryStockField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	int i = this->api->ReqStockQryStockInfo(&myreq);
	return i;
};

int TdApi::reqStockQryStockStaticInfo(const dict &req)
{
	DFITCStockReqQryStockStaticField myreq = DFITCStockReqQryStockStaticField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "incQryIndex", myreq.incQryIndex);
	int i = this->api->ReqStockQryStockStaticInfo(&myreq);
	return i;
};

int TdApi::reqStockQryTradeTime(const dict &req)
{
	DFITCStockReqQryTradeTimeField myreq = DFITCStockReqQryTradeTimeField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	int i = this->api->ReqStockQryTradeTime(&myreq);
	return i;
};

int TdApi::reqSOPUserLogin(const dict &req)
{
	DFITCSECReqUserLoginField myreq = DFITCSECReqUserLoginField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "password", myreq.password);
	getInt(req, "compressflag", &myreq.compressflag);
	getString(req, "authenticCode", myreq.authenticCode);
	getString(req, "appID", myreq.appID);
	getInt(req, "collectInterType", &myreq.collectInterType);
	getString(req, "exchangeID", myreq.exchangeID);
	int i = this->api->ReqSOPUserLogin(&myreq);
	return i;
};

int TdApi::reqSOPUserLogout(const dict &req)
{
	DFITCSECReqUserLogoutField myreq = DFITCSECReqUserLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	int i = this->api->ReqSOPUserLogout(&myreq);
	return i;
};

int TdApi::reqSOPUserPasswordUpdate(const dict &req)
{
	DFITCSECReqPasswordUpdateField myreq = DFITCSECReqPasswordUpdateField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "oldPassword", myreq.oldPassword);
	getString(req, "newPassword", myreq.newPassword);
	getInt(req, "passwordType", &myreq.passwordType);
	int i = this->api->ReqSOPUserPasswordUpdate(&myreq);
	return i;
};

int TdApi::reqSOPEntrustOrder(const dict &req)
{
	DFITCSOPReqEntrustOrderField myreq = DFITCSOPReqEntrustOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getString(req, "subAccountID", myreq.subAccountID);
	getInt(req, "entrustQty", &myreq.entrustQty);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "openCloseFlag", &myreq.openCloseFlag);
	getInt(req, "coveredFlag", &myreq.coveredFlag);
	getInt(req, "orderType", &myreq.orderType);
	getInt(req, "orderExpiryDate", &myreq.orderExpiryDate);
	getInt(req, "orderCategory", &myreq.orderCategory);
	getInt(req, "serialID", &myreq.serialID);
	getString(req, "devID", myreq.devID);
	getString(req, "devDecInfo", myreq.devDecInfo);
	getString(req, "groupCode", myreq.groupCode);
	int i = this->api->ReqSOPEntrustOrder(&myreq);
	return i;
};

int TdApi::reqSOPQuoteEntrustOrder(const dict &req)
{
	DFITCSOPReqQuoteEntrustOrderField myreq = DFITCSOPReqQuoteEntrustOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "bidQty", &myreq.bidQty);
	getDouble(req, "bidPrice", &myreq.bidPrice);
	getInt(req, "bidOpenCloseFlag", &myreq.bidOpenCloseFlag);
	getInt(req, "bidCoveredFlag", &myreq.bidCoveredFlag);
	getInt(req, "askQty", &myreq.askQty);
	getDouble(req, "askPrice", &myreq.askPrice);
	getInt(req, "askOpenCloseFlag", &myreq.askOpenCloseFlag);
	getInt(req, "askCoveredFlag", &myreq.askCoveredFlag);
	getInt(req, "orderType", &myreq.orderType);
	getInt(req, "orderExpiryDate", &myreq.orderExpiryDate);
	getInt(req, "orderCategory", &myreq.orderCategory);
	getInt(req, "quoteID", &myreq.quoteID);
	getString(req, "devID", myreq.devID);
	getString(req, "devDecInfo", myreq.devDecInfo);
	int i = this->api->ReqSOPQuoteEntrustOrder(&myreq);
	return i;
};

int TdApi::reqSOPGroupSplit(const dict &req)
{
	DFITCSOPReqGroupSplitField myreq = DFITCSOPReqGroupSplitField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityOptionID", myreq.securityOptionID);
	getString(req, "subAccountID", myreq.subAccountID);
	getInt(req, "openCloseFlag", &myreq.openCloseFlag);
	getInt(req, "groupType", &myreq.groupType);
	getString(req, "groupCode", myreq.groupCode);
	getString(req, "securityOptionID1", myreq.securityOptionID1);
	getString(req, "securityOptionID2", myreq.securityOptionID2);
	getString(req, "securityOptionID3", myreq.securityOptionID3);
	getString(req, "securityOptionID4", myreq.securityOptionID4);
	getInt(req, "entrustQty", &myreq.entrustQty);
	getString(req, "devID", myreq.devID);
	getString(req, "devDecInfo", myreq.devDecInfo);
	int i = this->api->ReqSOPGroupSplit(&myreq);
	return i;
};

int TdApi::reqSOPGroupExectueOrder(const dict &req)
{
	DFITCSOPReqGroupExectueOrderField myreq = DFITCSOPReqGroupExectueOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityOptionID1", myreq.securityOptionID1);
	getString(req, "securityOptionID2", myreq.securityOptionID2);
	getString(req, "subAccountID", myreq.subAccountID);
	getInt(req, "entrustQty", &myreq.entrustQty);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "openCloseFlag", &myreq.openCloseFlag);
	getInt(req, "orderCategory", &myreq.orderCategory);
	getString(req, "devID", myreq.devID);
	getString(req, "devDecInfo", myreq.devDecInfo);
	int i = this->api->ReqSOPGroupExectueOrder(&myreq);
	return i;
};

int TdApi::reqSOPQryGroupPosition(const dict &req)
{
	DFITCSOPReqQryGroupPositionField myreq = DFITCSOPReqQryGroupPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	int i = this->api->ReqSOPQryGroupPosition(&myreq);
	return i;
};

int TdApi::reqSOPLockOUnLockStock(const dict &req)
{
	DFITCSOPReqLockOUnLockStockField myreq = DFITCSOPReqLockOUnLockStockField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "subAccountID", myreq.subAccountID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustQty", &myreq.entrustQty);
	getInt(req, "openCloseFlag", &myreq.openCloseFlag);
	getString(req, "devID", myreq.devID);
	getString(req, "devDecInfo", myreq.devDecInfo);
	int i = this->api->ReqSOPLockOUnLockStock(&myreq);
	return i;
};

int TdApi::reqSOPWithdrawOrder(const dict &req)
{
	DFITCSECReqWithdrawOrderField myreq = DFITCSECReqWithdrawOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "spdOrderID", &myreq.spdOrderID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getInt64(req, "sessionID", &myreq.sessionID);
	int i = this->api->ReqSOPWithdrawOrder(&myreq);
	return i;
};

int TdApi::reqSOPQryEntrustOrder(const dict &req)
{
	DFITCSOPReqQryEntrustOrderField myreq = DFITCSOPReqQryEntrustOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityOptionID", myreq.securityOptionID);
	getString(req, "withdrawFlag", myreq.withdrawFlag);
	getInt(req, "exSerialID", &myreq.exSerialID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "spdOrderID", &myreq.spdOrderID);
	getInt(req, "entrustQryFlag", &myreq.entrustQryFlag);
	getInt(req, "rowIndex", &myreq.rowIndex);
	getInt(req, "rowCount", &myreq.rowCount);
	int i = this->api->ReqSOPQryEntrustOrder(&myreq);
	return i;
};

int TdApi::reqSOPQrySerialTrade(const dict &req)
{
	DFITCSOPReqQrySerialTradeField myreq = DFITCSOPReqQrySerialTradeField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "spdOrderID", &myreq.spdOrderID);
	getString(req, "incQryIndex", myreq.incQryIndex);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "entrustBatchID", &myreq.entrustBatchID);
	getInt(req, "tradeQryFlag", &myreq.tradeQryFlag);
	getString(req, "currency", myreq.currency);
	getInt(req, "rowIndex", &myreq.rowIndex);
	getInt(req, "rowCount", &myreq.rowCount);
	int i = this->api->ReqSOPQrySerialTrade(&myreq);
	return i;
};

int TdApi::reqSOPQryPosition(const dict &req)
{
	DFITCSOPReqQryPositionField myreq = DFITCSOPReqQryPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityOptionID", myreq.securityOptionID);
	getInt(req, "rowIndex", &myreq.rowIndex);
	getInt(req, "rowCount", &myreq.rowCount);
	int i = this->api->ReqSOPQryPosition(&myreq);
	return i;
};

int TdApi::reqSOPQryCollateralPosition(const dict &req)
{
	DFITCSOPReqQryCollateralPositionField myreq = DFITCSOPReqQryCollateralPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	int i = this->api->ReqSOPQryCollateralPosition(&myreq);
	return i;
};

int TdApi::reqSOPQryCapitalAccountInfo(const dict &req)
{
	DFITCSOPReqQryCapitalAccountField myreq = DFITCSOPReqQryCapitalAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "currency", myreq.currency);
	getInt(req, "FundsQryFlag", &myreq.FundsQryFlag);
	int i = this->api->ReqSOPQryCapitalAccountInfo(&myreq);
	return i;
};

int TdApi::reqSOPQryAccountInfo(const dict &req)
{
	DFITCSOPReqQryAccountField myreq = DFITCSOPReqQryAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	int i = this->api->ReqSOPQryAccountInfo(&myreq);
	return i;
};

int TdApi::reqSOPQryShareholderInfo(const dict &req)
{
	DFITCSOPReqQryShareholderField myreq = DFITCSOPReqQryShareholderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "accountID", myreq.accountID);
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "exchangeID", myreq.exchangeID);
	int i = this->api->ReqSOPQryShareholderInfo(&myreq);
	return i;
};

int TdApi::reqSOPCalcAbleEntrustQty(const dict &req)
{
	DFITCSOPReqCalcAbleEntrustQtyField myreq = DFITCSOPReqCalcAbleEntrustQtyField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "subAccountID", myreq.subAccountID);
	getString(req, "securityOptionID", myreq.securityOptionID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "openCloseFlag", &myreq.openCloseFlag);
	getInt(req, "coveredFlag", &myreq.coveredFlag);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "checkUpLimit", &myreq.checkUpLimit);
	getString(req, "devID", myreq.devID);
	getString(req, "devDecInfo", myreq.devDecInfo);
	getString(req, "groupCode", myreq.groupCode);
	int i = this->api->ReqSOPCalcAbleEntrustQty(&myreq);
	return i;
};

int TdApi::reqSOPQryAbleLockStock(const dict &req)
{
	DFITCSOPReqQryAbleLockStockField myreq = DFITCSOPReqQryAbleLockStockField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	int i = this->api->ReqSOPQryAbleLockStock(&myreq);
	return i;
};

int TdApi::reqSOPQryContactInfo(const dict &req)
{
	DFITCSOPReqQryContactField myreq = DFITCSOPReqQryContactField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityOptionID", myreq.securityOptionID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "contractObjectType", &myreq.contractObjectType);
	getInt(req, "optType", &myreq.optType);
	getString(req, "rowIndex", myreq.rowIndex);
	getInt(req, "rowCount", &myreq.rowCount);
	int i = this->api->ReqSOPQryContactInfo(&myreq);
	return i;
};

int TdApi::reqSOPExectueOrder(const dict &req)
{
	DFITCSOPReqExectueOrderField myreq = DFITCSOPReqExectueOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityOptionID", myreq.securityOptionID);
	getString(req, "subAccountID", myreq.subAccountID);
	getInt(req, "entrustQty", &myreq.entrustQty);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "openCloseFlag", &myreq.openCloseFlag);
	getString(req, "devID", myreq.devID);
	getString(req, "devDecInfo", myreq.devDecInfo);
	int i = this->api->ReqSOPExectueOrder(&myreq);
	return i;
};

int TdApi::reqSOPQryExecAssiInfo(const dict &req)
{
	DFITCSOPReqQryExecAssiInfoField myreq = DFITCSOPReqQryExecAssiInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "securityOptionID", myreq.securityOptionID);
	getInt(req, "tradeDate", &myreq.tradeDate);
	int i = this->api->ReqSOPQryExecAssiInfo(&myreq);
	return i;
};

int TdApi::reqSOPQryTradeTime(const dict &req)
{
	DFITCSOPReqQryTradeTimeField myreq = DFITCSOPReqQryTradeTimeField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	int i = this->api->ReqSOPQryTradeTime(&myreq);
	return i;
};

int TdApi::reqSOPQryExchangeInfo(const dict &req)
{
	DFITCSOPReqQryExchangeInfoField myreq = DFITCSOPReqQryExchangeInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	int i = this->api->ReqSOPQryExchangeInfo(&myreq);
	return i;
};

int TdApi::reqSOPQryCommission(const dict &req)
{
	DFITCSOPReqQryCommissionField myreq = DFITCSOPReqQryCommissionField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getInt(req, "refType", &myreq.refType);
	getInt(req, "contractObjectType", &myreq.contractObjectType);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "openCloseFlag", &myreq.openCloseFlag);
	getInt(req, "level", &myreq.level);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	int i = this->api->ReqSOPQryCommission(&myreq);
	return i;
};

int TdApi::reqSOPQryDeposit(const dict &req)
{
	DFITCSOPReqQryDepositField myreq = DFITCSOPReqQryDepositField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getInt(req, "refType", &myreq.refType);
	getInt(req, "securityObjectType", &myreq.securityObjectType);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "level", &myreq.level);
	int i = this->api->ReqSOPQryDeposit(&myreq);
	return i;
};

int TdApi::reqSOPQryContractObjectInfo(const dict &req)
{
	DFITCSOPReqQryContractObjectField myreq = DFITCSOPReqQryContractObjectField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "securityObjectType", &myreq.securityObjectType);
	int i = this->api->ReqSOPQryContractObjectInfo(&myreq);
	return i;
};

int TdApi::reqSOPCapitalTranInOut(const dict &req)
{
	DFITCSOPReqCapitalTranInOutField myreq = DFITCSOPReqCapitalTranInOutField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getDouble(req, "allocationAmount", &myreq.allocationAmount);
	getString(req, "currency", myreq.currency);
	getString(req, "summaryMsg", myreq.summaryMsg);
	getInt(req, "fundsTransFlag", &myreq.fundsTransFlag);
	int i = this->api->ReqSOPCapitalTranInOut(&myreq);
	return i;
};

int TdApi::reqSOPCapitalDistributionRatio(const dict &req)
{
	DFITCSOPReqQryCapitalDistributionRatioField myreq = DFITCSOPReqQryCapitalDistributionRatioField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	int i = this->api->ReqSOPCapitalDistributionRatio(&myreq);
	return i;
};

int TdApi::reqSOPFundTransBetweenNodes(const dict &req)
{
	DFITCSOPReqFundTransBetweenNodesField myreq = DFITCSOPReqFundTransBetweenNodesField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getDouble(req, "allocationAmount", &myreq.allocationAmount);
	getInt(req, "nodeIDOut", &myreq.nodeIDOut);
	getInt(req, "nodeIDIn", &myreq.nodeIDIn);
	getString(req, "summaryMsg", myreq.summaryMsg);
	int i = this->api->ReqSOPFundTransBetweenNodes(&myreq);
	return i;
};

int TdApi::reqSOPModCapitalDistributionRatio(const dict &req)
{
	DFITCSOPReqModCapitalDistributionRatioField myreq = DFITCSOPReqModCapitalDistributionRatioField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "nodeID", &myreq.nodeID);
	getDouble(req, "distributionRatio", &myreq.distributionRatio);
	getString(req, "summaryMsg", myreq.summaryMsg);
	int i = this->api->ReqSOPModCapitalDistributionRatio(&myreq);
	return i;
};

int TdApi::reqFASLUserLogin(const dict &req)
{
	DFITCSECReqUserLoginField myreq = DFITCSECReqUserLoginField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "password", myreq.password);
	getInt(req, "compressflag", &myreq.compressflag);
	getString(req, "authenticCode", myreq.authenticCode);
	getString(req, "appID", myreq.appID);
	getInt(req, "collectInterType", &myreq.collectInterType);
	getString(req, "exchangeID", myreq.exchangeID);
	int i = this->api->ReqFASLUserLogin(&myreq);
	return i;
};

int TdApi::reqFASLUserLogout(const dict &req)
{
	DFITCSECReqUserLogoutField myreq = DFITCSECReqUserLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	int i = this->api->ReqFASLUserLogout(&myreq);
	return i;
};

int TdApi::reqFASLQryAbleFinInfo(const dict &req)
{
	DFITCFASLReqAbleFinInfoField myreq = DFITCFASLReqAbleFinInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "sourceContract", &myreq.sourceContract);
	int i = this->api->ReqFASLQryAbleFinInfo(&myreq);
	return i;
};

int TdApi::reqFASLQryAbleSloInfo(const dict &req)
{
	DFITCFASLReqAbleSloInfoField myreq = DFITCFASLReqAbleSloInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustQryFlag", &myreq.entrustQryFlag);
	int i = this->api->ReqFASLQryAbleSloInfo(&myreq);
	return i;
};

int TdApi::reqFASLTransferCollateral(const dict &req)
{
	DFITCFASLReqTransferCollateralField myreq = DFITCFASLReqTransferCollateralField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "transferQty", &myreq.transferQty);
	getInt(req, "orderCategory", &myreq.orderCategory);
	getInt(req, "orderType", &myreq.orderType);
	getInt(req, "orderTradeLimit", &myreq.orderTradeLimit);
	getInt(req, "orderExpiryDate", &myreq.orderExpiryDate);
	getInt(req, "orderEffectiveDate", &myreq.orderEffectiveDate);
	getDouble(req, "stopLossLimitPrice", &myreq.stopLossLimitPrice);
	getInt(req, "serialID", &myreq.serialID);
	getString(req, "devID", myreq.devID);
	getString(req, "devDecInfo", myreq.devDecInfo);
	getString(req, "step", myreq.step);
	getString(req, "offerShareholderID", myreq.offerShareholderID);
	getString(req, "eachSeatID", myreq.eachSeatID);
	int i = this->api->ReqFASLTransferCollateral(&myreq);
	return i;
};

int TdApi::reqFASLDirectRepayment(const dict &req)
{
	DFITCFASLReqDirectRepaymentField myreq = DFITCFASLReqDirectRepaymentField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getDouble(req, "repayFunds", &myreq.repayFunds);
	getInt(req, "entrustType", &myreq.entrustType);
	getInt(req, "orderCategory", &myreq.orderCategory);
	getInt(req, "orderType", &myreq.orderType);
	getInt(req, "orderTradeLimit", &myreq.orderTradeLimit);
	getInt(req, "orderExpiryDate", &myreq.orderExpiryDate);
	getInt(req, "orderEffectiveDate", &myreq.orderEffectiveDate);
	getInt(req, "serialID", &myreq.serialID);
	getString(req, "devID", myreq.devID);
	getString(req, "devDecInfo", myreq.devDecInfo);
	getString(req, "step", myreq.step);
	getInt(req, "sourceContract", &myreq.sourceContract);
	getString(req, "contractNO", myreq.contractNO);
	getInt(req, "entrustQryFlag", &myreq.entrustQryFlag);
	int i = this->api->ReqFASLDirectRepayment(&myreq);
	return i;
};

int TdApi::reqFASLRepayStockTransfer(const dict &req)
{
	DFITCFASLReqRepayStockTransferField myreq = DFITCFASLReqRepayStockTransferField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "repayQty", &myreq.repayQty);
	getInt(req, "orderCategory", &myreq.orderCategory);
	getInt(req, "orderType", &myreq.orderType);
	getInt(req, "orderTradeLimit", &myreq.orderTradeLimit);
	getInt(req, "orderExpiryDate", &myreq.orderExpiryDate);
	getInt(req, "orderEffectiveDate", &myreq.orderEffectiveDate);
	getDouble(req, "stopLossLimitPrice", &myreq.stopLossLimitPrice);
	getInt(req, "serialID", &myreq.serialID);
	getString(req, "devID", myreq.devID);
	getString(req, "devDecInfo", myreq.devDecInfo);
	getString(req, "step", myreq.step);
	getInt(req, "entrustQryFlag", &myreq.entrustQryFlag);
	getInt(req, "sourceContract", &myreq.sourceContract);
	getString(req, "contractNO", myreq.contractNO);
	int i = this->api->ReqFASLRepayStockTransfer(&myreq);
	return i;
};

int TdApi::reqFASLEntrustCrdtOrder(const dict &req)
{
	DFITCFASLReqEntrustCrdtOrderField myreq = DFITCFASLReqEntrustCrdtOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "entrustQty", &myreq.entrustQty);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "orderCategory", &myreq.orderCategory);
	getInt(req, "orderType", &myreq.orderType);
	getInt(req, "entrustType", &myreq.entrustType);
	getInt(req, "orderTradeLimit", &myreq.orderTradeLimit);
	getInt(req, "orderExpiryDate", &myreq.orderExpiryDate);
	getInt(req, "orderEffectiveDate", &myreq.orderEffectiveDate);
	getDouble(req, "stopLossLimitPrice", &myreq.stopLossLimitPrice);
	getString(req, "trusteeshipUnit", myreq.trusteeshipUnit);
	getInt(req, "serialID", &myreq.serialID);
	getString(req, "devID", myreq.devID);
	getString(req, "devDecInfo", myreq.devDecInfo);
	getString(req, "step", myreq.step);
	getInt(req, "sourceContract", &myreq.sourceContract);
	getString(req, "contractNO", myreq.contractNO);
	getInt(req, "entrustQryFlag", &myreq.entrustQryFlag);
	getInt(req, "specialSigns", &myreq.specialSigns);
	getString(req, "dividendsPattern", myreq.dividendsPattern);
	int i = this->api->ReqFASLEntrustCrdtOrder(&myreq);
	return i;
};

int TdApi::reqFASLEntrustOrder(const dict &req)
{
	DFITCFASLReqEntrustOrderField myreq = DFITCFASLReqEntrustOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "entrustQty", &myreq.entrustQty);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "orderCategory", &myreq.orderCategory);
	getInt(req, "orderType", &myreq.orderType);
	getInt(req, "orderTradeLimit", &myreq.orderTradeLimit);
	getInt(req, "orderExpiryDate", &myreq.orderExpiryDate);
	getInt(req, "orderEffectiveDate", &myreq.orderEffectiveDate);
	getDouble(req, "stopLossLimitPrice", &myreq.stopLossLimitPrice);
	getString(req, "trusteeshipUnit", myreq.trusteeshipUnit);
	getInt(req, "serialID", &myreq.serialID);
	getString(req, "devID", myreq.devID);
	getString(req, "devDecInfo", myreq.devDecInfo);
	getString(req, "step", myreq.step);
	getInt(req, "sourceContract", &myreq.sourceContract);
	int i = this->api->ReqFASLEntrustOrder(&myreq);
	return i;
};

int TdApi::reqFASLWithdrawOrder(const dict &req)
{
	DFITCFASLReqWithdrawOrderField myreq = DFITCFASLReqWithdrawOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "spdOrderID", &myreq.spdOrderID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getInt64(req, "sessionID", &myreq.sessionID);
	getString(req, "exchangeID", myreq.exchangeID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "serialID", &myreq.serialID);
	getString(req, "devID", myreq.devID);
	getString(req, "devDecInfo", myreq.devDecInfo);
	int i = this->api->ReqFASLWithdrawOrder(&myreq);
	return i;
};

int TdApi::reqFASLCalcAbleEntrustCrdtQty(const dict &req)
{
	DFITCFASLReqCalcAbleEntrustCrdtQtyField myreq = DFITCFASLReqCalcAbleEntrustCrdtQtyField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "orderType", &myreq.orderType);
	getInt(req, "entrustType", &myreq.entrustType);
	getString(req, "trusteeshipUnit", myreq.trusteeshipUnit);
	getInt(req, "sourceContract", &myreq.sourceContract);
	getString(req, "contractNO", myreq.contractNO);
	int i = this->api->ReqFASLCalcAbleEntrustCrdtQty(&myreq);
	return i;
};

int TdApi::reqFASLQryCrdtFunds(const dict &req)
{
	DFITCFASLReqQryCrdtFundsField myreq = DFITCFASLReqQryCrdtFundsField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "fundsQryFlag", &myreq.fundsQryFlag);
	getInt(req, "flag", &myreq.flag);
	int i = this->api->ReqFASLQryCrdtFunds(&myreq);
	return i;
};

int TdApi::reqFASLQryCrdtContract(const dict &req)
{
	DFITCFASLReqQryCrdtContractField myreq = DFITCFASLReqQryCrdtContractField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "contractNO", myreq.contractNO);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "rowIndex", &myreq.rowIndex);
	getInt(req, "rowCount", &myreq.rowCount);
	int i = this->api->ReqFASLQryCrdtContract(&myreq);
	return i;
};

int TdApi::reqFASLQryCrdtConChangeInfo(const dict &req)
{
	DFITCFASLReqQryCrdtConChangeInfoField myreq = DFITCFASLReqQryCrdtConChangeInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "withdrawFlag", myreq.withdrawFlag);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getString(req, "contractNO", myreq.contractNO);
	getInt(req, "conSerialNO", &myreq.conSerialNO);
	int i = this->api->ReqFASLQryCrdtConChangeInfo(&myreq);
	return i;
};

int TdApi::reqFASLTransferFunds(const dict &req)
{
	DFITCFASLReqTransferFundsField myreq = DFITCFASLReqTransferFundsField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "currency", myreq.currency);
	getString(req, "summaryMsg", myreq.summaryMsg);
	getDouble(req, "operateFunds", &myreq.operateFunds);
	getInt(req, "fundsTransFlag", &myreq.fundsTransFlag);
	int i = this->api->ReqFASLTransferFunds(&myreq);
	return i;
};

int TdApi::reqFASLTransferStock(const dict &req)
{
	DFITCFASLReqTransferStockField myreq = DFITCFASLReqTransferStockField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getString(req, "currency", myreq.currency);
	getString(req, "summaryMsg", myreq.summaryMsg);
	getInt(req, "operatorQty", &myreq.operatorQty);
	getInt(req, "stockTransFlag", &myreq.stockTransFlag);
	getString(req, "branchID", myreq.branchID);
	getString(req, "circulateType", myreq.circulateType);
	getString(req, "shareNature", myreq.shareNature);
	int i = this->api->ReqFASLTransferStock(&myreq);
	return i;
};

int TdApi::reqFASLQryAccountInfo(const dict &req)
{
	DFITCFASLReqQryAccountField myreq = DFITCFASLReqQryAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	int i = this->api->ReqFASLQryAccountInfo(&myreq);
	return i;
};

int TdApi::reqFASLQryCapitalAccountInfo(const dict &req)
{
	DFITCFASLReqQryCapitalAccountField myreq = DFITCFASLReqQryCapitalAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "fundsQryFlag", &myreq.fundsQryFlag);
	getString(req, "capitalID", myreq.capitalID);
	int i = this->api->ReqFASLQryCapitalAccountInfo(&myreq);
	return i;
};

int TdApi::reqFASLQryShareholderInfo(const dict &req)
{
	DFITCFASLReqQryShareholderField myreq = DFITCFASLReqQryShareholderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	int i = this->api->ReqFASLQryShareholderInfo(&myreq);
	return i;
};

int TdApi::reqFASLQryPosition(const dict &req)
{
	DFITCFASLReqQryPositionField myreq = DFITCFASLReqQryPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "posiQryFlag", &myreq.posiQryFlag);
	getString(req, "capitalID", myreq.capitalID);
	getString(req, "circulateType", myreq.circulateType);
	getInt(req, "rowIndex", &myreq.rowIndex);
	getInt(req, "rowCount", &myreq.rowCount);
	int i = this->api->ReqFASLQryPosition(&myreq);
	return i;
};

int TdApi::reqFASLQryEntrustOrder(const dict &req)
{
	DFITCFASLReqQryEntrustOrderField myreq = DFITCFASLReqQryEntrustOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getInt(req, "spdOrderID", &myreq.spdOrderID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "capitalID", myreq.capitalID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getString(req, "withdrawFlag", myreq.withdrawFlag);
	getInt(req, "orderCategory", &myreq.orderCategory);
	getInt(req, "serialID", &myreq.serialID);
	getString(req, "devID", myreq.devID);
	getString(req, "devDecInfo", myreq.devDecInfo);
	getInt(req, "entrustQryFlag", &myreq.entrustQryFlag);
	getInt(req, "rowIndex", &myreq.rowIndex);
	getInt(req, "rowCount", &myreq.rowCount);
	int i = this->api->ReqFASLQryEntrustOrder(&myreq);
	return i;
};

int TdApi::reqFASLQrySerialTrade(const dict &req)
{
	DFITCFASLReqQrySerialTradeField myreq = DFITCFASLReqQrySerialTradeField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getInt(req, "spdOrderID", &myreq.spdOrderID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "capitalID", myreq.capitalID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getString(req, "withdrawFlag", myreq.withdrawFlag);
	getInt(req, "orderCategory", &myreq.orderCategory);
	getInt(req, "serialID", &myreq.serialID);
	getString(req, "devID", myreq.devID);
	getString(req, "devDecInfo", myreq.devDecInfo);
	getInt(req, "entrustQryFlag", &myreq.entrustQryFlag);
	getInt(req, "rowIndex", &myreq.rowIndex);
	getInt(req, "rowCount", &myreq.rowCount);
	int i = this->api->ReqFASLQrySerialTrade(&myreq);
	return i;
};

int TdApi::reqFASLQryRealTimeTrade(const dict &req)
{
	DFITCFASLReqQryRealTimeTradeField myreq = DFITCFASLReqQryRealTimeTradeField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getInt(req, "spdOrderID", &myreq.spdOrderID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "capitalID", myreq.capitalID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "orderCategory", &myreq.orderCategory);
	getInt(req, "serialID", &myreq.serialID);
	getInt(req, "entrustQryFlag", &myreq.entrustQryFlag);
	getInt(req, "rowIndex", &myreq.rowIndex);
	getInt(req, "rowCount", &myreq.rowCount);
	int i = this->api->ReqFASLQryRealTimeTrade(&myreq);
	return i;
};

int TdApi::reqFASLQryFreezeFundsDetail(const dict &req)
{
	DFITCFASLReqQryFreezeFundsDetailField myreq = DFITCFASLReqQryFreezeFundsDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "currency", myreq.currency);
	getInt(req, "fundsFreezeType", &myreq.fundsFreezeType);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "serialID", &myreq.serialID);
	getString(req, "capitalID", myreq.capitalID);
	getInt(req, "rowIndex", &myreq.rowIndex);
	getInt(req, "rowCount", &myreq.rowCount);
	int i = this->api->ReqFASLQryFreezeFundsDetail(&myreq);
	return i;
};

int TdApi::reqFASLQryFreezeStockDetail(const dict &req)
{
	DFITCFASLReqQryFreezeStockDetailField myreq = DFITCFASLReqQryFreezeStockDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getInt(req, "stockFreezeType", &myreq.stockFreezeType);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "serialID", &myreq.serialID);
	getInt(req, "rowIndex", &myreq.rowIndex);
	getInt(req, "rowCount", &myreq.rowCount);
	getInt(req, "outserialID", &myreq.outserialID);
	getString(req, "devDecInfo", myreq.devDecInfo);
	getInt(req, "queryFlag", &myreq.queryFlag);
	int i = this->api->ReqFASLQryFreezeStockDetail(&myreq);
	return i;
};

int TdApi::reqFASLQryTransferFundsDetail(const dict &req)
{
	DFITCFASLReqQryTransferFundsDetailField myreq = DFITCFASLReqQryTransferFundsDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "capitalID", myreq.capitalID);
	getInt(req, "rowIndex", &myreq.rowIndex);
	getInt(req, "rowCount", &myreq.rowCount);
	getInt(req, "accountNodeID", &myreq.accountNodeID);
	int i = this->api->ReqFASLQryTransferFundsDetail(&myreq);
	return i;
};

int TdApi::reqFASLQrySystemTime(const dict &req)
{
	DFITCFASLReqQryTradeTimeField myreq = DFITCFASLReqQryTradeTimeField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getInt(req, "flag", &myreq.flag);
	int i = this->api->ReqFASLQrySystemTime(&myreq);
	return i;
};

int TdApi::reqFASLQryTransferredContract(const dict &req)
{
	DFITCFASLReqQryTransferredContractField myreq = DFITCFASLReqQryTransferredContractField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "securityID", myreq.securityID);
	getString(req, "exchangeID", myreq.exchangeID);
	int i = this->api->ReqFASLQryTransferredContract(&myreq);
	return i;
};

int TdApi::reqFASLDesirableFundsOut(const dict &req)
{
	DFITCFASLReqDesirableFundsOutField myreq = DFITCFASLReqDesirableFundsOutField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "currency", myreq.currency);
	getDouble(req, "operateFunds", &myreq.operateFunds);
	getString(req, "summaryMsg", myreq.summaryMsg);
	int i = this->api->ReqFASLDesirableFundsOut(&myreq);
	return i;
};

int TdApi::reqFASLQryGuaranteedContract(const dict &req)
{
	DFITCFASLReqQryGuaranteedContractField myreq = DFITCFASLReqQryGuaranteedContractField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	int i = this->api->ReqFASLQryGuaranteedContract(&myreq);
	return i;
};

int TdApi::reqFASLQryUnderlyingContract(const dict &req)
{
	DFITCFASLReqQryUnderlyingContractField myreq = DFITCFASLReqQryUnderlyingContractField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "rowIndex", &myreq.rowIndex);
	getInt(req, "rowCount", &myreq.rowCount);
	int i = this->api->ReqFASLQryUnderlyingContract(&myreq);
	return i;
};

int TdApi::reqFASLQryCentreFundAvlInfo(const dict &req)
{
	DFITCFASLReqQryCentreFundAvlField myreq = DFITCFASLReqQryCentreFundAvlField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	int i = this->api->ReqFASLQryCentreFundAvlInfo(&myreq);
	return i;
};

int TdApi::reqFASLQryPlacingInterestsInfo(const dict &req)
{
	DFITCFASLReqQryPlacingInterestsField myreq = DFITCFASLReqQryPlacingInterestsField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	int i = this->api->ReqFASLQryPlacingInterestsInfo(&myreq);
	return i;
};

int TdApi::reqFASLUserPasswordUpdate(const dict &req)
{
	DFITCSECReqPasswordUpdateField myreq = DFITCSECReqPasswordUpdateField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "oldPassword", myreq.oldPassword);
	getString(req, "newPassword", myreq.newPassword);
	getInt(req, "passwordType", &myreq.passwordType);
	int i = this->api->ReqFASLUserPasswordUpdate(&myreq);
	return i;
};

int TdApi::reqStockETFEntrustOrder(const dict &req)
{
	DFITCStockReqETFEntrustOrderField myreq = DFITCStockReqETFEntrustOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "fundID", myreq.fundID);
	getString(req, "componentStocksID", myreq.componentStocksID);
	getInt(req, "entrustQty", &myreq.entrustQty);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "orderType", &myreq.orderType);
	getInt(req, "orderCategory", &myreq.orderCategory);
	getString(req, "step", myreq.step);
	getInt(req, "entrustBatchID", &myreq.entrustBatchID);
	getString(req, "eachSeatID", myreq.eachSeatID);
	getInt(req, "serialID", &myreq.serialID);
	int i = this->api->ReqStockETFEntrustOrder(&myreq);
	return i;
};

int TdApi::reqStockETFBasketOrder(const dict &req)
{
	DFITCStockReqETFBasketOrderField myreq = DFITCStockReqETFBasketOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "fundID", myreq.fundID);
	getInt(req, "entrustQty", &myreq.entrustQty);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "orderType", &myreq.orderType);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "orderCategory", &myreq.orderCategory);
	getString(req, "step", myreq.step);
	getInt(req, "entrustBatchID", &myreq.entrustBatchID);
	getString(req, "eachSeatID", myreq.eachSeatID);
	getInt(req, "serialID", &myreq.serialID);
	int i = this->api->ReqStockETFBasketOrder(&myreq);
	return i;
};

int TdApi::reqStockBondRepurchaseOrder(const dict &req)
{
	DFITCStockReqBondRepurchaseOrderField myreq = DFITCStockReqBondRepurchaseOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "entrustQty", &myreq.entrustQty);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "orderType", &myreq.orderType);
	getInt(req, "orderCategory", &myreq.orderCategory);
	getString(req, "step", myreq.step);
	getInt(req, "serialID", &myreq.serialID);
	int i = this->api->ReqStockBondRepurchaseOrder(&myreq);
	return i;
};

int TdApi::reqStockBondInOutStockOrder(const dict &req)
{
	DFITCStockReqBondInOutStockOrderField myreq = DFITCStockReqBondInOutStockOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "entrustQty", &myreq.entrustQty);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "orderType", &myreq.orderType);
	getInt(req, "orderCategory", &myreq.orderCategory);
	getInt(req, "orderTradeLimit", &myreq.orderTradeLimit);
	getInt(req, "orderExpiryDate", &myreq.orderExpiryDate);
	getInt(req, "orderEffectiveDate", &myreq.orderEffectiveDate);
	getDouble(req, "stopLossLimitPrice", &myreq.stopLossLimitPrice);
	getString(req, "step", myreq.step);
	getInt(req, "serialID", &myreq.serialID);
	int i = this->api->ReqStockBondInOutStockOrder(&myreq);
	return i;
};

int TdApi::reqStockIssueBusinessOrder(const dict &req)
{
	DFITCStockReqIssueBusinessOrderField myreq = DFITCStockReqIssueBusinessOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "entrustQty", &myreq.entrustQty);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "orderType", &myreq.orderType);
	getInt(req, "serialID", &myreq.serialID);
	int i = this->api->ReqStockIssueBusinessOrder(&myreq);
	return i;
};

int TdApi::reqStockLOFEntrustOrder(const dict &req)
{
	DFITCStockReqLOFEntrustOrderField myreq = DFITCStockReqLOFEntrustOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "fundID", myreq.fundID);
	getInt(req, "entrustQty", &myreq.entrustQty);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "orderType", &myreq.orderType);
	getInt(req, "orderCategory", &myreq.orderCategory);
	getString(req, "dividendsPattern", myreq.dividendsPattern);
	getInt(req, "serialID", &myreq.serialID);
	int i = this->api->ReqStockLOFEntrustOrder(&myreq);
	return i;
};

int TdApi::reqStockAfterHoursPriceOrder(const dict &req)
{
	DFITCStockReqAfterHoursPriceOrderField myreq = DFITCStockReqAfterHoursPriceOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "entrustQty", &myreq.entrustQty);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "orderType", &myreq.orderType);
	getInt(req, "serialID", &myreq.serialID);
	int i = this->api->ReqStockAfterHoursPriceOrder(&myreq);
	return i;
};

int TdApi::reqStockNonTradingBusinessOrder(const dict &req)
{
	DFITCStockReqNonTradingBusinessOrderField myreq = DFITCStockReqNonTradingBusinessOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "entrustQty", &myreq.entrustQty);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "orderType", &myreq.orderType);
	getInt(req, "orderTradeLimit", &myreq.orderTradeLimit);
	getInt(req, "orderExpiryDate", &myreq.orderExpiryDate);
	getInt(req, "orderEffectiveDate", &myreq.orderEffectiveDate);
	getDouble(req, "stopLossLimitPrice", &myreq.stopLossLimitPrice);
	getInt(req, "orderCategoryType", &myreq.orderCategoryType);
	getString(req, "step", myreq.step);
	getInt(req, "serialID", &myreq.serialID);
	getInt(req, "entrustBatchID", &myreq.entrustBatchID);
	getString(req, "shareNature", myreq.shareNature);
	getString(req, "branchID", myreq.branchID);
	int i = this->api->ReqStockNonTradingBusinessOrder(&myreq);
	return i;
};

int TdApi::reqStockSHMutualFundOrder(const dict &req)
{
	DFITCStockReqSHMutualFundOrderField myreq = DFITCStockReqSHMutualFundOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getInt(req, "localOrderID", &myreq.localOrderID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "entrustQty", &myreq.entrustQty);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "orderType", &myreq.orderType);
	getInt(req, "orderCategory", &myreq.orderCategory);
	getString(req, "dividendsPattern", myreq.dividendsPattern);
	getString(req, "fundID", myreq.fundID);
	getInt(req, "orderTradeLimit", &myreq.orderTradeLimit);
	getInt(req, "orderExpiryDate", &myreq.orderExpiryDate);
	getInt(req, "orderEffectiveDate", &myreq.orderEffectiveDate);
	getDouble(req, "stopLossLimitPrice", &myreq.stopLossLimitPrice);
	getInt(req, "orderCategoryType", &myreq.orderCategoryType);
	getString(req, "step", myreq.step);
	getInt(req, "serialID", &myreq.serialID);
	int i = this->api->ReqStockSHMutualFundOrder(&myreq);
	return i;
};

int TdApi::reqStockCalcAblePurchaseETFBasketQty(const dict &req)
{
	DFITCStockReqCalcAblePurchaseETFBasketQtyField myreq = DFITCStockReqCalcAblePurchaseETFBasketQtyField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "orderType", &myreq.orderType);
	int i = this->api->ReqStockCalcAblePurchaseETFBasketQty(&myreq);
	return i;
};

int TdApi::reqStockCalcAbleBondRepurchaseQty(const dict &req)
{
	DFITCStockReqCalcAbleBondRepurchaseQtyField myreq = DFITCStockReqCalcAbleBondRepurchaseQtyField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getInt(req, "orderType", &myreq.orderType);
	int i = this->api->ReqStockCalcAbleBondRepurchaseQty(&myreq);
	return i;
};

int TdApi::reqStockCalcAbleIssueBusinessQty(const dict &req)
{
	DFITCStockReqCalcAbleIssueBusinessQtyField myreq = DFITCStockReqCalcAbleIssueBusinessQtyField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "orderType", &myreq.orderType);
	int i = this->api->ReqStockCalcAbleIssueBusinessQty(&myreq);
	return i;
};

int TdApi::reqStockCalcAblePurchaseLOFQty(const dict &req)
{
	DFITCStockReqCalcAblePurchaseLOFQtyField myreq = DFITCStockReqCalcAblePurchaseLOFQtyField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "orderType", &myreq.orderType);
	int i = this->api->ReqStockCalcAblePurchaseLOFQty(&myreq);
	return i;
};

int TdApi::reqStockCalcAbleAfterHoursPriceQty(const dict &req)
{
	DFITCStockReqCalcAbleAfterHoursPriceQtyField myreq = DFITCStockReqCalcAbleAfterHoursPriceQtyField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "orderType", &myreq.orderType);
	getInt8(req, "specificFlag", &myreq.specificFlag);
	int i = this->api->ReqStockCalcAbleAfterHoursPriceQty(&myreq);
	return i;
};

int TdApi::reqStockCalcAbleNonTradingBusinessQty(const dict &req)
{
	DFITCStockReqCalcAbleNonTradingBusinessQtyField myreq = DFITCStockReqCalcAbleNonTradingBusinessQtyField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "orderType", &myreq.orderType);
	int i = this->api->ReqStockCalcAbleNonTradingBusinessQty(&myreq);
	return i;
};

int TdApi::reqStockCalcAbleSHMutualFundQty(const dict &req)
{
	DFITCStockReqCalcAbleSHMutualFundQtyField myreq = DFITCStockReqCalcAbleSHMutualFundQtyField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "requestID", &myreq.requestID);
	getString(req, "exchangeID", myreq.exchangeID);
	getString(req, "accountID", myreq.accountID);
	getString(req, "securityID", myreq.securityID);
	getInt(req, "entrustDirection", &myreq.entrustDirection);
	getDouble(req, "entrustPrice", &myreq.entrustPrice);
	getInt(req, "orderType", &myreq.orderType);
	int i = this->api->ReqStockCalcAbleSHMutualFundQty(&myreq);
	return i;
};


///-------------------------------------------------------------------------------------
///Boost.Python封装
///-------------------------------------------------------------------------------------

class PyTdApi : public TdApi
{
public:
	using TdApi::TdApi;
	void onFrontConnected() override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onFrontConnected);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onFrontDisconnected(int reqid) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onFrontDisconnected, reqid);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnNotice(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnNotice, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspError(const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspError, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockUserLogin(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockUserLogin, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockUserLogout(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockUserLogout, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockUserPasswordUpdate(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockUserPasswordUpdate, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockEntrustOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockEntrustOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockWithdrawOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockWithdrawOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockQryEntrustOrder(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockQryEntrustOrder, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockQryRealTimeTrade(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockQryRealTimeTrade, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockQrySerialTrade(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockQrySerialTrade, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockQryPosition(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockQryPosition, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockQryCapitalAccountInfo(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockQryCapitalAccountInfo, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockQryAccountInfo(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockQryAccountInfo, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockQryShareholderInfo(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockQryShareholderInfo, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockTransferFunds(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockTransferFunds, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockEntrustBatchOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockEntrustBatchOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockWithdrawBatchOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockWithdrawBatchOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockCalcAbleEntrustQty(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockCalcAbleEntrustQty, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockCalcAblePurchaseETFQty(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockCalcAblePurchaseETFQty, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockQryFreezeFundsDetail(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockQryFreezeFundsDetail, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockQryFreezeStockDetail(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockQryFreezeStockDetail, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockQryTransferStockDetail(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockQryTransferStockDetail, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockQryTransferFundsDetail(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockQryTransferFundsDetail, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockQryStockInfo(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockQryStockInfo, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockQryStockStaticInfo(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockQryStockStaticInfo, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockQryTradeTime(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockQryTradeTime, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onStockEntrustOrderRtn(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onStockEntrustOrderRtn, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onStockTradeRtn(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onStockTradeRtn, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onStockWithdrawOrderRtn(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onStockWithdrawOrderRtn, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPUserLogin(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPUserLogin, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPUserLogout(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPUserLogout, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPUserPasswordUpdate(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPUserPasswordUpdate, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPEntrustOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPEntrustOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPQuoteEntrustOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPQuoteEntrustOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPGroupSplit(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPGroupSplit, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPGroupExectueOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPGroupExectueOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPQryGroupPosition(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPQryGroupPosition, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPLockOUnLockStock(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPLockOUnLockStock, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPWithdrawOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPWithdrawOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPQryEntrustOrder(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPQryEntrustOrder, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPQrySerialTrade(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPQrySerialTrade, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPQryPosition(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPQryPosition, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPQryCollateralPosition(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPQryCollateralPosition, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPQryCapitalAccountInfo(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPQryCapitalAccountInfo, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPQryAccountInfo(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPQryAccountInfo, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPQryShareholderInfo(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPQryShareholderInfo, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPCalcAbleEntrustQty(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPCalcAbleEntrustQty, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPQryAbleLockStock(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPQryAbleLockStock, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPQryContactInfo(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPQryContactInfo, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPExectueOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPExectueOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPQryExecAssiInfo(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPQryExecAssiInfo, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPQryTradeTime(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPQryTradeTime, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPQryExchangeInfo(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPQryExchangeInfo, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPQryCommission(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPQryCommission, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPQryDeposit(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPQryDeposit, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPQryContractObjectInfo(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPQryContractObjectInfo, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onSOPEntrustOrderRtn(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onSOPEntrustOrderRtn, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onSOPTradeRtn(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onSOPTradeRtn, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onSOPWithdrawOrderRtn(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onSOPWithdrawOrderRtn, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onSOPQuoteEntrustOrderRtn(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onSOPQuoteEntrustOrderRtn, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPCapitalTranInOut(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPCapitalTranInOut, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPCapitalDistributionRatio(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPCapitalDistributionRatio, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPFundTransBetweenNodes(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPFundTransBetweenNodes, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSOPModCapitalDistributionRatio(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSOPModCapitalDistributionRatio, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLUserLogin(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLUserLogin, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLUserLogout(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLUserLogout, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryAbleFinInfo(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryAbleFinInfo, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryAbleSloInfo(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryAbleSloInfo, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLTransferCollateral(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLTransferCollateral, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLDirectRepayment(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLDirectRepayment, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLRepayStockTransfer(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLRepayStockTransfer, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLEntrustCrdtOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLEntrustCrdtOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLEntrustOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLEntrustOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLCalcAbleEntrustCrdtQty(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLCalcAbleEntrustCrdtQty, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryCrdtFunds(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryCrdtFunds, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryCrdtContract(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryCrdtContract, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryCrdtConChangeInfo(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryCrdtConChangeInfo, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLTransferFunds(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLTransferFunds, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLTransferStock(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLTransferStock, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryAccountInfo(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryAccountInfo, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryCapitalAccountInfo(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryCapitalAccountInfo, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryShareholderInfo(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryShareholderInfo, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryPosition(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryPosition, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryEntrustOrder(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryEntrustOrder, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQrySerialTrade(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQrySerialTrade, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryRealTimeTrade(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryRealTimeTrade, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryFreezeFundsDetail(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryFreezeFundsDetail, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryFreezeStockDetail(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryFreezeStockDetail, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryTransferFundsDetail(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryTransferFundsDetail, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLWithdrawOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLWithdrawOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQrySystemTime(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQrySystemTime, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryTransferredContract(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryTransferredContract, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLDesirableFundsOut(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLDesirableFundsOut, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryGuaranteedContract(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryGuaranteedContract, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryUnderlyingContract(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryUnderlyingContract, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryCentreFundAvlInfo(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryCentreFundAvlInfo, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLQryPlacingInterestsInfo(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLQryPlacingInterestsInfo, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFASLUserPasswordUpdate(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFASLUserPasswordUpdate, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onFASLEntrustOrderRtn(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onFASLEntrustOrderRtn, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onFASLTradeRtn(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onFASLTradeRtn, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onFASLWithdrawOrderRtn(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onFASLWithdrawOrderRtn, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onFASLLiabilitiesRtn(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onFASLLiabilitiesRtn, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockETFEntrustOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockETFEntrustOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockETFBasketOrder(const dict &data, const dict &error, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockETFBasketOrder, data, error, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockBondRepurchaseOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockBondRepurchaseOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockBondInOutStockOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockBondInOutStockOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockIssueBusinessOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockIssueBusinessOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockLOFEntrustOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockLOFEntrustOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockAfterHoursPriceOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockAfterHoursPriceOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockNonTradingBusinessOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockNonTradingBusinessOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockSHMutualFundOrder(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockSHMutualFundOrder, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockCalcAblePurchaseETFBasketQty(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockCalcAblePurchaseETFBasketQty, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockCalcAbleBondRepurchaseQty(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockCalcAbleBondRepurchaseQty, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockCalcAbleIssueBusinessQty(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockCalcAbleIssueBusinessQty, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockCalcAblePurchaseLOFQty(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockCalcAblePurchaseLOFQty, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockCalcAbleAfterHoursPriceQty(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockCalcAbleAfterHoursPriceQty, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockCalcAbleNonTradingBusinessQty(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockCalcAbleNonTradingBusinessQty, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspStockCalcAbleSHMutualFundQty(const dict &data, const dict &error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspStockCalcAbleSHMutualFundQty, data, error);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};
};

PYBIND11_MODULE(vnhtstd, m)
{
	class_<TdApi, PyTdApi> TdApi(m, "TdApi", module_local());
	TdApi
		.def(init<>())
		.def("createDFITCSECTraderApi", &TdApi::createDFITCSECTraderApi)
		.def("release", &TdApi::release)
		.def("init", &TdApi::init)
		.def("exit", &TdApi::exit)
		.def("subscribePrivateTopic", &TdApi::subscribePrivateTopic)

		.def("reqStockUserLogin", &TdApi::reqStockUserLogin)
		.def("reqStockUserLogout", &TdApi::reqStockUserLogout)
		.def("reqStockUserPasswordUpdate", &TdApi::reqStockUserPasswordUpdate)
		.def("reqStockEntrustOrder", &TdApi::reqStockEntrustOrder)
		.def("reqStockWithdrawOrder", &TdApi::reqStockWithdrawOrder)
		.def("reqStockQryEntrustOrder", &TdApi::reqStockQryEntrustOrder)
		.def("reqStockQryRealTimeTrade", &TdApi::reqStockQryRealTimeTrade)
		.def("reqStockQrySerialTrade", &TdApi::reqStockQrySerialTrade)
		.def("reqStockQryPosition", &TdApi::reqStockQryPosition)
		.def("reqStockQryCapitalAccountInfo", &TdApi::reqStockQryCapitalAccountInfo)
		.def("reqStockQryAccountInfo", &TdApi::reqStockQryAccountInfo)
		.def("reqStockQryShareholderInfo", &TdApi::reqStockQryShareholderInfo)
		.def("reqStockTransferFunds", &TdApi::reqStockTransferFunds)
		.def("reqStockEntrustBatchOrder", &TdApi::reqStockEntrustBatchOrder)
		.def("reqStockWithdrawBatchOrder", &TdApi::reqStockWithdrawBatchOrder)
		.def("reqStockCalcAbleEntrustQty", &TdApi::reqStockCalcAbleEntrustQty)
		.def("reqStockCalcAblePurchaseETFQty", &TdApi::reqStockCalcAblePurchaseETFQty)
		.def("reqStockQryFreezeFundsDetail", &TdApi::reqStockQryFreezeFundsDetail)
		.def("reqStockQryFreezeStockDetail", &TdApi::reqStockQryFreezeStockDetail)
		.def("reqStockQryTransferFundsDetail", &TdApi::reqStockQryTransferFundsDetail)
		.def("reqStockQryTransferStockDetail", &TdApi::reqStockQryTransferStockDetail)
		.def("reqStockQryStockInfo", &TdApi::reqStockQryStockInfo)
		.def("reqStockQryStockStaticInfo", &TdApi::reqStockQryStockStaticInfo)
		.def("reqStockQryTradeTime", &TdApi::reqStockQryTradeTime)
		.def("reqSOPUserLogin", &TdApi::reqSOPUserLogin)
		.def("reqSOPUserLogout", &TdApi::reqSOPUserLogout)
		.def("reqSOPUserPasswordUpdate", &TdApi::reqSOPUserPasswordUpdate)
		.def("reqSOPEntrustOrder", &TdApi::reqSOPEntrustOrder)
		.def("reqSOPQuoteEntrustOrder", &TdApi::reqSOPQuoteEntrustOrder)
		.def("reqSOPGroupSplit", &TdApi::reqSOPGroupSplit)
		.def("reqSOPGroupExectueOrder", &TdApi::reqSOPGroupExectueOrder)
		.def("reqSOPQryGroupPosition", &TdApi::reqSOPQryGroupPosition)
		.def("reqSOPLockOUnLockStock", &TdApi::reqSOPLockOUnLockStock)
		.def("reqSOPWithdrawOrder", &TdApi::reqSOPWithdrawOrder)
		.def("reqSOPQryEntrustOrder", &TdApi::reqSOPQryEntrustOrder)
		.def("reqSOPQrySerialTrade", &TdApi::reqSOPQrySerialTrade)
		.def("reqSOPQryPosition", &TdApi::reqSOPQryPosition)
		.def("reqSOPQryCollateralPosition", &TdApi::reqSOPQryCollateralPosition)
		.def("reqSOPQryCapitalAccountInfo", &TdApi::reqSOPQryCapitalAccountInfo)
		.def("reqSOPQryAccountInfo", &TdApi::reqSOPQryAccountInfo)
		.def("reqSOPQryShareholderInfo", &TdApi::reqSOPQryShareholderInfo)
		.def("reqSOPCalcAbleEntrustQty", &TdApi::reqSOPCalcAbleEntrustQty)
		.def("reqSOPQryAbleLockStock", &TdApi::reqSOPQryAbleLockStock)
		.def("reqSOPQryContactInfo", &TdApi::reqSOPQryContactInfo)
		.def("reqSOPExectueOrder", &TdApi::reqSOPExectueOrder)
		.def("reqSOPQryExecAssiInfo", &TdApi::reqSOPQryExecAssiInfo)
		.def("reqSOPQryTradeTime", &TdApi::reqSOPQryTradeTime)
		.def("reqSOPQryExchangeInfo", &TdApi::reqSOPQryExchangeInfo)
		.def("reqSOPQryCommission", &TdApi::reqSOPQryCommission)
		.def("reqSOPQryDeposit", &TdApi::reqSOPQryDeposit)
		.def("reqSOPQryContractObjectInfo", &TdApi::reqSOPQryContractObjectInfo)
		.def("reqSOPCapitalTranInOut", &TdApi::reqSOPCapitalTranInOut)
		.def("reqSOPCapitalDistributionRatio", &TdApi::reqSOPCapitalDistributionRatio)
		.def("reqSOPFundTransBetweenNodes", &TdApi::reqSOPFundTransBetweenNodes)
		.def("reqSOPModCapitalDistributionRatio", &TdApi::reqSOPModCapitalDistributionRatio)
		.def("reqFASLUserLogin", &TdApi::reqFASLUserLogin)
		.def("reqFASLUserLogout", &TdApi::reqFASLUserLogout)
		.def("reqFASLQryAbleFinInfo", &TdApi::reqFASLQryAbleFinInfo)
		.def("reqFASLQryAbleSloInfo", &TdApi::reqFASLQryAbleSloInfo)
		.def("reqFASLTransferCollateral", &TdApi::reqFASLTransferCollateral)
		.def("reqFASLDirectRepayment", &TdApi::reqFASLDirectRepayment)
		.def("reqFASLRepayStockTransfer", &TdApi::reqFASLRepayStockTransfer)
		.def("reqFASLEntrustCrdtOrder", &TdApi::reqFASLEntrustCrdtOrder)
		.def("reqFASLEntrustOrder", &TdApi::reqFASLEntrustOrder)
		.def("reqFASLWithdrawOrder", &TdApi::reqFASLWithdrawOrder)
		.def("reqFASLCalcAbleEntrustCrdtQty", &TdApi::reqFASLCalcAbleEntrustCrdtQty)
		.def("reqFASLQryCrdtFunds", &TdApi::reqFASLQryCrdtFunds)
		.def("reqFASLQryCrdtContract", &TdApi::reqFASLQryCrdtContract)
		.def("reqFASLQryCrdtConChangeInfo", &TdApi::reqFASLQryCrdtConChangeInfo)
		.def("reqFASLTransferFunds", &TdApi::reqFASLTransferFunds)
		.def("reqFASLTransferStock", &TdApi::reqFASLTransferStock)
		.def("reqFASLQryAccountInfo", &TdApi::reqFASLQryAccountInfo)
		.def("reqFASLQryCapitalAccountInfo", &TdApi::reqFASLQryCapitalAccountInfo)
		.def("reqFASLQryShareholderInfo", &TdApi::reqFASLQryShareholderInfo)
		.def("reqFASLQryPosition", &TdApi::reqFASLQryPosition)
		.def("reqFASLQryEntrustOrder", &TdApi::reqFASLQryEntrustOrder)
		.def("reqFASLQrySerialTrade", &TdApi::reqFASLQrySerialTrade)
		.def("reqFASLQryRealTimeTrade", &TdApi::reqFASLQryRealTimeTrade)
		.def("reqFASLQryFreezeFundsDetail", &TdApi::reqFASLQryFreezeFundsDetail)
		.def("reqFASLQryFreezeStockDetail", &TdApi::reqFASLQryFreezeStockDetail)
		.def("reqFASLQryTransferFundsDetail", &TdApi::reqFASLQryTransferFundsDetail)
		.def("reqFASLQrySystemTime", &TdApi::reqFASLQrySystemTime)
		.def("reqFASLQryTransferredContract", &TdApi::reqFASLQryTransferredContract)
		.def("reqFASLDesirableFundsOut", &TdApi::reqFASLDesirableFundsOut)
		.def("reqFASLQryGuaranteedContract", &TdApi::reqFASLQryGuaranteedContract)
		.def("reqFASLQryUnderlyingContract", &TdApi::reqFASLQryUnderlyingContract)
		.def("reqFASLQryCentreFundAvlInfo", &TdApi::reqFASLQryCentreFundAvlInfo)
		.def("reqFASLQryPlacingInterestsInfo", &TdApi::reqFASLQryPlacingInterestsInfo)
		.def("reqFASLUserPasswordUpdate", &TdApi::reqFASLUserPasswordUpdate)
		.def("reqStockETFEntrustOrder", &TdApi::reqStockETFEntrustOrder)
		.def("reqStockETFBasketOrder", &TdApi::reqStockETFBasketOrder)
		.def("reqStockBondRepurchaseOrder", &TdApi::reqStockBondRepurchaseOrder)
		.def("reqStockBondInOutStockOrder", &TdApi::reqStockBondInOutStockOrder)
		.def("reqStockIssueBusinessOrder", &TdApi::reqStockIssueBusinessOrder)
		.def("reqStockLOFEntrustOrder", &TdApi::reqStockLOFEntrustOrder)
		.def("reqStockAfterHoursPriceOrder", &TdApi::reqStockAfterHoursPriceOrder)
		.def("reqStockNonTradingBusinessOrder", &TdApi::reqStockNonTradingBusinessOrder)
		.def("reqStockSHMutualFundOrder", &TdApi::reqStockSHMutualFundOrder)
		.def("reqStockCalcAblePurchaseETFBasketQty", &TdApi::reqStockCalcAblePurchaseETFBasketQty)
		.def("reqStockCalcAbleBondRepurchaseQty", &TdApi::reqStockCalcAbleBondRepurchaseQty)
		.def("reqStockCalcAbleIssueBusinessQty", &TdApi::reqStockCalcAbleIssueBusinessQty)
		.def("reqStockCalcAblePurchaseLOFQty", &TdApi::reqStockCalcAblePurchaseLOFQty)
		.def("reqStockCalcAbleAfterHoursPriceQty", &TdApi::reqStockCalcAbleAfterHoursPriceQty)
		.def("reqStockCalcAbleNonTradingBusinessQty", &TdApi::reqStockCalcAbleNonTradingBusinessQty)
		.def("reqStockCalcAbleSHMutualFundQty", &TdApi::reqStockCalcAbleSHMutualFundQty)

		.def("onFrontConnected", &TdApi::onFrontConnected)
		.def("onFrontDisconnected", &TdApi::onFrontDisconnected)
		.def("onRtnNotice", &TdApi::onRtnNotice)
		.def("onRspError", &TdApi::onRspError)
		.def("onRspStockUserLogin", &TdApi::onRspStockUserLogin)
		.def("onRspStockUserLogout", &TdApi::onRspStockUserLogout)
		.def("onRspStockUserPasswordUpdate", &TdApi::onRspStockUserPasswordUpdate)
		.def("onRspStockEntrustOrder", &TdApi::onRspStockEntrustOrder)
		.def("onRspStockWithdrawOrder", &TdApi::onRspStockWithdrawOrder)
		.def("onRspStockQryEntrustOrder", &TdApi::onRspStockQryEntrustOrder)
		.def("onRspStockQryRealTimeTrade", &TdApi::onRspStockQryRealTimeTrade)
		.def("onRspStockQrySerialTrade", &TdApi::onRspStockQrySerialTrade)
		.def("onRspStockQryPosition", &TdApi::onRspStockQryPosition)
		.def("onRspStockQryCapitalAccountInfo", &TdApi::onRspStockQryCapitalAccountInfo)
		.def("onRspStockQryAccountInfo", &TdApi::onRspStockQryAccountInfo)
		.def("onRspStockQryShareholderInfo", &TdApi::onRspStockQryShareholderInfo)
		.def("onRspStockTransferFunds", &TdApi::onRspStockTransferFunds)
		.def("onRspStockEntrustBatchOrder", &TdApi::onRspStockEntrustBatchOrder)
		.def("onRspStockWithdrawBatchOrder", &TdApi::onRspStockWithdrawBatchOrder)
		.def("onRspStockCalcAbleEntrustQty", &TdApi::onRspStockCalcAbleEntrustQty)
		.def("onRspStockCalcAblePurchaseETFQty", &TdApi::onRspStockCalcAblePurchaseETFQty)
		.def("onRspStockQryFreezeFundsDetail", &TdApi::onRspStockQryFreezeFundsDetail)
		.def("onRspStockQryFreezeStockDetail", &TdApi::onRspStockQryFreezeStockDetail)
		.def("onRspStockQryTransferStockDetail", &TdApi::onRspStockQryTransferStockDetail)
		.def("onRspStockQryTransferFundsDetail", &TdApi::onRspStockQryTransferFundsDetail)
		.def("onRspStockQryStockInfo", &TdApi::onRspStockQryStockInfo)
		.def("onRspStockQryStockStaticInfo", &TdApi::onRspStockQryStockStaticInfo)
		.def("onRspStockQryTradeTime", &TdApi::onRspStockQryTradeTime)
		.def("onStockEntrustOrderRtn", &TdApi::onStockEntrustOrderRtn)
		.def("onStockTradeRtn", &TdApi::onStockTradeRtn)
		.def("onStockWithdrawOrderRtn", &TdApi::onStockWithdrawOrderRtn)
		.def("onRspSOPUserLogin", &TdApi::onRspSOPUserLogin)
		.def("onRspSOPUserLogout", &TdApi::onRspSOPUserLogout)
		.def("onRspSOPUserPasswordUpdate", &TdApi::onRspSOPUserPasswordUpdate)
		.def("onRspSOPEntrustOrder", &TdApi::onRspSOPEntrustOrder)
		.def("onRspSOPQuoteEntrustOrder", &TdApi::onRspSOPQuoteEntrustOrder)
		.def("onRspSOPGroupSplit", &TdApi::onRspSOPGroupSplit)
		.def("onRspSOPGroupExectueOrder", &TdApi::onRspSOPGroupExectueOrder)
		.def("onRspSOPQryGroupPosition", &TdApi::onRspSOPQryGroupPosition)
		.def("onRspSOPLockOUnLockStock", &TdApi::onRspSOPLockOUnLockStock)
		.def("onRspSOPWithdrawOrder", &TdApi::onRspSOPWithdrawOrder)
		.def("onRspSOPQryEntrustOrder", &TdApi::onRspSOPQryEntrustOrder)
		.def("onRspSOPQrySerialTrade", &TdApi::onRspSOPQrySerialTrade)
		.def("onRspSOPQryPosition", &TdApi::onRspSOPQryPosition)
		.def("onRspSOPQryCollateralPosition", &TdApi::onRspSOPQryCollateralPosition)
		.def("onRspSOPQryCapitalAccountInfo", &TdApi::onRspSOPQryCapitalAccountInfo)
		.def("onRspSOPQryAccountInfo", &TdApi::onRspSOPQryAccountInfo)
		.def("onRspSOPQryShareholderInfo", &TdApi::onRspSOPQryShareholderInfo)
		.def("onRspSOPCalcAbleEntrustQty", &TdApi::onRspSOPCalcAbleEntrustQty)
		.def("onRspSOPQryAbleLockStock", &TdApi::onRspSOPQryAbleLockStock)
		.def("onRspSOPQryContactInfo", &TdApi::onRspSOPQryContactInfo)
		.def("onRspSOPExectueOrder", &TdApi::onRspSOPExectueOrder)
		.def("onRspSOPQryExecAssiInfo", &TdApi::onRspSOPQryExecAssiInfo)
		.def("onRspSOPQryTradeTime", &TdApi::onRspSOPQryTradeTime)
		.def("onRspSOPQryExchangeInfo", &TdApi::onRspSOPQryExchangeInfo)
		.def("onRspSOPQryCommission", &TdApi::onRspSOPQryCommission)
		.def("onRspSOPQryDeposit", &TdApi::onRspSOPQryDeposit)
		.def("onRspSOPQryContractObjectInfo", &TdApi::onRspSOPQryContractObjectInfo)
		.def("onSOPEntrustOrderRtn", &TdApi::onSOPEntrustOrderRtn)
		.def("onSOPTradeRtn", &TdApi::onSOPTradeRtn)
		.def("onSOPWithdrawOrderRtn", &TdApi::onSOPWithdrawOrderRtn)
		.def("onSOPQuoteEntrustOrderRtn", &TdApi::onSOPQuoteEntrustOrderRtn)
		.def("onRspSOPCapitalTranInOut", &TdApi::onRspSOPCapitalTranInOut)
		.def("onRspSOPCapitalDistributionRatio", &TdApi::onRspSOPCapitalDistributionRatio)
		.def("onRspSOPFundTransBetweenNodes", &TdApi::onRspSOPFundTransBetweenNodes)
		.def("onRspSOPModCapitalDistributionRatio", &TdApi::onRspSOPModCapitalDistributionRatio)
		.def("onRspFASLUserLogin", &TdApi::onRspFASLUserLogin)
		.def("onRspFASLUserLogout", &TdApi::onRspFASLUserLogout)
		.def("onRspFASLQryAbleFinInfo", &TdApi::onRspFASLQryAbleFinInfo)
		.def("onRspFASLQryAbleSloInfo", &TdApi::onRspFASLQryAbleSloInfo)
		.def("onRspFASLTransferCollateral", &TdApi::onRspFASLTransferCollateral)
		.def("onRspFASLDirectRepayment", &TdApi::onRspFASLDirectRepayment)
		.def("onRspFASLRepayStockTransfer", &TdApi::onRspFASLRepayStockTransfer)
		.def("onRspFASLEntrustCrdtOrder", &TdApi::onRspFASLEntrustCrdtOrder)
		.def("onRspFASLEntrustOrder", &TdApi::onRspFASLEntrustOrder)
		.def("onRspFASLCalcAbleEntrustCrdtQty", &TdApi::onRspFASLCalcAbleEntrustCrdtQty)
		.def("onRspFASLQryCrdtFunds", &TdApi::onRspFASLQryCrdtFunds)
		.def("onRspFASLQryCrdtContract", &TdApi::onRspFASLQryCrdtContract)
		.def("onRspFASLQryCrdtConChangeInfo", &TdApi::onRspFASLQryCrdtConChangeInfo)
		.def("onRspFASLTransferFunds", &TdApi::onRspFASLTransferFunds)
		.def("onRspFASLTransferStock", &TdApi::onRspFASLTransferStock)
		.def("onRspFASLQryAccountInfo", &TdApi::onRspFASLQryAccountInfo)
		.def("onRspFASLQryCapitalAccountInfo", &TdApi::onRspFASLQryCapitalAccountInfo)
		.def("onRspFASLQryShareholderInfo", &TdApi::onRspFASLQryShareholderInfo)
		.def("onRspFASLQryPosition", &TdApi::onRspFASLQryPosition)
		.def("onRspFASLQryEntrustOrder", &TdApi::onRspFASLQryEntrustOrder)
		.def("onRspFASLQrySerialTrade", &TdApi::onRspFASLQrySerialTrade)
		.def("onRspFASLQryRealTimeTrade", &TdApi::onRspFASLQryRealTimeTrade)
		.def("onRspFASLQryFreezeFundsDetail", &TdApi::onRspFASLQryFreezeFundsDetail)
		.def("onRspFASLQryFreezeStockDetail", &TdApi::onRspFASLQryFreezeStockDetail)
		.def("onRspFASLQryTransferFundsDetail", &TdApi::onRspFASLQryTransferFundsDetail)
		.def("onRspFASLWithdrawOrder", &TdApi::onRspFASLWithdrawOrder)
		.def("onRspFASLQrySystemTime", &TdApi::onRspFASLQrySystemTime)
		.def("onRspFASLQryTransferredContract", &TdApi::onRspFASLQryTransferredContract)
		.def("onRspFASLDesirableFundsOut", &TdApi::onRspFASLDesirableFundsOut)
		.def("onRspFASLQryGuaranteedContract", &TdApi::onRspFASLQryGuaranteedContract)
		.def("onRspFASLQryUnderlyingContract", &TdApi::onRspFASLQryUnderlyingContract)
		.def("onRspFASLQryCentreFundAvlInfo", &TdApi::onRspFASLQryCentreFundAvlInfo)
		.def("onRspFASLQryPlacingInterestsInfo", &TdApi::onRspFASLQryPlacingInterestsInfo)
		.def("onRspFASLUserPasswordUpdate", &TdApi::onRspFASLUserPasswordUpdate)
		.def("onFASLEntrustOrderRtn", &TdApi::onFASLEntrustOrderRtn)
		.def("onFASLTradeRtn", &TdApi::onFASLTradeRtn)
		.def("onFASLWithdrawOrderRtn", &TdApi::onFASLWithdrawOrderRtn)
		.def("onFASLLiabilitiesRtn", &TdApi::onFASLLiabilitiesRtn)
		.def("onRspStockETFEntrustOrder", &TdApi::onRspStockETFEntrustOrder)
		.def("onRspStockETFBasketOrder", &TdApi::onRspStockETFBasketOrder)
		.def("onRspStockBondRepurchaseOrder", &TdApi::onRspStockBondRepurchaseOrder)
		.def("onRspStockBondInOutStockOrder", &TdApi::onRspStockBondInOutStockOrder)
		.def("onRspStockIssueBusinessOrder", &TdApi::onRspStockIssueBusinessOrder)
		.def("onRspStockLOFEntrustOrder", &TdApi::onRspStockLOFEntrustOrder)
		.def("onRspStockAfterHoursPriceOrder", &TdApi::onRspStockAfterHoursPriceOrder)
		.def("onRspStockNonTradingBusinessOrder", &TdApi::onRspStockNonTradingBusinessOrder)
		.def("onRspStockSHMutualFundOrder", &TdApi::onRspStockSHMutualFundOrder)
		.def("onRspStockCalcAblePurchaseETFBasketQty", &TdApi::onRspStockCalcAblePurchaseETFBasketQty)
		.def("onRspStockCalcAbleBondRepurchaseQty", &TdApi::onRspStockCalcAbleBondRepurchaseQty)
		.def("onRspStockCalcAbleIssueBusinessQty", &TdApi::onRspStockCalcAbleIssueBusinessQty)
		.def("onRspStockCalcAblePurchaseLOFQty", &TdApi::onRspStockCalcAblePurchaseLOFQty)
		.def("onRspStockCalcAbleAfterHoursPriceQty", &TdApi::onRspStockCalcAbleAfterHoursPriceQty)
		.def("onRspStockCalcAbleNonTradingBusinessQty", &TdApi::onRspStockCalcAbleNonTradingBusinessQty)
		.def("onRspStockCalcAbleSHMutualFundQty", &TdApi::onRspStockCalcAbleSHMutualFundQty)
		;

}

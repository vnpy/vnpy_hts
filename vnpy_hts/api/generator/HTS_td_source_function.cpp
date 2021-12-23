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
	getInt(req, "sessionID", &myreq.sessionID);
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
	getInt(req, "sessionID", &myreq.sessionID);
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
	getInt(req, "sessionID", &myreq.sessionID);
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
	getInt(req, "specificFlag", &myreq.specificFlag);
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


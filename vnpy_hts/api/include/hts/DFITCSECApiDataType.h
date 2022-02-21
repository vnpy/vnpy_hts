/**
 * 版权所有(C)2012-2016, 福建顶点软件股份有限公司
 * 文件名称：DFITCSECApiDataType.h
 * 文件说明：定义接口所需的数据类型的头文件
 * 当前版本：1.6
 * 作者：专业交易接口开发组
 * 发布日期：2019年11月
 */

#ifndef DFITCSECAPIDATATYPE_H
#define DFITCSECAPIDATATYPE_H


//基本类型
#if defined(__APPLE__)

typedef signed char    ax_int8;
typedef short          ax_int16;
typedef int            ax_int32;
typedef long           ax_int64;

typedef unsigned char  ax_uint8;
typedef unsigned short ax_uint16;
typedef unsigned int   ax_uint32;
typedef unsigned long  ax_uint64;

typedef unsigned char  ax_size8;
typedef unsigned short ax_size16;
typedef unsigned int   ax_size32;
typedef unsigned long  ax_size64;

typedef char           ax_vbool;
typedef unsigned char  ax_vbyte;
typedef ax_int64           ax_vdate;
typedef float          ax_float32;
typedef double         ax_float64;

#elif defined(__linux__)

typedef signed char    ax_int8;
typedef short          ax_int16;
typedef int            ax_int32;
typedef long           ax_int64;

typedef unsigned char  ax_uint8;
typedef unsigned short ax_uint16;
typedef unsigned int   ax_uint32;
typedef unsigned long  ax_uint64;

typedef unsigned char  ax_size8;
typedef unsigned short ax_size16;
typedef unsigned int   ax_size32;
typedef unsigned long  ax_size64;

typedef char           ax_vbool;
typedef unsigned char  ax_vbyte;
typedef ax_int64           ax_vdate;
typedef float          ax_float32;
typedef double         ax_float64;

#else // Windows

typedef __int8            ax_int8;
typedef __int16           ax_int16;
typedef __int32           ax_int32;
typedef __int64           ax_int64;

typedef unsigned __int8   ax_uint8;
typedef unsigned __int16  ax_uint16;
typedef unsigned __int32  ax_uint32;
typedef unsigned __int64  ax_uint64;

typedef unsigned __int8   ax_size8;
typedef unsigned __int16  ax_size16;
typedef unsigned __int32  ax_size32;
typedef unsigned __int64  ax_size64;

typedef __int8            ax_vbool;
typedef unsigned char     ax_vbyte;
typedef __int64           ax_vdate;
typedef float             ax_float32;
typedef double            ax_float64;

#endif



/////////////////////////////////////////////////////////////////////////
///DFITCSECBusinessTypeType 是一个业务类别类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECBusinessTypeType;
///股票
#define DFITCSEC_BT_Stock                                         0
///ETF期权
#define DFITCSEC_BT_SOP                                           1
///融资融券
#define DFITCSEC_BT_FASL                                          2

/////////////////////////////////////////////////////////////////////////
///DFITCSECAppName 是一个APPNAME类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECAppName[31];

/////////////////////////////////////////////////////////////////////////
///DFITCSECAppVer 是一个APPVER类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECAppVer[31];

/////////////////////////////////////////////////////////////////////////
///DFITCSECCertFile 是一个CertFile类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECCertFile[31];

/////////////////////////////////////////////////////////////////////////
///DFITCSECRequestIDType 是一个请求ID类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32   DFITCSECRequestIDType; 

/////////////////////////////////////////////////////////////////////////
///DFITCSECAccountIDType 是一个客户号类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECAccountIDType[21];

/////////////////////////////////////////////////////////////////////////
///DFITCSECPasswordType 是一个密码类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECPasswordType[17];

/////////////////////////////////////////////////////////////////////////
///DFITCSECCAFile 是一个CAFile类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECCAFile[31];

/////////////////////////////////////////////////////////////////////////
///DFITCSECAuthenticCodeType 是一个认证码类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECAuthenticCodeType[31];

/////////////////////////////////////////////////////////////////////////
///DFITCSECAppID 是一个APPID类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECAppID[31];

/////////////////////////////////////////////////////////////////////////
///DFITCSECErrorIDType 是一个错误ID类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32   DFITCSECErrorIDType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECSessionIDType 是一个会话ID类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int64   DFITCSECSessionIDType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECLocalOrderIDType 是一个本地委托号类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32   DFITCSECLocalOrderIDType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECSpdOrderIDType 是一个柜台委托号类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECSpdOrderIDType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECMessageType 是一返回信息类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECMessageType[1024];

/////////////////////////////////////////////////////////////////////////
///DFITCSECFrontIDType 是一个前置机编号类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32   DFITCSECFrontIDType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECTimeType 是一个时间类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECTimeType[13];

/////////////////////////////////////////////////////////////////////////
///DFITCSECDateType 是一个日期类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECDateType;
/////////////////////////////////////////////////////////////////////////
///DFITCSECWeekType 是一个星期类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECWeekType;
/////////////////////////////////////////////////////////////////////////
///DFITCSECDateType 是一个毫秒类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECMillisecondType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECPasswordTypeType 是一个密码类别类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECPasswordTypeType;
///交易
#define DFITCSEC_PWT_Trade                                        1
///资金
#define DFITCSEC_PWT_Funds                                        2

/////////////////////////////////////////////////////////////////////////
///DFITCSECPriceType 是一个价格类型
/////////////////////////////////////////////////////////////////////////
typedef double DFITCSECPriceType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECFundsType 是一个金额类型
/////////////////////////////////////////////////////////////////////////
typedef double DFITCSECFundsType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECPositionSourceType 是一个头寸来源类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECPositionSourceType;
///普通头寸
#define DFITCSEC_PS_General                                       0
///专项头寸
#define DFITCSEC_PS_Special                                       1

/////////////////////////////////////////////////////////////////////////
///DFITCSECEntrustDirectionType 是一个委托类别类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECEntrustDirectionType;
///买
#define DFITCSEC_ED_Buy                                           1
///卖
#define DFITCSEC_ED_Sell                                          2
///配股缴款
#define DFITCSEC_ED_RightsIssueContribution                       3
///回购融资
#define DFITCSEC_ED_RepurchaseFinancing                           4
///回购融券
#define DFITCSEC_ED_RepurchaseSecurities                          5
///深圳转托管
#define DFITCSEC_ED_CustodyTransfer                               7
///上海指定交易
#define DFITCSEC_ED_DesignateTrading                              9
///上海撤指交易
#define DFITCSEC_ED_RevocationDesignateTrading                    10
///转债转股
#define DFITCSEC_ED_DebtToEquity                                  11
///转债回售
#define DFITCSEC_ED_BondsSoldBack                                 12
///配售申购
#define DFITCSEC_ED_PlacingPurchase                               14
///投票
#define DFITCSEC_ED_Vote                                          23
///配售放弃
#define DFITCSEC_ED_PlacingAbandon                                24
///ETF申购
#define DFITCSEC_ED_Purchase                                      29
///ETF赎回
#define DFITCSEC_ED_Redemp                                        30
///质押券入库
#define DFITCSEC_ED_PledgeVoucherIn                               37
///质押券出库
#define DFITCSEC_ED_PledgeVoucherOut                              38
///基金认购
#define DFITCSEC_ED_FundSubscribe                                 41
///基金申购
#define DFITCSEC_ED_FundPurchase                                  42
///基金赎回
#define DFITCSEC_ED_FundRedemption                                43
///基金分红设置
#define DFITCSEC_ED_FundBonusSetting                              44
///基金转换
#define DFITCSEC_ED_FundConversion                                46
///基金分拆
#define DFITCSEC_ED_FundSplit                                     47
///基金合并
#define DFITCSEC_ED_FundMerge                                     48
///权证行权
#define DFITCSEC_ED_WarrantExercise                               50
///融资买入
#define DFITCSEC_ED_FinancingToBuy                                61
///卖券还款
#define DFITCSEC_ED_SellSecPayment                                62
///买券还券
#define DFITCSEC_ED_BuySecRepaySec                                63
///融券卖出
#define DFITCSEC_ED_SecuritiesToSell                              64
///担保划入
#define DFITCSEC_ED_GuaranteeInto                                 65
///担保划出
#define DFITCSEC_ED_GuaranteeLayOff                               66
///融资强平
#define DFITCSEC_ED_FinancingForceSelling                         71
///融券强平
#define DFITCSEC_ED_SecuritiesForceSelling                        72
///预受要约
#define DFITCSEC_ED_PreAcceptedOffers                             76
///解除预受要约
#define DFITCSEC_ED_RelievePreAcceptedOffers                      77
///盘后定价买入
#define DFITCSEC_ED_AfterHoursPriceBuying                         178
///盘后定价卖出
#define DFITCSEC_ED_AfterHoursPriceSelling                        179
///回售撤销
#define DFITCSEC_ED_SoldBackRevoke                                212

/////////////////////////////////////////////////////////////////////////
///DFITCSECQuantityType 是一个数量类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECQuantityType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECLargeQuantityType 是一个大数量类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int64   DFITCSECLargeQuantityType;


/////////////////////////////////////////////////////////////////////////
///DFITCSECOrderTypeType 是一个订单类型类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECOrderTypeType;
////STOCK部分的订单类型
///限价
#define DFITCSEC_OT_LimitPrice                                    0
///最优五档立即成交剩余撤单（上海）
#define DFITCSEC_OT_SHBESTFRTradeLeftWithdraw                     1
///最优五档立即成交剩余转限价（上海）
#define DFITCSEC_OT_SHBESTFRTradeLeftTLimit                       2
///对方最优价格（深圳）
#define DFITCSEC_OT_SZOtherBestPrice                              101
///本方最优价格（深圳）
#define DFITCSEC_OT_SZBestPrice                                   102
///即时成交剩余撤销（深圳）
#define DFITCSEC_OT_SZImdeTradeLeftWithdraw                       103
///最优五档即时成交剩余撤销（深圳）
#define DFITCSEC_OT_SZBESTFRTradeLeftWithdraw                     104
///全额成交或撤销（深圳）
#define DFITCSEC_OT_SZBESTTotalTradeOWithdraw                     105
//add by xubin 
///盘后定价大宗交易收盘价（深圳）
#define DFITCSEC_OT_SZBlockTradeClosingPrice                      106
///盘后定价大宗交易平均价（深圳）
#define DFITCSEC_OT_SZBlockTradeAveragePrice                      107
///对手方最优价格（上海）
#define DFITCSEC_OT_SHOtherBestPrice                              4
///本方最优价格（上海）
#define DFITCSEC_OT_SHBestPrice                                   5
///盘后定价大宗交易收盘价（上海）
#define DFITCSEC_OT_SHBlockTradeClosingPrice                      6
//add by xubin
////SOP部分的订单类型
///限价
#define DFITCSEC_SOP_LimitPrice                                   1
///市价
#define DFITCSEC_SOP_LastPrice                                    2
///市价剩余转限价（上海）
#define DFITCSEC_SOP_LastTLimit                                   3
///市价本方最优（深圳）
#define DFITCSEC_SOP_MineBestPrice                                4
///市价最优五档成交剩余撤销（深圳）
#define DFITCSEC_SOP_OptimalFive                                  5

/////////////////////////////////////////////////////////////////////////
///DFITCSECAccountType 是一个客户类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECAccountType;
///公司
#define DFITCSEC_AT_Company                                       0
///个人
#define DFITCSEC_AT_Personal                                      1

/////////////////////////////////////////////////////////////////////////
///DFITCSECOrderBatchIDType 是一个委托批次号类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECEntrustBatchIDType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECSeatIDType 是一个席位号类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECSeatIDType[9];

/////////////////////////////////////////////////////////////////////////
///DFITCSECExchangeType 是一个交易所代码类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECExchangeIDType[3];
///沪A
#define DFITCSEC_EI_SH                                          "SH"
///深A
#define DFITCSEC_EI_SZ                                          "SZ"

/////////////////////////////////////////////////////////////////////////
///DFITCSecurityIDType 是一个证券代码类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECSecurityIDType[11];

////////////////////////////////////////////////////////////
///DFITCSECOrderQryFlagType 是一个报单查询标志类型
////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECEntrustQryFlagType;
///所有委托
#define DFITCSTOCK_EQF_Total                                    0
///可撤单委托
#define DFITCSTOCK_EQF_AbleWithdraw                             1

/////////////////////////////////////////////////////////////////////////
///DFITCSECWithdrawFlagType 是一个撤销标志类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECWithdrawFlagType[2];
///委托
#define DFITCSEC_CF_EntrustSucc                                 "O"
///撤单
#define DFITCSEC_CF_WithdrawSuc                                 "W"
////FASL信用合约变动信息查询专用
///撤销
#define DFITCSEC_CF_Withdraw                                    "-1"
///正常
#define DFITCSEC_CF_Normal                                      "0"

/////////////////////////////////////////////////////////////////////////
///DFITCSECIncQryIndexType 是一个增量查询索引类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECIncQryIndexType[129];

////////////////////////////////////////////////////////////
///DFITCSECTradeQryFlagType 是一个成交查询标志类型
////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECTradeQryFlagType;
///所有回转记录含撤单回转
#define DFITCSEC_TQF_Total                                      0
///返回成交记录
#define DFITCSEC_TQF_Trade                                      1

////////////////////////////////////////////////////////////
///DFITCSECPositionQryFlagType 是一个成交查询标志类型
////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECPositionQryFlagType;
///无扩展信息
#define DFITCSEC_PQF_Normal                                     0
///返回扩展信息
#define DFITCSEC_PQF_Extend                                     1

////////////////////////////////////////////////////////////
///DFITCSECFundsQryFlagType 是一个资金查询标志类型
////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECFundsQryFlagType;
///返回基本信息
#define DFITCSEC_FQF_Normal                                     0
///扩展字段，暂不使用
#define DFITCSEC_FQF_Extend                                     1

////////////////////////////////////////////////////////////
///DFITCSECSystemQryFlagType 是一个高精度返回标志类型
////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECSystemQryFlagType;
///正常时间
#define DFITCSEC_PQF_Normal                                     0
///高精度时间
#define DFITCSEC_SQF_High                                       1

/////////////////////////////////////////////////////////////////////////
///DFITCSECCurrencyType 是一个币种类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECCurrencyType[4];
///人民币
#define DFITCSEC_C_RMB                                          "RMB"
///美元 
#define DFITCSEC_S_USD                                          "USD"
///港币
#define DFITCSEC_S_HKD                                          "HKD"

////////////////////////////////////////////////////////////
///DFITCSECFundsTransferFlagType 是一个资金调转标志类型
////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECFundsTransferFlagType;
///转入
#define DFITCSEC_FTF_In                                         1
///转出 
#define DFITCSEC_FTF_Out                                        2

/////////////////////////////////////////////////////////////////////////
///DFITCSECEntrustBatchOrderDetailType 是一个批量委托明细类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECEntrustBatchOrderDetailType[1024];

/////////////////////////////////////////////////////////////////////////
///DFITCSECOrderRangeID 是一个委托号范围类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECOrderIDRangeType[1024];

/////////////////////////////////////////////////////////////////////////
///DFITCSECFundsFreezeTypeType 是一个资金冻结类别类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECFundsFreezeTypeType;
///委托冻结
#define DFITCSEC_FFT_EntrustFreeze                             1
///实时成交解冻
#define DFITCSEC_FFT_RealtimeTradeUnFreeze                     2
///手工冻结
#define DFITCSEC_FFT_ManualFreeze                              3
///手工解冻
#define DFITCSEC_FFT_ManualUnFreeze                            4

/////////////////////////////////////////////////////////////////////////
///DFITCSECTransFundsFreezeTypeType 是一个调拨资金冻结类别类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECTransFundsFreezeTypeType;
///初始化资金
#define DFITCSEC_FFT_InitFunds                                 50
///盘中资金调入
#define DFITCSEC_FFT_FundsIn                                   51
///盘中资金调出
#define DFITCSEC_FFT_FundsOut                                  52

/////////////////////////////////////////////////////////////////////////
///DFITCSECSerialIDType 是一个流水号类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECSerialIDType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECLargeSerialIDType 是一个大流水号类型
/////////////////////////////////////////////////////////////////////////
typedef char    DFITCSECLargeSerialIDType[30];

/////////////////////////////////////////////////////////////////////////
///DFITCSECStockFreezeTypeType 是一个证券冻结类别类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECStockFreezeTypeType;
///委托冻结
#define DFITCSEC_SFT_EntrustFreeze                            1
///增加可卖数量
#define DFITCSEC_SFT_IncSellQty                               2
///减少可卖数量
#define DFITCSEC_SFT_DecSellQty                               3
///手工长期冻结
#define DFITCSEC_SFT_ManualFreeze                             4
///清算冻结
#define DFITCSEC_SFT_ClearFreeze                              5
///ETF申购赎回冻结
#define DFITCSEC_SFT_PurchaseETFFreeze                        6
///要约收购冻结
#define DFITCSEC_SFT_OfferFreeze                              7
///权证行权冻结
#define DFITCSEC_SFT_ExeFreeze                                8
///债券抵押转标准券冻结
#define DFITCSEC_SFT_CollTranStandFreeze                      9
///质押券入库冻结
#define DFITCSEC_SFT_PledgeStoringFreeze                      10
///初始化股份
#define DFITCSEC_SFT_INITStock                                50
///盘中证券调入
#define DFITCSEC_SFT_StockIn                                  53
///盘中证券调出
#define DFITCSEC_SFT_StockOut                                 54

/////////////////////////////////////////////////////////////////////////
///DFITCSECShareholderIDType 是一个股东号类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECShareholderIDType[11];

/////////////////////////////////////////////////////////////////////////
///DFITCSECEntrustTypeType 是一个委托方式类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECEntrustTypeType;
///电话
#define DFITCSEC_ET_Phone                                    1
///磁卡
#define DFITCSEC_ET_MagicCard                                2
///热键
#define DFITCSEC_ET_Hotkey                                   4
///柜台
#define DFITCSEC_ET_Spd                                      8
///远程
#define DFITCSEC_ET_Remote                                   16
///互联网
#define DFITCSEC_ET_Internet                                 32
///手机
#define DFITCSEC_ET_Mobile                                   64

/////////////////////////////////////////////////////////////////////////
///DFITCSECSecurityNameType 是一个证券名称类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECSecurityNameType[21];

/////////////////////////////////////////////////////////////////////////
///DFITCSECDeclareResultType 是一个申报结果类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECDeclareResultType;
///未申报
#define DFITCSEC_DR_UnDeclare                                0
///正在申报
#define DFITCSEC_DR_Declaring                                1
///已申报未成交
#define DFITCSEC_DR_UnTrade                                  2
///非法委托/废单
#define DFITCSEC_DR_EntrustFail                              3
///部分成交
#define DFITCSEC_DR_PartTrade                                5
///全部成交
#define DFITCSEC_DR_TotalTrade                               6
///部成部撤
#define DFITCSEC_DR_TradeAWithdraw                           7
///全部撤单
#define DFITCSEC_DR_TotalWithdraw                            8
///撤单未成
#define DFITCSEC_DR_WithdrawFail                             9
///等待人工申报
#define DFITCSEC_DR_ManualDeclare                            10

/////////////////////////////////////////////////////////////////////////
///DFITCSECBatchDeclareResultType 是一个批量申报结果类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECBatchDeclareResultType;
///已申报
#define DFITCSEC_BDR_Declared                                1

/////////////////////////////////////////////////////////////////////////
///DFITCSECDeclareOrderIDType 是申报委托号类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECDeclareOrderIDType[11];

/////////////////////////////////////////////////////////////////////////
///DFITCSECIPAddressType 是一个ip地址类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECIPAddressType[32];

/////////////////////////////////////////////////////////////////////////
///DFITCSECMacAddressType 是一个mac地址类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECMacAddressType[32];

/////////////////////////////////////////////////////////////////////////
///DFITCSECTradeIDType 是一个成交编号类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECTradeIDType[17];

/////////////////////////////////////////////////////////////////////////
///DFITCSECSecurityTypeType 是一个证券类别类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECSecurityTypeType[3];

/////////////////////////////////////////////////////////////////////////
///DFITCSECAccountStatusType 是一个状态标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECAccountStatusType;
///正常
#define DFITCSEC_AS_Normal                                    0
///冻结
#define DFITCSEC_AS_Freeze                                    1
///客户卡挂失
#define DFITCSEC_AS_LossReporting                             2
///销户
#define DFITCSEC_AS_CloseAccount                              3
///小额休眠
#define DFITCSEC_AS_MicroDormancy                             6
///不合格
#define DFITCSEC_AS_UnQualified                               7
///公司不合格
#define DFITCSEC_AS_CompUnQualified                           9

/////////////////////////////////////////////////////////////////////////
///DFITCSECTradeStatusType 是一个状态标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECTradeStatusType;
///正常
#define DFITCSEC_TS_Normal                                    0
///暂停
#define DFITCSEC_TS_Suspend                                   2
///调出
#define DFITCSEC_TS_CallOut                                   4

/////////////////////////////////////////////////////////////////////////
///DFITCSECBranchIDType 是一个机构代码类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECBranchIDType[5];

/////////////////////////////////////////////////////////////////////////
///DFITCSECPhoneIDType 是一个联系电话类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECPhoneIDType[21];

/////////////////////////////////////////////////////////////////////////
///DFITCSECAccountNameType 是一个客户名称类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECAccountNameType[81];

/////////////////////////////////////////////////////////////////////////
///DFITCSECAccountIdentityIDType 是一个证件编号类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECAccountIdentityIDType[31];

/////////////////////////////////////////////////////////////////////////
///DFITCSECAccountIdentityTypeType 是一个证件标示类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECAccountIdentityTypeType;
///身份证
#define DFITCSEC_AI_IDcard                                   0
///护照
#define DFITCSEC_AI_PasPrt                                   1
///军官证
#define DFITCSEC_AI_OffCard                                  2
///士兵证
#define DFITCSEC_AI_SolderCard                               3
///回乡证
#define DFITCSEC_AI_RntryPrmt                                4
///户口本
#define DFITCSEC_AI_HusHldRgstr                              5
///外国护照
#define DFITCSEC_AI_FrignPasPrt                              6
///技术监督局代码
#define DFITCSEC_AI_TechSupBruCode                           7
///营业执照
#define DFITCSEC_AI_BsnsLicence                              8
///行政机关
#define DFITCSEC_AI_AdminOrgan                               9
///社会团体
#define DFITCSEC_AI_SocialGrup                               10
///军队
#define DFITCSEC_AI_Army                                     11
///武警
#define DFITCSEC_AI_ArmdPolice                               12
///下属机构
#define DFITCSEC_AI_SubBody                                  13
///基金会
#define DFITCSEC_AI_Foundation                               14
///台胞证
#define DFITCSEC_AI_TaiWanCard                               15
///港澳台居民身份证
#define DFITCSEC_AI_HMTIDcard                                16
///其他
#define DFITCSEC_AI_OtherCard                                99

/////////////////////////////////////////////////////////////////////////
///DFITCSBranchTypeType 是一个机构标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSBranchTypeType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECPasswdSyncFlagType 是一个密码同步标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECPasswdSyncFlagType;
///不同步
#define DFITCSEC_PSF_Sync                                     0
///同步
#define DFITCSEC_PSF_UnSync                                   1

/////////////////////////////////////////////////////////////////////////
///DFITCSECShareholderSpecPropType 是一个股东限制属性类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32   DFITCSECShareholderSpecPropType;
///当日指定
#define DFITCSEC_SSP_SpecTheDay                               2
///回购指定
#define DFITCSEC_SSP_SpecRePurchase                           16
///隔日指定
#define DFITCSEC_SSP_SpecOtherDay                             32

/////////////////////////////////////////////////////////////////////////
///DFITCSECTradePermissionsType 是一个交易权限类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECTradePermissionsType;
///基本交易权限
#define DFITCSEC_TP_BasicTrade                                 1
///回购融资
#define DFITCSEC_TP_ReprchFnc                                  2
///回购融券
#define DFITCSEC_TP_ReprchSecLoan                              4
///ETF申赎
#define DFITCSEC_TP_ETF_SubRedemp                              8
///权证交易
#define DFITCSEC_TP_WarrantTrade                               16
///三板报价转让
#define DFITCSEC_TP_ThreeBrdTran                               32
///创业板
#define DFITCSEC_TP_GEM                                        64

/////////////////////////////////////////////////////////////////////////
///DFITCSECShareholderStatusType 是一个股东状态类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECShareholderStatusType;
///正常
#define DFITCSEC_SHS_Normal                                    0
///股东冻结
#define DFITCSEC_SHS_Freeze                                    1
///股东卡挂失
#define DFITCSEC_SHS_LOSS                                      2
///小额休眠
#define DFITCSEC_SHS_Dormancy                                  6
///不合格
#define DFITCSEC_SHS_Unqualified                               7
///激活
#define DFITCSEC_SHS_Activation                                8
///公司不合格
#define DFITCSEC_SHS_CompanyUnqualified                        9
///使用申请中
#define DFITCSEC_SHS_Applying                                  10
///使用申请失败
#define DFITCSEC_SHS_ApplyFailed                               11
///VIP状态
#define DFITCSEC_SHS_VIP                                       12

/////////////////////////////////////////////////////////////////////////
///DFITCSECMainAccountFlagType 是一个主账户标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECMainAccountFlagType;
///辅助帐号
#define DFITCSEC_MA_Auxiliary                                  0
///主帐号
#define DFITCSEC_MA_Master                                     1

/////////////////////////////////////////////////////////////////////////
///DFITCSECShareholderCtlPropType 是一个股东控制属性类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECShareholderCtlPropType;
///正常
#define DFITCSEC_SHC_Normal                                    0
///禁止买入
#define DFITCSEC_SHC_ForbidBuy                                 4
///禁止卖出
#define DFITCSEC_SHC_ForbidSell                                8
///禁止撤指
#define DFITCSEC_SHC_ForbidWithdraw                            64
///禁止转托管
#define DFITCSEC_SHC_ForbidCustodyTransfer                     128

/////////////////////////////////////////////////////////////////////////
///DFITCSECOrderRangeID 是一个委托号范围类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECOrderRangeID[1024];

/////////////////////////////////////////////////////////////////////////
///DFITCSECBidTradeFlagType 是一个竞价交易标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECBidTradeFlagType;
///不允许集合竞价期间交易 
#define DFITCSEC_BTF_UnBidTrade                           0
///允许集合竞价期间交易
#define DFITCSEC_BTF_BidTrade                             1

/////////////////////////////////////////////////////////////////////////
///DFITCSECTradeUnitType 是一个交易单位类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32   DFITCSECTradeUnitType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECBusinessLimitType 是一个买卖限制类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32   DFITCSECBusinessLimitType;
///T+0交易
#define DFITCSEC_T0_Transaction                          1
///席位托管
#define DFITCSEC_Seat_Hosting                            2
///计算市值
#define DFITCSEC_Computing_Market_Value                  8

/////////////////////////////////////////////////////////////////////////
///DFITCSECSubAccountIDType 是子账户编码类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECSubAccountIDType[7];

/////////////////////////////////////////////////////////////////////////
///DFITCSECOpenCloseFlagType 是一个开平标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECOpenCloseFlagType;
///开仓
#define DFITCSEC_OCF_Open                                1
///平仓
#define DFITCSEC_OCF_Close                               2
///执行
#define DFITCSEC_OCF_Execute                             6
///履约
#define DFITCSEC_OCF_Perform                             7
///实物意向交割
#define DFITCSEC_OCF_RealIntenDevi                       8
///合约持仓调整                     
#define DFITCSEC_OCF_ConPosiAdj                          9 
///证券冻结
#define DFITCSEC_OCF_SecFreeze                           10
///证券解冻
#define DFITCSEC_OCF_SecThaw                             11
///强平
#define DFITCSEC_OCF_ForceClose                          12
///组合
#define DFITCSEC_OCF_Group                               19
///拆分
#define DFITCSEC_OCF_Split                               20
///转备兑
#define DFITCSEC_OCF_ToPrePare                           21
///转现金
#define DFITCSEC_OCF_ToCash                              22
///组合行权
#define DFITCSEC_OCF_GroupExecute                        23

/////////////////////////////////////////////////////////////////////////
///DFITCSECCoveredFlagType 是一个备兑标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECCoveredFlagType;
///非备兑
#define DFITCSEC_CF_UnCovered                            0
///备兑
#define DFITCSEC_CF_Covered                              1
///备兑优先(预留，目前不支持)
#define DFITCSEC_CF_CoveredPrior                         2

/////////////////////////////////////////////////////////////////////////
///DFITCSECOrderExpiryDateType 是一个订单时效限制类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECOrderExpiryDateType;
///当日有效
#define DFITCSEC_OE_NONE                                 0
///立即成交剩余指令自动撤销指令 FAK(IOC)
#define DFITCSEC_OE_FAK                                  1
///立即全部成交否则自动撤销指令 FOK
#define DFITCSEC_OE_FOK                                  2

/////////////////////////////////////////////////////////////////////////
///DFITCSECOrderCategoryType 是一个委托单类别类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECOrderCategoryType;
///普通委托
#define DFITCSEC_OC_GeneralOrder                         0
///手动强平单
#define DFITCSEC_OC_ManualCloseOrder                     1
///行情触发单(预留，目前系统不支持)
//#define DFITCSEC_OC_QuoteTriggOrder                    2
///自动强平单 
#define DFITCSEC_OC_AutoCloseOrder                       8
///做市报价
#define DFITCSEC_OC_MarketmakeQuotation                  7
///报价撤单
#define DFITCSEC_OC_MarketmakeQuotationWithdraw          9

/////////////////////////////////////////////////////////////////////////
///DFITCSECQuoteIDType 是一个询价编号类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECQuoteIDType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECTDevIDType 是一个第三方开发商代码类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECTDevIDType[13];

/////////////////////////////////////////////////////////////////////////
///DFITCSECTDevDecInfoType 是一个第三方开发商申报信息类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECTDevDecInfoType[101];

/////////////////////////////////////////////////////////////////////////
///DFITCSECOptionTypeType 是一个期权类别类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECOptionTypeType;
///认购期权
#define DFITCSEC_OT_CALL                                1
///认沽期权
#define DFITCSEC_OT_PUT                                 2

/////////////////////////////////////////////////////////////////////////
///DFITCSECContractObjectTypeType 是一个标的类型类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECContractObjectTypeType;
///A股
#define DFITCSEC_COT_STOCK                              1
///ETF
#define DFITCSEC_COT_ETF                                2

/////////////////////////////////////////////////////////////////////////
///DFITCSECContractUnitType 是一个期权合约单位类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECContractUnitType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECContractIDType 是一个期权合约编码类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECContractIDType[20];


/////////////////////////////////////////////////////////////////////////
///DFITCSECContractIDType 是一个产品实时阶段及标志类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECTradingPhaseCodeType[9];

/////////////////////////////////////////////////////////////////////////
///DFITCSECAccountTypeType 是一个投资者类别类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECAccountTypeType;
///个人
#define DFITCSEC_AT_Personal                           1
///机构
#define DFITCSEC_AT_Organization                       2
///自营
#define DFITCSEC_AT_Selfoperation                      3
///做市商
#define DFITCSEC_AT_Marketmaker                        4
///交易会员
#define DFITCSEC_AT_member                             0

/////////////////////////////////////////////////////////////////////////
///DFITCSECAccountPropType 是一个客户属性类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECAccountPropType;
///禁止存款
#define DFITCSEC_AP_PrhbtDeposit                       1
///禁止取款
#define DFITCSEC_AP_PrhbtDrawMoney                     2
///禁止银证转账
#define DFITCSEC_AP_PrhbtBankTran                      4
///禁止转托管
#define DFITCSEC_AP_PrhbtTransfer                      8
///禁止撤指
#define DFITCSEC_AP_PrhbtCancelSpecTran                16
///禁止销户
#define DFITCSEC_AP_PrhbtCancelAcc                     32
///禁止开仓
#define DFITCSEC_AP_PrhbtTakePos                       64
///禁止平仓
#define DFITCSEC_AP_PrhbtClsPos                        128
///禁止单户资金内转
#define DFITCSEC_AP_PrhbtSngFamFunTran                 256

/////////////////////////////////////////////////////////////////////////
///DFITCSECAccountNodeIDType 是一个客户节点编号类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECAccountNodeIDType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECCheckUpLimitFlagType 是一个检查委托上限标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECCheckUpLimitFlagType;
///检查
#define DFITCSEC_CULF_Check                           0
///不检查
#define DFITCSEC_CULF_UnChec                          1

/////////////////////////////////////////////////////////////////////////
///DFITCSECContractNameType 是一个合约名称类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECContractNameType[52];

/////////////////////////////////////////////////////////////////////////
///DFITCSECExecuteTypeType 是一个行权方式类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECExecuteTypeType;
///美式
#define DFITCSEC_ET_US                                0
///欧式
#define DFITCSEC_ET_Europe                            1

/////////////////////////////////////////////////////////////////////////
///DFITCSECDeliveryTypeType 是一个交割方式类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECDeliveryTypeType;
///实物交割
#define DFITCSEC_DT_Real                              1
///现金交割
#define DFITCSEC_DT_Cash                              2

/////////////////////////////////////////////////////////////////////////
///DFITCSECOpenLimitsType 是一个开仓限制类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECOpenLimitsType;
///允许开仓
#define DFITCSEC_OL_Permit                            0
///限制开仓
#define DFITCSEC_OL_UnPermit                          1

/////////////////////////////////////////////////////////////////////////
///DFITCSECStockTradeFlagType 是一个股票交易标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECStockTradeFlagType;
///为"停牌标志"时, 取值如下
///正常
#define DFITCSEC_STF_Normal                           0
///停牌
#define DFITCSEC_STF_Stop                             1
///为"交易状态"时, 取值如下
///正常
#define DFITCSEC_STF_Normal                           0
///停牌
#define DFITCSEC_STF_Stop                             1
///发行
#define DFITCSEC_STF_Issue                            2
///首日上市
#define DFITCSEC_STF_FirstList                        3
///退市
#define DFITCSEC_STF_UnList                           4

////////////////////////////////////////////////////////////////////////
///DFITCSECApproachExpireFlagType 是一个临近到期日标志类型
////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECApproachExpireFlagType;

////////////////////////////////////////////////////////////////////////
///DFITCSECTempAdjuestFlagType 是一个调整标志类型
////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECTempAdjuestFlagType;

////////////////////////////////////////////////////////////////////////
///DFITCSECStockListFlagType 是一个挂牌标志类型
////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECStockListFlagType[2];
///当日新挂牌合约
#define DFITCSEC_SLF_A                               'A'
///存续的合约
#define DFITCSEC_SLF_E                               'E'
///当日摘牌的合约
#define DFITCSEC_SLF_D                               'D'

////////////////////////////////////////////////////////////////////////
///DFITCSECContractObjectStatusType 是一个标的证券状态类型
////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECContractObjectStatusType;
///正常
#define DFITCSEC_COS_Normal                          0
///暂停
#define DFITCSEC_COS_Suspend                         1
///作废
#define DFITCSEC_COS_Cancel                          2

/////////////////////////////////////////////////////////////////////////
///DFITCSECExchangeNameType 是一个交易所代码类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECExchangeNameType[11];

/////////////////////////////////////////////////////////////////////////
///DFITCSECNightTradingFlagType 是一个夜市交易标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECNightTradingFlagType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECTradingDayFlagType 是一个交易日标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECTradingDayFlagType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECLvelCategoryType 是一个级别类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECLvelType;
///交易所
#define DFITCSEC_L_EXCHANGE                         1
///公司
#define DFITCSEC_L_COMPANY                          2
///单户
#define DFITCSEC_L_CUSTOMER                         3

/////////////////////////////////////////////////////////////////////////
///DFITCSECReferenceTypeType 是一个费率参数类别类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECReferenceTypeType;
///按标的类型
#define DFITCSEC_RT_ObjectType                      1
///按标的代码
#define DFITCSEC_RT_ObjectID                        2
///按期权代码
#define DFITCSEC_RT_OptionID                        3

/////////////////////////////////////////////////////////////////////////
///DFITCSECCalcTypeType 是一个计算方式类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECCalcTypeType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECContractNOType 是一个指定合约编号类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECContractNOType[33];

/////////////////////////////////////////////////////////////////////////
///DFITCSECCrdtContractQryFlagType 是一个查询标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECCrdtContractQryFlagType;
///查询所有
#define DFITCSEC_CCQF_Queryall                      0
///当日了结
#define DFITCSEC_CCQF_Endoftheday                   1
///未了结
#define DFITCSEC_CCQF_Unfinished                    2

/////////////////////////////////////////////////////////////////////////
///DFITCSECCrdtContractStatusType 是一个合约状态类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECCrdtContractStatusType;
///未了结
#define DFITCSEC_CCS_UnSettle                      0
///已了结未清算
#define DFITCSEC_CCS_UnClear                       1
///已了结
#define DFITCSEC_CCS_Settle                        3

/////////////////////////////////////////////////////////////////////////
///DFITCSECPositionNOType 是一个头寸编号类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECPositionNOType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECClearFlagType 是一个清算标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECClearFlagType;
///成交引起
#define DFITCSEC_CF_TradeCause                     1
///清算引起
#define DFITCSEC_CF_ClearCause                     2
///权益补偿引起
#define DFITCSEC_CF_ComCause                       3

/////////////////////////////////////////////////////////////////////////
///DFITCSECShareholderTypeType 是一个股东类别类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECShareholderTypeType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECHKEntrustLimitType 是一个港股交易限制类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECHKEntrustLimitType;
///普通股票
#define DFITCSEC_HKEL_NormalStolk                  0
///竞价
#define DFITCSEC_HKEL_Bid                          1
///开市竞价
#define DFITCSEC_HKEL_OpeningBid                   2
///零股               
#define DFITCSEC_HKEL_OddStock                     3

/////////////////////////////////////////////////////////////////////////
///DFITCSECHKOrderTypeType 是一个港股订单属性类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECHKOrderTypeType;
///当日有效
#define DFITCSEC_HKOT_GFT                          0
///全额即时
#define DFITCSEC_HKOT_FOK                          4

/////////////////////////////////////////////////////////////////////////
///DFITCSECOrderConfirmFlagType 是一个委托确认类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECOrderConfirmFlagType;
///委托成功
#define DFITCSEC_ORDER_SUCCESS                     0
///委托失败
#define DFITCSEC_ORDER_FAIL                        1

//////////////////////////////////////////////////////////////////////////
///DFITCSECExchangeGroupTypeType 是一个交易所组合类型
//////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECExchangeGroupTypeType;
///转备兑
#define DFITCSEC_EGT_ToPrepare                     1
///认购牛市价差策略
#define DFITCSEC_EGT_BullBuy                       2
///认沽熊市价差策略
#define DFITCSEC_EGT_BearSell                      3
///认沽牛市价差策略
#define DFITCSEC_EGT_BullSell                      4
///认购熊市价差策略
#define DFITCSEC_EGT_BearBuy                       5
///跨式空头
#define DFITCSEC_EGT_ShortStraddle                 6
///宽跨式空头
#define DFITCSEC_EGT_WideStraddle                  7
///备兑转现金
#define DFITCSEC_EGT_CoveredToCash                 8

//////////////////////////////////////////////////////////////////////////
///DFITCSECGroupCodeType 是一个组合编码类型
//////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECGroupCodeType[21];

//////////////////////////////////////////////////////////////////////////
///DFITCSECContractAdjustRemindType 是一个合约调整提醒类型
//////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECContractAdjustRemindType;
///未调整
#define DFITCSEC_CAR_NotAdj                        0
///已调整
#define DFITCSEC_CAR_Adj                           1

//////////////////////////////////////////////////////////////////////////
///DFITCSECContraceExpireRemindType 是一个合约即将到期提醒类型
//////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECContraceExpireRemindType;
///未到期
#define DFITCSEC_CER_NotExpire                     0
///距离到期日不足10个交易日
#define DFITCSEC_CER_WillExpire                    1

//////////////////////////////////////////////////////////////////////////
///DFITCSESecurityOptionIndexType 是一个股票期权索引值类型
//////////////////////////////////////////////////////////////////////////
typedef char   DFITCSESecurityOptionIndexType[21];

/////////////////////////////////////////////////////////////////////////
///DFITCSECOrderTypeLimitType 是一个订单类型限制类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECOrderTypeLimitType[128];

/////////////////////////////////////////////////////////////////////////
///DFITCSECMiniPriceChangeType 是一个最小变动价位类型
/////////////////////////////////////////////////////////////////////////
typedef double DFITCSECMiniPriceChangeType;

//////////////////////////////////////////////////////////////////////////
///DFITCSECMDCompressFalgType 行情压缩标志类型
//////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECMDCompressFalgType;
///不要求行情前置压缩行情
#define DFITCSEC_COMPRESS_FALSE                                      0
///要求行情前置压缩行情
#define DFITCSEC_COMPRESS_TRUE                                       1

//////////////////////////////////////////////////////////////////////////
///DFITCSECCollectInterfaceType 看穿式监管采集接口类型
//////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECCollectInterfaceType;
///顶点采集接口
#define DFITCSEC_COLLECTTYPE_APEX                                    1
///恒生采集接口
#define DFITCSEC_COLLECTTYPE_HS                                      2
///金证采集接口
#define DFITCSEC_COLLECTTYPE_KD                                      3
///金仕达采集接口
#define DFITCSEC_COLLECTTYPE_KS                                      4

//////////////////////////////////////////////////////////////////////////
///看穿式监管使用类型
//////////////////////////////////////////////////////////////////////////
///看穿式监管连接类型
typedef ax_int32     DFITCSECConnectType;
///直连模式
#define DFITCSEC_CONNECT_DIRECT 1
///中继模式
#define DFITCSEC_CONNECT_RELAY  2
///采集信息
typedef char    DFITCSECSystemInfo[1024];
///采集信息完整性
typedef char    DFITCSECSystemInfoIntegrity[512];
///秘钥版本
typedef char    DFITCSECSecretkeyVer[1024];
///AppID
typedef char    DFITCSECAppID[31];
///异常标识
typedef ax_int32     DFITCSECExceptionFlag;
///客户终端公网IP地址
typedef char    DFITCSECClientPublicIP[20];
///客户终端公网端口号
typedef ax_int32     DFITCSECClientPublicPort;
///客户终端登录时间
typedef char    DFITCSECClientLoginTime[9];

//by xubin 
#define SYSINFO_IP		0
#define SYSINFO_MAC	    1 
#define SYSINFO_OS		2 
#define SYSINFO_CPU		3 
#define SYSINFO_DISK	4	
#define SYSINFO_NETIP	5
#define SYSINFO_NETPORT 6



//以下为STOCK新增业务的数据类型 
/////////////////////////////////////////////////////////////////////////
///DFITCSECComponentStocksIDType 是一个成分股代码类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECComponentStocksIDType[9];

/////////////////////////////////////////////////////////////////////////
///DFITCSECStockOrderCategoryType 是一个订单类别类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECStockOrderCategoryType;
///正常委托
#define DFITCSEC_OC_NormalEntrust                                 0
///批量委托
#define DFITCSEC_OC_BatchEntrust                                  1
///强平委托
#define DFITCSEC_OT_ForceCloseEntrust                             2
///报价回购
#define DFITCSEC_OC_QuotedPriceRepurchase                         3
///约定购回
#define DFITCSEC_OC_AppointmentRepurchase                         4
///质押回购
#define DFITCSEC_OC_PledgeRepurchase                              5
///全部转托管
#define DFITCSEC_OC_AllCustodyTransfer                            6
///做市双边报价
#define DFITCSEC_OC_MarketmakeBilateralQuotation                  7
///协议回购
#define DFITCSEC_OC_AgreementRepurchase                           8

/////////////////////////////////////////////////////////////////////////
///DFITCSECStepType 是一个报盘step串类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECStepType[21];

/////////////////////////////////////////////////////////////////////////
///DFITCSECFundIDType 是一个基金代码类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECFundIDType[9];

/////////////////////////////////////////////////////////////////////////
///DFITCSECStopLossLimitPriceType 是一个止损限价类型
/////////////////////////////////////////////////////////////////////////
typedef double DFITCSECStopLossLimitPriceType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECOrderTradeLimitType 是一个订单交易限制类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32 DFITCSECOrderTradeLimitType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECOrderEffectiveDateType 是一个订单有效日期类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32 DFITCSECOrderEffectiveDateType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECDividendsPatternType 是一个分红方式类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECDividendsPatternType[2];
///转投
#define DFITCSEC_DP_TransferInvestment             "0"
///现金
#define DFITCSEC_DP_Csah                           "1"

/////////////////////////////////////////////////////////////////////////
///DFITCSECSourceContractType 是一个合约来源类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECSourceContractType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECTrusteeshipUnitType 是一个托管单元类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECTrusteeshipUnitType[7];

/////////////////////////////////////////////////////////////////////////
///DFITCSECAccountStatusType 是一个特殊标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECSpecialSignsType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECCustomerCtlPropType 是一个客户控制属性类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECCustomerCtlPropType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECShareNatureType 是一个股份性质类型
/////////////////////////////////////////////////////////////////////////
typedef char   DFITCSECShareNatureType[2];
///无限流通股
#define DFITCSEC_SN_UnlimitedTradableShares					  "00"
///首发后个人类限售股
#define DFITCSEC_SN_PersonalRestrictedSharesAfterIPO		  "01"
///首发后机构类限售股
#define DFITCSEC_SN_OrganizationRestrictedSharesAfterIPO      "03"
///高管锁定股
#define DFITCSEC_SN_ExecutiveLockInShares					  "04"
///首发前个人类限售股
#define DFITCSEC_SN_PersonalRestrictedSharesBeforeIPO         "05"
///首发前机构类限售股
#define DFITCSEC_SN_OrganizationRestrictedSharesBeforeIPO     "06"

/////////////////////////////////////////////////////////////////////////
///DFITCSECCirculateTypeType 是一个流通类型类型
/////////////////////////////////////////////////////////////////////////
typedef char    DFITCSECCirculateTypeType[2];

/////////////////////////////////////////////////////////////////////////
///DFITCSECContractTypeType 是一个合约类别类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECContractTypeType;
///融资
#define DFITCSEC_CT_FIN                                           1
///融券
#define DFITCSEC_BT_SLO                                           2

/////////////////////////////////////////////////////////////////////////
///DFITCSECChangeTypeType 是一个变动类别类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECChangeTypeType;

////////////////////////////////////////////////////////////
///DFITCSECStockTransferFlagType 是一个证券调转标志类型
////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECStockTransferFlagType;
///转入
#define DFITCSEC_STF_In                                         1
///转出 
#define DFITCSEC_STF_Out                                        2


////////////////////////////////////////////////////////////
///DFITCSECSpecificFlagType 是一个特定标志类型
////////////////////////////////////////////////////////////
typedef ax_int8    DFITCSECSpecificFlagType;


/////////////////////////////////////////////////////////////////////////
///DFITCSECSecurityPropType 是一个证券属性类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECSecurityPropType;
///融资标的
#define DFITCSEC_SP_FinancingContractObject            1
///融券标的
#define DFITCSEC_SP_SecuritiesContractObject           2
///担保物
#define DFITCSEC_SP_Collateral                         4

/////////////////////////////////////////////////////////////////////////
///DFITCSECOtherPropType 是一个其他属性类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECOtherPropType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECExhibitionTimesType 是一个展期次数类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECExhibitionTimesType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECCheckFairPriceFlagType 是一个检查公允价格标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECCheckFairPriceFlagType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECStockSectorType 是一个股票板块类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECStockSectorType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECDesignatedRepaymentFlagType 是一个指定偿还标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECDesignatedRepaymentFlagType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECForceClosePositionFlagType 是一个强平标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECForceClosePositionFlagType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECPositionSizeType 是一个头寸规模类型
/////////////////////////////////////////////////////////////////////////
typedef double    DFITCSECPositionSizeType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECInterestSettlementMethodType 是一个利息了结方式类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECInterestSettlementMethodType;

/////////////////////////////////////////////////////////////////////////
///DFITCSECArrearsFlagFlagType 是一个欠款标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECArrearsFlagFlagType;


/////////////////////////////////////////////////////////////////////////
///DFITCSECOutstandingSecuritiesFlagType 是一个欠券标志类型
/////////////////////////////////////////////////////////////////////////
typedef ax_int32    DFITCSECOutstandingSecuritiesFlagType;


#endif//DFITCStockAPIDATATYPE_H

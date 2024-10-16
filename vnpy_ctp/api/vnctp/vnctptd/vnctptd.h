//系统
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnctp.h"
#include "pybind11/pybind11.h"
#include "ctp/ThostFtdcTraderApi.h"

using namespace pybind11;

//常量


#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONHEARTBEATWARNING 2
#define ONRSPAUTHENTICATE 3
#define ONRSPUSERLOGIN 4
#define ONRSPUSERLOGOUT 5
#define ONRSPUSERPASSWORDUPDATE 6
#define ONRSPTRADINGACCOUNTPASSWORDUPDATE 7
#define ONRSPUSERAUTHMETHOD 8
#define ONRSPGENUSERCAPTCHA 9
#define ONRSPGENUSERTEXT 10
#define ONRSPORDERINSERT 11
#define ONRSPPARKEDORDERINSERT 12
#define ONRSPPARKEDORDERACTION 13
#define ONRSPORDERACTION 14
#define ONRSPQRYMAXORDERVOLUME 15
#define ONRSPSETTLEMENTINFOCONFIRM 16
#define ONRSPREMOVEPARKEDORDER 17
#define ONRSPREMOVEPARKEDORDERACTION 18
#define ONRSPEXECORDERINSERT 19
#define ONRSPEXECORDERACTION 20
#define ONRSPFORQUOTEINSERT 21
#define ONRSPQUOTEINSERT 22
#define ONRSPQUOTEACTION 23
#define ONRSPBATCHORDERACTION 24
#define ONRSPOPTIONSELFCLOSEINSERT 25
#define ONRSPOPTIONSELFCLOSEACTION 26
#define ONRSPCOMBACTIONINSERT 27
#define ONRSPQRYORDER 28
#define ONRSPQRYTRADE 29
#define ONRSPQRYINVESTORPOSITION 30
#define ONRSPQRYTRADINGACCOUNT 31
#define ONRSPQRYINVESTOR 32
#define ONRSPQRYTRADINGCODE 33
#define ONRSPQRYINSTRUMENTMARGINRATE 34
#define ONRSPQRYINSTRUMENTCOMMISSIONRATE 35
#define ONRSPQRYEXCHANGE 36
#define ONRSPQRYPRODUCT 37
#define ONRSPQRYINSTRUMENT 38
#define ONRSPQRYDEPTHMARKETDATA 39
#define ONRSPQRYTRADEROFFER 40
#define ONRSPQRYSETTLEMENTINFO 41
#define ONRSPQRYTRANSFERBANK 42
#define ONRSPQRYINVESTORPOSITIONDETAIL 43
#define ONRSPQRYNOTICE 44
#define ONRSPQRYSETTLEMENTINFOCONFIRM 45
#define ONRSPQRYINVESTORPOSITIONCOMBINEDETAIL 46
#define ONRSPQRYCFMMCTRADINGACCOUNTKEY 47
#define ONRSPQRYEWARRANTOFFSET 48
#define ONRSPQRYINVESTORPRODUCTGROUPMARGIN 49
#define ONRSPQRYEXCHANGEMARGINRATE 50
#define ONRSPQRYEXCHANGEMARGINRATEADJUST 51
#define ONRSPQRYEXCHANGERATE 52
#define ONRSPQRYSECAGENTACIDMAP 53
#define ONRSPQRYPRODUCTEXCHRATE 54
#define ONRSPQRYPRODUCTGROUP 55
#define ONRSPQRYMMINSTRUMENTCOMMISSIONRATE 56
#define ONRSPQRYMMOPTIONINSTRCOMMRATE 57
#define ONRSPQRYINSTRUMENTORDERCOMMRATE 58
#define ONRSPQRYSECAGENTTRADINGACCOUNT 59
#define ONRSPQRYSECAGENTCHECKMODE 60
#define ONRSPQRYSECAGENTTRADEINFO 61
#define ONRSPQRYOPTIONINSTRTRADECOST 62
#define ONRSPQRYOPTIONINSTRCOMMRATE 63
#define ONRSPQRYEXECORDER 64
#define ONRSPQRYFORQUOTE 65
#define ONRSPQRYQUOTE 66
#define ONRSPQRYOPTIONSELFCLOSE 67
#define ONRSPQRYINVESTUNIT 68
#define ONRSPQRYCOMBINSTRUMENTGUARD 69
#define ONRSPQRYCOMBACTION 70
#define ONRSPQRYTRANSFERSERIAL 71
#define ONRSPQRYACCOUNTREGISTER 72
#define ONRSPERROR 73
#define ONRTNORDER 74
#define ONRTNTRADE 75
#define ONERRRTNORDERINSERT 76
#define ONERRRTNORDERACTION 77
#define ONRTNINSTRUMENTSTATUS 78
#define ONRTNBULLETIN 79
#define ONRTNTRADINGNOTICE 80
#define ONRTNERRORCONDITIONALORDER 81
#define ONRTNEXECORDER 82
#define ONERRRTNEXECORDERINSERT 83
#define ONERRRTNEXECORDERACTION 84
#define ONERRRTNFORQUOTEINSERT 85
#define ONRTNQUOTE 86
#define ONERRRTNQUOTEINSERT 87
#define ONERRRTNQUOTEACTION 88
#define ONRTNFORQUOTERSP 89
#define ONRTNCFMMCTRADINGACCOUNTTOKEN 90
#define ONERRRTNBATCHORDERACTION 91
#define ONRTNOPTIONSELFCLOSE 92
#define ONERRRTNOPTIONSELFCLOSEINSERT 93
#define ONERRRTNOPTIONSELFCLOSEACTION 94
#define ONRTNCOMBACTION 95
#define ONERRRTNCOMBACTIONINSERT 96
#define ONRSPQRYCONTRACTBANK 97
#define ONRSPQRYPARKEDORDER 98
#define ONRSPQRYPARKEDORDERACTION 99
#define ONRSPQRYTRADINGNOTICE 100
#define ONRSPQRYBROKERTRADINGPARAMS 101
#define ONRSPQRYBROKERTRADINGALGOS 102
#define ONRSPQUERYCFMMCTRADINGACCOUNTTOKEN 103
#define ONRTNFROMBANKTOFUTUREBYBANK 104
#define ONRTNFROMFUTURETOBANKBYBANK 105
#define ONRTNREPEALFROMBANKTOFUTUREBYBANK 106
#define ONRTNREPEALFROMFUTURETOBANKBYBANK 107
#define ONRTNFROMBANKTOFUTUREBYFUTURE 108
#define ONRTNFROMFUTURETOBANKBYFUTURE 109
#define ONRTNREPEALFROMBANKTOFUTUREBYFUTUREMANUAL 110
#define ONRTNREPEALFROMFUTURETOBANKBYFUTUREMANUAL 111
#define ONRTNQUERYBANKBALANCEBYFUTURE 112
#define ONERRRTNBANKTOFUTUREBYFUTURE 113
#define ONERRRTNFUTURETOBANKBYFUTURE 114
#define ONERRRTNREPEALBANKTOFUTUREBYFUTUREMANUAL 115
#define ONERRRTNREPEALFUTURETOBANKBYFUTUREMANUAL 116
#define ONERRRTNQUERYBANKBALANCEBYFUTURE 117
#define ONRTNREPEALFROMBANKTOFUTUREBYFUTURE 118
#define ONRTNREPEALFROMFUTURETOBANKBYFUTURE 119
#define ONRSPFROMBANKTOFUTUREBYFUTURE 120
#define ONRSPFROMFUTURETOBANKBYFUTURE 121
#define ONRSPQUERYBANKACCOUNTMONEYBYFUTURE 122
#define ONRTNOPENACCOUNTBYBANK 123
#define ONRTNCANCELACCOUNTBYBANK 124
#define ONRTNCHANGEACCOUNTBYBANK 125
#define ONRSPQRYCLASSIFIEDINSTRUMENT 126
#define ONRSPQRYCOMBPROMOTIONPARAM 127
#define ONRSPQRYRISKSETTLEINVSTPOSITION 128
#define ONRSPQRYRISKSETTLEPRODUCTSTATUS 129
#define ONRSPQRYSPBMFUTUREPARAMETER 130
#define ONRSPQRYSPBMOPTIONPARAMETER 131
#define ONRSPQRYSPBMINTRAPARAMETER 132
#define ONRSPQRYSPBMINTERPARAMETER 133
#define ONRSPQRYSPBMPORTFDEFINITION 134
#define ONRSPQRYSPBMINVESTORPORTFDEF 135
#define ONRSPQRYINVESTORPORTFMARGINRATIO 136
#define ONRSPQRYINVESTORPRODSPBMDETAIL 137
#define ONRSPQRYINVESTORCOMMODITYSPMMMARGIN 138
#define ONRSPQRYINVESTORCOMMODITYGROUPSPMMMARGIN 139
#define ONRSPQRYSPMMINSTPARAM 140
#define ONRSPQRYSPMMPRODUCTPARAM 141
#define ONRSPQRYSPBMADDONINTERPARAMETER 142
#define ONRSPQRYRCAMSCOMBPRODUCTINFO 143
#define ONRSPQRYRCAMSINSTRPARAMETER 144
#define ONRSPQRYRCAMSINTRAPARAMETER 145
#define ONRSPQRYRCAMSINTERPARAMETER 146
#define ONRSPQRYRCAMSSHORTOPTADJUSTPARAM 147
#define ONRSPQRYRCAMSINVESTORCOMBPOSITION 148
#define ONRSPQRYINVESTORPRODRCAMSMARGIN 149
#define ONRSPQRYRULEINSTRPARAMETER 150
#define ONRSPQRYRULEINTRAPARAMETER 151
#define ONRSPQRYRULEINTERPARAMETER 152
#define ONRSPQRYINVESTORPRODRULEMARGIN 153


///-------------------------------------------------------------------------------------
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现
class TdApi : public CThostFtdcTraderSpi
{
private:
	CThostFtdcTraderApi* api;            //API对象
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
	
	virtual void TdApi::OnFrontConnected();
	virtual void TdApi::OnFrontDisconnected(int nReason);
	virtual void TdApi::OnHeartBeatWarning(int nTimeLapse);
	virtual void TdApi::OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField *pRspUserAuthMethod, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField *pRspGenUserCaptcha, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspGenUserText(CThostFtdcRspGenUserTextField *pRspGenUserText, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField *pQryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryTraderOffer(CThostFtdcTraderOfferField *pTraderOffer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryProductExchRate(CThostFtdcProductExchRateField *pProductExchRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryProductGroup(CThostFtdcProductGroupField *pProductGroup, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField *pMMInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField *pMMOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *pInstrumentOrderCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField *pSecAgentCheckMode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField *pSecAgentTradeInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryInvestUnit(CThostFtdcInvestUnitField *pInvestUnit, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField *pCombInstrumentGuard, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryCombAction(CThostFtdcCombActionField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRtnOrder(CThostFtdcOrderField *pOrder);
	virtual void TdApi::OnRtnTrade(CThostFtdcTradeField *pTrade);
	virtual void TdApi::OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo);
	virtual void TdApi::OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo);
	virtual void TdApi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus);
	virtual void TdApi::OnRtnBulletin(CThostFtdcBulletinField *pBulletin);
	virtual void TdApi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo);
	virtual void TdApi::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder);
	virtual void TdApi::OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder);
	virtual void TdApi::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo);
	virtual void TdApi::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo);
	virtual void TdApi::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo);
	virtual void TdApi::OnRtnQuote(CThostFtdcQuoteField *pQuote);
	virtual void TdApi::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo);
	virtual void TdApi::OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo);
	virtual void TdApi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp);
	virtual void TdApi::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken);
	virtual void TdApi::OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo);
	virtual void TdApi::OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose);
	virtual void TdApi::OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo);
	virtual void TdApi::OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField *pOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo);
	virtual void TdApi::OnRtnCombAction(CThostFtdcCombActionField *pCombAction);
	virtual void TdApi::OnErrRtnCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo);
	virtual void TdApi::OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer);
	virtual void TdApi::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer);
	virtual void TdApi::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal);
	virtual void TdApi::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal);
	virtual void TdApi::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer);
	virtual void TdApi::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer);
	virtual void TdApi::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal);
	virtual void TdApi::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal);
	virtual void TdApi::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount);
	virtual void TdApi::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
	virtual void TdApi::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
	virtual void TdApi::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
	virtual void TdApi::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
	virtual void TdApi::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo);
	virtual void TdApi::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal);
	virtual void TdApi::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal);
	virtual void TdApi::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount);
	virtual void TdApi::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount);
	virtual void TdApi::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount);
	virtual void TdApi::OnRspQryClassifiedInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryCombPromotionParam(CThostFtdcCombPromotionParamField *pCombPromotionParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryRiskSettleInvstPosition(CThostFtdcRiskSettleInvstPositionField *pRiskSettleInvstPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryRiskSettleProductStatus(CThostFtdcRiskSettleProductStatusField *pRiskSettleProductStatus, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQrySPBMFutureParameter(CThostFtdcSPBMFutureParameterField *pSPBMFutureParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQrySPBMOptionParameter(CThostFtdcSPBMOptionParameterField *pSPBMOptionParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQrySPBMIntraParameter(CThostFtdcSPBMIntraParameterField *pSPBMIntraParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQrySPBMInterParameter(CThostFtdcSPBMInterParameterField *pSPBMInterParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQrySPBMPortfDefinition(CThostFtdcSPBMPortfDefinitionField *pSPBMPortfDefinition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQrySPBMInvestorPortfDef(CThostFtdcSPBMInvestorPortfDefField *pSPBMInvestorPortfDef, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryInvestorPortfMarginRatio(CThostFtdcInvestorPortfMarginRatioField *pInvestorPortfMarginRatio, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryInvestorProdSPBMDetail(CThostFtdcInvestorProdSPBMDetailField *pInvestorProdSPBMDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryInvestorCommoditySPMMMargin(CThostFtdcInvestorCommoditySPMMMarginField *pInvestorCommoditySPMMMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryInvestorCommodityGroupSPMMMargin(CThostFtdcInvestorCommodityGroupSPMMMarginField *pInvestorCommodityGroupSPMMMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQrySPMMInstParam(CThostFtdcSPMMInstParamField *pSPMMInstParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQrySPMMProductParam(CThostFtdcSPMMProductParamField *pSPMMProductParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQrySPBMAddOnInterParameter(CThostFtdcSPBMAddOnInterParameterField *pSPBMAddOnInterParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryRCAMSCombProductInfo(CThostFtdcRCAMSCombProductInfoField *pRCAMSCombProductInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryRCAMSInstrParameter(CThostFtdcRCAMSInstrParameterField *pRCAMSInstrParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryRCAMSIntraParameter(CThostFtdcRCAMSIntraParameterField *pRCAMSIntraParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryRCAMSInterParameter(CThostFtdcRCAMSInterParameterField *pRCAMSInterParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryRCAMSShortOptAdjustParam(CThostFtdcRCAMSShortOptAdjustParamField *pRCAMSShortOptAdjustParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryRCAMSInvestorCombPosition(CThostFtdcRCAMSInvestorCombPositionField *pRCAMSInvestorCombPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryInvestorProdRCAMSMargin(CThostFtdcInvestorProdRCAMSMarginField *pInvestorProdRCAMSMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryRULEInstrParameter(CThostFtdcRULEInstrParameterField *pRULEInstrParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryRULEIntraParameter(CThostFtdcRULEIntraParameterField *pRULEIntraParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryRULEInterParameter(CThostFtdcRULEInterParameterField *pRULEInterParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void TdApi::OnRspQryInvestorProdRULEMargin(CThostFtdcInvestorProdRULEMarginField *pInvestorProdRULEMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    //-------------------------------------------------------------------------------------
    //task：任务
    //-------------------------------------------------------------------------------------
    void processTask();

	
	void processFrontConnected(Task *task);
	
	void processFrontDisconnected(Task *task);
	
	void processHeartBeatWarning(Task *task);
	
	void processRspAuthenticate(Task *task);
	
	void processRspUserLogin(Task *task);
	
	void processRspUserLogout(Task *task);
	
	void processRspUserPasswordUpdate(Task *task);
	
	void processRspTradingAccountPasswordUpdate(Task *task);
	
	void processRspUserAuthMethod(Task *task);
	
	void processRspGenUserCaptcha(Task *task);
	
	void processRspGenUserText(Task *task);
	
	void processRspOrderInsert(Task *task);
	
	void processRspParkedOrderInsert(Task *task);
	
	void processRspParkedOrderAction(Task *task);
	
	void processRspOrderAction(Task *task);
	
	void processRspQryMaxOrderVolume(Task *task);
	
	void processRspSettlementInfoConfirm(Task *task);
	
	void processRspRemoveParkedOrder(Task *task);
	
	void processRspRemoveParkedOrderAction(Task *task);
	
	void processRspExecOrderInsert(Task *task);
	
	void processRspExecOrderAction(Task *task);
	
	void processRspForQuoteInsert(Task *task);
	
	void processRspQuoteInsert(Task *task);
	
	void processRspQuoteAction(Task *task);
	
	void processRspBatchOrderAction(Task *task);
	
	void processRspOptionSelfCloseInsert(Task *task);
	
	void processRspOptionSelfCloseAction(Task *task);
	
	void processRspCombActionInsert(Task *task);
	
	void processRspQryOrder(Task *task);
	
	void processRspQryTrade(Task *task);
	
	void processRspQryInvestorPosition(Task *task);
	
	void processRspQryTradingAccount(Task *task);
	
	void processRspQryInvestor(Task *task);
	
	void processRspQryTradingCode(Task *task);
	
	void processRspQryInstrumentMarginRate(Task *task);
	
	void processRspQryInstrumentCommissionRate(Task *task);
	
	void processRspQryExchange(Task *task);
	
	void processRspQryProduct(Task *task);
	
	void processRspQryInstrument(Task *task);
	
	void processRspQryDepthMarketData(Task *task);
	
	void processRspQryTraderOffer(Task *task);
	
	void processRspQrySettlementInfo(Task *task);
	
	void processRspQryTransferBank(Task *task);
	
	void processRspQryInvestorPositionDetail(Task *task);
	
	void processRspQryNotice(Task *task);
	
	void processRspQrySettlementInfoConfirm(Task *task);
	
	void processRspQryInvestorPositionCombineDetail(Task *task);
	
	void processRspQryCFMMCTradingAccountKey(Task *task);
	
	void processRspQryEWarrantOffset(Task *task);
	
	void processRspQryInvestorProductGroupMargin(Task *task);
	
	void processRspQryExchangeMarginRate(Task *task);
	
	void processRspQryExchangeMarginRateAdjust(Task *task);
	
	void processRspQryExchangeRate(Task *task);
	
	void processRspQrySecAgentACIDMap(Task *task);
	
	void processRspQryProductExchRate(Task *task);
	
	void processRspQryProductGroup(Task *task);
	
	void processRspQryMMInstrumentCommissionRate(Task *task);
	
	void processRspQryMMOptionInstrCommRate(Task *task);
	
	void processRspQryInstrumentOrderCommRate(Task *task);
	
	void processRspQrySecAgentTradingAccount(Task *task);
	
	void processRspQrySecAgentCheckMode(Task *task);
	
	void processRspQrySecAgentTradeInfo(Task *task);
	
	void processRspQryOptionInstrTradeCost(Task *task);
	
	void processRspQryOptionInstrCommRate(Task *task);
	
	void processRspQryExecOrder(Task *task);
	
	void processRspQryForQuote(Task *task);
	
	void processRspQryQuote(Task *task);
	
	void processRspQryOptionSelfClose(Task *task);
	
	void processRspQryInvestUnit(Task *task);
	
	void processRspQryCombInstrumentGuard(Task *task);
	
	void processRspQryCombAction(Task *task);
	
	void processRspQryTransferSerial(Task *task);
	
	void processRspQryAccountregister(Task *task);
	
	void processRspError(Task *task);
	
	void processRtnOrder(Task *task);
	
	void processRtnTrade(Task *task);
	
	void processErrRtnOrderInsert(Task *task);
	
	void processErrRtnOrderAction(Task *task);
	
	void processRtnInstrumentStatus(Task *task);
	
	void processRtnBulletin(Task *task);
	
	void processRtnTradingNotice(Task *task);
	
	void processRtnErrorConditionalOrder(Task *task);
	
	void processRtnExecOrder(Task *task);
	
	void processErrRtnExecOrderInsert(Task *task);
	
	void processErrRtnExecOrderAction(Task *task);
	
	void processErrRtnForQuoteInsert(Task *task);
	
	void processRtnQuote(Task *task);
	
	void processErrRtnQuoteInsert(Task *task);
	
	void processErrRtnQuoteAction(Task *task);
	
	void processRtnForQuoteRsp(Task *task);
	
	void processRtnCFMMCTradingAccountToken(Task *task);
	
	void processErrRtnBatchOrderAction(Task *task);
	
	void processRtnOptionSelfClose(Task *task);
	
	void processErrRtnOptionSelfCloseInsert(Task *task);
	
	void processErrRtnOptionSelfCloseAction(Task *task);
	
	void processRtnCombAction(Task *task);
	
	void processErrRtnCombActionInsert(Task *task);
	
	void processRspQryContractBank(Task *task);
	
	void processRspQryParkedOrder(Task *task);
	
	void processRspQryParkedOrderAction(Task *task);
	
	void processRspQryTradingNotice(Task *task);
	
	void processRspQryBrokerTradingParams(Task *task);
	
	void processRspQryBrokerTradingAlgos(Task *task);
	
	void processRspQueryCFMMCTradingAccountToken(Task *task);
	
	void processRtnFromBankToFutureByBank(Task *task);
	
	void processRtnFromFutureToBankByBank(Task *task);
	
	void processRtnRepealFromBankToFutureByBank(Task *task);
	
	void processRtnRepealFromFutureToBankByBank(Task *task);
	
	void processRtnFromBankToFutureByFuture(Task *task);
	
	void processRtnFromFutureToBankByFuture(Task *task);
	
	void processRtnRepealFromBankToFutureByFutureManual(Task *task);
	
	void processRtnRepealFromFutureToBankByFutureManual(Task *task);
	
	void processRtnQueryBankBalanceByFuture(Task *task);
	
	void processErrRtnBankToFutureByFuture(Task *task);
	
	void processErrRtnFutureToBankByFuture(Task *task);
	
	void processErrRtnRepealBankToFutureByFutureManual(Task *task);
	
	void processErrRtnRepealFutureToBankByFutureManual(Task *task);
	
	void processErrRtnQueryBankBalanceByFuture(Task *task);
	
	void processRtnRepealFromBankToFutureByFuture(Task *task);
	
	void processRtnRepealFromFutureToBankByFuture(Task *task);
	
	void processRspFromBankToFutureByFuture(Task *task);
	
	void processRspFromFutureToBankByFuture(Task *task);
	
	void processRspQueryBankAccountMoneyByFuture(Task *task);
	
	void processRtnOpenAccountByBank(Task *task);
	
	void processRtnCancelAccountByBank(Task *task);
	
	void processRtnChangeAccountByBank(Task *task);
	
	void processRspQryClassifiedInstrument(Task *task);
	
	void processRspQryCombPromotionParam(Task *task);
	
	void processRspQryRiskSettleInvstPosition(Task *task);
	
	void processRspQryRiskSettleProductStatus(Task *task);
	
	void processRspQrySPBMFutureParameter(Task *task);
	
	void processRspQrySPBMOptionParameter(Task *task);
	
	void processRspQrySPBMIntraParameter(Task *task);
	
	void processRspQrySPBMInterParameter(Task *task);
	
	void processRspQrySPBMPortfDefinition(Task *task);
	
	void processRspQrySPBMInvestorPortfDef(Task *task);
	
	void processRspQryInvestorPortfMarginRatio(Task *task);
	
	void processRspQryInvestorProdSPBMDetail(Task *task);
	
	void processRspQryInvestorCommoditySPMMMargin(Task *task);
	
	void processRspQryInvestorCommodityGroupSPMMMargin(Task *task);
	
	void processRspQrySPMMInstParam(Task *task);
	
	void processRspQrySPMMProductParam(Task *task);
	
	void processRspQrySPBMAddprocessInterParameter(Task *task);
	
	void processRspQryRCAMSCombProductInfo(Task *task);
	
	void processRspQryRCAMSInstrParameter(Task *task);
	
	void processRspQryRCAMSIntraParameter(Task *task);
	
	void processRspQryRCAMSInterParameter(Task *task);
	
	void processRspQryRCAMSShortOptAdjustParam(Task *task);
	
	void processRspQryRCAMSInvestorCombPosition(Task *task);
	
	void processRspQryInvestorProdRCAMSMargin(Task *task);
	
	void processRspQryRULEInstrParameter(Task *task);
	
	void processRspQryRULEIntraParameter(Task *task);
	
	void processRspQryRULEInterParameter(Task *task);
	
	void processRspQryInvestorProdRULEMargin(Task *task);
	
	

    //-------------------------------------------------------------------------------------
    //data：回调函数的数据字典
    //error：回调函数的错误字典
    //id：请求id
    //last：是否为最后返回
    //i：整数
    //-------------------------------------------------------------------------------------

	
	virtual void onFrontConnected() {};
	
	virtual void onFrontDisconnected(int reqid) {};
	
	virtual void onHeartBeatWarning(int reqid) {};
	
	virtual void onRspAuthenticate(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspUserLogin(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspUserLogout(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspUserPasswordUpdate(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspTradingAccountPasswordUpdate(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspUserAuthMethod(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspGenUserCaptcha(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspGenUserText(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspOrderInsert(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspParkedOrderInsert(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspParkedOrderAction(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspOrderAction(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryMaxOrderVolume(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspSettlementInfoConfirm(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspRemoveParkedOrder(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspRemoveParkedOrderAction(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspExecOrderInsert(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspExecOrderAction(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspForQuoteInsert(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQuoteInsert(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQuoteAction(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspBatchOrderAction(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspOptionSelfCloseInsert(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspOptionSelfCloseAction(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspCombActionInsert(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryOrder(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryTrade(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryInvestorPosition(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryTradingAccount(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryInvestor(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryTradingCode(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryInstrumentMarginRate(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryInstrumentCommissionRate(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryExchange(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryProduct(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryInstrument(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryDepthMarketData(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryTraderOffer(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQrySettlementInfo(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryTransferBank(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryInvestorPositionDetail(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryNotice(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQrySettlementInfoConfirm(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryInvestorPositionCombineDetail(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryCFMMCTradingAccountKey(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryEWarrantOffset(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryInvestorProductGroupMargin(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryExchangeMarginRate(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryExchangeMarginRateAdjust(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryExchangeRate(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQrySecAgentACIDMap(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryProductExchRate(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryProductGroup(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryMMInstrumentCommissionRate(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryMMOptionInstrCommRate(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryInstrumentOrderCommRate(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQrySecAgentTradingAccount(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQrySecAgentCheckMode(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQrySecAgentTradeInfo(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryOptionInstrTradeCost(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryOptionInstrCommRate(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryExecOrder(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryForQuote(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryQuote(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryOptionSelfClose(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryInvestUnit(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryCombInstrumentGuard(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryCombAction(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryTransferSerial(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryAccountregister(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspError(const dict &error, int reqid, bool last) {};
	
	virtual void onRtnOrder(const dict &data) {};
	
	virtual void onRtnTrade(const dict &data) {};
	
	virtual void onErrRtnOrderInsert(const dict &data, const dict &error) {};
	
	virtual void onErrRtnOrderAction(const dict &data, const dict &error) {};
	
	virtual void onRtnInstrumentStatus(const dict &data) {};
	
	virtual void onRtnBulletin(const dict &data) {};
	
	virtual void onRtnTradingNotice(const dict &data) {};
	
	virtual void onRtnErrorConditionalOrder(const dict &data) {};
	
	virtual void onRtnExecOrder(const dict &data) {};
	
	virtual void onErrRtnExecOrderInsert(const dict &data, const dict &error) {};
	
	virtual void onErrRtnExecOrderAction(const dict &data, const dict &error) {};
	
	virtual void onErrRtnForQuoteInsert(const dict &data, const dict &error) {};
	
	virtual void onRtnQuote(const dict &data) {};
	
	virtual void onErrRtnQuoteInsert(const dict &data, const dict &error) {};
	
	virtual void onErrRtnQuoteAction(const dict &data, const dict &error) {};
	
	virtual void onRtnForQuoteRsp(const dict &data) {};
	
	virtual void onRtnCFMMCTradingAccountToken(const dict &data) {};
	
	virtual void onErrRtnBatchOrderAction(const dict &data, const dict &error) {};
	
	virtual void onRtnOptionSelfClose(const dict &data) {};
	
	virtual void onErrRtnOptionSelfCloseInsert(const dict &data, const dict &error) {};
	
	virtual void onErrRtnOptionSelfCloseAction(const dict &data, const dict &error) {};
	
	virtual void onRtnCombAction(const dict &data) {};
	
	virtual void onErrRtnCombActionInsert(const dict &data, const dict &error) {};
	
	virtual void onRspQryContractBank(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryParkedOrder(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryParkedOrderAction(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryTradingNotice(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryBrokerTradingParams(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryBrokerTradingAlgos(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQueryCFMMCTradingAccountToken(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRtnFromBankToFutureByBank(const dict &data) {};
	
	virtual void onRtnFromFutureToBankByBank(const dict &data) {};
	
	virtual void onRtnRepealFromBankToFutureByBank(const dict &data) {};
	
	virtual void onRtnRepealFromFutureToBankByBank(const dict &data) {};
	
	virtual void onRtnFromBankToFutureByFuture(const dict &data) {};
	
	virtual void onRtnFromFutureToBankByFuture(const dict &data) {};
	
	virtual void onRtnRepealFromBankToFutureByFutureManual(const dict &data) {};
	
	virtual void onRtnRepealFromFutureToBankByFutureManual(const dict &data) {};
	
	virtual void onRtnQueryBankBalanceByFuture(const dict &data) {};
	
	virtual void onErrRtnBankToFutureByFuture(const dict &data, const dict &error) {};
	
	virtual void onErrRtnFutureToBankByFuture(const dict &data, const dict &error) {};
	
	virtual void onErrRtnRepealBankToFutureByFutureManual(const dict &data, const dict &error) {};
	
	virtual void onErrRtnRepealFutureToBankByFutureManual(const dict &data, const dict &error) {};
	
	virtual void onErrRtnQueryBankBalanceByFuture(const dict &data, const dict &error) {};
	
	virtual void onRtnRepealFromBankToFutureByFuture(const dict &data) {};
	
	virtual void onRtnRepealFromFutureToBankByFuture(const dict &data) {};
	
	virtual void onRspFromBankToFutureByFuture(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspFromFutureToBankByFuture(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQueryBankAccountMoneyByFuture(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRtnOpenAccountByBank(const dict &data) {};
	
	virtual void onRtnCancelAccountByBank(const dict &data) {};
	
	virtual void onRtnChangeAccountByBank(const dict &data) {};
	
	virtual void onRspQryClassifiedInstrument(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryCombPromotionParam(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryRiskSettleInvstPosition(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryRiskSettleProductStatus(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQrySPBMFutureParameter(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQrySPBMOptionParameter(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQrySPBMIntraParameter(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQrySPBMInterParameter(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQrySPBMPortfDefinition(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQrySPBMInvestorPortfDef(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryInvestorPortfMarginRatio(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryInvestorProdSPBMDetail(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryInvestorCommoditySPMMMargin(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryInvestorCommodityGroupSPMMMargin(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQrySPMMInstParam(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQrySPMMProductParam(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQrySPBMAddonInterParameter(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryRCAMSCombProductInfo(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryRCAMSInstrParameter(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryRCAMSIntraParameter(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryRCAMSInterParameter(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryRCAMSShortOptAdjustParam(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryRCAMSInvestorCombPosition(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryInvestorProdRCAMSMargin(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryRULEInstrParameter(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryRULEIntraParameter(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryRULEInterParameter(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryInvestorProdRULEMargin(const dict &data, const dict &error, int reqid, bool last) {};
	
	

    //-------------------------------------------------------------------------------------
    //req:主动函数的请求字典
    //-------------------------------------------------------------------------------------

    void createFtdcTraderApi(string pszFlowPath = "");

    void release();

    void init();

    int join();

    int exit();

    string getTradingDay();

	string getApiVersion();

    void registerFront(string pszFrontAddress);

	void registerNameServer(string pszNsAddress);

	void registerFensUserInfo(const dict &req);

    void subscribePrivateTopic(int nType);

    void subscribePublicTopic(int nType);

	
	int reqAuthenticate(const dict &req, int reqid);
	
	int reqUserLogin(const dict &req, int reqid);
	
	int reqUserLogout(const dict &req, int reqid);
	
	int reqUserPasswordUpdate(const dict &req, int reqid);
	
	int reqTradingAccountPasswordUpdate(const dict &req, int reqid);
	
	int reqUserAuthMethod(const dict &req, int reqid);
	
	int reqGenUserCaptcha(const dict &req, int reqid);
	
	int reqGenUserText(const dict &req, int reqid);
	
	int reqUserLoginWithCaptcha(const dict &req, int reqid);
	
	int reqUserLoginWithText(const dict &req, int reqid);
	
	int reqUserLoginWithOTP(const dict &req, int reqid);
	
	int reqOrderInsert(const dict &req, int reqid);
	
	int reqParkedOrderInsert(const dict &req, int reqid);
	
	int reqParkedOrderAction(const dict &req, int reqid);
	
	int reqOrderAction(const dict &req, int reqid);
	
	int reqQryMaxOrderVolume(const dict &req, int reqid);
	
	int reqSettlementInfoConfirm(const dict &req, int reqid);
	
	int reqRemoveParkedOrder(const dict &req, int reqid);
	
	int reqRemoveParkedOrderAction(const dict &req, int reqid);
	
	int reqExecOrderInsert(const dict &req, int reqid);
	
	int reqExecOrderAction(const dict &req, int reqid);
	
	int reqForQuoteInsert(const dict &req, int reqid);
	
	int reqQuoteInsert(const dict &req, int reqid);
	
	int reqQuoteAction(const dict &req, int reqid);
	
	int reqBatchOrderAction(const dict &req, int reqid);
	
	int reqOptionSelfCloseInsert(const dict &req, int reqid);
	
	int reqOptionSelfCloseAction(const dict &req, int reqid);
	
	int reqCombActionInsert(const dict &req, int reqid);
	
	int reqQryOrder(const dict &req, int reqid);
	
	int reqQryTrade(const dict &req, int reqid);
	
	int reqQryInvestorPosition(const dict &req, int reqid);
	
	int reqQryTradingAccount(const dict &req, int reqid);
	
	int reqQryInvestor(const dict &req, int reqid);
	
	int reqQryTradingCode(const dict &req, int reqid);
	
	int reqQryInstrumentMarginRate(const dict &req, int reqid);
	
	int reqQryInstrumentCommissionRate(const dict &req, int reqid);
	
	int reqQryExchange(const dict &req, int reqid);
	
	int reqQryProduct(const dict &req, int reqid);
	
	int reqQryInstrument(const dict &req, int reqid);
	
	int reqQryDepthMarketData(const dict &req, int reqid);
	
	int reqQryTraderOffer(const dict &req, int reqid);
	
	int reqQrySettlementInfo(const dict &req, int reqid);
	
	int reqQryTransferBank(const dict &req, int reqid);
	
	int reqQryInvestorPositionDetail(const dict &req, int reqid);
	
	int reqQryNotice(const dict &req, int reqid);
	
	int reqQrySettlementInfoConfirm(const dict &req, int reqid);
	
	int reqQryInvestorPositionCombineDetail(const dict &req, int reqid);
	
	int reqQryCFMMCTradingAccountKey(const dict &req, int reqid);
	
	int reqQryEWarrantOffset(const dict &req, int reqid);
	
	int reqQryInvestorProductGroupMargin(const dict &req, int reqid);
	
	int reqQryExchangeMarginRate(const dict &req, int reqid);
	
	int reqQryExchangeMarginRateAdjust(const dict &req, int reqid);
	
	int reqQryExchangeRate(const dict &req, int reqid);
	
	int reqQrySecAgentACIDMap(const dict &req, int reqid);
	
	int reqQryProductExchRate(const dict &req, int reqid);
	
	int reqQryProductGroup(const dict &req, int reqid);
	
	int reqQryMMInstrumentCommissionRate(const dict &req, int reqid);
	
	int reqQryMMOptionInstrCommRate(const dict &req, int reqid);
	
	int reqQryInstrumentOrderCommRate(const dict &req, int reqid);
	
	int reqQrySecAgentTradingAccount(const dict &req, int reqid);
	
	int reqQrySecAgentCheckMode(const dict &req, int reqid);
	
	int reqQrySecAgentTradeInfo(const dict &req, int reqid);
	
	int reqQryOptionInstrTradeCost(const dict &req, int reqid);
	
	int reqQryOptionInstrCommRate(const dict &req, int reqid);
	
	int reqQryExecOrder(const dict &req, int reqid);
	
	int reqQryForQuote(const dict &req, int reqid);
	
	int reqQryQuote(const dict &req, int reqid);
	
	int reqQryOptionSelfClose(const dict &req, int reqid);
	
	int reqQryInvestUnit(const dict &req, int reqid);
	
	int reqQryCombInstrumentGuard(const dict &req, int reqid);
	
	int reqQryCombAction(const dict &req, int reqid);
	
	int reqQryTransferSerial(const dict &req, int reqid);
	
	int reqQryAccountregister(const dict &req, int reqid);
	
	int reqQryContractBank(const dict &req, int reqid);
	
	int reqQryParkedOrder(const dict &req, int reqid);
	
	int reqQryParkedOrderAction(const dict &req, int reqid);
	
	int reqQryTradingNotice(const dict &req, int reqid);
	
	int reqQryBrokerTradingParams(const dict &req, int reqid);
	
	int reqQryBrokerTradingAlgos(const dict &req, int reqid);
	
	int reqQueryCFMMCTradingAccountToken(const dict &req, int reqid);
	
	int reqFromBankToFutureByFuture(const dict &req, int reqid);
	
	int reqFromFutureToBankByFuture(const dict &req, int reqid);
	
	int reqQueryBankAccountMoneyByFuture(const dict &req, int reqid);
	
	int reqQryClassifiedInstrument(const dict &req, int reqid);
	
	int reqQryCombPromotionParam(const dict &req, int reqid);
	
	int reqQryRiskSettleInvstPosition(const dict &req, int reqid);
	
	int reqQryRiskSettleProductStatus(const dict &req, int reqid);
	
	int reqQrySPBMFutureParameter(const dict &req, int reqid);
	
	int reqQrySPBMOptionParameter(const dict &req, int reqid);
	
	int reqQrySPBMIntraParameter(const dict &req, int reqid);
	
	int reqQrySPBMInterParameter(const dict &req, int reqid);
	
	int reqQrySPBMPortfDefinition(const dict &req, int reqid);
	
	int reqQrySPBMInvestorPortfDef(const dict &req, int reqid);
	
	int reqQryInvestorPortfMarginRatio(const dict &req, int reqid);
	
	int reqQryInvestorProdSPBMDetail(const dict &req, int reqid);
	
	int reqQryInvestorCommoditySPMMMargin(const dict &req, int reqid);
	
	int reqQryInvestorCommodityGroupSPMMMargin(const dict &req, int reqid);
	
	int reqQrySPMMInstParam(const dict &req, int reqid);
	
	int reqQrySPMMProductParam(const dict &req, int reqid);
	
	int reqQrySPBMAddOnInterParameter(const dict &req, int reqid);
	
	int reqQryRCAMSCombProductInfo(const dict &req, int reqid);
	
	int reqQryRCAMSInstrParameter(const dict &req, int reqid);
	
	int reqQryRCAMSIntraParameter(const dict &req, int reqid);
	
	int reqQryRCAMSInterParameter(const dict &req, int reqid);
	
	int reqQryRCAMSShortOptAdjustParam(const dict &req, int reqid);
	
	int reqQryRCAMSInvestorCombPosition(const dict &req, int reqid);
	
	int reqQryInvestorProdRCAMSMargin(const dict &req, int reqid);
	
	int reqQryRULEInstrParameter(const dict &req, int reqid);
	
	int reqQryRULEIntraParameter(const dict &req, int reqid);
	
	int reqQryRULEInterParameter(const dict &req, int reqid);
	
	int reqQryInvestorProdRULEMargin(const dict &req, int reqid);
	
	

};

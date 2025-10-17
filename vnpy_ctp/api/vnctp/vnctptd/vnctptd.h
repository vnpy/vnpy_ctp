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
#define ONRSPQRYUSERSESSION 36
#define ONRSPQRYEXCHANGE 37
#define ONRSPQRYPRODUCT 38
#define ONRSPQRYINSTRUMENT 39
#define ONRSPQRYDEPTHMARKETDATA 40
#define ONRSPQRYTRADEROFFER 41
#define ONRSPQRYSETTLEMENTINFO 42
#define ONRSPQRYTRANSFERBANK 43
#define ONRSPQRYINVESTORPOSITIONDETAIL 44
#define ONRSPQRYNOTICE 45
#define ONRSPQRYSETTLEMENTINFOCONFIRM 46
#define ONRSPQRYINVESTORPOSITIONCOMBINEDETAIL 47
#define ONRSPQRYCFMMCTRADINGACCOUNTKEY 48
#define ONRSPQRYEWARRANTOFFSET 49
#define ONRSPQRYINVESTORPRODUCTGROUPMARGIN 50
#define ONRSPQRYEXCHANGEMARGINRATE 51
#define ONRSPQRYEXCHANGEMARGINRATEADJUST 52
#define ONRSPQRYEXCHANGERATE 53
#define ONRSPQRYSECAGENTACIDMAP 54
#define ONRSPQRYPRODUCTEXCHRATE 55
#define ONRSPQRYPRODUCTGROUP 56
#define ONRSPQRYMMINSTRUMENTCOMMISSIONRATE 57
#define ONRSPQRYMMOPTIONINSTRCOMMRATE 58
#define ONRSPQRYINSTRUMENTORDERCOMMRATE 59
#define ONRSPQRYSECAGENTTRADINGACCOUNT 60
#define ONRSPQRYSECAGENTCHECKMODE 61
#define ONRSPQRYSECAGENTTRADEINFO 62
#define ONRSPQRYOPTIONINSTRTRADECOST 63
#define ONRSPQRYOPTIONINSTRCOMMRATE 64
#define ONRSPQRYEXECORDER 65
#define ONRSPQRYFORQUOTE 66
#define ONRSPQRYQUOTE 67
#define ONRSPQRYOPTIONSELFCLOSE 68
#define ONRSPQRYINVESTUNIT 69
#define ONRSPQRYCOMBINSTRUMENTGUARD 70
#define ONRSPQRYCOMBACTION 71
#define ONRSPQRYTRANSFERSERIAL 72
#define ONRSPQRYACCOUNTREGISTER 73
#define ONRSPERROR 74
#define ONRTNORDER 75
#define ONRTNTRADE 76
#define ONERRRTNORDERINSERT 77
#define ONERRRTNORDERACTION 78
#define ONRTNINSTRUMENTSTATUS 79
#define ONRTNBULLETIN 80
#define ONRTNTRADINGNOTICE 81
#define ONRTNERRORCONDITIONALORDER 82
#define ONRTNEXECORDER 83
#define ONERRRTNEXECORDERINSERT 84
#define ONERRRTNEXECORDERACTION 85
#define ONERRRTNFORQUOTEINSERT 86
#define ONRTNQUOTE 87
#define ONERRRTNQUOTEINSERT 88
#define ONERRRTNQUOTEACTION 89
#define ONRTNFORQUOTERSP 90
#define ONRTNCFMMCTRADINGACCOUNTTOKEN 91
#define ONERRRTNBATCHORDERACTION 92
#define ONRTNOPTIONSELFCLOSE 93
#define ONERRRTNOPTIONSELFCLOSEINSERT 94
#define ONERRRTNOPTIONSELFCLOSEACTION 95
#define ONRTNCOMBACTION 96
#define ONERRRTNCOMBACTIONINSERT 97
#define ONRSPQRYCONTRACTBANK 98
#define ONRSPQRYPARKEDORDER 99
#define ONRSPQRYPARKEDORDERACTION 100
#define ONRSPQRYTRADINGNOTICE 101
#define ONRSPQRYBROKERTRADINGPARAMS 102
#define ONRSPQRYBROKERTRADINGALGOS 103
#define ONRSPQUERYCFMMCTRADINGACCOUNTTOKEN 104
#define ONRTNFROMBANKTOFUTUREBYBANK 105
#define ONRTNFROMFUTURETOBANKBYBANK 106
#define ONRTNREPEALFROMBANKTOFUTUREBYBANK 107
#define ONRTNREPEALFROMFUTURETOBANKBYBANK 108
#define ONRTNFROMBANKTOFUTUREBYFUTURE 109
#define ONRTNFROMFUTURETOBANKBYFUTURE 110
#define ONRTNREPEALFROMBANKTOFUTUREBYFUTUREMANUAL 111
#define ONRTNREPEALFROMFUTURETOBANKBYFUTUREMANUAL 112
#define ONRTNQUERYBANKBALANCEBYFUTURE 113
#define ONERRRTNBANKTOFUTUREBYFUTURE 114
#define ONERRRTNFUTURETOBANKBYFUTURE 115
#define ONERRRTNREPEALBANKTOFUTUREBYFUTUREMANUAL 116
#define ONERRRTNREPEALFUTURETOBANKBYFUTUREMANUAL 117
#define ONERRRTNQUERYBANKBALANCEBYFUTURE 118
#define ONRTNREPEALFROMBANKTOFUTUREBYFUTURE 119
#define ONRTNREPEALFROMFUTURETOBANKBYFUTURE 120
#define ONRSPFROMBANKTOFUTUREBYFUTURE 121
#define ONRSPFROMFUTURETOBANKBYFUTURE 122
#define ONRSPQUERYBANKACCOUNTMONEYBYFUTURE 123
#define ONRTNOPENACCOUNTBYBANK 124
#define ONRTNCANCELACCOUNTBYBANK 125
#define ONRTNCHANGEACCOUNTBYBANK 126
#define ONRSPQRYCLASSIFIEDINSTRUMENT 127
#define ONRSPQRYCOMBPROMOTIONPARAM 128
#define ONRSPQRYRISKSETTLEINVSTPOSITION 129
#define ONRSPQRYRISKSETTLEPRODUCTSTATUS 130
#define ONRSPQRYSPBMFUTUREPARAMETER 131
#define ONRSPQRYSPBMOPTIONPARAMETER 132
#define ONRSPQRYSPBMINTRAPARAMETER 133
#define ONRSPQRYSPBMINTERPARAMETER 134
#define ONRSPQRYSPBMPORTFDEFINITION 135
#define ONRSPQRYSPBMINVESTORPORTFDEF 136
#define ONRSPQRYINVESTORPORTFMARGINRATIO 137
#define ONRSPQRYINVESTORPRODSPBMDETAIL 138
#define ONRSPQRYINVESTORCOMMODITYSPMMMARGIN 139
#define ONRSPQRYINVESTORCOMMODITYGROUPSPMMMARGIN 140
#define ONRSPQRYSPMMINSTPARAM 141
#define ONRSPQRYSPMMPRODUCTPARAM 142
#define ONRSPQRYSPBMADDONINTERPARAMETER 143
#define ONRSPQRYRCAMSCOMBPRODUCTINFO 144
#define ONRSPQRYRCAMSINSTRPARAMETER 145
#define ONRSPQRYRCAMSINTRAPARAMETER 146
#define ONRSPQRYRCAMSINTERPARAMETER 147
#define ONRSPQRYRCAMSSHORTOPTADJUSTPARAM 148
#define ONRSPQRYRCAMSINVESTORCOMBPOSITION 149
#define ONRSPQRYINVESTORPRODRCAMSMARGIN 150
#define ONRSPQRYRULEINSTRPARAMETER 151
#define ONRSPQRYRULEINTRAPARAMETER 152
#define ONRSPQRYRULEINTERPARAMETER 153
#define ONRSPQRYINVESTORPRODRULEMARGIN 154
#define ONRSPQRYINVESTORPORTFSETTING 155
#define ONRSPQRYINVESTORINFOCOMMREC 156
#define ONRSPQRYCOMBLEG 157
#define ONRSPOFFSETSETTING 158
#define ONRSPCANCELOFFSETSETTING 159
#define ONRTNOFFSETSETTING 160
#define ONERRRTNOFFSETSETTING 161
#define ONERRRTNCANCELOFFSETSETTING 162
#define ONRSPQRYOFFSETSETTING 163

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

    virtual ~TdApi()
    {
        if (this->active)
        {
            this->exit();
        }
    };

    //-------------------------------------------------------------------------------------
    //API回调函数
    //-------------------------------------------------------------------------------------

	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	virtual void OnFrontConnected();
	
	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	virtual void OnFrontDisconnected(int nReason);
		
	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	virtual void OnHeartBeatWarning(int nTimeLapse);
	
	///客户端认证响应
	virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	

	///登录请求响应
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///登出请求响应
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///用户口令更新请求响应
	virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///资金账户口令更新请求响应
	virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///查询用户当前支持的认证模式的回复
	virtual void OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField *pRspUserAuthMethod, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///获取图形验证码请求的回复
	virtual void OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField *pRspGenUserCaptcha, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///获取短信验证码请求的回复
	virtual void OnRspGenUserText(CThostFtdcRspGenUserTextField *pRspGenUserText, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///报单录入请求响应
	virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///预埋单录入请求响应
	virtual void OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///预埋撤单录入请求响应
	virtual void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///报单操作请求响应
	virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///查询最大报单数量响应
	virtual void OnRspQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField *pQryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///投资者结算结果确认响应
	virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///删除预埋单响应
	virtual void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///删除预埋撤单响应
	virtual void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///执行宣告录入请求响应
	virtual void OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///执行宣告操作请求响应
	virtual void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///询价录入请求响应
	virtual void OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///报价录入请求响应
	virtual void OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///报价操作请求响应
	virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///批量报单操作请求响应
	virtual void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///期权自对冲录入请求响应
	virtual void OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///期权自对冲操作请求响应
	virtual void OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///申请组合录入请求响应
	virtual void OnRspCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询报单响应
	virtual void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询成交响应
	virtual void OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询投资者持仓响应
	virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询资金账户响应
	virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询投资者响应
	virtual void OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询交易编码响应
	virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询合约保证金率响应
	virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询合约手续费率响应
	virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询用户会话响应
	virtual void OnRspQryUserSession(CThostFtdcUserSessionField* pUserSession, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///请求查询交易所响应
	virtual void OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询产品响应
	virtual void OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询合约响应
	virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询行情响应
	virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询交易员报盘机响应
	virtual void OnRspQryTraderOffer(CThostFtdcTraderOfferField *pTraderOffer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询投资者结算结果响应
	virtual void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询转帐银行响应
	virtual void OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询投资者持仓明细响应
	virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询客户通知响应
	virtual void OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询结算信息确认响应
	virtual void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询投资者持仓明细响应
	virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///查询保证金监管系统经纪公司资金账户密钥响应
	virtual void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询仓单折抵信息响应
	virtual void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询投资者品种/跨品种保证金响应
	virtual void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询交易所保证金率响应
	virtual void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询交易所调整保证金率响应
	virtual void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询汇率响应
	virtual void OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询二级代理操作员银期权限响应
	virtual void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询产品报价汇率
	virtual void OnRspQryProductExchRate(CThostFtdcProductExchRateField *pProductExchRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询产品组
	virtual void OnRspQryProductGroup(CThostFtdcProductGroupField *pProductGroup, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询做市商合约手续费率响应
	virtual void OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField *pMMInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询做市商期权合约手续费响应
	virtual void OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField *pMMOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询报单手续费响应
	virtual void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *pInstrumentOrderCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询资金账户响应
	virtual void OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询二级代理商资金校验模式响应
	virtual void OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField *pSecAgentCheckMode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询二级代理商信息响应
	virtual void OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField *pSecAgentTradeInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询期权交易成本响应
	virtual void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询期权合约手续费响应
	virtual void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询执行宣告响应
	virtual void OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询询价响应
	virtual void OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询报价响应
	virtual void OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询期权自对冲响应
	virtual void OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询投资单元响应
	virtual void OnRspQryInvestUnit(CThostFtdcInvestUnitField *pInvestUnit, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询组合合约安全系数响应
	virtual void OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField *pCombInstrumentGuard, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询申请组合响应
	virtual void OnRspQryCombAction(CThostFtdcCombActionField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询转帐流水响应
	virtual void OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询银期签约关系响应
	virtual void OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///错误应答
	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///报单通知
	virtual void OnRtnOrder(CThostFtdcOrderField *pOrder);

	///成交通知
	virtual void OnRtnTrade(CThostFtdcTradeField *pTrade);

	///报单录入错误回报
	virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo);

	///报单操作错误回报
	virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo);

	///合约交易状态通知
	virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus);

	///交易所公告通知
	virtual void OnRtnBulletin(CThostFtdcBulletinField *pBulletin);

	///交易通知
	virtual void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo);

	///提示条件单校验错误
	virtual void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder);

	///执行宣告通知
	virtual void OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder);

	///执行宣告录入错误回报
	virtual void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo);

	///执行宣告操作错误回报
	virtual void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo);

	///询价录入错误回报
	virtual void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo);

	///报价通知
	virtual void OnRtnQuote(CThostFtdcQuoteField *pQuote);

	///报价录入错误回报
	virtual void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo);

	///报价操作错误回报
	virtual void OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo);

	///询价通知
	virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp);

	///保证金监控中心用户令牌
	virtual void OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken);

	///批量报单操作错误回报
	virtual void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo);

	///期权自对冲通知
	virtual void OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose);

	///期权自对冲录入错误回报
	virtual void OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo);

	///期权自对冲操作错误回报
	virtual void OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField *pOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo);

	///申请组合通知
	virtual void OnRtnCombAction(CThostFtdcCombActionField *pCombAction);

	///申请组合录入错误回报
	virtual void OnErrRtnCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo);

	///请求查询签约银行响应
	virtual void OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询预埋单响应
	virtual void OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询预埋撤单响应
	virtual void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询交易通知响应
	virtual void OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询经纪公司交易参数响应
	virtual void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询经纪公司交易算法响应
	virtual void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求查询监控中心用户令牌
	virtual void OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///银行发起银行资金转期货通知
	virtual void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer);

	///银行发起期货资金转银行通知
	virtual void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer);

	///银行发起冲正银行转期货通知
	virtual void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal);

	///银行发起冲正期货转银行通知
	virtual void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal);

	///期货发起银行资金转期货通知
	virtual void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer);

	///期货发起期货资金转银行通知
	virtual void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer);

	///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	virtual void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal);

	///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	virtual void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal);

	///期货发起查询银行余额通知
	virtual void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount);

	///期货发起银行资金转期货错误回报
	virtual void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);

	///期货发起期货资金转银行错误回报
	virtual void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);

	///系统运行时期货端手工发起冲正银行转期货错误回报
	virtual void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);

	///系统运行时期货端手工发起冲正期货转银行错误回报
	virtual void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);

	///期货发起查询银行余额错误回报
	virtual void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo);

	///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	virtual void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal);

	///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	virtual void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal);

	///期货发起银行资金转期货应答
	virtual void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///期货发起期货资金转银行应答
	virtual void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///期货发起查询银行余额应答
	virtual void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///银行发起银期开户通知
	virtual void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount);

	///银行发起银期销户通知
	virtual void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount);

	///银行发起变更银行账号通知
	virtual void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount);

	///请求查询分类合约响应
	virtual void OnRspQryClassifiedInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///请求组合优惠比例响应
	virtual void OnRspQryCombPromotionParam(CThostFtdcCombPromotionParamField *pCombPromotionParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///投资者风险结算持仓查询响应
	virtual void OnRspQryRiskSettleInvstPosition(CThostFtdcRiskSettleInvstPositionField *pRiskSettleInvstPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///风险结算产品查询响应
	virtual void OnRspQryRiskSettleProductStatus(CThostFtdcRiskSettleProductStatusField *pRiskSettleProductStatus, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///SPBM期货合约参数查询响应
	virtual void OnRspQrySPBMFutureParameter(CThostFtdcSPBMFutureParameterField *pSPBMFutureParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///SPBM期权合约参数查询响应
	virtual void OnRspQrySPBMOptionParameter(CThostFtdcSPBMOptionParameterField *pSPBMOptionParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///SPBM品种内对锁仓折扣参数查询响应
	virtual void OnRspQrySPBMIntraParameter(CThostFtdcSPBMIntraParameterField *pSPBMIntraParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///SPBM跨品种抵扣参数查询响应
	virtual void OnRspQrySPBMInterParameter(CThostFtdcSPBMInterParameterField *pSPBMInterParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///SPBM组合保证金套餐查询响应
	virtual void OnRspQrySPBMPortfDefinition(CThostFtdcSPBMPortfDefinitionField *pSPBMPortfDefinition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///投资者SPBM套餐选择查询响应
	virtual void OnRspQrySPBMInvestorPortfDef(CThostFtdcSPBMInvestorPortfDefField *pSPBMInvestorPortfDef, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///投资者新型组合保证金系数查询响应
	virtual void OnRspQryInvestorPortfMarginRatio(CThostFtdcInvestorPortfMarginRatioField *pInvestorPortfMarginRatio, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///投资者产品SPBM明细查询响应
	virtual void OnRspQryInvestorProdSPBMDetail(CThostFtdcInvestorProdSPBMDetailField *pInvestorProdSPBMDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///投资者商品组SPMM记录查询响应
	virtual void OnRspQryInvestorCommoditySPMMMargin(CThostFtdcInvestorCommoditySPMMMarginField *pInvestorCommoditySPMMMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///投资者商品群SPMM记录查询响应
	virtual void OnRspQryInvestorCommodityGroupSPMMMargin(CThostFtdcInvestorCommodityGroupSPMMMarginField *pInvestorCommodityGroupSPMMMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///SPMM合约参数查询响应
	virtual void OnRspQrySPMMInstParam(CThostFtdcSPMMInstParamField *pSPMMInstParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///SPMM产品参数查询响应
	virtual void OnRspQrySPMMProductParam(CThostFtdcSPMMProductParamField *pSPMMProductParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///SPBM附加跨品种抵扣参数查询响应
	virtual void OnRspQrySPBMAddOnInterParameter(CThostFtdcSPBMAddOnInterParameterField *pSPBMAddOnInterParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///RCAMS产品组合信息查询响应
	virtual void OnRspQryRCAMSCombProductInfo(CThostFtdcRCAMSCombProductInfoField *pRCAMSCombProductInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///RCAMS同合约风险对冲参数查询响应
	virtual void OnRspQryRCAMSInstrParameter(CThostFtdcRCAMSInstrParameterField *pRCAMSInstrParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///RCAMS品种内风险对冲参数查询响应
	virtual void OnRspQryRCAMSIntraParameter(CThostFtdcRCAMSIntraParameterField *pRCAMSIntraParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///RCAMS跨品种风险折抵参数查询响应
	virtual void OnRspQryRCAMSInterParameter(CThostFtdcRCAMSInterParameterField *pRCAMSInterParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///RCAMS空头期权风险调整参数查询响应
	virtual void OnRspQryRCAMSShortOptAdjustParam(CThostFtdcRCAMSShortOptAdjustParamField *pRCAMSShortOptAdjustParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///RCAMS策略组合持仓查询响应
	virtual void OnRspQryRCAMSInvestorCombPosition(CThostFtdcRCAMSInvestorCombPositionField *pRCAMSInvestorCombPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///投资者品种RCAMS保证金查询响应
	virtual void OnRspQryInvestorProdRCAMSMargin(CThostFtdcInvestorProdRCAMSMarginField *pInvestorProdRCAMSMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///RULE合约保证金参数查询响应
	virtual void OnRspQryRULEInstrParameter(CThostFtdcRULEInstrParameterField *pRULEInstrParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///RULE品种内对锁仓折扣参数查询响应
	virtual void OnRspQryRULEIntraParameter(CThostFtdcRULEIntraParameterField *pRULEIntraParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///RULE跨品种抵扣参数查询响应
	virtual void OnRspQryRULEInterParameter(CThostFtdcRULEInterParameterField *pRULEInterParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///投资者产品RULE保证金查询响应
	virtual void OnRspQryInvestorProdRULEMargin(CThostFtdcInvestorProdRULEMarginField *pInvestorProdRULEMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///投资者新型组合保证金开关查询响应
	virtual void OnRspQryInvestorPortfSetting(CThostFtdcInvestorPortfSettingField* pInvestorPortfSetting, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///投资者申报费阶梯收取记录查询响应
	virtual void OnRspQryInvestorInfoCommRec(CThostFtdcInvestorInfoCommRecField* pInvestorInfoCommRec, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///组合腿信息查询响应
	virtual void OnRspQryCombLeg(CThostFtdcCombLegField* pCombLeg, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///对冲设置请求响应
	virtual void OnRspOffsetSetting(CThostFtdcInputOffsetSettingField* pInputOffsetSetting, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///对冲设置撤销请求响应
	virtual void OnRspCancelOffsetSetting(CThostFtdcInputOffsetSettingField* pInputOffsetSetting, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///对冲设置通知
	virtual void OnRtnOffsetSetting(CThostFtdcOffsetSettingField* pOffsetSetting);

	///对冲设置错误回报
	virtual void OnErrRtnOffsetSetting(CThostFtdcInputOffsetSettingField* pInputOffsetSetting, CThostFtdcRspInfoField* pRspInfo);

	///对冲设置撤销错误回报
	virtual void OnErrRtnCancelOffsetSetting(CThostFtdcCancelOffsetSettingField* pCancelOffsetSetting, CThostFtdcRspInfoField* pRspInfo);

	///投资者对冲设置查询响应
	virtual void OnRspQryOffsetSetting(CThostFtdcOffsetSettingField* pOffsetSetting, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);
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

	void processRspQryUserSession(Task* task);

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

	void processRspQryInvestorPortfSetting(Task *task);

	void processRspQryInvestorInfoCommRec(Task* task);

	void processRspQryCombLeg(Task* task);

	void processRspOffsetSetting(Task* task);

	void processRspCancelOffsetSetting(Task* task);

	void processRtnOffsetSetting(Task* task);

	void processErrRtnOffsetSetting(Task* task);

	void processErrRtnCancelOffsetSetting(Task* task);

	void processRspQryOffsetSetting(Task* task);

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

	virtual void onRspQryUserSession(const dict& data, const dict& error, int reqid, bool last) {};

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

	virtual void onRspQryInvestorPortfSetting(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryInvestorInfoCommRec(const dict& data, const dict& error, int reqid, bool last) {};

	virtual void onRspQryCombLeg(const dict& data, const dict& error, int reqid, bool last) {};

	virtual void onRspOffsetSetting(const dict& data, const dict& error, int reqid, bool last) {};

	virtual void onRspCancelOffsetSetting(const dict& data, const dict& error, int reqid, bool last) {};

	virtual void onRtnOffsetSetting(const dict& data) {};

	virtual void onErrRtnOffsetSetting(const dict& data, const dict& error) {};

	virtual void onErrRtnCancelOffsetSetting(const dict& data, const dict& error) {};

	virtual void onRspQryOffsetSetting(const dict& data, const dict& error, int reqid, bool last) {};

    //-------------------------------------------------------------------------------------
    //req:主动函数的请求字典
    //-------------------------------------------------------------------------------------

    void createFtdcTraderApi(string pszFlowPath = "", bool bIsProductionMode = true);

    void release();

    void init();

    int join();

    int exit();

    string getTradingDay();

	string getApiVersion();

	dict getFrontInfo();

    void registerFront(string pszFrontAddress);

	void registerNameServer(string pszNsAddress);

	void registerFensUserInfo(const dict &req);

    void subscribePrivateTopic(int nType);

    void subscribePublicTopic(int nType);

	int registerUserSystemInfo(const dict& req);

	int submitUserSystemInfo(const dict& req);

	int registerWechatUserSystemInfo(const dict& req);

	int submitWechatUserSystemInfo(const dict& req);

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

	int reqQryUserSession(const dict& req, int reqid);

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

	int reqQryInvestorPortfSetting(const dict &req, int reqid);

	int reqQryInvestorInfoCommRec(const dict& req, int reqid);

	int reqQryCombLeg(const dict& req, int reqid);

	int reqOffsetSetting(const dict& req, int reqid);

	int reqCancelOffsetSetting(const dict& req, int reqid);

	int reqQryOffsetSetting(const dict& req, int reqid);
};

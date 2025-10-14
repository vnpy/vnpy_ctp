//ϵͳ
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnctp.h"
#include "pybind11/pybind11.h"
#include "ctp/ThostFtdcTraderApi.h"


using namespace pybind11;

//����
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
///C++ SPI�Ļص���������ʵ��
///-------------------------------------------------------------------------------------

//API�ļ̳�ʵ��
class TdApi : public CThostFtdcTraderSpi
{
private:
	CThostFtdcTraderApi* api;            //API����
    thread task_thread;                    //�����߳�ָ�루��python���������ݣ�
    TaskQueue task_queue;                //�������
    bool active = false;                //����״̬

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
    //API�ص�����
    //-------------------------------------------------------------------------------------

	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected();
	
	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason);
		
	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse);
	
	///�ͻ�����֤��Ӧ
	virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	

	///��¼������Ӧ
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�û��������������Ӧ
	virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ʽ��˻��������������Ӧ
	virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��ѯ�û���ǰ֧�ֵ���֤ģʽ�Ļظ�
	virtual void OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField *pRspUserAuthMethod, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��ȡͼ����֤������Ļظ�
	virtual void OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField *pRspGenUserCaptcha, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��ȡ������֤������Ļظ�
	virtual void OnRspGenUserText(CThostFtdcRspGenUserTextField *pRspGenUserText, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����¼��������Ӧ
	virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///Ԥ��¼��������Ӧ
	virtual void OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///Ԥ�񳷵�¼��������Ӧ
	virtual void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��������������Ӧ
	virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��ѯ��󱨵�������Ӧ
	virtual void OnRspQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField *pQryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///Ͷ���߽�����ȷ����Ӧ
	virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///ɾ��Ԥ����Ӧ
	virtual void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///ɾ��Ԥ�񳷵���Ӧ
	virtual void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///ִ������¼��������Ӧ
	virtual void OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///ִ���������������Ӧ
	virtual void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///ѯ��¼��������Ӧ
	virtual void OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����¼��������Ӧ
	virtual void OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///���۲���������Ӧ
	virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///������������������Ӧ
	virtual void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��Ȩ�ԶԳ�¼��������Ӧ
	virtual void OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��Ȩ�ԶԳ����������Ӧ
	virtual void OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�������¼��������Ӧ
	virtual void OnRspCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ������Ӧ
	virtual void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ�ɽ���Ӧ
	virtual void OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯͶ���ֲ߳���Ӧ
	virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ�ʽ��˻���Ӧ
	virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯͶ������Ӧ
	virtual void OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ���ױ�����Ӧ
	virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��Լ��֤������Ӧ
	virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��Լ����������Ӧ
	virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ�û��Ự��Ӧ
	virtual void OnRspQryUserSession(CThostFtdcUserSessionField* pUserSession, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��������Ӧ
	virtual void OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��Ʒ��Ӧ
	virtual void OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��Լ��Ӧ
	virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ������Ӧ
	virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ����Ա���̻���Ӧ
	virtual void OnRspQryTraderOffer(CThostFtdcTraderOfferField *pTraderOffer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯͶ���߽�������Ӧ
	virtual void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯת��������Ӧ
	virtual void OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯͶ���ֲ߳���ϸ��Ӧ
	virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ�ͻ�֪ͨ��Ӧ
	virtual void OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ������Ϣȷ����Ӧ
	virtual void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯͶ���ֲ߳���ϸ��Ӧ
	virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ��Ӧ
	virtual void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ�ֵ��۵���Ϣ��Ӧ
	virtual void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯͶ����Ʒ��/��Ʒ�ֱ�֤����Ӧ
	virtual void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��������֤������Ӧ
	virtual void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ������������֤������Ӧ
	virtual void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ������Ӧ
	virtual void OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ�����������Ա����Ȩ����Ӧ
	virtual void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��Ʒ���ۻ���
	virtual void OnRspQryProductExchRate(CThostFtdcProductExchRateField *pProductExchRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��Ʒ��
	virtual void OnRspQryProductGroup(CThostFtdcProductGroupField *pProductGroup, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ�����̺�Լ����������Ӧ
	virtual void OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField *pMMInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��������Ȩ��Լ��������Ӧ
	virtual void OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField *pMMOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ������������Ӧ
	virtual void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *pInstrumentOrderCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ�ʽ��˻���Ӧ
	virtual void OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ�����������ʽ�У��ģʽ��Ӧ
	virtual void OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField *pSecAgentCheckMode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ������������Ϣ��Ӧ
	virtual void OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField *pSecAgentTradeInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��Ȩ���׳ɱ���Ӧ
	virtual void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��Ȩ��Լ��������Ӧ
	virtual void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯִ��������Ӧ
	virtual void OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯѯ����Ӧ
	virtual void OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ������Ӧ
	virtual void OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��Ȩ�ԶԳ���Ӧ
	virtual void OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯͶ�ʵ�Ԫ��Ӧ
	virtual void OnRspQryInvestUnit(CThostFtdcInvestUnitField *pInvestUnit, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��Ϻ�Լ��ȫϵ����Ӧ
	virtual void OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField *pCombInstrumentGuard, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ���������Ӧ
	virtual void OnRspQryCombAction(CThostFtdcCombActionField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯת����ˮ��Ӧ
	virtual void OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ����ǩԼ��ϵ��Ӧ
	virtual void OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����Ӧ��
	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����֪ͨ
	virtual void OnRtnOrder(CThostFtdcOrderField *pOrder);

	///�ɽ�֪ͨ
	virtual void OnRtnTrade(CThostFtdcTradeField *pTrade);

	///����¼�����ر�
	virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo);

	///������������ر�
	virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo);

	///��Լ����״̬֪ͨ
	virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus);

	///����������֪ͨ
	virtual void OnRtnBulletin(CThostFtdcBulletinField *pBulletin);

	///����֪ͨ
	virtual void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo);

	///��ʾ������У�����
	virtual void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder);

	///ִ������֪ͨ
	virtual void OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder);

	///ִ������¼�����ر�
	virtual void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo);

	///ִ�������������ر�
	virtual void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo);

	///ѯ��¼�����ر�
	virtual void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo);

	///����֪ͨ
	virtual void OnRtnQuote(CThostFtdcQuoteField *pQuote);

	///����¼�����ر�
	virtual void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo);

	///���۲�������ر�
	virtual void OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo);

	///ѯ��֪ͨ
	virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp);

	///��֤���������û�����
	virtual void OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken);

	///����������������ر�
	virtual void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo);

	///��Ȩ�ԶԳ�֪ͨ
	virtual void OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose);

	///��Ȩ�ԶԳ�¼�����ر�
	virtual void OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo);

	///��Ȩ�ԶԳ��������ر�
	virtual void OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField *pOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo);

	///�������֪ͨ
	virtual void OnRtnCombAction(CThostFtdcCombActionField *pCombAction);

	///�������¼�����ر�
	virtual void OnErrRtnCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo);

	///�����ѯǩԼ������Ӧ
	virtual void OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯԤ����Ӧ
	virtual void OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯԤ�񳷵���Ӧ
	virtual void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ����֪ͨ��Ӧ
	virtual void OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ���͹�˾���ײ�����Ӧ
	virtual void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ���͹�˾�����㷨��Ӧ
	virtual void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��������û�����
	virtual void OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///���з��������ʽ�ת�ڻ�֪ͨ
	virtual void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer);

	///���з����ڻ��ʽ�ת����֪ͨ
	virtual void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer);

	///���з����������ת�ڻ�֪ͨ
	virtual void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal);

	///���з�������ڻ�ת����֪ͨ
	virtual void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal);

	///�ڻ����������ʽ�ת�ڻ�֪ͨ
	virtual void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer);

	///�ڻ������ڻ��ʽ�ת����֪ͨ
	virtual void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer);

	///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
	virtual void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal);

	///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
	virtual void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal);

	///�ڻ������ѯ�������֪ͨ
	virtual void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount);

	///�ڻ����������ʽ�ת�ڻ�����ر�
	virtual void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);

	///�ڻ������ڻ��ʽ�ת���д���ر�
	virtual void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);

	///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ�����ر�
	virtual void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);

	///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת���д���ر�
	virtual void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);

	///�ڻ������ѯ����������ر�
	virtual void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo);

	///�ڻ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
	virtual void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal);

	///�ڻ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
	virtual void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal);

	///�ڻ����������ʽ�ת�ڻ�Ӧ��
	virtual void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ڻ������ڻ��ʽ�ת����Ӧ��
	virtual void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ڻ������ѯ�������Ӧ��
	virtual void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///���з������ڿ���֪ͨ
	virtual void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount);

	///���з�����������֪ͨ
	virtual void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount);

	///���з����������˺�֪ͨ
	virtual void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount);

	///�����ѯ�����Լ��Ӧ
	virtual void OnRspQryClassifiedInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��������Żݱ�����Ӧ
	virtual void OnRspQryCombPromotionParam(CThostFtdcCombPromotionParamField *pCombPromotionParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///Ͷ���߷��ս���ֲֲ�ѯ��Ӧ
	virtual void OnRspQryRiskSettleInvstPosition(CThostFtdcRiskSettleInvstPositionField *pRiskSettleInvstPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///���ս����Ʒ��ѯ��Ӧ
	virtual void OnRspQryRiskSettleProductStatus(CThostFtdcRiskSettleProductStatusField *pRiskSettleProductStatus, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///SPBM�ڻ���Լ������ѯ��Ӧ
	virtual void OnRspQrySPBMFutureParameter(CThostFtdcSPBMFutureParameterField *pSPBMFutureParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///SPBM��Ȩ��Լ������ѯ��Ӧ
	virtual void OnRspQrySPBMOptionParameter(CThostFtdcSPBMOptionParameterField *pSPBMOptionParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///SPBMƷ���ڶ������ۿ۲�����ѯ��Ӧ
	virtual void OnRspQrySPBMIntraParameter(CThostFtdcSPBMIntraParameterField *pSPBMIntraParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///SPBM��Ʒ�ֵֿ۲�����ѯ��Ӧ
	virtual void OnRspQrySPBMInterParameter(CThostFtdcSPBMInterParameterField *pSPBMInterParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///SPBM��ϱ�֤���ײͲ�ѯ��Ӧ
	virtual void OnRspQrySPBMPortfDefinition(CThostFtdcSPBMPortfDefinitionField *pSPBMPortfDefinition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///Ͷ����SPBM�ײ�ѡ���ѯ��Ӧ
	virtual void OnRspQrySPBMInvestorPortfDef(CThostFtdcSPBMInvestorPortfDefField *pSPBMInvestorPortfDef, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///Ͷ����������ϱ�֤��ϵ����ѯ��Ӧ
	virtual void OnRspQryInvestorPortfMarginRatio(CThostFtdcInvestorPortfMarginRatioField *pInvestorPortfMarginRatio, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///Ͷ���߲�ƷSPBM��ϸ��ѯ��Ӧ
	virtual void OnRspQryInvestorProdSPBMDetail(CThostFtdcInvestorProdSPBMDetailField *pInvestorProdSPBMDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///Ͷ������Ʒ��SPMM��¼��ѯ��Ӧ
	virtual void OnRspQryInvestorCommoditySPMMMargin(CThostFtdcInvestorCommoditySPMMMarginField *pInvestorCommoditySPMMMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///Ͷ������ƷȺSPMM��¼��ѯ��Ӧ
	virtual void OnRspQryInvestorCommodityGroupSPMMMargin(CThostFtdcInvestorCommodityGroupSPMMMarginField *pInvestorCommodityGroupSPMMMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///SPMM��Լ������ѯ��Ӧ
	virtual void OnRspQrySPMMInstParam(CThostFtdcSPMMInstParamField *pSPMMInstParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///SPMM��Ʒ������ѯ��Ӧ
	virtual void OnRspQrySPMMProductParam(CThostFtdcSPMMProductParamField *pSPMMProductParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///SPBM���ӿ�Ʒ�ֵֿ۲�����ѯ��Ӧ
	virtual void OnRspQrySPBMAddOnInterParameter(CThostFtdcSPBMAddOnInterParameterField *pSPBMAddOnInterParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///RCAMS��Ʒ�����Ϣ��ѯ��Ӧ
	virtual void OnRspQryRCAMSCombProductInfo(CThostFtdcRCAMSCombProductInfoField *pRCAMSCombProductInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///RCAMSͬ��Լ���նԳ������ѯ��Ӧ
	virtual void OnRspQryRCAMSInstrParameter(CThostFtdcRCAMSInstrParameterField *pRCAMSInstrParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///RCAMSƷ���ڷ��նԳ������ѯ��Ӧ
	virtual void OnRspQryRCAMSIntraParameter(CThostFtdcRCAMSIntraParameterField *pRCAMSIntraParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///RCAMS��Ʒ�ַ����۵ֲ�����ѯ��Ӧ
	virtual void OnRspQryRCAMSInterParameter(CThostFtdcRCAMSInterParameterField *pRCAMSInterParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///RCAMS��ͷ��Ȩ���յ���������ѯ��Ӧ
	virtual void OnRspQryRCAMSShortOptAdjustParam(CThostFtdcRCAMSShortOptAdjustParamField *pRCAMSShortOptAdjustParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///RCAMS������ϳֲֲ�ѯ��Ӧ
	virtual void OnRspQryRCAMSInvestorCombPosition(CThostFtdcRCAMSInvestorCombPositionField *pRCAMSInvestorCombPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///Ͷ����Ʒ��RCAMS��֤���ѯ��Ӧ
	virtual void OnRspQryInvestorProdRCAMSMargin(CThostFtdcInvestorProdRCAMSMarginField *pInvestorProdRCAMSMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///RULE��Լ��֤�������ѯ��Ӧ
	virtual void OnRspQryRULEInstrParameter(CThostFtdcRULEInstrParameterField *pRULEInstrParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///RULEƷ���ڶ������ۿ۲�����ѯ��Ӧ
	virtual void OnRspQryRULEIntraParameter(CThostFtdcRULEIntraParameterField *pRULEIntraParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///RULE��Ʒ�ֵֿ۲�����ѯ��Ӧ
	virtual void OnRspQryRULEInterParameter(CThostFtdcRULEInterParameterField *pRULEInterParameter, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///Ͷ���߲�ƷRULE��֤���ѯ��Ӧ
	virtual void OnRspQryInvestorProdRULEMargin(CThostFtdcInvestorProdRULEMarginField *pInvestorProdRULEMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///Ͷ����������ϱ�֤�𿪹ز�ѯ��Ӧ
	virtual void OnRspQryInvestorPortfSetting(CThostFtdcInvestorPortfSettingField* pInvestorPortfSetting, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///Ͷ�����걨�ѽ�����ȡ��¼��ѯ��Ӧ
	virtual void OnRspQryInvestorInfoCommRec(CThostFtdcInvestorInfoCommRecField* pInvestorInfoCommRec, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///�������Ϣ��ѯ��Ӧ
	virtual void OnRspQryCombLeg(CThostFtdcCombLegField* pCombLeg, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///�Գ�����������Ӧ
	virtual void OnRspOffsetSetting(CThostFtdcInputOffsetSettingField* pInputOffsetSetting, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///�Գ����ó���������Ӧ
	virtual void OnRspCancelOffsetSetting(CThostFtdcInputOffsetSettingField* pInputOffsetSetting, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

	///�Գ�����֪ͨ
	virtual void OnRtnOffsetSetting(CThostFtdcOffsetSettingField* pOffsetSetting);

	///�Գ����ô���ر�
	virtual void OnErrRtnOffsetSetting(CThostFtdcInputOffsetSettingField* pInputOffsetSetting, CThostFtdcRspInfoField* pRspInfo);

	///�Գ����ó�������ر�
	virtual void OnErrRtnCancelOffsetSetting(CThostFtdcCancelOffsetSettingField* pCancelOffsetSetting, CThostFtdcRspInfoField* pRspInfo);

	///Ͷ���߶Գ����ò�ѯ��Ӧ
	virtual void OnRspQryOffsetSetting(CThostFtdcOffsetSettingField* pOffsetSetting, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);
    //-------------------------------------------------------------------------------------
    //task������
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
    //data���ص������������ֵ�
    //error���ص������Ĵ����ֵ�
    //id������id
    //last���Ƿ�Ϊ��󷵻�
    //i������
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
    //req:���������������ֵ�
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

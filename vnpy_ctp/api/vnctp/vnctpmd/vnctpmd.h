//ϵͳ
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnctp.h"
#include "pybind11/pybind11.h"
#include "ctp/ThostFtdcMdApi.h"

using namespace pybind11;

//����


#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONHEARTBEATWARNING 2
#define ONRSPUSERLOGIN 3
#define ONRSPUSERLOGOUT 4
#define ONRSPQRYMULTICASTINSTRUMENT 5
#define ONRSPERROR 6
#define ONRSPSUBMARKETDATA 7
#define ONRSPUNSUBMARKETDATA 8
#define ONRSPSUBFORQUOTERSP 9
#define ONRSPUNSUBFORQUOTERSP 10
#define ONRTNDEPTHMARKETDATA 11
#define ONRTNFORQUOTERSP 12


///-------------------------------------------------------------------------------------
///C++ SPI�Ļص���������ʵ��
///-------------------------------------------------------------------------------------

//API�ļ̳�ʵ��
class MdApi : public CThostFtdcMdSpi
{
private:
	CThostFtdcMdApi* api;				//API����
	thread task_thread;					//�����߳�ָ�루��python���������ݣ�
	TaskQueue task_queue;			    //�������
	bool active = false;				//����״̬

public:
	MdApi()
	{
	};

	~MdApi()
	{
		if (this->active)
		{
			this->exit();
		}
	};

	//-------------------------------------------------------------------------------------
	//API�ص�����
	//-------------------------------------------------------------------------------------
    
    virtual void MdApi::OnFrontConnected();
    virtual void MdApi::OnFrontDisconnected(int nReason);
    virtual void MdApi::OnHeartBeatWarning(int nTimeLapse);
    virtual void MdApi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void MdApi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void MdApi::OnRspQryMulticastInstrument(CThostFtdcMulticastInstrumentField *pMulticastInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void MdApi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void MdApi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void MdApi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void MdApi::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void MdApi::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void MdApi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);
    virtual void MdApi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp);

	//-------------------------------------------------------------------------------------
	//task������
	//-------------------------------------------------------------------------------------

	void processTask();

	
	void processFrontConnected(Task *task);
	
	void processFrontDisconnected(Task *task);
	
	void processHeartBeatWarning(Task *task);
	
	void processRspUserLogin(Task *task);
	
	void processRspUserLogout(Task *task);
	
	void processRspQryMulticastInstrument(Task *task);
	
	void processRspError(Task *task);
	
	void processRspSubMarketData(Task *task);
	
	void processRspUnSubMarketData(Task *task);
	
	void processRspSubForQuoteRsp(Task *task);
	
	void processRspUnSubForQuoteRsp(Task *task);
	
	void processRtnDepthMarketData(Task *task);
	
	void processRtnForQuoteRsp(Task *task);
	
	

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
	
	virtual void onRspUserLogin(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspUserLogout(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspQryMulticastInstrument(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspError(const dict &error, int reqid, bool last) {};
	
	virtual void onRspSubMarketData(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspUnSubMarketData(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspSubForQuoteRsp(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRspUnSubForQuoteRsp(const dict &data, const dict &error, int reqid, bool last) {};
	
	virtual void onRtnDepthMarketData(const dict &data) {};
	
	virtual void onRtnForQuoteRsp(const dict &data) {};
	
	

	//-------------------------------------------------------------------------------------
	//req:���������������ֵ�
	//-------------------------------------------------------------------------------------

	void createFtdcMdApi(string pszFlowPath = "");

	void release();

	void init();

	int join();

	int exit();

	string getTradingDay();

	string getApiVersion();

	void registerFront(string pszFrontAddress);

	void registerNameServer(string pszNsAddress);

	void registerFensUserInfo(const dict &req);

	int subscribeMarketData(string instrumentID);

	int unSubscribeMarketData(string instrumentID);

	int subscribeForQuoteRsp(string instrumentID);

	int unSubscribeForQuoteRsp(string instrumentID);

	
	int reqUserLogin(const dict &req, int reqid);
	
	int reqUserLogout(const dict &req, int reqid);
	
	int reqQryMulticastInstrument(const dict &req, int reqid);
	
	

};

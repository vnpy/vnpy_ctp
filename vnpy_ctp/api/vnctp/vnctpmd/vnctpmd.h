//系统
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnctp.h"
#include "pybind11/pybind11.h"
#include "ctp/ThostFtdcMdApi.h"

using namespace pybind11;

//常量


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
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现
class MdApi : public CThostFtdcMdSpi
{
private:
	CThostFtdcMdApi* api;				//API对象
	thread task_thread;					//工作线程指针（向python中推送数据）
	TaskQueue task_queue;			    //任务队列
	bool active = false;				//工作状态

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
	//API回调函数
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
	//task：任务
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
	//data：回调函数的数据字典
	//error：回调函数的错误字典
	//id：请求id
	//last：是否为最后返回
	//i：整数
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
	//req:主动函数的请求字典
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

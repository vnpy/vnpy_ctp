int TdApi::reqAuthenticate(const dict &req, int reqid)
{
	CThostFtdcReqAuthenticateField myreq = CThostFtdcReqAuthenticateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "UserProductInfo", myreq.UserProductInfo);
	getString(req, "AuthCode", myreq.AuthCode);
	getString(req, "AppID", myreq.AppID);
	int i = this->api->ReqAuthenticate(&myreq, reqid);
	return i;
};

int TdApi::reqUserLogin(const dict &req, int reqid)
{
	CThostFtdcReqUserLoginField myreq = CThostFtdcReqUserLoginField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TradingDay", myreq.TradingDay);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "Password", myreq.Password);
	getString(req, "UserProductInfo", myreq.UserProductInfo);
	getString(req, "InterfaceProductInfo", myreq.InterfaceProductInfo);
	getString(req, "ProtocolInfo", myreq.ProtocolInfo);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "OneTimePassword", myreq.OneTimePassword);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "LoginRemark", myreq.LoginRemark);
	getInt(req, "ClientIPPort", &myreq.ClientIPPort);
	getString(req, "ClientIPAddress", myreq.ClientIPAddress);
	int i = this->api->ReqUserLogin(&myreq, reqid);
	return i;
};

int TdApi::reqUserLogout(const dict &req, int reqid)
{
	CThostFtdcUserLogoutField myreq = CThostFtdcUserLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "UserID", myreq.UserID);
	int i = this->api->ReqUserLogout(&myreq, reqid);
	return i;
};

int TdApi::reqUserPasswordUpdate(const dict &req, int reqid)
{
	CThostFtdcUserPasswordUpdateField myreq = CThostFtdcUserPasswordUpdateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "OldPassword", myreq.OldPassword);
	getString(req, "NewPassword", myreq.NewPassword);
	int i = this->api->ReqUserPasswordUpdate(&myreq, reqid);
	return i;
};

int TdApi::reqTradingAccountPasswordUpdate(const dict &req, int reqid)
{
	CThostFtdcTradingAccountPasswordUpdateField myreq = CThostFtdcTradingAccountPasswordUpdateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "OldPassword", myreq.OldPassword);
	getString(req, "NewPassword", myreq.NewPassword);
	getString(req, "CurrencyID", myreq.CurrencyID);
	int i = this->api->ReqTradingAccountPasswordUpdate(&myreq, reqid);
	return i;
};

int TdApi::reqUserAuthMethod(const dict &req, int reqid)
{
	CThostFtdcReqUserAuthMethodField myreq = CThostFtdcReqUserAuthMethodField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TradingDay", myreq.TradingDay);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "UserID", myreq.UserID);
	int i = this->api->ReqUserAuthMethod(&myreq, reqid);
	return i;
};

int TdApi::reqGenUserCaptcha(const dict &req, int reqid)
{
	CThostFtdcReqGenUserCaptchaField myreq = CThostFtdcReqGenUserCaptchaField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TradingDay", myreq.TradingDay);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "UserID", myreq.UserID);
	int i = this->api->ReqGenUserCaptcha(&myreq, reqid);
	return i;
};

int TdApi::reqGenUserText(const dict &req, int reqid)
{
	CThostFtdcReqGenUserTextField myreq = CThostFtdcReqGenUserTextField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TradingDay", myreq.TradingDay);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "UserID", myreq.UserID);
	int i = this->api->ReqGenUserText(&myreq, reqid);
	return i;
};

int TdApi::reqUserLoginWithCaptcha(const dict &req, int reqid)
{
	CThostFtdcReqUserLoginWithCaptchaField myreq = CThostFtdcReqUserLoginWithCaptchaField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TradingDay", myreq.TradingDay);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "Password", myreq.Password);
	getString(req, "UserProductInfo", myreq.UserProductInfo);
	getString(req, "InterfaceProductInfo", myreq.InterfaceProductInfo);
	getString(req, "ProtocolInfo", myreq.ProtocolInfo);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "LoginRemark", myreq.LoginRemark);
	getString(req, "Captcha", myreq.Captcha);
	getInt(req, "ClientIPPort", &myreq.ClientIPPort);
	getString(req, "ClientIPAddress", myreq.ClientIPAddress);
	int i = this->api->ReqUserLoginWithCaptcha(&myreq, reqid);
	return i;
};

int TdApi::reqUserLoginWithText(const dict &req, int reqid)
{
	CThostFtdcReqUserLoginWithTextField myreq = CThostFtdcReqUserLoginWithTextField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TradingDay", myreq.TradingDay);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "Password", myreq.Password);
	getString(req, "UserProductInfo", myreq.UserProductInfo);
	getString(req, "InterfaceProductInfo", myreq.InterfaceProductInfo);
	getString(req, "ProtocolInfo", myreq.ProtocolInfo);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "LoginRemark", myreq.LoginRemark);
	getString(req, "Text", myreq.Text);
	getInt(req, "ClientIPPort", &myreq.ClientIPPort);
	getString(req, "ClientIPAddress", myreq.ClientIPAddress);
	int i = this->api->ReqUserLoginWithText(&myreq, reqid);
	return i;
};

int TdApi::reqUserLoginWithOTP(const dict &req, int reqid)
{
	CThostFtdcReqUserLoginWithOTPField myreq = CThostFtdcReqUserLoginWithOTPField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TradingDay", myreq.TradingDay);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "Password", myreq.Password);
	getString(req, "UserProductInfo", myreq.UserProductInfo);
	getString(req, "InterfaceProductInfo", myreq.InterfaceProductInfo);
	getString(req, "ProtocolInfo", myreq.ProtocolInfo);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "LoginRemark", myreq.LoginRemark);
	getString(req, "OTPPassword", myreq.OTPPassword);
	getInt(req, "ClientIPPort", &myreq.ClientIPPort);
	getString(req, "ClientIPAddress", myreq.ClientIPAddress);
	int i = this->api->ReqUserLoginWithOTP(&myreq, reqid);
	return i;
};

int TdApi::reqOrderInsert(const dict &req, int reqid)
{
	CThostFtdcInputOrderField myreq = CThostFtdcInputOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "OrderRef", myreq.OrderRef);
	getString(req, "UserID", myreq.UserID);
	getChar(req, "OrderPriceType", &myreq.OrderPriceType);
	getChar(req, "Direction", &myreq.Direction);
	getString(req, "CombOffsetFlag", myreq.CombOffsetFlag);
	getString(req, "CombHedgeFlag", myreq.CombHedgeFlag);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	getInt(req, "VolumeTotalOriginal", &myreq.VolumeTotalOriginal);
	getChar(req, "TimeCondition", &myreq.TimeCondition);
	getString(req, "GTDDate", myreq.GTDDate);
	getChar(req, "VolumeCondition", &myreq.VolumeCondition);
	getInt(req, "MinVolume", &myreq.MinVolume);
	getChar(req, "ContingentCondition", &myreq.ContingentCondition);
	getDouble(req, "StopPrice", &myreq.StopPrice);
	getChar(req, "ForceCloseReason", &myreq.ForceCloseReason);
	getInt(req, "IsAutoSuspend", &myreq.IsAutoSuspend);
	getString(req, "BusinessUnit", myreq.BusinessUnit);
	getInt(req, "RequestID", &myreq.RequestID);
	getInt(req, "UserForceClose", &myreq.UserForceClose);
	getInt(req, "IsSwapOrder", &myreq.IsSwapOrder);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	getString(req, "ClientID", myreq.ClientID);
	getString(req, "reserve2", myreq.reserve2);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "IPAddress", myreq.IPAddress);
	getString(req, "OrderMemo", myreq.OrderMemo);
	getInt(req, "SessionReqSeq", &myreq.SessionReqSeq);
	int i = this->api->ReqOrderInsert(&myreq, reqid);
	return i;
};

int TdApi::reqParkedOrderInsert(const dict &req, int reqid)
{
	CThostFtdcParkedOrderField myreq = CThostFtdcParkedOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "OrderRef", myreq.OrderRef);
	getString(req, "UserID", myreq.UserID);
	getChar(req, "OrderPriceType", &myreq.OrderPriceType);
	getChar(req, "Direction", &myreq.Direction);
	getString(req, "CombOffsetFlag", myreq.CombOffsetFlag);
	getString(req, "CombHedgeFlag", myreq.CombHedgeFlag);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	getInt(req, "VolumeTotalOriginal", &myreq.VolumeTotalOriginal);
	getChar(req, "TimeCondition", &myreq.TimeCondition);
	getString(req, "GTDDate", myreq.GTDDate);
	getChar(req, "VolumeCondition", &myreq.VolumeCondition);
	getInt(req, "MinVolume", &myreq.MinVolume);
	getChar(req, "ContingentCondition", &myreq.ContingentCondition);
	getDouble(req, "StopPrice", &myreq.StopPrice);
	getChar(req, "ForceCloseReason", &myreq.ForceCloseReason);
	getInt(req, "IsAutoSuspend", &myreq.IsAutoSuspend);
	getString(req, "BusinessUnit", myreq.BusinessUnit);
	getInt(req, "RequestID", &myreq.RequestID);
	getInt(req, "UserForceClose", &myreq.UserForceClose);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ParkedOrderID", myreq.ParkedOrderID);
	getChar(req, "UserType", &myreq.UserType);
	getChar(req, "Status", &myreq.Status);
	getInt(req, "ErrorID", &myreq.ErrorID);
	getString(req, "ErrorMsg", myreq.ErrorMsg);
	getInt(req, "IsSwapOrder", &myreq.IsSwapOrder);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	getString(req, "ClientID", myreq.ClientID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "reserve2", myreq.reserve2);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "IPAddress", myreq.IPAddress);
	int i = this->api->ReqParkedOrderInsert(&myreq, reqid);
	return i;
};

int TdApi::reqParkedOrderAction(const dict &req, int reqid)
{
	CThostFtdcParkedOrderActionField myreq = CThostFtdcParkedOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getInt(req, "OrderActionRef", &myreq.OrderActionRef);
	getString(req, "OrderRef", myreq.OrderRef);
	getInt(req, "RequestID", &myreq.RequestID);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getChar(req, "ActionFlag", &myreq.ActionFlag);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	getInt(req, "VolumeChange", &myreq.VolumeChange);
	getString(req, "UserID", myreq.UserID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ParkedOrderActionID", myreq.ParkedOrderActionID);
	getChar(req, "UserType", &myreq.UserType);
	getChar(req, "Status", &myreq.Status);
	getInt(req, "ErrorID", &myreq.ErrorID);
	getString(req, "ErrorMsg", myreq.ErrorMsg);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "reserve2", myreq.reserve2);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "IPAddress", myreq.IPAddress);
	int i = this->api->ReqParkedOrderAction(&myreq, reqid);
	return i;
};

int TdApi::reqOrderAction(const dict &req, int reqid)
{
	CThostFtdcInputOrderActionField myreq = CThostFtdcInputOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getInt(req, "OrderActionRef", &myreq.OrderActionRef);
	getString(req, "OrderRef", myreq.OrderRef);
	getInt(req, "RequestID", &myreq.RequestID);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getChar(req, "ActionFlag", &myreq.ActionFlag);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	getInt(req, "VolumeChange", &myreq.VolumeChange);
	getString(req, "UserID", myreq.UserID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "reserve2", myreq.reserve2);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "IPAddress", myreq.IPAddress);
	getString(req, "OrderMemo", myreq.OrderMemo);
	getInt(req, "SessionReqSeq", &myreq.SessionReqSeq);
	int i = this->api->ReqOrderAction(&myreq, reqid);
	return i;
};

int TdApi::reqQryMaxOrderVolume(const dict &req, int reqid)
{
	CThostFtdcQryMaxOrderVolumeField myreq = CThostFtdcQryMaxOrderVolumeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getChar(req, "Direction", &myreq.Direction);
	getChar(req, "OffsetFlag", &myreq.OffsetFlag);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getInt(req, "MaxVolume", &myreq.MaxVolume);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryMaxOrderVolume(&myreq, reqid);
	return i;
};

int TdApi::reqSettlementInfoConfirm(const dict &req, int reqid)
{
	CThostFtdcSettlementInfoConfirmField myreq = CThostFtdcSettlementInfoConfirmField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "ConfirmDate", myreq.ConfirmDate);
	getString(req, "ConfirmTime", myreq.ConfirmTime);
	getInt(req, "SettlementID", &myreq.SettlementID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	int i = this->api->ReqSettlementInfoConfirm(&myreq, reqid);
	return i;
};

int TdApi::reqRemoveParkedOrder(const dict &req, int reqid)
{
	CThostFtdcRemoveParkedOrderField myreq = CThostFtdcRemoveParkedOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "ParkedOrderID", myreq.ParkedOrderID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	int i = this->api->ReqRemoveParkedOrder(&myreq, reqid);
	return i;
};

int TdApi::reqRemoveParkedOrderAction(const dict &req, int reqid)
{
	CThostFtdcRemoveParkedOrderActionField myreq = CThostFtdcRemoveParkedOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "ParkedOrderActionID", myreq.ParkedOrderActionID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	int i = this->api->ReqRemoveParkedOrderAction(&myreq, reqid);
	return i;
};

int TdApi::reqExecOrderInsert(const dict &req, int reqid)
{
	CThostFtdcInputExecOrderField myreq = CThostFtdcInputExecOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExecOrderRef", myreq.ExecOrderRef);
	getString(req, "UserID", myreq.UserID);
	getInt(req, "Volume", &myreq.Volume);
	getInt(req, "RequestID", &myreq.RequestID);
	getString(req, "BusinessUnit", myreq.BusinessUnit);
	getChar(req, "OffsetFlag", &myreq.OffsetFlag);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getChar(req, "ActionType", &myreq.ActionType);
	getChar(req, "PosiDirection", &myreq.PosiDirection);
	getChar(req, "ReservePositionFlag", &myreq.ReservePositionFlag);
	getChar(req, "CloseFlag", &myreq.CloseFlag);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	getString(req, "ClientID", myreq.ClientID);
	getString(req, "reserve2", myreq.reserve2);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "IPAddress", myreq.IPAddress);
	int i = this->api->ReqExecOrderInsert(&myreq, reqid);
	return i;
};

int TdApi::reqExecOrderAction(const dict &req, int reqid)
{
	CThostFtdcInputExecOrderActionField myreq = CThostFtdcInputExecOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getInt(req, "ExecOrderActionRef", &myreq.ExecOrderActionRef);
	getString(req, "ExecOrderRef", myreq.ExecOrderRef);
	getInt(req, "RequestID", &myreq.RequestID);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ExecOrderSysID", myreq.ExecOrderSysID);
	getChar(req, "ActionFlag", &myreq.ActionFlag);
	getString(req, "UserID", myreq.UserID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "reserve2", myreq.reserve2);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "IPAddress", myreq.IPAddress);
	int i = this->api->ReqExecOrderAction(&myreq, reqid);
	return i;
};

int TdApi::reqForQuoteInsert(const dict &req, int reqid)
{
	CThostFtdcInputForQuoteField myreq = CThostFtdcInputForQuoteField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ForQuoteRef", myreq.ForQuoteRef);
	getString(req, "UserID", myreq.UserID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "reserve2", myreq.reserve2);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "IPAddress", myreq.IPAddress);
	int i = this->api->ReqForQuoteInsert(&myreq, reqid);
	return i;
};

int TdApi::reqQuoteInsert(const dict &req, int reqid)
{
	CThostFtdcInputQuoteField myreq = CThostFtdcInputQuoteField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "QuoteRef", myreq.QuoteRef);
	getString(req, "UserID", myreq.UserID);
	getDouble(req, "AskPrice", &myreq.AskPrice);
	getDouble(req, "BidPrice", &myreq.BidPrice);
	getInt(req, "AskVolume", &myreq.AskVolume);
	getInt(req, "BidVolume", &myreq.BidVolume);
	getInt(req, "RequestID", &myreq.RequestID);
	getString(req, "BusinessUnit", myreq.BusinessUnit);
	getChar(req, "AskOffsetFlag", &myreq.AskOffsetFlag);
	getChar(req, "BidOffsetFlag", &myreq.BidOffsetFlag);
	getChar(req, "AskHedgeFlag", &myreq.AskHedgeFlag);
	getChar(req, "BidHedgeFlag", &myreq.BidHedgeFlag);
	getString(req, "AskOrderRef", myreq.AskOrderRef);
	getString(req, "BidOrderRef", myreq.BidOrderRef);
	getString(req, "ForQuoteSysID", myreq.ForQuoteSysID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "ClientID", myreq.ClientID);
	getString(req, "reserve2", myreq.reserve2);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "IPAddress", myreq.IPAddress);
	getString(req, "ReplaceSysID", myreq.ReplaceSysID);
	getChar(req, "TimeCondition", &myreq.TimeCondition);
	getString(req, "OrderMemo", myreq.OrderMemo);
	getInt(req, "SessionReqSeq", &myreq.SessionReqSeq);
	int i = this->api->ReqQuoteInsert(&myreq, reqid);
	return i;
};

int TdApi::reqQuoteAction(const dict &req, int reqid)
{
	CThostFtdcInputQuoteActionField myreq = CThostFtdcInputQuoteActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getInt(req, "QuoteActionRef", &myreq.QuoteActionRef);
	getString(req, "QuoteRef", myreq.QuoteRef);
	getInt(req, "RequestID", &myreq.RequestID);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "QuoteSysID", myreq.QuoteSysID);
	getChar(req, "ActionFlag", &myreq.ActionFlag);
	getString(req, "UserID", myreq.UserID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "ClientID", myreq.ClientID);
	getString(req, "reserve2", myreq.reserve2);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "IPAddress", myreq.IPAddress);
	getString(req, "OrderMemo", myreq.OrderMemo);
	getInt(req, "SessionReqSeq", &myreq.SessionReqSeq);
	int i = this->api->ReqQuoteAction(&myreq, reqid);
	return i;
};

int TdApi::reqBatchOrderAction(const dict &req, int reqid)
{
	CThostFtdcInputBatchOrderActionField myreq = CThostFtdcInputBatchOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getInt(req, "OrderActionRef", &myreq.OrderActionRef);
	getInt(req, "RequestID", &myreq.RequestID);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "IPAddress", myreq.IPAddress);
	int i = this->api->ReqBatchOrderAction(&myreq, reqid);
	return i;
};

int TdApi::reqOptionSelfCloseInsert(const dict &req, int reqid)
{
	CThostFtdcInputOptionSelfCloseField myreq = CThostFtdcInputOptionSelfCloseField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "OptionSelfCloseRef", myreq.OptionSelfCloseRef);
	getString(req, "UserID", myreq.UserID);
	getInt(req, "Volume", &myreq.Volume);
	getInt(req, "RequestID", &myreq.RequestID);
	getString(req, "BusinessUnit", myreq.BusinessUnit);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getChar(req, "OptSelfCloseFlag", &myreq.OptSelfCloseFlag);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	getString(req, "ClientID", myreq.ClientID);
	getString(req, "reserve2", myreq.reserve2);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "IPAddress", myreq.IPAddress);
	int i = this->api->ReqOptionSelfCloseInsert(&myreq, reqid);
	return i;
};

int TdApi::reqOptionSelfCloseAction(const dict &req, int reqid)
{
	CThostFtdcInputOptionSelfCloseActionField myreq = CThostFtdcInputOptionSelfCloseActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getInt(req, "OptionSelfCloseActionRef", &myreq.OptionSelfCloseActionRef);
	getString(req, "OptionSelfCloseRef", myreq.OptionSelfCloseRef);
	getInt(req, "RequestID", &myreq.RequestID);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "OptionSelfCloseSysID", myreq.OptionSelfCloseSysID);
	getChar(req, "ActionFlag", &myreq.ActionFlag);
	getString(req, "UserID", myreq.UserID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "reserve2", myreq.reserve2);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "IPAddress", myreq.IPAddress);
	int i = this->api->ReqOptionSelfCloseAction(&myreq, reqid);
	return i;
};

int TdApi::reqCombActionInsert(const dict &req, int reqid)
{
	CThostFtdcInputCombActionField myreq = CThostFtdcInputCombActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "CombActionRef", myreq.CombActionRef);
	getString(req, "UserID", myreq.UserID);
	getChar(req, "Direction", &myreq.Direction);
	getInt(req, "Volume", &myreq.Volume);
	getChar(req, "CombDirection", &myreq.CombDirection);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "reserve2", myreq.reserve2);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "IPAddress", myreq.IPAddress);
	int i = this->api->ReqCombActionInsert(&myreq, reqid);
	return i;
};

int TdApi::reqQryOrder(const dict &req, int reqid)
{
	CThostFtdcQryOrderField myreq = CThostFtdcQryOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "OrderSysID", myreq.OrderSysID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryOrder(&myreq, reqid);
	return i;
};

int TdApi::reqQryTrade(const dict &req, int reqid)
{
	CThostFtdcQryTradeField myreq = CThostFtdcQryTradeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "TradeID", myreq.TradeID);
	getString(req, "TradeTimeStart", myreq.TradeTimeStart);
	getString(req, "TradeTimeEnd", myreq.TradeTimeEnd);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryTrade(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestorPosition(const dict &req, int reqid)
{
	CThostFtdcQryInvestorPositionField myreq = CThostFtdcQryInvestorPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryInvestorPosition(&myreq, reqid);
	return i;
};

int TdApi::reqQryTradingAccount(const dict &req, int reqid)
{
	CThostFtdcQryTradingAccountField myreq = CThostFtdcQryTradingAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	getChar(req, "BizType", &myreq.BizType);
	getString(req, "AccountID", myreq.AccountID);
	int i = this->api->ReqQryTradingAccount(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestor(const dict &req, int reqid)
{
	CThostFtdcQryInvestorField myreq = CThostFtdcQryInvestorField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryInvestor(&myreq, reqid);
	return i;
};

int TdApi::reqQryTradingCode(const dict &req, int reqid)
{
	CThostFtdcQryTradingCodeField myreq = CThostFtdcQryTradingCodeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ClientID", myreq.ClientID);
	getChar(req, "ClientIDType", &myreq.ClientIDType);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	int i = this->api->ReqQryTradingCode(&myreq, reqid);
	return i;
};

int TdApi::reqQryInstrumentMarginRate(const dict &req, int reqid)
{
	CThostFtdcQryInstrumentMarginRateField myreq = CThostFtdcQryInstrumentMarginRateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryInstrumentMarginRate(&myreq, reqid);
	return i;
};

int TdApi::reqQryInstrumentCommissionRate(const dict &req, int reqid)
{
	CThostFtdcQryInstrumentCommissionRateField myreq = CThostFtdcQryInstrumentCommissionRateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryInstrumentCommissionRate(&myreq, reqid);
	return i;
};

int TdApi::reqQryUserSession(const dict &req, int reqid)
{
	CThostFtdcQryUserSessionField myreq = CThostFtdcQryUserSessionField();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "FrontID", &myreq.FrontID);
	getInt(req, "SessionID", &myreq.SessionID);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "UserID", myreq.UserID);
	int i = this->api->ReqQryUserSession(&myreq, reqid);
	return i;
};

int TdApi::reqQryExchange(const dict &req, int reqid)
{
	CThostFtdcQryExchangeField myreq = CThostFtdcQryExchangeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	int i = this->api->ReqQryExchange(&myreq, reqid);
	return i;
};

int TdApi::reqQryProduct(const dict &req, int reqid)
{
	CThostFtdcQryProductField myreq = CThostFtdcQryProductField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "reserve1", myreq.reserve1);
	getChar(req, "ProductClass", &myreq.ProductClass);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ProductID", myreq.ProductID);
	int i = this->api->ReqQryProduct(&myreq, reqid);
	return i;
};

int TdApi::reqQryInstrument(const dict &req, int reqid)
{
	CThostFtdcQryInstrumentField myreq = CThostFtdcQryInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "reserve2", myreq.reserve2);
	getString(req, "reserve3", myreq.reserve3);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "ExchangeInstID", myreq.ExchangeInstID);
	getString(req, "ProductID", myreq.ProductID);
	int i = this->api->ReqQryInstrument(&myreq, reqid);
	return i;
};

int TdApi::reqQryDepthMarketData(const dict &req, int reqid)
{
	CThostFtdcQryDepthMarketDataField myreq = CThostFtdcQryDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "ProductClass", &myreq.ProductClass);
	int i = this->api->ReqQryDepthMarketData(&myreq, reqid);
	return i;
};

int TdApi::reqQryTraderOffer(const dict &req, int reqid)
{
	CThostFtdcQryTraderOfferField myreq = CThostFtdcQryTraderOfferField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ParticipantID", myreq.ParticipantID);
	getString(req, "TraderID", myreq.TraderID);
	int i = this->api->ReqQryTraderOffer(&myreq, reqid);
	return i;
};

int TdApi::reqQrySettlementInfo(const dict &req, int reqid)
{
	CThostFtdcQrySettlementInfoField myreq = CThostFtdcQrySettlementInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "TradingDay", myreq.TradingDay);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	int i = this->api->ReqQrySettlementInfo(&myreq, reqid);
	return i;
};

int TdApi::reqQryTransferBank(const dict &req, int reqid)
{
	CThostFtdcQryTransferBankField myreq = CThostFtdcQryTransferBankField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BankID", myreq.BankID);
	getString(req, "BankBrchID", myreq.BankBrchID);
	int i = this->api->ReqQryTransferBank(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestorPositionDetail(const dict &req, int reqid)
{
	CThostFtdcQryInvestorPositionDetailField myreq = CThostFtdcQryInvestorPositionDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryInvestorPositionDetail(&myreq, reqid);
	return i;
};

int TdApi::reqQryNotice(const dict &req, int reqid)
{
	CThostFtdcQryNoticeField myreq = CThostFtdcQryNoticeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	int i = this->api->ReqQryNotice(&myreq, reqid);
	return i;
};

int TdApi::reqQrySettlementInfoConfirm(const dict &req, int reqid)
{
	CThostFtdcQrySettlementInfoConfirmField myreq = CThostFtdcQrySettlementInfoConfirmField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	int i = this->api->ReqQrySettlementInfoConfirm(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestorPositionCombineDetail(const dict &req, int reqid)
{
	CThostFtdcQryInvestorPositionCombineDetailField myreq = CThostFtdcQryInvestorPositionCombineDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "CombInstrumentID", myreq.CombInstrumentID);
	int i = this->api->ReqQryInvestorPositionCombineDetail(&myreq, reqid);
	return i;
};

int TdApi::reqQryCFMMCTradingAccountKey(const dict &req, int reqid)
{
	CThostFtdcQryCFMMCTradingAccountKeyField myreq = CThostFtdcQryCFMMCTradingAccountKeyField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryCFMMCTradingAccountKey(&myreq, reqid);
	return i;
};

int TdApi::reqQryEWarrantOffset(const dict &req, int reqid)
{
	CThostFtdcQryEWarrantOffsetField myreq = CThostFtdcQryEWarrantOffsetField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryEWarrantOffset(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestorProductGroupMargin(const dict &req, int reqid)
{
	CThostFtdcQryInvestorProductGroupMarginField myreq = CThostFtdcQryInvestorProductGroupMarginField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "ProductGroupID", myreq.ProductGroupID);
	int i = this->api->ReqQryInvestorProductGroupMargin(&myreq, reqid);
	return i;
};

int TdApi::reqQryExchangeMarginRate(const dict &req, int reqid)
{
	CThostFtdcQryExchangeMarginRateField myreq = CThostFtdcQryExchangeMarginRateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "reserve1", myreq.reserve1);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryExchangeMarginRate(&myreq, reqid);
	return i;
};

int TdApi::reqQryExchangeMarginRateAdjust(const dict &req, int reqid)
{
	CThostFtdcQryExchangeMarginRateAdjustField myreq = CThostFtdcQryExchangeMarginRateAdjustField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "reserve1", myreq.reserve1);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryExchangeMarginRateAdjust(&myreq, reqid);
	return i;
};

int TdApi::reqQryExchangeRate(const dict &req, int reqid)
{
	CThostFtdcQryExchangeRateField myreq = CThostFtdcQryExchangeRateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "FromCurrencyID", myreq.FromCurrencyID);
	getString(req, "ToCurrencyID", myreq.ToCurrencyID);
	int i = this->api->ReqQryExchangeRate(&myreq, reqid);
	return i;
};

int TdApi::reqQrySecAgentACIDMap(const dict &req, int reqid)
{
	CThostFtdcQrySecAgentACIDMapField myreq = CThostFtdcQrySecAgentACIDMapField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	int i = this->api->ReqQrySecAgentACIDMap(&myreq, reqid);
	return i;
};

int TdApi::reqQryProductExchRate(const dict &req, int reqid)
{
	CThostFtdcQryProductExchRateField myreq = CThostFtdcQryProductExchRateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ProductID", myreq.ProductID);
	int i = this->api->ReqQryProductExchRate(&myreq, reqid);
	return i;
};

int TdApi::reqQryProductGroup(const dict &req, int reqid)
{
	CThostFtdcQryProductGroupField myreq = CThostFtdcQryProductGroupField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ProductID", myreq.ProductID);
	int i = this->api->ReqQryProductGroup(&myreq, reqid);
	return i;
};

int TdApi::reqQryMMInstrumentCommissionRate(const dict &req, int reqid)
{
	CThostFtdcQryMMInstrumentCommissionRateField myreq = CThostFtdcQryMMInstrumentCommissionRateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryMMInstrumentCommissionRate(&myreq, reqid);
	return i;
};

int TdApi::reqQryMMOptionInstrCommRate(const dict &req, int reqid)
{
	CThostFtdcQryMMOptionInstrCommRateField myreq = CThostFtdcQryMMOptionInstrCommRateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryMMOptionInstrCommRate(&myreq, reqid);
	return i;
};

int TdApi::reqQryInstrumentOrderCommRate(const dict &req, int reqid)
{
	CThostFtdcQryInstrumentOrderCommRateField myreq = CThostFtdcQryInstrumentOrderCommRateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryInstrumentOrderCommRate(&myreq, reqid);
	return i;
};

int TdApi::reqQrySecAgentTradingAccount(const dict &req, int reqid)
{
	CThostFtdcQryTradingAccountField myreq = CThostFtdcQryTradingAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	getChar(req, "BizType", &myreq.BizType);
	getString(req, "AccountID", myreq.AccountID);
	int i = this->api->ReqQrySecAgentTradingAccount(&myreq, reqid);
	return i;
};

int TdApi::reqQrySecAgentCheckMode(const dict &req, int reqid)
{
	CThostFtdcQrySecAgentCheckModeField myreq = CThostFtdcQrySecAgentCheckModeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQrySecAgentCheckMode(&myreq, reqid);
	return i;
};

int TdApi::reqQrySecAgentTradeInfo(const dict &req, int reqid)
{
	CThostFtdcQrySecAgentTradeInfoField myreq = CThostFtdcQrySecAgentTradeInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "BrokerSecAgentID", myreq.BrokerSecAgentID);
	int i = this->api->ReqQrySecAgentTradeInfo(&myreq, reqid);
	return i;
};

int TdApi::reqQryOptionInstrTradeCost(const dict &req, int reqid)
{
	CThostFtdcQryOptionInstrTradeCostField myreq = CThostFtdcQryOptionInstrTradeCostField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getDouble(req, "InputPrice", &myreq.InputPrice);
	getDouble(req, "UnderlyingPrice", &myreq.UnderlyingPrice);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryOptionInstrTradeCost(&myreq, reqid);
	return i;
};

int TdApi::reqQryOptionInstrCommRate(const dict &req, int reqid)
{
	CThostFtdcQryOptionInstrCommRateField myreq = CThostFtdcQryOptionInstrCommRateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryOptionInstrCommRate(&myreq, reqid);
	return i;
};

int TdApi::reqQryExecOrder(const dict &req, int reqid)
{
	CThostFtdcQryExecOrderField myreq = CThostFtdcQryExecOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ExecOrderSysID", myreq.ExecOrderSysID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryExecOrder(&myreq, reqid);
	return i;
};

int TdApi::reqQryForQuote(const dict &req, int reqid)
{
	CThostFtdcQryForQuoteField myreq = CThostFtdcQryForQuoteField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryForQuote(&myreq, reqid);
	return i;
};

int TdApi::reqQryQuote(const dict &req, int reqid)
{
	CThostFtdcQryQuoteField myreq = CThostFtdcQryQuoteField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "QuoteSysID", myreq.QuoteSysID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryQuote(&myreq, reqid);
	return i;
};

int TdApi::reqQryOptionSelfClose(const dict &req, int reqid)
{
	CThostFtdcQryOptionSelfCloseField myreq = CThostFtdcQryOptionSelfCloseField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "OptionSelfCloseSysID", myreq.OptionSelfCloseSysID);
	getString(req, "InsertTimeStart", myreq.InsertTimeStart);
	getString(req, "InsertTimeEnd", myreq.InsertTimeEnd);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryOptionSelfClose(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestUnit(const dict &req, int reqid)
{
	CThostFtdcQryInvestUnitField myreq = CThostFtdcQryInvestUnitField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	int i = this->api->ReqQryInvestUnit(&myreq, reqid);
	return i;
};

int TdApi::reqQryCombInstrumentGuard(const dict &req, int reqid)
{
	CThostFtdcQryCombInstrumentGuardField myreq = CThostFtdcQryCombInstrumentGuardField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryCombInstrumentGuard(&myreq, reqid);
	return i;
};

int TdApi::reqQryCombAction(const dict &req, int reqid)
{
	CThostFtdcQryCombActionField myreq = CThostFtdcQryCombActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryCombAction(&myreq, reqid);
	return i;
};

int TdApi::reqQryTransferSerial(const dict &req, int reqid)
{
	CThostFtdcQryTransferSerialField myreq = CThostFtdcQryTransferSerialField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "BankID", myreq.BankID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	int i = this->api->ReqQryTransferSerial(&myreq, reqid);
	return i;
};

int TdApi::reqQryAccountregister(const dict &req, int reqid)
{
	CThostFtdcQryAccountregisterField myreq = CThostFtdcQryAccountregisterField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "BankID", myreq.BankID);
	getString(req, "BankBranchID", myreq.BankBranchID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	int i = this->api->ReqQryAccountregister(&myreq, reqid);
	return i;
};

int TdApi::reqQryContractBank(const dict &req, int reqid)
{
	CThostFtdcQryContractBankField myreq = CThostFtdcQryContractBankField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "BankID", myreq.BankID);
	getString(req, "BankBrchID", myreq.BankBrchID);
	int i = this->api->ReqQryContractBank(&myreq, reqid);
	return i;
};

int TdApi::reqQryParkedOrder(const dict &req, int reqid)
{
	CThostFtdcQryParkedOrderField myreq = CThostFtdcQryParkedOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryParkedOrder(&myreq, reqid);
	return i;
};

int TdApi::reqQryParkedOrderAction(const dict &req, int reqid)
{
	CThostFtdcQryParkedOrderActionField myreq = CThostFtdcQryParkedOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryParkedOrderAction(&myreq, reqid);
	return i;
};

int TdApi::reqQryTradingNotice(const dict &req, int reqid)
{
	CThostFtdcQryTradingNoticeField myreq = CThostFtdcQryTradingNoticeField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	int i = this->api->ReqQryTradingNotice(&myreq, reqid);
	return i;
};

int TdApi::reqQryBrokerTradingParams(const dict &req, int reqid)
{
	CThostFtdcQryBrokerTradingParamsField myreq = CThostFtdcQryBrokerTradingParamsField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "CurrencyID", myreq.CurrencyID);
	getString(req, "AccountID", myreq.AccountID);
	int i = this->api->ReqQryBrokerTradingParams(&myreq, reqid);
	return i;
};

int TdApi::reqQryBrokerTradingAlgos(const dict &req, int reqid)
{
	CThostFtdcQryBrokerTradingAlgosField myreq = CThostFtdcQryBrokerTradingAlgosField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "reserve1", myreq.reserve1);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryBrokerTradingAlgos(&myreq, reqid);
	return i;
};

int TdApi::reqQueryCFMMCTradingAccountToken(const dict &req, int reqid)
{
	CThostFtdcQueryCFMMCTradingAccountTokenField myreq = CThostFtdcQueryCFMMCTradingAccountTokenField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InvestUnitID", myreq.InvestUnitID);
	int i = this->api->ReqQueryCFMMCTradingAccountToken(&myreq, reqid);
	return i;
};

int TdApi::reqFromBankToFutureByFuture(const dict &req, int reqid)
{
	CThostFtdcReqTransferField myreq = CThostFtdcReqTransferField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TradeCode", myreq.TradeCode);
	getString(req, "BankID", myreq.BankID);
	getString(req, "BankBranchID", myreq.BankBranchID);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "BrokerBranchID", myreq.BrokerBranchID);
	getString(req, "TradeDate", myreq.TradeDate);
	getString(req, "TradeTime", myreq.TradeTime);
	getString(req, "BankSerial", myreq.BankSerial);
	getString(req, "TradingDay", myreq.TradingDay);
	getInt(req, "PlateSerial", &myreq.PlateSerial);
	getChar(req, "LastFragment", &myreq.LastFragment);
	getInt(req, "SessionID", &myreq.SessionID);
	getString(req, "CustomerName", myreq.CustomerName);
	getChar(req, "IdCardType", &myreq.IdCardType);
	getString(req, "IdentifiedCardNo", myreq.IdentifiedCardNo);
	getChar(req, "CustType", &myreq.CustType);
	getString(req, "BankAccount", myreq.BankAccount);
	getString(req, "BankPassWord", myreq.BankPassWord);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "Password", myreq.Password);
	getInt(req, "InstallID", &myreq.InstallID);
	getInt(req, "FutureSerial", &myreq.FutureSerial);
	getString(req, "UserID", myreq.UserID);
	getChar(req, "VerifyCertNoFlag", &myreq.VerifyCertNoFlag);
	getString(req, "CurrencyID", myreq.CurrencyID);
	getDouble(req, "TradeAmount", &myreq.TradeAmount);
	getDouble(req, "FutureFetchAmount", &myreq.FutureFetchAmount);
	getChar(req, "FeePayFlag", &myreq.FeePayFlag);
	getDouble(req, "CustFee", &myreq.CustFee);
	getDouble(req, "BrokerFee", &myreq.BrokerFee);
	getString(req, "Message", myreq.Message);
	getString(req, "Digest", myreq.Digest);
	getChar(req, "BankAccType", &myreq.BankAccType);
	getString(req, "DeviceID", myreq.DeviceID);
	getChar(req, "BankSecuAccType", &myreq.BankSecuAccType);
	getString(req, "BrokerIDByBank", myreq.BrokerIDByBank);
	getString(req, "BankSecuAcc", myreq.BankSecuAcc);
	getChar(req, "BankPwdFlag", &myreq.BankPwdFlag);
	getChar(req, "SecuPwdFlag", &myreq.SecuPwdFlag);
	getString(req, "OperNo", myreq.OperNo);
	getInt(req, "RequestID", &myreq.RequestID);
	getInt(req, "TID", &myreq.TID);
	getChar(req, "TransferStatus", &myreq.TransferStatus);
	getString(req, "LongCustomerName", myreq.LongCustomerName);
	int i = this->api->ReqFromBankToFutureByFuture(&myreq, reqid);
	return i;
};

int TdApi::reqFromFutureToBankByFuture(const dict &req, int reqid)
{
	CThostFtdcReqTransferField myreq = CThostFtdcReqTransferField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TradeCode", myreq.TradeCode);
	getString(req, "BankID", myreq.BankID);
	getString(req, "BankBranchID", myreq.BankBranchID);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "BrokerBranchID", myreq.BrokerBranchID);
	getString(req, "TradeDate", myreq.TradeDate);
	getString(req, "TradeTime", myreq.TradeTime);
	getString(req, "BankSerial", myreq.BankSerial);
	getString(req, "TradingDay", myreq.TradingDay);
	getInt(req, "PlateSerial", &myreq.PlateSerial);
	getChar(req, "LastFragment", &myreq.LastFragment);
	getInt(req, "SessionID", &myreq.SessionID);
	getString(req, "CustomerName", myreq.CustomerName);
	getChar(req, "IdCardType", &myreq.IdCardType);
	getString(req, "IdentifiedCardNo", myreq.IdentifiedCardNo);
	getChar(req, "CustType", &myreq.CustType);
	getString(req, "BankAccount", myreq.BankAccount);
	getString(req, "BankPassWord", myreq.BankPassWord);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "Password", myreq.Password);
	getInt(req, "InstallID", &myreq.InstallID);
	getInt(req, "FutureSerial", &myreq.FutureSerial);
	getString(req, "UserID", myreq.UserID);
	getChar(req, "VerifyCertNoFlag", &myreq.VerifyCertNoFlag);
	getString(req, "CurrencyID", myreq.CurrencyID);
	getDouble(req, "TradeAmount", &myreq.TradeAmount);
	getDouble(req, "FutureFetchAmount", &myreq.FutureFetchAmount);
	getChar(req, "FeePayFlag", &myreq.FeePayFlag);
	getDouble(req, "CustFee", &myreq.CustFee);
	getDouble(req, "BrokerFee", &myreq.BrokerFee);
	getString(req, "Message", myreq.Message);
	getString(req, "Digest", myreq.Digest);
	getChar(req, "BankAccType", &myreq.BankAccType);
	getString(req, "DeviceID", myreq.DeviceID);
	getChar(req, "BankSecuAccType", &myreq.BankSecuAccType);
	getString(req, "BrokerIDByBank", myreq.BrokerIDByBank);
	getString(req, "BankSecuAcc", myreq.BankSecuAcc);
	getChar(req, "BankPwdFlag", &myreq.BankPwdFlag);
	getChar(req, "SecuPwdFlag", &myreq.SecuPwdFlag);
	getString(req, "OperNo", myreq.OperNo);
	getInt(req, "RequestID", &myreq.RequestID);
	getInt(req, "TID", &myreq.TID);
	getChar(req, "TransferStatus", &myreq.TransferStatus);
	getString(req, "LongCustomerName", myreq.LongCustomerName);
	int i = this->api->ReqFromFutureToBankByFuture(&myreq, reqid);
	return i;
};

int TdApi::reqQueryBankAccountMoneyByFuture(const dict &req, int reqid)
{
	CThostFtdcReqQueryAccountField myreq = CThostFtdcReqQueryAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TradeCode", myreq.TradeCode);
	getString(req, "BankID", myreq.BankID);
	getString(req, "BankBranchID", myreq.BankBranchID);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "BrokerBranchID", myreq.BrokerBranchID);
	getString(req, "TradeDate", myreq.TradeDate);
	getString(req, "TradeTime", myreq.TradeTime);
	getString(req, "BankSerial", myreq.BankSerial);
	getString(req, "TradingDay", myreq.TradingDay);
	getInt(req, "PlateSerial", &myreq.PlateSerial);
	getChar(req, "LastFragment", &myreq.LastFragment);
	getInt(req, "SessionID", &myreq.SessionID);
	getString(req, "CustomerName", myreq.CustomerName);
	getChar(req, "IdCardType", &myreq.IdCardType);
	getString(req, "IdentifiedCardNo", myreq.IdentifiedCardNo);
	getChar(req, "CustType", &myreq.CustType);
	getString(req, "BankAccount", myreq.BankAccount);
	getString(req, "BankPassWord", myreq.BankPassWord);
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "Password", myreq.Password);
	getInt(req, "FutureSerial", &myreq.FutureSerial);
	getInt(req, "InstallID", &myreq.InstallID);
	getString(req, "UserID", myreq.UserID);
	getChar(req, "VerifyCertNoFlag", &myreq.VerifyCertNoFlag);
	getString(req, "CurrencyID", myreq.CurrencyID);
	getString(req, "Digest", myreq.Digest);
	getChar(req, "BankAccType", &myreq.BankAccType);
	getString(req, "DeviceID", myreq.DeviceID);
	getChar(req, "BankSecuAccType", &myreq.BankSecuAccType);
	getString(req, "BrokerIDByBank", myreq.BrokerIDByBank);
	getString(req, "BankSecuAcc", myreq.BankSecuAcc);
	getChar(req, "BankPwdFlag", &myreq.BankPwdFlag);
	getChar(req, "SecuPwdFlag", &myreq.SecuPwdFlag);
	getString(req, "OperNo", myreq.OperNo);
	getInt(req, "RequestID", &myreq.RequestID);
	getInt(req, "TID", &myreq.TID);
	getString(req, "LongCustomerName", myreq.LongCustomerName);
	int i = this->api->ReqQueryBankAccountMoneyByFuture(&myreq, reqid);
	return i;
};

int TdApi::reqQryClassifiedInstrument(const dict &req, int reqid)
{
	CThostFtdcQryClassifiedInstrumentField myreq = CThostFtdcQryClassifiedInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ExchangeInstID", myreq.ExchangeInstID);
	getString(req, "ProductID", myreq.ProductID);
	getChar(req, "TradingType", &myreq.TradingType);
	getChar(req, "ClassType", &myreq.ClassType);
	int i = this->api->ReqQryClassifiedInstrument(&myreq, reqid);
	return i;
};

int TdApi::reqQryCombPromotionParam(const dict &req, int reqid)
{
	CThostFtdcQryCombPromotionParamField myreq = CThostFtdcQryCombPromotionParamField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryCombPromotionParam(&myreq, reqid);
	return i;
};

int TdApi::reqQryRiskSettleInvstPosition(const dict &req, int reqid)
{
	CThostFtdcQryRiskSettleInvstPositionField myreq = CThostFtdcQryRiskSettleInvstPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryRiskSettleInvstPosition(&myreq, reqid);
	return i;
};

int TdApi::reqQryRiskSettleProductStatus(const dict &req, int reqid)
{
	CThostFtdcQryRiskSettleProductStatusField myreq = CThostFtdcQryRiskSettleProductStatusField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ProductID", myreq.ProductID);
	int i = this->api->ReqQryRiskSettleProductStatus(&myreq, reqid);
	return i;
};

int TdApi::reqQrySPBMFutureParameter(const dict &req, int reqid)
{
	CThostFtdcQrySPBMFutureParameterField myreq = CThostFtdcQrySPBMFutureParameterField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "ProdFamilyCode", myreq.ProdFamilyCode);
	int i = this->api->ReqQrySPBMFutureParameter(&myreq, reqid);
	return i;
};

int TdApi::reqQrySPBMOptionParameter(const dict &req, int reqid)
{
	CThostFtdcQrySPBMOptionParameterField myreq = CThostFtdcQrySPBMOptionParameterField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "ProdFamilyCode", myreq.ProdFamilyCode);
	int i = this->api->ReqQrySPBMOptionParameter(&myreq, reqid);
	return i;
};

int TdApi::reqQrySPBMIntraParameter(const dict &req, int reqid)
{
	CThostFtdcQrySPBMIntraParameterField myreq = CThostFtdcQrySPBMIntraParameterField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ProdFamilyCode", myreq.ProdFamilyCode);
	int i = this->api->ReqQrySPBMIntraParameter(&myreq, reqid);
	return i;
};

int TdApi::reqQrySPBMInterParameter(const dict &req, int reqid)
{
	CThostFtdcQrySPBMInterParameterField myreq = CThostFtdcQrySPBMInterParameterField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "Leg1ProdFamilyCode", myreq.Leg1ProdFamilyCode);
	getString(req, "Leg2ProdFamilyCode", myreq.Leg2ProdFamilyCode);
	int i = this->api->ReqQrySPBMInterParameter(&myreq, reqid);
	return i;
};

int TdApi::reqQrySPBMPortfDefinition(const dict &req, int reqid)
{
	CThostFtdcQrySPBMPortfDefinitionField myreq = CThostFtdcQrySPBMPortfDefinitionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getInt(req, "PortfolioDefID", &myreq.PortfolioDefID);
	getString(req, "ProdFamilyCode", myreq.ProdFamilyCode);
	int i = this->api->ReqQrySPBMPortfDefinition(&myreq, reqid);
	return i;
};

int TdApi::reqQrySPBMInvestorPortfDef(const dict &req, int reqid)
{
	CThostFtdcQrySPBMInvestorPortfDefField myreq = CThostFtdcQrySPBMInvestorPortfDefField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQrySPBMInvestorPortfDef(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestorPortfMarginRatio(const dict &req, int reqid)
{
	CThostFtdcQryInvestorPortfMarginRatioField myreq = CThostFtdcQryInvestorPortfMarginRatioField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ProductGroupID", myreq.ProductGroupID);
	int i = this->api->ReqQryInvestorPortfMarginRatio(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestorProdSPBMDetail(const dict &req, int reqid)
{
	CThostFtdcQryInvestorProdSPBMDetailField myreq = CThostFtdcQryInvestorProdSPBMDetailField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "ProdFamilyCode", myreq.ProdFamilyCode);
	int i = this->api->ReqQryInvestorProdSPBMDetail(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestorCommoditySPMMMargin(const dict &req, int reqid)
{
	CThostFtdcQryInvestorCommoditySPMMMarginField myreq = CThostFtdcQryInvestorCommoditySPMMMarginField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "CommodityID", myreq.CommodityID);
	int i = this->api->ReqQryInvestorCommoditySPMMMargin(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestorCommodityGroupSPMMMargin(const dict &req, int reqid)
{
	CThostFtdcQryInvestorCommodityGroupSPMMMarginField myreq = CThostFtdcQryInvestorCommodityGroupSPMMMarginField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "CommodityGroupID", myreq.CommodityGroupID);
	int i = this->api->ReqQryInvestorCommodityGroupSPMMMargin(&myreq, reqid);
	return i;
};

int TdApi::reqQrySPMMInstParam(const dict &req, int reqid)
{
	CThostFtdcQrySPMMInstParamField myreq = CThostFtdcQrySPMMInstParamField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQrySPMMInstParam(&myreq, reqid);
	return i;
};

int TdApi::reqQrySPMMProductParam(const dict &req, int reqid)
{
	CThostFtdcQrySPMMProductParamField myreq = CThostFtdcQrySPMMProductParamField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ProductID", myreq.ProductID);
	int i = this->api->ReqQrySPMMProductParam(&myreq, reqid);
	return i;
};

int TdApi::reqQrySPBMAddOnInterParameter(const dict &req, int reqid)
{
	CThostFtdcQrySPBMAddOnInterParameterField myreq = CThostFtdcQrySPBMAddOnInterParameterField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "Leg1ProdFamilyCode", myreq.Leg1ProdFamilyCode);
	getString(req, "Leg2ProdFamilyCode", myreq.Leg2ProdFamilyCode);
	int i = this->api->ReqQrySPBMAddOnInterParameter(&myreq, reqid);
	return i;
};

int TdApi::reqQryRCAMSCombProductInfo(const dict &req, int reqid)
{
	CThostFtdcQryRCAMSCombProductInfoField myreq = CThostFtdcQryRCAMSCombProductInfoField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ProductID", myreq.ProductID);
	getString(req, "CombProductID", myreq.CombProductID);
	getString(req, "ProductGroupID", myreq.ProductGroupID);
	int i = this->api->ReqQryRCAMSCombProductInfo(&myreq, reqid);
	return i;
};

int TdApi::reqQryRCAMSInstrParameter(const dict &req, int reqid)
{
	CThostFtdcQryRCAMSInstrParameterField myreq = CThostFtdcQryRCAMSInstrParameterField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ProductID", myreq.ProductID);
	int i = this->api->ReqQryRCAMSInstrParameter(&myreq, reqid);
	return i;
};

int TdApi::reqQryRCAMSIntraParameter(const dict &req, int reqid)
{
	CThostFtdcQryRCAMSIntraParameterField myreq = CThostFtdcQryRCAMSIntraParameterField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "CombProductID", myreq.CombProductID);
	int i = this->api->ReqQryRCAMSIntraParameter(&myreq, reqid);
	return i;
};

int TdApi::reqQryRCAMSInterParameter(const dict &req, int reqid)
{
	CThostFtdcQryRCAMSInterParameterField myreq = CThostFtdcQryRCAMSInterParameterField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ProductGroupID", myreq.ProductGroupID);
	getString(req, "CombProduct1", myreq.CombProduct1);
	getString(req, "CombProduct2", myreq.CombProduct2);
	int i = this->api->ReqQryRCAMSInterParameter(&myreq, reqid);
	return i;
};

int TdApi::reqQryRCAMSShortOptAdjustParam(const dict &req, int reqid)
{
	CThostFtdcQryRCAMSShortOptAdjustParamField myreq = CThostFtdcQryRCAMSShortOptAdjustParamField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "CombProductID", myreq.CombProductID);
	int i = this->api->ReqQryRCAMSShortOptAdjustParam(&myreq, reqid);
	return i;
};

int TdApi::reqQryRCAMSInvestorCombPosition(const dict &req, int reqid)
{
	CThostFtdcQryRCAMSInvestorCombPositionField myreq = CThostFtdcQryRCAMSInvestorCombPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "CombInstrumentID", myreq.CombInstrumentID);
	int i = this->api->ReqQryRCAMSInvestorCombPosition(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestorProdRCAMSMargin(const dict &req, int reqid)
{
	CThostFtdcQryInvestorProdRCAMSMarginField myreq = CThostFtdcQryInvestorProdRCAMSMarginField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "CombProductID", myreq.CombProductID);
	getString(req, "ProductGroupID", myreq.ProductGroupID);
	int i = this->api->ReqQryInvestorProdRCAMSMargin(&myreq, reqid);
	return i;
};

int TdApi::reqQryRULEInstrParameter(const dict &req, int reqid)
{
	CThostFtdcQryRULEInstrParameterField myreq = CThostFtdcQryRULEInstrParameterField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryRULEInstrParameter(&myreq, reqid);
	return i;
};

int TdApi::reqQryRULEIntraParameter(const dict &req, int reqid)
{
	CThostFtdcQryRULEIntraParameterField myreq = CThostFtdcQryRULEIntraParameterField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "ProdFamilyCode", myreq.ProdFamilyCode);
	int i = this->api->ReqQryRULEIntraParameter(&myreq, reqid);
	return i;
};

int TdApi::reqQryRULEInterParameter(const dict &req, int reqid)
{
	CThostFtdcQryRULEInterParameterField myreq = CThostFtdcQryRULEInterParameterField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "Leg1ProdFamilyCode", myreq.Leg1ProdFamilyCode);
	getString(req, "Leg2ProdFamilyCode", myreq.Leg2ProdFamilyCode);
	getInt(req, "CommodityGroupID", &myreq.CommodityGroupID);
	int i = this->api->ReqQryRULEInterParameter(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestorProdRULEMargin(const dict &req, int reqid)
{
	CThostFtdcQryInvestorProdRULEMarginField myreq = CThostFtdcQryInvestorProdRULEMarginField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "ProdFamilyCode", myreq.ProdFamilyCode);
	getInt(req, "CommodityGroupID", &myreq.CommodityGroupID);
	int i = this->api->ReqQryInvestorProdRULEMargin(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestorPortfSetting(const dict &req, int reqid)
{
	CThostFtdcQryInvestorPortfSettingField myreq = CThostFtdcQryInvestorPortfSettingField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	int i = this->api->ReqQryInvestorPortfSetting(&myreq, reqid);
	return i;
};

int TdApi::reqQryInvestorInfoCommRec(const dict &req, int reqid)
{
	CThostFtdcQryInvestorInfoCommRecField myreq = CThostFtdcQryInvestorInfoCommRecField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "BrokerID", myreq.BrokerID);
	int i = this->api->ReqQryInvestorInfoCommRec(&myreq, reqid);
	return i;
};

int TdApi::reqQryCombLeg(const dict &req, int reqid)
{
	CThostFtdcQryCombLegField myreq = CThostFtdcQryCombLegField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "LegInstrumentID", myreq.LegInstrumentID);
	int i = this->api->ReqQryCombLeg(&myreq, reqid);
	return i;
};

int TdApi::reqOffsetSetting(const dict &req, int reqid)
{
	CThostFtdcInputOffsetSettingField myreq = CThostFtdcInputOffsetSettingField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "UnderlyingInstrID", myreq.UnderlyingInstrID);
	getString(req, "ProductID", myreq.ProductID);
	getChar(req, "OffsetType", &myreq.OffsetType);
	getInt(req, "Volume", &myreq.Volume);
	getInt(req, "IsOffset", &myreq.IsOffset);
	getInt(req, "RequestID", &myreq.RequestID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "IPAddress", myreq.IPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	int i = this->api->ReqOffsetSetting(&myreq, reqid);
	return i;
};

int TdApi::reqCancelOffsetSetting(const dict &req, int reqid)
{
	CThostFtdcInputOffsetSettingField myreq = CThostFtdcInputOffsetSettingField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "UnderlyingInstrID", myreq.UnderlyingInstrID);
	getString(req, "ProductID", myreq.ProductID);
	getChar(req, "OffsetType", &myreq.OffsetType);
	getInt(req, "Volume", &myreq.Volume);
	getInt(req, "IsOffset", &myreq.IsOffset);
	getInt(req, "RequestID", &myreq.RequestID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "IPAddress", myreq.IPAddress);
	getString(req, "MacAddress", myreq.MacAddress);
	int i = this->api->ReqCancelOffsetSetting(&myreq, reqid);
	return i;
};

int TdApi::reqQryOffsetSetting(const dict &req, int reqid)
{
	CThostFtdcQryOffsetSettingField myreq = CThostFtdcQryOffsetSettingField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "InvestorID", myreq.InvestorID);
	getString(req, "ProductID", myreq.ProductID);
	getChar(req, "OffsetType", &myreq.OffsetType);
	int i = this->api->ReqQryOffsetSetting(&myreq, reqid);
	return i;
};


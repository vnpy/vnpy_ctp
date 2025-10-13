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

void TdApi::processHeartBeatWarning(Task *task)
{
	gil_scoped_acquire acquire;
	this->onHeartBeatWarning(task->task_id);
};

void TdApi::processRspAuthenticate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRspAuthenticateField *task_data = (CThostFtdcRspAuthenticateField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["UserID"] = toUtf(task_data->UserID);
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["AppID"] = toUtf(task_data->AppID);
		data["AppType"] = task_data->AppType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspAuthenticate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspUserLogin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRspUserLoginField *task_data = (CThostFtdcRspUserLoginField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["LoginTime"] = toUtf(task_data->LoginTime);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["UserID"] = toUtf(task_data->UserID);
		data["SystemName"] = toUtf(task_data->SystemName);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["MaxOrderRef"] = toUtf(task_data->MaxOrderRef);
		data["SHFETime"] = toUtf(task_data->SHFETime);
		data["DCETime"] = toUtf(task_data->DCETime);
		data["CZCETime"] = toUtf(task_data->CZCETime);
		data["FFEXTime"] = toUtf(task_data->FFEXTime);
		data["INETime"] = toUtf(task_data->INETime);
		data["SysVersion"] = toUtf(task_data->SysVersion);
		data["GFEXTime"] = toUtf(task_data->GFEXTime);
		data["LoginDRIdentityID"] = task_data->LoginDRIdentityID;
		data["UserDRIdentityID"] = task_data->UserDRIdentityID;
		data["LastLoginTime"] = toUtf(task_data->LastLoginTime);
		data["ReserveInfo"] = toUtf(task_data->ReserveInfo);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserLogin(data, error, task->task_id, task->task_last);
};

void TdApi::processRspUserLogout(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcUserLogoutField *task_data = (CThostFtdcUserLogoutField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["UserID"] = toUtf(task_data->UserID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserLogout(data, error, task->task_id, task->task_last);
};

void TdApi::processRspUserPasswordUpdate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcUserPasswordUpdateField *task_data = (CThostFtdcUserPasswordUpdateField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["UserID"] = toUtf(task_data->UserID);
		data["OldPassword"] = toUtf(task_data->OldPassword);
		data["NewPassword"] = toUtf(task_data->NewPassword);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserPasswordUpdate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspTradingAccountPasswordUpdate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcTradingAccountPasswordUpdateField *task_data = (CThostFtdcTradingAccountPasswordUpdateField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["OldPassword"] = toUtf(task_data->OldPassword);
		data["NewPassword"] = toUtf(task_data->NewPassword);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspTradingAccountPasswordUpdate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspUserAuthMethod(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRspUserAuthMethodField *task_data = (CThostFtdcRspUserAuthMethodField*)task->task_data;
		data["UsableAuthMethod"] = task_data->UsableAuthMethod;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserAuthMethod(data, error, task->task_id, task->task_last);
};

void TdApi::processRspGenUserCaptcha(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRspGenUserCaptchaField *task_data = (CThostFtdcRspGenUserCaptchaField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["UserID"] = toUtf(task_data->UserID);
		data["CaptchaInfoLen"] = task_data->CaptchaInfoLen;
		data["CaptchaInfo"] = toUtf(task_data->CaptchaInfo);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspGenUserCaptcha(data, error, task->task_id, task->task_last);
};

void TdApi::processRspGenUserText(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRspGenUserTextField *task_data = (CThostFtdcRspGenUserTextField*)task->task_data;
		data["UserTextSeq"] = task_data->UserTextSeq;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspGenUserText(data, error, task->task_id, task->task_last);
};

void TdApi::processRspOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputOrderField *task_data = (CThostFtdcInputOrderField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["Direction"] = task_data->Direction;
		data["CombOffsetFlag"] = toUtf(task_data->CombOffsetFlag);
		data["CombHedgeFlag"] = toUtf(task_data->CombHedgeFlag);
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["TimeCondition"] = task_data->TimeCondition;
		data["GTDDate"] = toUtf(task_data->GTDDate);
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["MinVolume"] = task_data->MinVolume;
		data["ContingentCondition"] = task_data->ContingentCondition;
		data["StopPrice"] = task_data->StopPrice;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["IsAutoSuspend"] = task_data->IsAutoSuspend;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["RequestID"] = task_data->RequestID;
		data["UserForceClose"] = task_data->UserForceClose;
		data["IsSwapOrder"] = task_data->IsSwapOrder;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["OrderMemo"] = toUtf(task_data->OrderMemo);
		data["SessionReqSeq"] = task_data->SessionReqSeq;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOrderInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRspParkedOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcParkedOrderField *task_data = (CThostFtdcParkedOrderField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["Direction"] = task_data->Direction;
		data["CombOffsetFlag"] = toUtf(task_data->CombOffsetFlag);
		data["CombHedgeFlag"] = toUtf(task_data->CombHedgeFlag);
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["TimeCondition"] = task_data->TimeCondition;
		data["GTDDate"] = toUtf(task_data->GTDDate);
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["MinVolume"] = task_data->MinVolume;
		data["ContingentCondition"] = task_data->ContingentCondition;
		data["StopPrice"] = task_data->StopPrice;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["IsAutoSuspend"] = task_data->IsAutoSuspend;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["RequestID"] = task_data->RequestID;
		data["UserForceClose"] = task_data->UserForceClose;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ParkedOrderID"] = toUtf(task_data->ParkedOrderID);
		data["UserType"] = task_data->UserType;
		data["Status"] = task_data->Status;
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["IsSwapOrder"] = task_data->IsSwapOrder;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspParkedOrderInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRspParkedOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcParkedOrderActionField *task_data = (CThostFtdcParkedOrderActionField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["OrderActionRef"] = task_data->OrderActionRef;
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["RequestID"] = task_data->RequestID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["ActionFlag"] = task_data->ActionFlag;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeChange"] = task_data->VolumeChange;
		data["UserID"] = toUtf(task_data->UserID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["ParkedOrderActionID"] = toUtf(task_data->ParkedOrderActionID);
		data["UserType"] = task_data->UserType;
		data["Status"] = task_data->Status;
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspParkedOrderAction(data, error, task->task_id, task->task_last);
};

void TdApi::processRspOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputOrderActionField *task_data = (CThostFtdcInputOrderActionField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["OrderActionRef"] = task_data->OrderActionRef;
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["RequestID"] = task_data->RequestID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["ActionFlag"] = task_data->ActionFlag;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeChange"] = task_data->VolumeChange;
		data["UserID"] = toUtf(task_data->UserID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["OrderMemo"] = toUtf(task_data->OrderMemo);
		data["SessionReqSeq"] = task_data->SessionReqSeq;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOrderAction(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryMaxOrderVolume(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcQryMaxOrderVolumeField *task_data = (CThostFtdcQryMaxOrderVolumeField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["Direction"] = task_data->Direction;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["MaxVolume"] = task_data->MaxVolume;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryMaxOrderVolume(data, error, task->task_id, task->task_last);
};

void TdApi::processRspSettlementInfoConfirm(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSettlementInfoConfirmField *task_data = (CThostFtdcSettlementInfoConfirmField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ConfirmDate"] = toUtf(task_data->ConfirmDate);
		data["ConfirmTime"] = toUtf(task_data->ConfirmTime);
		data["SettlementID"] = task_data->SettlementID;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSettlementInfoConfirm(data, error, task->task_id, task->task_last);
};

void TdApi::processRspRemoveParkedOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRemoveParkedOrderField *task_data = (CThostFtdcRemoveParkedOrderField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ParkedOrderID"] = toUtf(task_data->ParkedOrderID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspRemoveParkedOrder(data, error, task->task_id, task->task_last);
};

void TdApi::processRspRemoveParkedOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRemoveParkedOrderActionField *task_data = (CThostFtdcRemoveParkedOrderActionField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ParkedOrderActionID"] = toUtf(task_data->ParkedOrderActionID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspRemoveParkedOrderAction(data, error, task->task_id, task->task_last);
};

void TdApi::processRspExecOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputExecOrderField *task_data = (CThostFtdcInputExecOrderField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["ExecOrderRef"] = toUtf(task_data->ExecOrderRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["Volume"] = task_data->Volume;
		data["RequestID"] = task_data->RequestID;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["ActionType"] = task_data->ActionType;
		data["PosiDirection"] = task_data->PosiDirection;
		data["ReservePositionFlag"] = task_data->ReservePositionFlag;
		data["CloseFlag"] = task_data->CloseFlag;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspExecOrderInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRspExecOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputExecOrderActionField *task_data = (CThostFtdcInputExecOrderActionField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExecOrderActionRef"] = task_data->ExecOrderActionRef;
		data["ExecOrderRef"] = toUtf(task_data->ExecOrderRef);
		data["RequestID"] = task_data->RequestID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ExecOrderSysID"] = toUtf(task_data->ExecOrderSysID);
		data["ActionFlag"] = task_data->ActionFlag;
		data["UserID"] = toUtf(task_data->UserID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspExecOrderAction(data, error, task->task_id, task->task_last);
};

void TdApi::processRspForQuoteInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputForQuoteField *task_data = (CThostFtdcInputForQuoteField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["ForQuoteRef"] = toUtf(task_data->ForQuoteRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspForQuoteInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQuoteInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputQuoteField *task_data = (CThostFtdcInputQuoteField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["QuoteRef"] = toUtf(task_data->QuoteRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["AskPrice"] = task_data->AskPrice;
		data["BidPrice"] = task_data->BidPrice;
		data["AskVolume"] = task_data->AskVolume;
		data["BidVolume"] = task_data->BidVolume;
		data["RequestID"] = task_data->RequestID;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["AskOffsetFlag"] = task_data->AskOffsetFlag;
		data["BidOffsetFlag"] = task_data->BidOffsetFlag;
		data["AskHedgeFlag"] = task_data->AskHedgeFlag;
		data["BidHedgeFlag"] = task_data->BidHedgeFlag;
		data["AskOrderRef"] = toUtf(task_data->AskOrderRef);
		data["BidOrderRef"] = toUtf(task_data->BidOrderRef);
		data["ForQuoteSysID"] = toUtf(task_data->ForQuoteSysID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["ReplaceSysID"] = toUtf(task_data->ReplaceSysID);
		data["TimeCondition"] = task_data->TimeCondition;
		data["OrderMemo"] = toUtf(task_data->OrderMemo);
		data["SessionReqSeq"] = task_data->SessionReqSeq;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQuoteInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQuoteAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputQuoteActionField *task_data = (CThostFtdcInputQuoteActionField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["QuoteActionRef"] = task_data->QuoteActionRef;
		data["QuoteRef"] = toUtf(task_data->QuoteRef);
		data["RequestID"] = task_data->RequestID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["QuoteSysID"] = toUtf(task_data->QuoteSysID);
		data["ActionFlag"] = task_data->ActionFlag;
		data["UserID"] = toUtf(task_data->UserID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["OrderMemo"] = toUtf(task_data->OrderMemo);
		data["SessionReqSeq"] = task_data->SessionReqSeq;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQuoteAction(data, error, task->task_id, task->task_last);
};

void TdApi::processRspBatchOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputBatchOrderActionField *task_data = (CThostFtdcInputBatchOrderActionField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["OrderActionRef"] = task_data->OrderActionRef;
		data["RequestID"] = task_data->RequestID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["UserID"] = toUtf(task_data->UserID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspBatchOrderAction(data, error, task->task_id, task->task_last);
};

void TdApi::processRspOptionSelfCloseInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputOptionSelfCloseField *task_data = (CThostFtdcInputOptionSelfCloseField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["OptionSelfCloseRef"] = toUtf(task_data->OptionSelfCloseRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["Volume"] = task_data->Volume;
		data["RequestID"] = task_data->RequestID;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["OptSelfCloseFlag"] = task_data->OptSelfCloseFlag;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOptionSelfCloseInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRspOptionSelfCloseAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputOptionSelfCloseActionField *task_data = (CThostFtdcInputOptionSelfCloseActionField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["OptionSelfCloseActionRef"] = task_data->OptionSelfCloseActionRef;
		data["OptionSelfCloseRef"] = toUtf(task_data->OptionSelfCloseRef);
		data["RequestID"] = task_data->RequestID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["OptionSelfCloseSysID"] = toUtf(task_data->OptionSelfCloseSysID);
		data["ActionFlag"] = task_data->ActionFlag;
		data["UserID"] = toUtf(task_data->UserID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOptionSelfCloseAction(data, error, task->task_id, task->task_last);
};

void TdApi::processRspCombActionInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputCombActionField *task_data = (CThostFtdcInputCombActionField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["CombActionRef"] = toUtf(task_data->CombActionRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["Direction"] = task_data->Direction;
		data["Volume"] = task_data->Volume;
		data["CombDirection"] = task_data->CombDirection;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspCombActionInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcOrderField *task_data = (CThostFtdcOrderField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["Direction"] = task_data->Direction;
		data["CombOffsetFlag"] = toUtf(task_data->CombOffsetFlag);
		data["CombHedgeFlag"] = toUtf(task_data->CombHedgeFlag);
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["TimeCondition"] = task_data->TimeCondition;
		data["GTDDate"] = toUtf(task_data->GTDDate);
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["MinVolume"] = task_data->MinVolume;
		data["ContingentCondition"] = task_data->ContingentCondition;
		data["StopPrice"] = task_data->StopPrice;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["IsAutoSuspend"] = task_data->IsAutoSuspend;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["RequestID"] = task_data->RequestID;
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["OrderSubmitStatus"] = task_data->OrderSubmitStatus;
		data["NotifySequence"] = task_data->NotifySequence;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["OrderSource"] = task_data->OrderSource;
		data["OrderStatus"] = task_data->OrderStatus;
		data["OrderType"] = task_data->OrderType;
		data["VolumeTraded"] = task_data->VolumeTraded;
		data["VolumeTotal"] = task_data->VolumeTotal;
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["ActiveTime"] = toUtf(task_data->ActiveTime);
		data["SuspendTime"] = toUtf(task_data->SuspendTime);
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["ActiveTraderID"] = toUtf(task_data->ActiveTraderID);
		data["ClearingPartID"] = toUtf(task_data->ClearingPartID);
		data["SequenceNo"] = task_data->SequenceNo;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["UserForceClose"] = task_data->UserForceClose;
		data["ActiveUserID"] = toUtf(task_data->ActiveUserID);
		data["BrokerOrderSeq"] = task_data->BrokerOrderSeq;
		data["RelativeOrderSysID"] = toUtf(task_data->RelativeOrderSysID);
		data["ZCETotalTradedVolume"] = task_data->ZCETotalTradedVolume;
		data["IsSwapOrder"] = task_data->IsSwapOrder;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["reserve3"] = toUtf(task_data->reserve3);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["OrderMemo"] = toUtf(task_data->OrderMemo);
		data["SessionReqSeq"] = task_data->SessionReqSeq;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOrder(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcTradeField *task_data = (CThostFtdcTradeField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["TradeID"] = toUtf(task_data->TradeID);
		data["Direction"] = task_data->Direction;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["TradingRole"] = task_data->TradingRole;
		data["reserve2"] = toUtf(task_data->reserve2);
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["Price"] = task_data->Price;
		data["Volume"] = task_data->Volume;
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["TradeType"] = task_data->TradeType;
		data["PriceSource"] = task_data->PriceSource;
		data["TraderID"] = toUtf(task_data->TraderID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["ClearingPartID"] = toUtf(task_data->ClearingPartID);
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["SequenceNo"] = task_data->SequenceNo;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["BrokerOrderSeq"] = task_data->BrokerOrderSeq;
		data["TradeSource"] = task_data->TradeSource;
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTrade(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInvestorPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInvestorPositionField *task_data = (CThostFtdcInvestorPositionField*)task->task_data;
		data["reserve1"] = toUtf(task_data->reserve1);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["PosiDirection"] = task_data->PosiDirection;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["PositionDate"] = task_data->PositionDate;
		data["YdPosition"] = task_data->YdPosition;
		data["Position"] = task_data->Position;
		data["LongFrozen"] = task_data->LongFrozen;
		data["ShortFrozen"] = task_data->ShortFrozen;
		data["LongFrozenAmount"] = task_data->LongFrozenAmount;
		data["ShortFrozenAmount"] = task_data->ShortFrozenAmount;
		data["OpenVolume"] = task_data->OpenVolume;
		data["CloseVolume"] = task_data->CloseVolume;
		data["OpenAmount"] = task_data->OpenAmount;
		data["CloseAmount"] = task_data->CloseAmount;
		data["PositionCost"] = task_data->PositionCost;
		data["PreMargin"] = task_data->PreMargin;
		data["UseMargin"] = task_data->UseMargin;
		data["FrozenMargin"] = task_data->FrozenMargin;
		data["FrozenCash"] = task_data->FrozenCash;
		data["FrozenCommission"] = task_data->FrozenCommission;
		data["CashIn"] = task_data->CashIn;
		data["Commission"] = task_data->Commission;
		data["CloseProfit"] = task_data->CloseProfit;
		data["PositionProfit"] = task_data->PositionProfit;
		data["PreSettlementPrice"] = task_data->PreSettlementPrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["OpenCost"] = task_data->OpenCost;
		data["ExchangeMargin"] = task_data->ExchangeMargin;
		data["CombPosition"] = task_data->CombPosition;
		data["CombLongFrozen"] = task_data->CombLongFrozen;
		data["CombShortFrozen"] = task_data->CombShortFrozen;
		data["CloseProfitByDate"] = task_data->CloseProfitByDate;
		data["CloseProfitByTrade"] = task_data->CloseProfitByTrade;
		data["TodayPosition"] = task_data->TodayPosition;
		data["MarginRateByMoney"] = task_data->MarginRateByMoney;
		data["MarginRateByVolume"] = task_data->MarginRateByVolume;
		data["StrikeFrozen"] = task_data->StrikeFrozen;
		data["StrikeFrozenAmount"] = task_data->StrikeFrozenAmount;
		data["AbandonFrozen"] = task_data->AbandonFrozen;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["YdStrikeFrozen"] = task_data->YdStrikeFrozen;
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["PositionCostOffset"] = task_data->PositionCostOffset;
		data["TasPosition"] = task_data->TasPosition;
		data["TasPositionCost"] = task_data->TasPositionCost;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["OptionValue"] = task_data->OptionValue;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorPosition(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryTradingAccount(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcTradingAccountField *task_data = (CThostFtdcTradingAccountField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["PreMortgage"] = task_data->PreMortgage;
		data["PreCredit"] = task_data->PreCredit;
		data["PreDeposit"] = task_data->PreDeposit;
		data["PreBalance"] = task_data->PreBalance;
		data["PreMargin"] = task_data->PreMargin;
		data["InterestBase"] = task_data->InterestBase;
		data["Interest"] = task_data->Interest;
		data["Deposit"] = task_data->Deposit;
		data["Withdraw"] = task_data->Withdraw;
		data["FrozenMargin"] = task_data->FrozenMargin;
		data["FrozenCash"] = task_data->FrozenCash;
		data["FrozenCommission"] = task_data->FrozenCommission;
		data["CurrMargin"] = task_data->CurrMargin;
		data["CashIn"] = task_data->CashIn;
		data["Commission"] = task_data->Commission;
		data["CloseProfit"] = task_data->CloseProfit;
		data["PositionProfit"] = task_data->PositionProfit;
		data["Balance"] = task_data->Balance;
		data["Available"] = task_data->Available;
		data["WithdrawQuota"] = task_data->WithdrawQuota;
		data["Reserve"] = task_data->Reserve;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["Credit"] = task_data->Credit;
		data["Mortgage"] = task_data->Mortgage;
		data["ExchangeMargin"] = task_data->ExchangeMargin;
		data["DeliveryMargin"] = task_data->DeliveryMargin;
		data["ExchangeDeliveryMargin"] = task_data->ExchangeDeliveryMargin;
		data["ReserveBalance"] = task_data->ReserveBalance;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["PreFundMortgageIn"] = task_data->PreFundMortgageIn;
		data["PreFundMortgageOut"] = task_data->PreFundMortgageOut;
		data["FundMortgageIn"] = task_data->FundMortgageIn;
		data["FundMortgageOut"] = task_data->FundMortgageOut;
		data["FundMortgageAvailable"] = task_data->FundMortgageAvailable;
		data["MortgageableFund"] = task_data->MortgageableFund;
		data["SpecProductMargin"] = task_data->SpecProductMargin;
		data["SpecProductFrozenMargin"] = task_data->SpecProductFrozenMargin;
		data["SpecProductCommission"] = task_data->SpecProductCommission;
		data["SpecProductFrozenCommission"] = task_data->SpecProductFrozenCommission;
		data["SpecProductPositionProfit"] = task_data->SpecProductPositionProfit;
		data["SpecProductCloseProfit"] = task_data->SpecProductCloseProfit;
		data["SpecProductPositionProfitByAlg"] = task_data->SpecProductPositionProfitByAlg;
		data["SpecProductExchangeMargin"] = task_data->SpecProductExchangeMargin;
		data["BizType"] = task_data->BizType;
		data["FrozenSwap"] = task_data->FrozenSwap;
		data["RemainSwap"] = task_data->RemainSwap;
		data["OptionValue"] = task_data->OptionValue;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTradingAccount(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInvestor(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInvestorField *task_data = (CThostFtdcInvestorField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorGroupID"] = toUtf(task_data->InvestorGroupID);
		data["InvestorName"] = toUtf(task_data->InvestorName);
		data["IdentifiedCardType"] = task_data->IdentifiedCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["IsActive"] = task_data->IsActive;
		data["Telephone"] = toUtf(task_data->Telephone);
		data["Address"] = toUtf(task_data->Address);
		data["OpenDate"] = toUtf(task_data->OpenDate);
		data["Mobile"] = toUtf(task_data->Mobile);
		data["CommModelID"] = toUtf(task_data->CommModelID);
		data["MarginModelID"] = toUtf(task_data->MarginModelID);
		data["IsOrderFreq"] = task_data->IsOrderFreq;
		data["IsOpenVolLimit"] = task_data->IsOpenVolLimit;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestor(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryTradingCode(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcTradingCodeField *task_data = (CThostFtdcTradingCodeField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["IsActive"] = task_data->IsActive;
		data["ClientIDType"] = task_data->ClientIDType;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["BizType"] = task_data->BizType;
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTradingCode(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInstrumentMarginRate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInstrumentMarginRateField *task_data = (CThostFtdcInstrumentMarginRateField*)task->task_data;
		data["reserve1"] = toUtf(task_data->reserve1);
		data["InvestorRange"] = task_data->InvestorRange;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["LongMarginRatioByMoney"] = task_data->LongMarginRatioByMoney;
		data["LongMarginRatioByVolume"] = task_data->LongMarginRatioByVolume;
		data["ShortMarginRatioByMoney"] = task_data->ShortMarginRatioByMoney;
		data["ShortMarginRatioByVolume"] = task_data->ShortMarginRatioByVolume;
		data["IsRelative"] = task_data->IsRelative;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInstrumentMarginRate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInstrumentCommissionRate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInstrumentCommissionRateField *task_data = (CThostFtdcInstrumentCommissionRateField*)task->task_data;
		data["reserve1"] = toUtf(task_data->reserve1);
		data["InvestorRange"] = task_data->InvestorRange;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["OpenRatioByMoney"] = task_data->OpenRatioByMoney;
		data["OpenRatioByVolume"] = task_data->OpenRatioByVolume;
		data["CloseRatioByMoney"] = task_data->CloseRatioByMoney;
		data["CloseRatioByVolume"] = task_data->CloseRatioByVolume;
		data["CloseTodayRatioByMoney"] = task_data->CloseTodayRatioByMoney;
		data["CloseTodayRatioByVolume"] = task_data->CloseTodayRatioByVolume;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["BizType"] = task_data->BizType;
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInstrumentCommissionRate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryUserSession(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcUserSessionField *task_data = (CThostFtdcUserSessionField*)task->task_data;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["UserID"] = toUtf(task_data->UserID);
		data["LoginDate"] = toUtf(task_data->LoginDate);
		data["LoginTime"] = toUtf(task_data->LoginTime);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["InterfaceProductInfo"] = toUtf(task_data->InterfaceProductInfo);
		data["ProtocolInfo"] = toUtf(task_data->ProtocolInfo);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["LoginRemark"] = toUtf(task_data->LoginRemark);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryUserSession(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryExchange(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcExchangeField *task_data = (CThostFtdcExchangeField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ExchangeName"] = toUtf(task_data->ExchangeName);
		data["ExchangeProperty"] = task_data->ExchangeProperty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExchange(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryProduct(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcProductField *task_data = (CThostFtdcProductField*)task->task_data;
		data["reserve1"] = toUtf(task_data->reserve1);
		data["ProductName"] = toUtf(task_data->ProductName);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ProductClass"] = task_data->ProductClass;
		data["VolumeMultiple"] = task_data->VolumeMultiple;
		data["PriceTick"] = task_data->PriceTick;
		data["MaxMarketOrderVolume"] = task_data->MaxMarketOrderVolume;
		data["MinMarketOrderVolume"] = task_data->MinMarketOrderVolume;
		data["MaxLimitOrderVolume"] = task_data->MaxLimitOrderVolume;
		data["MinLimitOrderVolume"] = task_data->MinLimitOrderVolume;
		data["PositionType"] = task_data->PositionType;
		data["PositionDateType"] = task_data->PositionDateType;
		data["CloseDealType"] = task_data->CloseDealType;
		data["TradeCurrencyID"] = toUtf(task_data->TradeCurrencyID);
		data["MortgageFundUseRange"] = task_data->MortgageFundUseRange;
		data["reserve2"] = toUtf(task_data->reserve2);
		data["UnderlyingMultiple"] = task_data->UnderlyingMultiple;
		data["ProductID"] = toUtf(task_data->ProductID);
		data["ExchangeProductID"] = toUtf(task_data->ExchangeProductID);
		data["OpenLimitControlLevel"] = task_data->OpenLimitControlLevel;
		data["OrderFreqControlLevel"] = task_data->OrderFreqControlLevel;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryProduct(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInstrument(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInstrumentField *task_data = (CThostFtdcInstrumentField*)task->task_data;
		data["reserve1"] = toUtf(task_data->reserve1);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentName"] = toUtf(task_data->InstrumentName);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["reserve3"] = toUtf(task_data->reserve3);
		data["ProductClass"] = task_data->ProductClass;
		data["DeliveryYear"] = task_data->DeliveryYear;
		data["DeliveryMonth"] = task_data->DeliveryMonth;
		data["MaxMarketOrderVolume"] = task_data->MaxMarketOrderVolume;
		data["MinMarketOrderVolume"] = task_data->MinMarketOrderVolume;
		data["MaxLimitOrderVolume"] = task_data->MaxLimitOrderVolume;
		data["MinLimitOrderVolume"] = task_data->MinLimitOrderVolume;
		data["VolumeMultiple"] = task_data->VolumeMultiple;
		data["PriceTick"] = task_data->PriceTick;
		data["CreateDate"] = toUtf(task_data->CreateDate);
		data["OpenDate"] = toUtf(task_data->OpenDate);
		data["ExpireDate"] = toUtf(task_data->ExpireDate);
		data["StartDelivDate"] = toUtf(task_data->StartDelivDate);
		data["EndDelivDate"] = toUtf(task_data->EndDelivDate);
		data["InstLifePhase"] = task_data->InstLifePhase;
		data["IsTrading"] = task_data->IsTrading;
		data["PositionType"] = task_data->PositionType;
		data["PositionDateType"] = task_data->PositionDateType;
		data["LongMarginRatio"] = task_data->LongMarginRatio;
		data["ShortMarginRatio"] = task_data->ShortMarginRatio;
		data["MaxMarginSideAlgorithm"] = task_data->MaxMarginSideAlgorithm;
		data["reserve4"] = toUtf(task_data->reserve4);
		data["StrikePrice"] = task_data->StrikePrice;
		data["OptionsType"] = task_data->OptionsType;
		data["UnderlyingMultiple"] = task_data->UnderlyingMultiple;
		data["CombinationType"] = task_data->CombinationType;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["ProductID"] = toUtf(task_data->ProductID);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInstrument(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryDepthMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcDepthMarketDataField *task_data = (CThostFtdcDepthMarketDataField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["LastPrice"] = task_data->LastPrice;
		data["PreSettlementPrice"] = task_data->PreSettlementPrice;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["PreOpenInterest"] = task_data->PreOpenInterest;
		data["OpenPrice"] = task_data->OpenPrice;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["Volume"] = task_data->Volume;
		data["Turnover"] = task_data->Turnover;
		data["OpenInterest"] = task_data->OpenInterest;
		data["ClosePrice"] = task_data->ClosePrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["PreDelta"] = task_data->PreDelta;
		data["CurrDelta"] = task_data->CurrDelta;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		data["BidPrice1"] = task_data->BidPrice1;
		data["BidVolume1"] = task_data->BidVolume1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["AskVolume1"] = task_data->AskVolume1;
		data["BidPrice2"] = task_data->BidPrice2;
		data["BidVolume2"] = task_data->BidVolume2;
		data["AskPrice2"] = task_data->AskPrice2;
		data["AskVolume2"] = task_data->AskVolume2;
		data["BidPrice3"] = task_data->BidPrice3;
		data["BidVolume3"] = task_data->BidVolume3;
		data["AskPrice3"] = task_data->AskPrice3;
		data["AskVolume3"] = task_data->AskVolume3;
		data["BidPrice4"] = task_data->BidPrice4;
		data["BidVolume4"] = task_data->BidVolume4;
		data["AskPrice4"] = task_data->AskPrice4;
		data["AskVolume4"] = task_data->AskVolume4;
		data["BidPrice5"] = task_data->BidPrice5;
		data["BidVolume5"] = task_data->BidVolume5;
		data["AskPrice5"] = task_data->AskPrice5;
		data["AskVolume5"] = task_data->AskVolume5;
		data["AveragePrice"] = task_data->AveragePrice;
		data["ActionDay"] = toUtf(task_data->ActionDay);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["BandingUpperPrice"] = task_data->BandingUpperPrice;
		data["BandingLowerPrice"] = task_data->BandingLowerPrice;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryDepthMarketData(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryTraderOffer(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcTraderOfferField *task_data = (CThostFtdcTraderOfferField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["TraderConnectStatus"] = task_data->TraderConnectStatus;
		data["ConnectRequestDate"] = toUtf(task_data->ConnectRequestDate);
		data["ConnectRequestTime"] = toUtf(task_data->ConnectRequestTime);
		data["LastReportDate"] = toUtf(task_data->LastReportDate);
		data["LastReportTime"] = toUtf(task_data->LastReportTime);
		data["ConnectDate"] = toUtf(task_data->ConnectDate);
		data["ConnectTime"] = toUtf(task_data->ConnectTime);
		data["StartDate"] = toUtf(task_data->StartDate);
		data["StartTime"] = toUtf(task_data->StartTime);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["MaxTradeID"] = toUtf(task_data->MaxTradeID);
		data["MaxOrderMessageReference"] = toUtf(task_data->MaxOrderMessageReference);
		data["OrderCancelAlg"] = task_data->OrderCancelAlg;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTraderOffer(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQrySettlementInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSettlementInfoField *task_data = (CThostFtdcSettlementInfoField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["SequenceNo"] = task_data->SequenceNo;
		data["Content"] = toUtf(task_data->Content);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySettlementInfo(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryTransferBank(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcTransferBankField *task_data = (CThostFtdcTransferBankField*)task->task_data;
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBrchID"] = toUtf(task_data->BankBrchID);
		data["BankName"] = toUtf(task_data->BankName);
		data["IsActive"] = task_data->IsActive;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTransferBank(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInvestorPositionDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInvestorPositionDetailField *task_data = (CThostFtdcInvestorPositionDetailField*)task->task_data;
		data["reserve1"] = toUtf(task_data->reserve1);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["Direction"] = task_data->Direction;
		data["OpenDate"] = toUtf(task_data->OpenDate);
		data["TradeID"] = toUtf(task_data->TradeID);
		data["Volume"] = task_data->Volume;
		data["OpenPrice"] = task_data->OpenPrice;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["TradeType"] = task_data->TradeType;
		data["reserve2"] = toUtf(task_data->reserve2);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["CloseProfitByDate"] = task_data->CloseProfitByDate;
		data["CloseProfitByTrade"] = task_data->CloseProfitByTrade;
		data["PositionProfitByDate"] = task_data->PositionProfitByDate;
		data["PositionProfitByTrade"] = task_data->PositionProfitByTrade;
		data["Margin"] = task_data->Margin;
		data["ExchMargin"] = task_data->ExchMargin;
		data["MarginRateByMoney"] = task_data->MarginRateByMoney;
		data["MarginRateByVolume"] = task_data->MarginRateByVolume;
		data["LastSettlementPrice"] = task_data->LastSettlementPrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["CloseVolume"] = task_data->CloseVolume;
		data["CloseAmount"] = task_data->CloseAmount;
		data["TimeFirstVolume"] = task_data->TimeFirstVolume;
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["SpecPosiType"] = task_data->SpecPosiType;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["CombInstrumentID"] = toUtf(task_data->CombInstrumentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorPositionDetail(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryNotice(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcNoticeField *task_data = (CThostFtdcNoticeField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["Content"] = toUtf(task_data->Content);
		data["SequenceLabel"] = toUtf(task_data->SequenceLabel);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryNotice(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQrySettlementInfoConfirm(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSettlementInfoConfirmField *task_data = (CThostFtdcSettlementInfoConfirmField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ConfirmDate"] = toUtf(task_data->ConfirmDate);
		data["ConfirmTime"] = toUtf(task_data->ConfirmTime);
		data["SettlementID"] = task_data->SettlementID;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySettlementInfoConfirm(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInvestorPositionCombineDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInvestorPositionCombineDetailField *task_data = (CThostFtdcInvestorPositionCombineDetailField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["OpenDate"] = toUtf(task_data->OpenDate);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["SettlementID"] = task_data->SettlementID;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ComTradeID"] = toUtf(task_data->ComTradeID);
		data["TradeID"] = toUtf(task_data->TradeID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["Direction"] = task_data->Direction;
		data["TotalAmt"] = task_data->TotalAmt;
		data["Margin"] = task_data->Margin;
		data["ExchMargin"] = task_data->ExchMargin;
		data["MarginRateByMoney"] = task_data->MarginRateByMoney;
		data["MarginRateByVolume"] = task_data->MarginRateByVolume;
		data["LegID"] = task_data->LegID;
		data["LegMultiple"] = task_data->LegMultiple;
		data["reserve2"] = toUtf(task_data->reserve2);
		data["TradeGroupID"] = task_data->TradeGroupID;
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["CombInstrumentID"] = toUtf(task_data->CombInstrumentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorPositionCombineDetail(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryCFMMCTradingAccountKey(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcCFMMCTradingAccountKeyField *task_data = (CThostFtdcCFMMCTradingAccountKeyField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["KeyID"] = task_data->KeyID;
		data["CurrentKey"] = toUtf(task_data->CurrentKey);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCFMMCTradingAccountKey(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryEWarrantOffset(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcEWarrantOffsetField *task_data = (CThostFtdcEWarrantOffsetField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["Direction"] = task_data->Direction;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["Volume"] = task_data->Volume;
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryEWarrantOffset(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInvestorProductGroupMargin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInvestorProductGroupMarginField *task_data = (CThostFtdcInvestorProductGroupMarginField*)task->task_data;
		data["reserve1"] = toUtf(task_data->reserve1);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["FrozenMargin"] = task_data->FrozenMargin;
		data["LongFrozenMargin"] = task_data->LongFrozenMargin;
		data["ShortFrozenMargin"] = task_data->ShortFrozenMargin;
		data["UseMargin"] = task_data->UseMargin;
		data["LongUseMargin"] = task_data->LongUseMargin;
		data["ShortUseMargin"] = task_data->ShortUseMargin;
		data["ExchMargin"] = task_data->ExchMargin;
		data["LongExchMargin"] = task_data->LongExchMargin;
		data["ShortExchMargin"] = task_data->ShortExchMargin;
		data["CloseProfit"] = task_data->CloseProfit;
		data["FrozenCommission"] = task_data->FrozenCommission;
		data["Commission"] = task_data->Commission;
		data["FrozenCash"] = task_data->FrozenCash;
		data["CashIn"] = task_data->CashIn;
		data["PositionProfit"] = task_data->PositionProfit;
		data["OffsetAmount"] = task_data->OffsetAmount;
		data["LongOffsetAmount"] = task_data->LongOffsetAmount;
		data["ShortOffsetAmount"] = task_data->ShortOffsetAmount;
		data["ExchOffsetAmount"] = task_data->ExchOffsetAmount;
		data["LongExchOffsetAmount"] = task_data->LongExchOffsetAmount;
		data["ShortExchOffsetAmount"] = task_data->ShortExchOffsetAmount;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["ProductGroupID"] = toUtf(task_data->ProductGroupID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorProductGroupMargin(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryExchangeMarginRate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcExchangeMarginRateField *task_data = (CThostFtdcExchangeMarginRateField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["LongMarginRatioByMoney"] = task_data->LongMarginRatioByMoney;
		data["LongMarginRatioByVolume"] = task_data->LongMarginRatioByVolume;
		data["ShortMarginRatioByMoney"] = task_data->ShortMarginRatioByMoney;
		data["ShortMarginRatioByVolume"] = task_data->ShortMarginRatioByVolume;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExchangeMarginRate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryExchangeMarginRateAdjust(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcExchangeMarginRateAdjustField *task_data = (CThostFtdcExchangeMarginRateAdjustField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["LongMarginRatioByMoney"] = task_data->LongMarginRatioByMoney;
		data["LongMarginRatioByVolume"] = task_data->LongMarginRatioByVolume;
		data["ShortMarginRatioByMoney"] = task_data->ShortMarginRatioByMoney;
		data["ShortMarginRatioByVolume"] = task_data->ShortMarginRatioByVolume;
		data["ExchLongMarginRatioByMoney"] = task_data->ExchLongMarginRatioByMoney;
		data["ExchLongMarginRatioByVolume"] = task_data->ExchLongMarginRatioByVolume;
		data["ExchShortMarginRatioByMoney"] = task_data->ExchShortMarginRatioByMoney;
		data["ExchShortMarginRatioByVolume"] = task_data->ExchShortMarginRatioByVolume;
		data["NoLongMarginRatioByMoney"] = task_data->NoLongMarginRatioByMoney;
		data["NoLongMarginRatioByVolume"] = task_data->NoLongMarginRatioByVolume;
		data["NoShortMarginRatioByMoney"] = task_data->NoShortMarginRatioByMoney;
		data["NoShortMarginRatioByVolume"] = task_data->NoShortMarginRatioByVolume;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExchangeMarginRateAdjust(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryExchangeRate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcExchangeRateField *task_data = (CThostFtdcExchangeRateField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["FromCurrencyID"] = toUtf(task_data->FromCurrencyID);
		data["FromCurrencyUnit"] = task_data->FromCurrencyUnit;
		data["ToCurrencyID"] = toUtf(task_data->ToCurrencyID);
		data["ExchangeRate"] = task_data->ExchangeRate;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExchangeRate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQrySecAgentACIDMap(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSecAgentACIDMapField *task_data = (CThostFtdcSecAgentACIDMapField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["UserID"] = toUtf(task_data->UserID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["BrokerSecAgentID"] = toUtf(task_data->BrokerSecAgentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySecAgentACIDMap(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryProductExchRate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcProductExchRateField *task_data = (CThostFtdcProductExchRateField*)task->task_data;
		data["reserve1"] = toUtf(task_data->reserve1);
		data["QuoteCurrencyID"] = toUtf(task_data->QuoteCurrencyID);
		data["ExchangeRate"] = task_data->ExchangeRate;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ProductID"] = toUtf(task_data->ProductID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryProductExchRate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryProductGroup(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcProductGroupField *task_data = (CThostFtdcProductGroupField*)task->task_data;
		data["reserve1"] = toUtf(task_data->reserve1);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["ProductID"] = toUtf(task_data->ProductID);
		data["ProductGroupID"] = toUtf(task_data->ProductGroupID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryProductGroup(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryMMInstrumentCommissionRate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcMMInstrumentCommissionRateField *task_data = (CThostFtdcMMInstrumentCommissionRateField*)task->task_data;
		data["reserve1"] = toUtf(task_data->reserve1);
		data["InvestorRange"] = task_data->InvestorRange;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["OpenRatioByMoney"] = task_data->OpenRatioByMoney;
		data["OpenRatioByVolume"] = task_data->OpenRatioByVolume;
		data["CloseRatioByMoney"] = task_data->CloseRatioByMoney;
		data["CloseRatioByVolume"] = task_data->CloseRatioByVolume;
		data["CloseTodayRatioByMoney"] = task_data->CloseTodayRatioByMoney;
		data["CloseTodayRatioByVolume"] = task_data->CloseTodayRatioByVolume;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryMMInstrumentCommissionRate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryMMOptionInstrCommRate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcMMOptionInstrCommRateField *task_data = (CThostFtdcMMOptionInstrCommRateField*)task->task_data;
		data["reserve1"] = toUtf(task_data->reserve1);
		data["InvestorRange"] = task_data->InvestorRange;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["OpenRatioByMoney"] = task_data->OpenRatioByMoney;
		data["OpenRatioByVolume"] = task_data->OpenRatioByVolume;
		data["CloseRatioByMoney"] = task_data->CloseRatioByMoney;
		data["CloseRatioByVolume"] = task_data->CloseRatioByVolume;
		data["CloseTodayRatioByMoney"] = task_data->CloseTodayRatioByMoney;
		data["CloseTodayRatioByVolume"] = task_data->CloseTodayRatioByVolume;
		data["StrikeRatioByMoney"] = task_data->StrikeRatioByMoney;
		data["StrikeRatioByVolume"] = task_data->StrikeRatioByVolume;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryMMOptionInstrCommRate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInstrumentOrderCommRate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInstrumentOrderCommRateField *task_data = (CThostFtdcInstrumentOrderCommRateField*)task->task_data;
		data["reserve1"] = toUtf(task_data->reserve1);
		data["InvestorRange"] = task_data->InvestorRange;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["OrderCommByVolume"] = task_data->OrderCommByVolume;
		data["OrderActionCommByVolume"] = task_data->OrderActionCommByVolume;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["OrderCommByTrade"] = task_data->OrderCommByTrade;
		data["OrderActionCommByTrade"] = task_data->OrderActionCommByTrade;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInstrumentOrderCommRate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQrySecAgentTradingAccount(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcTradingAccountField *task_data = (CThostFtdcTradingAccountField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["PreMortgage"] = task_data->PreMortgage;
		data["PreCredit"] = task_data->PreCredit;
		data["PreDeposit"] = task_data->PreDeposit;
		data["PreBalance"] = task_data->PreBalance;
		data["PreMargin"] = task_data->PreMargin;
		data["InterestBase"] = task_data->InterestBase;
		data["Interest"] = task_data->Interest;
		data["Deposit"] = task_data->Deposit;
		data["Withdraw"] = task_data->Withdraw;
		data["FrozenMargin"] = task_data->FrozenMargin;
		data["FrozenCash"] = task_data->FrozenCash;
		data["FrozenCommission"] = task_data->FrozenCommission;
		data["CurrMargin"] = task_data->CurrMargin;
		data["CashIn"] = task_data->CashIn;
		data["Commission"] = task_data->Commission;
		data["CloseProfit"] = task_data->CloseProfit;
		data["PositionProfit"] = task_data->PositionProfit;
		data["Balance"] = task_data->Balance;
		data["Available"] = task_data->Available;
		data["WithdrawQuota"] = task_data->WithdrawQuota;
		data["Reserve"] = task_data->Reserve;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["Credit"] = task_data->Credit;
		data["Mortgage"] = task_data->Mortgage;
		data["ExchangeMargin"] = task_data->ExchangeMargin;
		data["DeliveryMargin"] = task_data->DeliveryMargin;
		data["ExchangeDeliveryMargin"] = task_data->ExchangeDeliveryMargin;
		data["ReserveBalance"] = task_data->ReserveBalance;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["PreFundMortgageIn"] = task_data->PreFundMortgageIn;
		data["PreFundMortgageOut"] = task_data->PreFundMortgageOut;
		data["FundMortgageIn"] = task_data->FundMortgageIn;
		data["FundMortgageOut"] = task_data->FundMortgageOut;
		data["FundMortgageAvailable"] = task_data->FundMortgageAvailable;
		data["MortgageableFund"] = task_data->MortgageableFund;
		data["SpecProductMargin"] = task_data->SpecProductMargin;
		data["SpecProductFrozenMargin"] = task_data->SpecProductFrozenMargin;
		data["SpecProductCommission"] = task_data->SpecProductCommission;
		data["SpecProductFrozenCommission"] = task_data->SpecProductFrozenCommission;
		data["SpecProductPositionProfit"] = task_data->SpecProductPositionProfit;
		data["SpecProductCloseProfit"] = task_data->SpecProductCloseProfit;
		data["SpecProductPositionProfitByAlg"] = task_data->SpecProductPositionProfitByAlg;
		data["SpecProductExchangeMargin"] = task_data->SpecProductExchangeMargin;
		data["BizType"] = task_data->BizType;
		data["FrozenSwap"] = task_data->FrozenSwap;
		data["RemainSwap"] = task_data->RemainSwap;
		data["OptionValue"] = task_data->OptionValue;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySecAgentTradingAccount(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQrySecAgentCheckMode(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSecAgentCheckModeField *task_data = (CThostFtdcSecAgentCheckModeField*)task->task_data;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["BrokerSecAgentID"] = toUtf(task_data->BrokerSecAgentID);
		data["CheckSelfAccount"] = task_data->CheckSelfAccount;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySecAgentCheckMode(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQrySecAgentTradeInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSecAgentTradeInfoField *task_data = (CThostFtdcSecAgentTradeInfoField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerSecAgentID"] = toUtf(task_data->BrokerSecAgentID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySecAgentTradeInfo(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryOptionInstrTradeCost(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcOptionInstrTradeCostField *task_data = (CThostFtdcOptionInstrTradeCostField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["FixedMargin"] = task_data->FixedMargin;
		data["MiniMargin"] = task_data->MiniMargin;
		data["Royalty"] = task_data->Royalty;
		data["ExchFixedMargin"] = task_data->ExchFixedMargin;
		data["ExchMiniMargin"] = task_data->ExchMiniMargin;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOptionInstrTradeCost(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryOptionInstrCommRate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcOptionInstrCommRateField *task_data = (CThostFtdcOptionInstrCommRateField*)task->task_data;
		data["reserve1"] = toUtf(task_data->reserve1);
		data["InvestorRange"] = task_data->InvestorRange;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["OpenRatioByMoney"] = task_data->OpenRatioByMoney;
		data["OpenRatioByVolume"] = task_data->OpenRatioByVolume;
		data["CloseRatioByMoney"] = task_data->CloseRatioByMoney;
		data["CloseRatioByVolume"] = task_data->CloseRatioByVolume;
		data["CloseTodayRatioByMoney"] = task_data->CloseTodayRatioByMoney;
		data["CloseTodayRatioByVolume"] = task_data->CloseTodayRatioByVolume;
		data["StrikeRatioByMoney"] = task_data->StrikeRatioByMoney;
		data["StrikeRatioByVolume"] = task_data->StrikeRatioByVolume;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOptionInstrCommRate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryExecOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcExecOrderField *task_data = (CThostFtdcExecOrderField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["ExecOrderRef"] = toUtf(task_data->ExecOrderRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["Volume"] = task_data->Volume;
		data["RequestID"] = task_data->RequestID;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["ActionType"] = task_data->ActionType;
		data["PosiDirection"] = task_data->PosiDirection;
		data["ReservePositionFlag"] = task_data->ReservePositionFlag;
		data["CloseFlag"] = task_data->CloseFlag;
		data["ExecOrderLocalID"] = toUtf(task_data->ExecOrderLocalID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["OrderSubmitStatus"] = task_data->OrderSubmitStatus;
		data["NotifySequence"] = task_data->NotifySequence;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["ExecOrderSysID"] = toUtf(task_data->ExecOrderSysID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["ExecResult"] = task_data->ExecResult;
		data["ClearingPartID"] = toUtf(task_data->ClearingPartID);
		data["SequenceNo"] = task_data->SequenceNo;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ActiveUserID"] = toUtf(task_data->ActiveUserID);
		data["BrokerExecOrderSeq"] = task_data->BrokerExecOrderSeq;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["reserve3"] = toUtf(task_data->reserve3);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryExecOrder(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryForQuote(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcForQuoteField *task_data = (CThostFtdcForQuoteField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["ForQuoteRef"] = toUtf(task_data->ForQuoteRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["ForQuoteLocalID"] = toUtf(task_data->ForQuoteLocalID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["ForQuoteStatus"] = task_data->ForQuoteStatus;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ActiveUserID"] = toUtf(task_data->ActiveUserID);
		data["BrokerForQutoSeq"] = task_data->BrokerForQutoSeq;
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["reserve3"] = toUtf(task_data->reserve3);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryForQuote(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryQuote(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcQuoteField *task_data = (CThostFtdcQuoteField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["QuoteRef"] = toUtf(task_data->QuoteRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["AskPrice"] = task_data->AskPrice;
		data["BidPrice"] = task_data->BidPrice;
		data["AskVolume"] = task_data->AskVolume;
		data["BidVolume"] = task_data->BidVolume;
		data["RequestID"] = task_data->RequestID;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["AskOffsetFlag"] = task_data->AskOffsetFlag;
		data["BidOffsetFlag"] = task_data->BidOffsetFlag;
		data["AskHedgeFlag"] = task_data->AskHedgeFlag;
		data["BidHedgeFlag"] = task_data->BidHedgeFlag;
		data["QuoteLocalID"] = toUtf(task_data->QuoteLocalID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["NotifySequence"] = task_data->NotifySequence;
		data["OrderSubmitStatus"] = task_data->OrderSubmitStatus;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["QuoteSysID"] = toUtf(task_data->QuoteSysID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["QuoteStatus"] = task_data->QuoteStatus;
		data["ClearingPartID"] = toUtf(task_data->ClearingPartID);
		data["SequenceNo"] = task_data->SequenceNo;
		data["AskOrderSysID"] = toUtf(task_data->AskOrderSysID);
		data["BidOrderSysID"] = toUtf(task_data->BidOrderSysID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ActiveUserID"] = toUtf(task_data->ActiveUserID);
		data["BrokerQuoteSeq"] = task_data->BrokerQuoteSeq;
		data["AskOrderRef"] = toUtf(task_data->AskOrderRef);
		data["BidOrderRef"] = toUtf(task_data->BidOrderRef);
		data["ForQuoteSysID"] = toUtf(task_data->ForQuoteSysID);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["reserve3"] = toUtf(task_data->reserve3);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["ReplaceSysID"] = toUtf(task_data->ReplaceSysID);
		data["TimeCondition"] = task_data->TimeCondition;
		data["OrderMemo"] = toUtf(task_data->OrderMemo);
		data["SessionReqSeq"] = task_data->SessionReqSeq;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryQuote(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryOptionSelfClose(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcOptionSelfCloseField *task_data = (CThostFtdcOptionSelfCloseField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["OptionSelfCloseRef"] = toUtf(task_data->OptionSelfCloseRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["Volume"] = task_data->Volume;
		data["RequestID"] = task_data->RequestID;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["OptSelfCloseFlag"] = task_data->OptSelfCloseFlag;
		data["OptionSelfCloseLocalID"] = toUtf(task_data->OptionSelfCloseLocalID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["OrderSubmitStatus"] = task_data->OrderSubmitStatus;
		data["NotifySequence"] = task_data->NotifySequence;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["OptionSelfCloseSysID"] = toUtf(task_data->OptionSelfCloseSysID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["ExecResult"] = task_data->ExecResult;
		data["ClearingPartID"] = toUtf(task_data->ClearingPartID);
		data["SequenceNo"] = task_data->SequenceNo;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ActiveUserID"] = toUtf(task_data->ActiveUserID);
		data["BrokerOptionSelfCloseSeq"] = task_data->BrokerOptionSelfCloseSeq;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["reserve3"] = toUtf(task_data->reserve3);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOptionSelfClose(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInvestUnit(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInvestUnitField *task_data = (CThostFtdcInvestUnitField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["InvestorUnitName"] = toUtf(task_data->InvestorUnitName);
		data["InvestorGroupID"] = toUtf(task_data->InvestorGroupID);
		data["CommModelID"] = toUtf(task_data->CommModelID);
		data["MarginModelID"] = toUtf(task_data->MarginModelID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestUnit(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryCombInstrumentGuard(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcCombInstrumentGuardField *task_data = (CThostFtdcCombInstrumentGuardField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["GuarantRatio"] = task_data->GuarantRatio;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombInstrumentGuard(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryCombAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcCombActionField *task_data = (CThostFtdcCombActionField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["CombActionRef"] = toUtf(task_data->CombActionRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["Direction"] = task_data->Direction;
		data["Volume"] = task_data->Volume;
		data["CombDirection"] = task_data->CombDirection;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["ActionLocalID"] = toUtf(task_data->ActionLocalID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["ActionStatus"] = task_data->ActionStatus;
		data["NotifySequence"] = task_data->NotifySequence;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["SequenceNo"] = task_data->SequenceNo;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["reserve3"] = toUtf(task_data->reserve3);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["ComTradeID"] = toUtf(task_data->ComTradeID);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombAction(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryTransferSerial(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcTransferSerialField *task_data = (CThostFtdcTransferSerialField*)task->task_data;
		data["PlateSerial"] = task_data->PlateSerial;
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["SessionID"] = task_data->SessionID;
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BankAccType"] = task_data->BankAccType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["FutureAccType"] = task_data->FutureAccType;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["FutureSerial"] = task_data->FutureSerial;
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["TradeAmount"] = task_data->TradeAmount;
		data["CustFee"] = task_data->CustFee;
		data["BrokerFee"] = task_data->BrokerFee;
		data["AvailabilityFlag"] = task_data->AvailabilityFlag;
		data["OperatorCode"] = toUtf(task_data->OperatorCode);
		data["BankNewAccount"] = toUtf(task_data->BankNewAccount);
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTransferSerial(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryAccountregister(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcAccountregisterField *task_data = (CThostFtdcAccountregisterField*)task->task_data;
		data["TradeDay"] = toUtf(task_data->TradeDay);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["OpenOrDestroy"] = task_data->OpenOrDestroy;
		data["RegDate"] = toUtf(task_data->RegDate);
		data["OutDate"] = toUtf(task_data->OutDate);
		data["TID"] = task_data->TID;
		data["CustType"] = task_data->CustType;
		data["BankAccType"] = task_data->BankAccType;
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryAccountregister(data, error, task->task_id, task->task_last);
};

void TdApi::processRspError(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspError(error, task->task_id, task->task_last);
};

void TdApi::processRtnOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcOrderField *task_data = (CThostFtdcOrderField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["Direction"] = task_data->Direction;
		data["CombOffsetFlag"] = toUtf(task_data->CombOffsetFlag);
		data["CombHedgeFlag"] = toUtf(task_data->CombHedgeFlag);
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["TimeCondition"] = task_data->TimeCondition;
		data["GTDDate"] = toUtf(task_data->GTDDate);
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["MinVolume"] = task_data->MinVolume;
		data["ContingentCondition"] = task_data->ContingentCondition;
		data["StopPrice"] = task_data->StopPrice;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["IsAutoSuspend"] = task_data->IsAutoSuspend;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["RequestID"] = task_data->RequestID;
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["OrderSubmitStatus"] = task_data->OrderSubmitStatus;
		data["NotifySequence"] = task_data->NotifySequence;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["OrderSource"] = task_data->OrderSource;
		data["OrderStatus"] = task_data->OrderStatus;
		data["OrderType"] = task_data->OrderType;
		data["VolumeTraded"] = task_data->VolumeTraded;
		data["VolumeTotal"] = task_data->VolumeTotal;
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["ActiveTime"] = toUtf(task_data->ActiveTime);
		data["SuspendTime"] = toUtf(task_data->SuspendTime);
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["ActiveTraderID"] = toUtf(task_data->ActiveTraderID);
		data["ClearingPartID"] = toUtf(task_data->ClearingPartID);
		data["SequenceNo"] = task_data->SequenceNo;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["UserForceClose"] = task_data->UserForceClose;
		data["ActiveUserID"] = toUtf(task_data->ActiveUserID);
		data["BrokerOrderSeq"] = task_data->BrokerOrderSeq;
		data["RelativeOrderSysID"] = toUtf(task_data->RelativeOrderSysID);
		data["ZCETotalTradedVolume"] = task_data->ZCETotalTradedVolume;
		data["IsSwapOrder"] = task_data->IsSwapOrder;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["reserve3"] = toUtf(task_data->reserve3);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["OrderMemo"] = toUtf(task_data->OrderMemo);
		data["SessionReqSeq"] = task_data->SessionReqSeq;
		delete task_data;
	}
	this->onRtnOrder(data);
};

void TdApi::processRtnTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcTradeField *task_data = (CThostFtdcTradeField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["TradeID"] = toUtf(task_data->TradeID);
		data["Direction"] = task_data->Direction;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["TradingRole"] = task_data->TradingRole;
		data["reserve2"] = toUtf(task_data->reserve2);
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["Price"] = task_data->Price;
		data["Volume"] = task_data->Volume;
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["TradeType"] = task_data->TradeType;
		data["PriceSource"] = task_data->PriceSource;
		data["TraderID"] = toUtf(task_data->TraderID);
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["ClearingPartID"] = toUtf(task_data->ClearingPartID);
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["SequenceNo"] = task_data->SequenceNo;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["BrokerOrderSeq"] = task_data->BrokerOrderSeq;
		data["TradeSource"] = task_data->TradeSource;
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		delete task_data;
	}
	this->onRtnTrade(data);
};

void TdApi::processErrRtnOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputOrderField *task_data = (CThostFtdcInputOrderField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["Direction"] = task_data->Direction;
		data["CombOffsetFlag"] = toUtf(task_data->CombOffsetFlag);
		data["CombHedgeFlag"] = toUtf(task_data->CombHedgeFlag);
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["TimeCondition"] = task_data->TimeCondition;
		data["GTDDate"] = toUtf(task_data->GTDDate);
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["MinVolume"] = task_data->MinVolume;
		data["ContingentCondition"] = task_data->ContingentCondition;
		data["StopPrice"] = task_data->StopPrice;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["IsAutoSuspend"] = task_data->IsAutoSuspend;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["RequestID"] = task_data->RequestID;
		data["UserForceClose"] = task_data->UserForceClose;
		data["IsSwapOrder"] = task_data->IsSwapOrder;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["OrderMemo"] = toUtf(task_data->OrderMemo);
		data["SessionReqSeq"] = task_data->SessionReqSeq;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnOrderInsert(data, error);
};

void TdApi::processErrRtnOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcOrderActionField *task_data = (CThostFtdcOrderActionField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["OrderActionRef"] = task_data->OrderActionRef;
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["RequestID"] = task_data->RequestID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["ActionFlag"] = task_data->ActionFlag;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeChange"] = task_data->VolumeChange;
		data["ActionDate"] = toUtf(task_data->ActionDate);
		data["ActionTime"] = toUtf(task_data->ActionTime);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["ActionLocalID"] = toUtf(task_data->ActionLocalID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["OrderActionStatus"] = task_data->OrderActionStatus;
		data["UserID"] = toUtf(task_data->UserID);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["OrderMemo"] = toUtf(task_data->OrderMemo);
		data["SessionReqSeq"] = task_data->SessionReqSeq;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnOrderAction(data, error);
};

void TdApi::processRtnInstrumentStatus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInstrumentStatusField *task_data = (CThostFtdcInstrumentStatusField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["SettlementGroupID"] = toUtf(task_data->SettlementGroupID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["InstrumentStatus"] = task_data->InstrumentStatus;
		data["TradingSegmentSN"] = task_data->TradingSegmentSN;
		data["EnterTime"] = toUtf(task_data->EnterTime);
		data["EnterReason"] = task_data->EnterReason;
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task_data;
	}
	this->onRtnInstrumentStatus(data);
};

void TdApi::processRtnBulletin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcBulletinField *task_data = (CThostFtdcBulletinField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["BulletinID"] = task_data->BulletinID;
		data["SequenceNo"] = task_data->SequenceNo;
		data["NewsType"] = toUtf(task_data->NewsType);
		data["NewsUrgency"] = task_data->NewsUrgency;
		data["SendTime"] = toUtf(task_data->SendTime);
		data["Abstract"] = toUtf(task_data->Abstract);
		data["ComeFrom"] = toUtf(task_data->ComeFrom);
		data["Content"] = toUtf(task_data->Content);
		data["URLLink"] = toUtf(task_data->URLLink);
		data["MarketID"] = toUtf(task_data->MarketID);
		delete task_data;
	}
	this->onRtnBulletin(data);
};

void TdApi::processRtnTradingNotice(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcTradingNoticeInfoField *task_data = (CThostFtdcTradingNoticeInfoField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["SendTime"] = toUtf(task_data->SendTime);
		data["FieldContent"] = toUtf(task_data->FieldContent);
		data["SequenceSeries"] = task_data->SequenceSeries;
		data["SequenceNo"] = task_data->SequenceNo;
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		delete task_data;
	}
	this->onRtnTradingNotice(data);
};

void TdApi::processRtnErrorConditionalOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcErrorConditionalOrderField *task_data = (CThostFtdcErrorConditionalOrderField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["Direction"] = task_data->Direction;
		data["CombOffsetFlag"] = toUtf(task_data->CombOffsetFlag);
		data["CombHedgeFlag"] = toUtf(task_data->CombHedgeFlag);
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["TimeCondition"] = task_data->TimeCondition;
		data["GTDDate"] = toUtf(task_data->GTDDate);
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["MinVolume"] = task_data->MinVolume;
		data["ContingentCondition"] = task_data->ContingentCondition;
		data["StopPrice"] = task_data->StopPrice;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["IsAutoSuspend"] = task_data->IsAutoSuspend;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["RequestID"] = task_data->RequestID;
		data["OrderLocalID"] = toUtf(task_data->OrderLocalID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["OrderSubmitStatus"] = task_data->OrderSubmitStatus;
		data["NotifySequence"] = task_data->NotifySequence;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["OrderSource"] = task_data->OrderSource;
		data["OrderStatus"] = task_data->OrderStatus;
		data["OrderType"] = task_data->OrderType;
		data["VolumeTraded"] = task_data->VolumeTraded;
		data["VolumeTotal"] = task_data->VolumeTotal;
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["ActiveTime"] = toUtf(task_data->ActiveTime);
		data["SuspendTime"] = toUtf(task_data->SuspendTime);
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["ActiveTraderID"] = toUtf(task_data->ActiveTraderID);
		data["ClearingPartID"] = toUtf(task_data->ClearingPartID);
		data["SequenceNo"] = task_data->SequenceNo;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["UserForceClose"] = task_data->UserForceClose;
		data["ActiveUserID"] = toUtf(task_data->ActiveUserID);
		data["BrokerOrderSeq"] = task_data->BrokerOrderSeq;
		data["RelativeOrderSysID"] = toUtf(task_data->RelativeOrderSysID);
		data["ZCETotalTradedVolume"] = task_data->ZCETotalTradedVolume;
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["IsSwapOrder"] = task_data->IsSwapOrder;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["reserve3"] = toUtf(task_data->reserve3);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	this->onRtnErrorConditionalOrder(data);
};

void TdApi::processRtnExecOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcExecOrderField *task_data = (CThostFtdcExecOrderField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["ExecOrderRef"] = toUtf(task_data->ExecOrderRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["Volume"] = task_data->Volume;
		data["RequestID"] = task_data->RequestID;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["ActionType"] = task_data->ActionType;
		data["PosiDirection"] = task_data->PosiDirection;
		data["ReservePositionFlag"] = task_data->ReservePositionFlag;
		data["CloseFlag"] = task_data->CloseFlag;
		data["ExecOrderLocalID"] = toUtf(task_data->ExecOrderLocalID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["OrderSubmitStatus"] = task_data->OrderSubmitStatus;
		data["NotifySequence"] = task_data->NotifySequence;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["ExecOrderSysID"] = toUtf(task_data->ExecOrderSysID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["ExecResult"] = task_data->ExecResult;
		data["ClearingPartID"] = toUtf(task_data->ClearingPartID);
		data["SequenceNo"] = task_data->SequenceNo;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ActiveUserID"] = toUtf(task_data->ActiveUserID);
		data["BrokerExecOrderSeq"] = task_data->BrokerExecOrderSeq;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["reserve3"] = toUtf(task_data->reserve3);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	this->onRtnExecOrder(data);
};

void TdApi::processErrRtnExecOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputExecOrderField *task_data = (CThostFtdcInputExecOrderField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["ExecOrderRef"] = toUtf(task_data->ExecOrderRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["Volume"] = task_data->Volume;
		data["RequestID"] = task_data->RequestID;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["ActionType"] = task_data->ActionType;
		data["PosiDirection"] = task_data->PosiDirection;
		data["ReservePositionFlag"] = task_data->ReservePositionFlag;
		data["CloseFlag"] = task_data->CloseFlag;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnExecOrderInsert(data, error);
};

void TdApi::processErrRtnExecOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcExecOrderActionField *task_data = (CThostFtdcExecOrderActionField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExecOrderActionRef"] = task_data->ExecOrderActionRef;
		data["ExecOrderRef"] = toUtf(task_data->ExecOrderRef);
		data["RequestID"] = task_data->RequestID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ExecOrderSysID"] = toUtf(task_data->ExecOrderSysID);
		data["ActionFlag"] = task_data->ActionFlag;
		data["ActionDate"] = toUtf(task_data->ActionDate);
		data["ActionTime"] = toUtf(task_data->ActionTime);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["ExecOrderLocalID"] = toUtf(task_data->ExecOrderLocalID);
		data["ActionLocalID"] = toUtf(task_data->ActionLocalID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["OrderActionStatus"] = task_data->OrderActionStatus;
		data["UserID"] = toUtf(task_data->UserID);
		data["ActionType"] = task_data->ActionType;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnExecOrderAction(data, error);
};

void TdApi::processErrRtnForQuoteInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputForQuoteField *task_data = (CThostFtdcInputForQuoteField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["ForQuoteRef"] = toUtf(task_data->ForQuoteRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnForQuoteInsert(data, error);
};

void TdApi::processRtnQuote(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcQuoteField *task_data = (CThostFtdcQuoteField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["QuoteRef"] = toUtf(task_data->QuoteRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["AskPrice"] = task_data->AskPrice;
		data["BidPrice"] = task_data->BidPrice;
		data["AskVolume"] = task_data->AskVolume;
		data["BidVolume"] = task_data->BidVolume;
		data["RequestID"] = task_data->RequestID;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["AskOffsetFlag"] = task_data->AskOffsetFlag;
		data["BidOffsetFlag"] = task_data->BidOffsetFlag;
		data["AskHedgeFlag"] = task_data->AskHedgeFlag;
		data["BidHedgeFlag"] = task_data->BidHedgeFlag;
		data["QuoteLocalID"] = toUtf(task_data->QuoteLocalID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["NotifySequence"] = task_data->NotifySequence;
		data["OrderSubmitStatus"] = task_data->OrderSubmitStatus;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["QuoteSysID"] = toUtf(task_data->QuoteSysID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["QuoteStatus"] = task_data->QuoteStatus;
		data["ClearingPartID"] = toUtf(task_data->ClearingPartID);
		data["SequenceNo"] = task_data->SequenceNo;
		data["AskOrderSysID"] = toUtf(task_data->AskOrderSysID);
		data["BidOrderSysID"] = toUtf(task_data->BidOrderSysID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ActiveUserID"] = toUtf(task_data->ActiveUserID);
		data["BrokerQuoteSeq"] = task_data->BrokerQuoteSeq;
		data["AskOrderRef"] = toUtf(task_data->AskOrderRef);
		data["BidOrderRef"] = toUtf(task_data->BidOrderRef);
		data["ForQuoteSysID"] = toUtf(task_data->ForQuoteSysID);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["reserve3"] = toUtf(task_data->reserve3);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["ReplaceSysID"] = toUtf(task_data->ReplaceSysID);
		data["TimeCondition"] = task_data->TimeCondition;
		data["OrderMemo"] = toUtf(task_data->OrderMemo);
		data["SessionReqSeq"] = task_data->SessionReqSeq;
		delete task_data;
	}
	this->onRtnQuote(data);
};

void TdApi::processErrRtnQuoteInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputQuoteField *task_data = (CThostFtdcInputQuoteField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["QuoteRef"] = toUtf(task_data->QuoteRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["AskPrice"] = task_data->AskPrice;
		data["BidPrice"] = task_data->BidPrice;
		data["AskVolume"] = task_data->AskVolume;
		data["BidVolume"] = task_data->BidVolume;
		data["RequestID"] = task_data->RequestID;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["AskOffsetFlag"] = task_data->AskOffsetFlag;
		data["BidOffsetFlag"] = task_data->BidOffsetFlag;
		data["AskHedgeFlag"] = task_data->AskHedgeFlag;
		data["BidHedgeFlag"] = task_data->BidHedgeFlag;
		data["AskOrderRef"] = toUtf(task_data->AskOrderRef);
		data["BidOrderRef"] = toUtf(task_data->BidOrderRef);
		data["ForQuoteSysID"] = toUtf(task_data->ForQuoteSysID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["ReplaceSysID"] = toUtf(task_data->ReplaceSysID);
		data["TimeCondition"] = task_data->TimeCondition;
		data["OrderMemo"] = toUtf(task_data->OrderMemo);
		data["SessionReqSeq"] = task_data->SessionReqSeq;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnQuoteInsert(data, error);
};

void TdApi::processErrRtnQuoteAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcQuoteActionField *task_data = (CThostFtdcQuoteActionField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["QuoteActionRef"] = task_data->QuoteActionRef;
		data["QuoteRef"] = toUtf(task_data->QuoteRef);
		data["RequestID"] = task_data->RequestID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["QuoteSysID"] = toUtf(task_data->QuoteSysID);
		data["ActionFlag"] = task_data->ActionFlag;
		data["ActionDate"] = toUtf(task_data->ActionDate);
		data["ActionTime"] = toUtf(task_data->ActionTime);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["QuoteLocalID"] = toUtf(task_data->QuoteLocalID);
		data["ActionLocalID"] = toUtf(task_data->ActionLocalID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["OrderActionStatus"] = task_data->OrderActionStatus;
		data["UserID"] = toUtf(task_data->UserID);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["OrderMemo"] = toUtf(task_data->OrderMemo);
		data["SessionReqSeq"] = task_data->SessionReqSeq;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnQuoteAction(data, error);
};

void TdApi::processRtnForQuoteRsp(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcForQuoteRspField *task_data = (CThostFtdcForQuoteRspField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["ForQuoteSysID"] = toUtf(task_data->ForQuoteSysID);
		data["ForQuoteTime"] = toUtf(task_data->ForQuoteTime);
		data["ActionDay"] = toUtf(task_data->ActionDay);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task_data;
	}
	this->onRtnForQuoteRsp(data);
};

void TdApi::processRtnCFMMCTradingAccountToken(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcCFMMCTradingAccountTokenField *task_data = (CThostFtdcCFMMCTradingAccountTokenField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["KeyID"] = task_data->KeyID;
		data["Token"] = toUtf(task_data->Token);
		delete task_data;
	}
	this->onRtnCFMMCTradingAccountToken(data);
};

void TdApi::processErrRtnBatchOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcBatchOrderActionField *task_data = (CThostFtdcBatchOrderActionField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["OrderActionRef"] = task_data->OrderActionRef;
		data["RequestID"] = task_data->RequestID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ActionDate"] = toUtf(task_data->ActionDate);
		data["ActionTime"] = toUtf(task_data->ActionTime);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["ActionLocalID"] = toUtf(task_data->ActionLocalID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["OrderActionStatus"] = task_data->OrderActionStatus;
		data["UserID"] = toUtf(task_data->UserID);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnBatchOrderAction(data, error);
};

void TdApi::processRtnOptionSelfClose(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcOptionSelfCloseField *task_data = (CThostFtdcOptionSelfCloseField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["OptionSelfCloseRef"] = toUtf(task_data->OptionSelfCloseRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["Volume"] = task_data->Volume;
		data["RequestID"] = task_data->RequestID;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["OptSelfCloseFlag"] = task_data->OptSelfCloseFlag;
		data["OptionSelfCloseLocalID"] = toUtf(task_data->OptionSelfCloseLocalID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["OrderSubmitStatus"] = task_data->OrderSubmitStatus;
		data["NotifySequence"] = task_data->NotifySequence;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["OptionSelfCloseSysID"] = toUtf(task_data->OptionSelfCloseSysID);
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["ExecResult"] = task_data->ExecResult;
		data["ClearingPartID"] = toUtf(task_data->ClearingPartID);
		data["SequenceNo"] = task_data->SequenceNo;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ActiveUserID"] = toUtf(task_data->ActiveUserID);
		data["BrokerOptionSelfCloseSeq"] = task_data->BrokerOptionSelfCloseSeq;
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["reserve3"] = toUtf(task_data->reserve3);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	this->onRtnOptionSelfClose(data);
};

void TdApi::processErrRtnOptionSelfCloseInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputOptionSelfCloseField *task_data = (CThostFtdcInputOptionSelfCloseField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["OptionSelfCloseRef"] = toUtf(task_data->OptionSelfCloseRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["Volume"] = task_data->Volume;
		data["RequestID"] = task_data->RequestID;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["OptSelfCloseFlag"] = task_data->OptSelfCloseFlag;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnOptionSelfCloseInsert(data, error);
};

void TdApi::processErrRtnOptionSelfCloseAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcOptionSelfCloseActionField *task_data = (CThostFtdcOptionSelfCloseActionField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["OptionSelfCloseActionRef"] = task_data->OptionSelfCloseActionRef;
		data["OptionSelfCloseRef"] = toUtf(task_data->OptionSelfCloseRef);
		data["RequestID"] = task_data->RequestID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["OptionSelfCloseSysID"] = toUtf(task_data->OptionSelfCloseSysID);
		data["ActionFlag"] = task_data->ActionFlag;
		data["ActionDate"] = toUtf(task_data->ActionDate);
		data["ActionTime"] = toUtf(task_data->ActionTime);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["OptionSelfCloseLocalID"] = toUtf(task_data->OptionSelfCloseLocalID);
		data["ActionLocalID"] = toUtf(task_data->ActionLocalID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["OrderActionStatus"] = task_data->OrderActionStatus;
		data["UserID"] = toUtf(task_data->UserID);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnOptionSelfCloseAction(data, error);
};

void TdApi::processRtnCombAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcCombActionField *task_data = (CThostFtdcCombActionField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["CombActionRef"] = toUtf(task_data->CombActionRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["Direction"] = task_data->Direction;
		data["Volume"] = task_data->Volume;
		data["CombDirection"] = task_data->CombDirection;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["ActionLocalID"] = toUtf(task_data->ActionLocalID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["ActionStatus"] = task_data->ActionStatus;
		data["NotifySequence"] = task_data->NotifySequence;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["SequenceNo"] = task_data->SequenceNo;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["UserProductInfo"] = toUtf(task_data->UserProductInfo);
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["reserve3"] = toUtf(task_data->reserve3);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["ComTradeID"] = toUtf(task_data->ComTradeID);
		data["BranchID"] = toUtf(task_data->BranchID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	this->onRtnCombAction(data);
};

void TdApi::processErrRtnCombActionInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputCombActionField *task_data = (CThostFtdcInputCombActionField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["CombActionRef"] = toUtf(task_data->CombActionRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["Direction"] = task_data->Direction;
		data["Volume"] = task_data->Volume;
		data["CombDirection"] = task_data->CombDirection;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnCombActionInsert(data, error);
};

void TdApi::processRspQryContractBank(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcContractBankField *task_data = (CThostFtdcContractBankField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBrchID"] = toUtf(task_data->BankBrchID);
		data["BankName"] = toUtf(task_data->BankName);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryContractBank(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryParkedOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcParkedOrderField *task_data = (CThostFtdcParkedOrderField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["UserID"] = toUtf(task_data->UserID);
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["Direction"] = task_data->Direction;
		data["CombOffsetFlag"] = toUtf(task_data->CombOffsetFlag);
		data["CombHedgeFlag"] = toUtf(task_data->CombHedgeFlag);
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["TimeCondition"] = task_data->TimeCondition;
		data["GTDDate"] = toUtf(task_data->GTDDate);
		data["VolumeCondition"] = task_data->VolumeCondition;
		data["MinVolume"] = task_data->MinVolume;
		data["ContingentCondition"] = task_data->ContingentCondition;
		data["StopPrice"] = task_data->StopPrice;
		data["ForceCloseReason"] = task_data->ForceCloseReason;
		data["IsAutoSuspend"] = task_data->IsAutoSuspend;
		data["BusinessUnit"] = toUtf(task_data->BusinessUnit);
		data["RequestID"] = task_data->RequestID;
		data["UserForceClose"] = task_data->UserForceClose;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ParkedOrderID"] = toUtf(task_data->ParkedOrderID);
		data["UserType"] = task_data->UserType;
		data["Status"] = task_data->Status;
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["IsSwapOrder"] = task_data->IsSwapOrder;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryParkedOrder(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryParkedOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcParkedOrderActionField *task_data = (CThostFtdcParkedOrderActionField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["OrderActionRef"] = task_data->OrderActionRef;
		data["OrderRef"] = toUtf(task_data->OrderRef);
		data["RequestID"] = task_data->RequestID;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["OrderSysID"] = toUtf(task_data->OrderSysID);
		data["ActionFlag"] = task_data->ActionFlag;
		data["LimitPrice"] = task_data->LimitPrice;
		data["VolumeChange"] = task_data->VolumeChange;
		data["UserID"] = toUtf(task_data->UserID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["ParkedOrderActionID"] = toUtf(task_data->ParkedOrderActionID);
		data["UserType"] = task_data->UserType;
		data["Status"] = task_data->Status;
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryParkedOrderAction(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryTradingNotice(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcTradingNoticeField *task_data = (CThostFtdcTradingNoticeField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorRange"] = task_data->InvestorRange;
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["SequenceSeries"] = task_data->SequenceSeries;
		data["UserID"] = toUtf(task_data->UserID);
		data["SendTime"] = toUtf(task_data->SendTime);
		data["SequenceNo"] = task_data->SequenceNo;
		data["FieldContent"] = toUtf(task_data->FieldContent);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryTradingNotice(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryBrokerTradingParams(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcBrokerTradingParamsField *task_data = (CThostFtdcBrokerTradingParamsField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["MarginPriceType"] = task_data->MarginPriceType;
		data["Algorithm"] = task_data->Algorithm;
		data["AvailIncludeCloseProfit"] = task_data->AvailIncludeCloseProfit;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["OptionRoyaltyPriceType"] = task_data->OptionRoyaltyPriceType;
		data["AccountID"] = toUtf(task_data->AccountID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryBrokerTradingParams(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryBrokerTradingAlgos(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcBrokerTradingAlgosField *task_data = (CThostFtdcBrokerTradingAlgosField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["reserve1"] = toUtf(task_data->reserve1);
		data["HandlePositionAlgoID"] = task_data->HandlePositionAlgoID;
		data["FindMarginRateAlgoID"] = task_data->FindMarginRateAlgoID;
		data["HandleTradingAccountAlgoID"] = task_data->HandleTradingAccountAlgoID;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryBrokerTradingAlgos(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQueryCFMMCTradingAccountToken(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcQueryCFMMCTradingAccountTokenField *task_data = (CThostFtdcQueryCFMMCTradingAccountTokenField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQueryCFMMCTradingAccountToken(data, error, task->task_id, task->task_last);
};

void TdApi::processRtnFromBankToFutureByBank(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRspTransferField *task_data = (CThostFtdcRspTransferField*)task->task_data;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["FutureSerial"] = task_data->FutureSerial;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["TradeAmount"] = task_data->TradeAmount;
		data["FutureFetchAmount"] = task_data->FutureFetchAmount;
		data["FeePayFlag"] = task_data->FeePayFlag;
		data["CustFee"] = task_data->CustFee;
		data["BrokerFee"] = task_data->BrokerFee;
		data["Message"] = toUtf(task_data->Message);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["TransferStatus"] = task_data->TransferStatus;
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	this->onRtnFromBankToFutureByBank(data);
};

void TdApi::processRtnFromFutureToBankByBank(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRspTransferField *task_data = (CThostFtdcRspTransferField*)task->task_data;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["FutureSerial"] = task_data->FutureSerial;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["TradeAmount"] = task_data->TradeAmount;
		data["FutureFetchAmount"] = task_data->FutureFetchAmount;
		data["FeePayFlag"] = task_data->FeePayFlag;
		data["CustFee"] = task_data->CustFee;
		data["BrokerFee"] = task_data->BrokerFee;
		data["Message"] = toUtf(task_data->Message);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["TransferStatus"] = task_data->TransferStatus;
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	this->onRtnFromFutureToBankByBank(data);
};

void TdApi::processRtnRepealFromBankToFutureByBank(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRspRepealField *task_data = (CThostFtdcRspRepealField*)task->task_data;
		data["RepealTimeInterval"] = task_data->RepealTimeInterval;
		data["RepealedTimes"] = task_data->RepealedTimes;
		data["BankRepealFlag"] = task_data->BankRepealFlag;
		data["BrokerRepealFlag"] = task_data->BrokerRepealFlag;
		data["PlateRepealSerial"] = task_data->PlateRepealSerial;
		data["BankRepealSerial"] = toUtf(task_data->BankRepealSerial);
		data["FutureRepealSerial"] = task_data->FutureRepealSerial;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["FutureSerial"] = task_data->FutureSerial;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["TradeAmount"] = task_data->TradeAmount;
		data["FutureFetchAmount"] = task_data->FutureFetchAmount;
		data["FeePayFlag"] = task_data->FeePayFlag;
		data["CustFee"] = task_data->CustFee;
		data["BrokerFee"] = task_data->BrokerFee;
		data["Message"] = toUtf(task_data->Message);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["TransferStatus"] = task_data->TransferStatus;
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	this->onRtnRepealFromBankToFutureByBank(data);
};

void TdApi::processRtnRepealFromFutureToBankByBank(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRspRepealField *task_data = (CThostFtdcRspRepealField*)task->task_data;
		data["RepealTimeInterval"] = task_data->RepealTimeInterval;
		data["RepealedTimes"] = task_data->RepealedTimes;
		data["BankRepealFlag"] = task_data->BankRepealFlag;
		data["BrokerRepealFlag"] = task_data->BrokerRepealFlag;
		data["PlateRepealSerial"] = task_data->PlateRepealSerial;
		data["BankRepealSerial"] = toUtf(task_data->BankRepealSerial);
		data["FutureRepealSerial"] = task_data->FutureRepealSerial;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["FutureSerial"] = task_data->FutureSerial;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["TradeAmount"] = task_data->TradeAmount;
		data["FutureFetchAmount"] = task_data->FutureFetchAmount;
		data["FeePayFlag"] = task_data->FeePayFlag;
		data["CustFee"] = task_data->CustFee;
		data["BrokerFee"] = task_data->BrokerFee;
		data["Message"] = toUtf(task_data->Message);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["TransferStatus"] = task_data->TransferStatus;
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	this->onRtnRepealFromFutureToBankByBank(data);
};

void TdApi::processRtnFromBankToFutureByFuture(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRspTransferField *task_data = (CThostFtdcRspTransferField*)task->task_data;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["FutureSerial"] = task_data->FutureSerial;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["TradeAmount"] = task_data->TradeAmount;
		data["FutureFetchAmount"] = task_data->FutureFetchAmount;
		data["FeePayFlag"] = task_data->FeePayFlag;
		data["CustFee"] = task_data->CustFee;
		data["BrokerFee"] = task_data->BrokerFee;
		data["Message"] = toUtf(task_data->Message);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["TransferStatus"] = task_data->TransferStatus;
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	this->onRtnFromBankToFutureByFuture(data);
};

void TdApi::processRtnFromFutureToBankByFuture(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRspTransferField *task_data = (CThostFtdcRspTransferField*)task->task_data;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["FutureSerial"] = task_data->FutureSerial;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["TradeAmount"] = task_data->TradeAmount;
		data["FutureFetchAmount"] = task_data->FutureFetchAmount;
		data["FeePayFlag"] = task_data->FeePayFlag;
		data["CustFee"] = task_data->CustFee;
		data["BrokerFee"] = task_data->BrokerFee;
		data["Message"] = toUtf(task_data->Message);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["TransferStatus"] = task_data->TransferStatus;
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	this->onRtnFromFutureToBankByFuture(data);
};

void TdApi::processRtnRepealFromBankToFutureByFutureManual(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRspRepealField *task_data = (CThostFtdcRspRepealField*)task->task_data;
		data["RepealTimeInterval"] = task_data->RepealTimeInterval;
		data["RepealedTimes"] = task_data->RepealedTimes;
		data["BankRepealFlag"] = task_data->BankRepealFlag;
		data["BrokerRepealFlag"] = task_data->BrokerRepealFlag;
		data["PlateRepealSerial"] = task_data->PlateRepealSerial;
		data["BankRepealSerial"] = toUtf(task_data->BankRepealSerial);
		data["FutureRepealSerial"] = task_data->FutureRepealSerial;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["FutureSerial"] = task_data->FutureSerial;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["TradeAmount"] = task_data->TradeAmount;
		data["FutureFetchAmount"] = task_data->FutureFetchAmount;
		data["FeePayFlag"] = task_data->FeePayFlag;
		data["CustFee"] = task_data->CustFee;
		data["BrokerFee"] = task_data->BrokerFee;
		data["Message"] = toUtf(task_data->Message);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["TransferStatus"] = task_data->TransferStatus;
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	this->onRtnRepealFromBankToFutureByFutureManual(data);
};

void TdApi::processRtnRepealFromFutureToBankByFutureManual(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRspRepealField *task_data = (CThostFtdcRspRepealField*)task->task_data;
		data["RepealTimeInterval"] = task_data->RepealTimeInterval;
		data["RepealedTimes"] = task_data->RepealedTimes;
		data["BankRepealFlag"] = task_data->BankRepealFlag;
		data["BrokerRepealFlag"] = task_data->BrokerRepealFlag;
		data["PlateRepealSerial"] = task_data->PlateRepealSerial;
		data["BankRepealSerial"] = toUtf(task_data->BankRepealSerial);
		data["FutureRepealSerial"] = task_data->FutureRepealSerial;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["FutureSerial"] = task_data->FutureSerial;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["TradeAmount"] = task_data->TradeAmount;
		data["FutureFetchAmount"] = task_data->FutureFetchAmount;
		data["FeePayFlag"] = task_data->FeePayFlag;
		data["CustFee"] = task_data->CustFee;
		data["BrokerFee"] = task_data->BrokerFee;
		data["Message"] = toUtf(task_data->Message);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["TransferStatus"] = task_data->TransferStatus;
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	this->onRtnRepealFromFutureToBankByFutureManual(data);
};

void TdApi::processRtnQueryBankBalanceByFuture(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcNotifyQueryAccountField *task_data = (CThostFtdcNotifyQueryAccountField*)task->task_data;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["FutureSerial"] = task_data->FutureSerial;
		data["InstallID"] = task_data->InstallID;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["BankUseAmount"] = task_data->BankUseAmount;
		data["BankFetchAmount"] = task_data->BankFetchAmount;
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	this->onRtnQueryBankBalanceByFuture(data);
};

void TdApi::processErrRtnBankToFutureByFuture(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcReqTransferField *task_data = (CThostFtdcReqTransferField*)task->task_data;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["FutureSerial"] = task_data->FutureSerial;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["TradeAmount"] = task_data->TradeAmount;
		data["FutureFetchAmount"] = task_data->FutureFetchAmount;
		data["FeePayFlag"] = task_data->FeePayFlag;
		data["CustFee"] = task_data->CustFee;
		data["BrokerFee"] = task_data->BrokerFee;
		data["Message"] = toUtf(task_data->Message);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["TransferStatus"] = task_data->TransferStatus;
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnBankToFutureByFuture(data, error);
};

void TdApi::processErrRtnFutureToBankByFuture(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcReqTransferField *task_data = (CThostFtdcReqTransferField*)task->task_data;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["FutureSerial"] = task_data->FutureSerial;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["TradeAmount"] = task_data->TradeAmount;
		data["FutureFetchAmount"] = task_data->FutureFetchAmount;
		data["FeePayFlag"] = task_data->FeePayFlag;
		data["CustFee"] = task_data->CustFee;
		data["BrokerFee"] = task_data->BrokerFee;
		data["Message"] = toUtf(task_data->Message);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["TransferStatus"] = task_data->TransferStatus;
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnFutureToBankByFuture(data, error);
};

void TdApi::processErrRtnRepealBankToFutureByFutureManual(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcReqRepealField *task_data = (CThostFtdcReqRepealField*)task->task_data;
		data["RepealTimeInterval"] = task_data->RepealTimeInterval;
		data["RepealedTimes"] = task_data->RepealedTimes;
		data["BankRepealFlag"] = task_data->BankRepealFlag;
		data["BrokerRepealFlag"] = task_data->BrokerRepealFlag;
		data["PlateRepealSerial"] = task_data->PlateRepealSerial;
		data["BankRepealSerial"] = toUtf(task_data->BankRepealSerial);
		data["FutureRepealSerial"] = task_data->FutureRepealSerial;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["FutureSerial"] = task_data->FutureSerial;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["TradeAmount"] = task_data->TradeAmount;
		data["FutureFetchAmount"] = task_data->FutureFetchAmount;
		data["FeePayFlag"] = task_data->FeePayFlag;
		data["CustFee"] = task_data->CustFee;
		data["BrokerFee"] = task_data->BrokerFee;
		data["Message"] = toUtf(task_data->Message);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["TransferStatus"] = task_data->TransferStatus;
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnRepealBankToFutureByFutureManual(data, error);
};

void TdApi::processErrRtnRepealFutureToBankByFutureManual(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcReqRepealField *task_data = (CThostFtdcReqRepealField*)task->task_data;
		data["RepealTimeInterval"] = task_data->RepealTimeInterval;
		data["RepealedTimes"] = task_data->RepealedTimes;
		data["BankRepealFlag"] = task_data->BankRepealFlag;
		data["BrokerRepealFlag"] = task_data->BrokerRepealFlag;
		data["PlateRepealSerial"] = task_data->PlateRepealSerial;
		data["BankRepealSerial"] = toUtf(task_data->BankRepealSerial);
		data["FutureRepealSerial"] = task_data->FutureRepealSerial;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["FutureSerial"] = task_data->FutureSerial;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["TradeAmount"] = task_data->TradeAmount;
		data["FutureFetchAmount"] = task_data->FutureFetchAmount;
		data["FeePayFlag"] = task_data->FeePayFlag;
		data["CustFee"] = task_data->CustFee;
		data["BrokerFee"] = task_data->BrokerFee;
		data["Message"] = toUtf(task_data->Message);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["TransferStatus"] = task_data->TransferStatus;
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnRepealFutureToBankByFutureManual(data, error);
};

void TdApi::processErrRtnQueryBankBalanceByFuture(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcReqQueryAccountField *task_data = (CThostFtdcReqQueryAccountField*)task->task_data;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["FutureSerial"] = task_data->FutureSerial;
		data["InstallID"] = task_data->InstallID;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnQueryBankBalanceByFuture(data, error);
};

void TdApi::processRtnRepealFromBankToFutureByFuture(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRspRepealField *task_data = (CThostFtdcRspRepealField*)task->task_data;
		data["RepealTimeInterval"] = task_data->RepealTimeInterval;
		data["RepealedTimes"] = task_data->RepealedTimes;
		data["BankRepealFlag"] = task_data->BankRepealFlag;
		data["BrokerRepealFlag"] = task_data->BrokerRepealFlag;
		data["PlateRepealSerial"] = task_data->PlateRepealSerial;
		data["BankRepealSerial"] = toUtf(task_data->BankRepealSerial);
		data["FutureRepealSerial"] = task_data->FutureRepealSerial;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["FutureSerial"] = task_data->FutureSerial;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["TradeAmount"] = task_data->TradeAmount;
		data["FutureFetchAmount"] = task_data->FutureFetchAmount;
		data["FeePayFlag"] = task_data->FeePayFlag;
		data["CustFee"] = task_data->CustFee;
		data["BrokerFee"] = task_data->BrokerFee;
		data["Message"] = toUtf(task_data->Message);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["TransferStatus"] = task_data->TransferStatus;
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	this->onRtnRepealFromBankToFutureByFuture(data);
};

void TdApi::processRtnRepealFromFutureToBankByFuture(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRspRepealField *task_data = (CThostFtdcRspRepealField*)task->task_data;
		data["RepealTimeInterval"] = task_data->RepealTimeInterval;
		data["RepealedTimes"] = task_data->RepealedTimes;
		data["BankRepealFlag"] = task_data->BankRepealFlag;
		data["BrokerRepealFlag"] = task_data->BrokerRepealFlag;
		data["PlateRepealSerial"] = task_data->PlateRepealSerial;
		data["BankRepealSerial"] = toUtf(task_data->BankRepealSerial);
		data["FutureRepealSerial"] = task_data->FutureRepealSerial;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["FutureSerial"] = task_data->FutureSerial;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["TradeAmount"] = task_data->TradeAmount;
		data["FutureFetchAmount"] = task_data->FutureFetchAmount;
		data["FeePayFlag"] = task_data->FeePayFlag;
		data["CustFee"] = task_data->CustFee;
		data["BrokerFee"] = task_data->BrokerFee;
		data["Message"] = toUtf(task_data->Message);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["TransferStatus"] = task_data->TransferStatus;
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	this->onRtnRepealFromFutureToBankByFuture(data);
};

void TdApi::processRspFromBankToFutureByFuture(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcReqTransferField *task_data = (CThostFtdcReqTransferField*)task->task_data;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["FutureSerial"] = task_data->FutureSerial;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["TradeAmount"] = task_data->TradeAmount;
		data["FutureFetchAmount"] = task_data->FutureFetchAmount;
		data["FeePayFlag"] = task_data->FeePayFlag;
		data["CustFee"] = task_data->CustFee;
		data["BrokerFee"] = task_data->BrokerFee;
		data["Message"] = toUtf(task_data->Message);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["TransferStatus"] = task_data->TransferStatus;
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspFromBankToFutureByFuture(data, error, task->task_id, task->task_last);
};

void TdApi::processRspFromFutureToBankByFuture(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcReqTransferField *task_data = (CThostFtdcReqTransferField*)task->task_data;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["FutureSerial"] = task_data->FutureSerial;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["TradeAmount"] = task_data->TradeAmount;
		data["FutureFetchAmount"] = task_data->FutureFetchAmount;
		data["FeePayFlag"] = task_data->FeePayFlag;
		data["CustFee"] = task_data->CustFee;
		data["BrokerFee"] = task_data->BrokerFee;
		data["Message"] = toUtf(task_data->Message);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["TransferStatus"] = task_data->TransferStatus;
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspFromFutureToBankByFuture(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQueryBankAccountMoneyByFuture(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcReqQueryAccountField *task_data = (CThostFtdcReqQueryAccountField*)task->task_data;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["CustType"] = task_data->CustType;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["FutureSerial"] = task_data->FutureSerial;
		data["InstallID"] = task_data->InstallID;
		data["UserID"] = toUtf(task_data->UserID);
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["RequestID"] = task_data->RequestID;
		data["TID"] = task_data->TID;
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQueryBankAccountMoneyByFuture(data, error, task->task_id, task->task_last);
};

void TdApi::processRtnOpenAccountByBank(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcOpenAccountField *task_data = (CThostFtdcOpenAccountField*)task->task_data;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["Gender"] = task_data->Gender;
		data["CountryCode"] = toUtf(task_data->CountryCode);
		data["CustType"] = task_data->CustType;
		data["Address"] = toUtf(task_data->Address);
		data["ZipCode"] = toUtf(task_data->ZipCode);
		data["Telephone"] = toUtf(task_data->Telephone);
		data["MobilePhone"] = toUtf(task_data->MobilePhone);
		data["Fax"] = toUtf(task_data->Fax);
		data["EMail"] = toUtf(task_data->EMail);
		data["MoneyAccountStatus"] = task_data->MoneyAccountStatus;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["CashExchangeCode"] = task_data->CashExchangeCode;
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["TID"] = task_data->TID;
		data["UserID"] = toUtf(task_data->UserID);
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	this->onRtnOpenAccountByBank(data);
};

void TdApi::processRtnCancelAccountByBank(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcCancelAccountField *task_data = (CThostFtdcCancelAccountField*)task->task_data;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["Gender"] = task_data->Gender;
		data["CountryCode"] = toUtf(task_data->CountryCode);
		data["CustType"] = task_data->CustType;
		data["Address"] = toUtf(task_data->Address);
		data["ZipCode"] = toUtf(task_data->ZipCode);
		data["Telephone"] = toUtf(task_data->Telephone);
		data["MobilePhone"] = toUtf(task_data->MobilePhone);
		data["Fax"] = toUtf(task_data->Fax);
		data["EMail"] = toUtf(task_data->EMail);
		data["MoneyAccountStatus"] = task_data->MoneyAccountStatus;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["InstallID"] = task_data->InstallID;
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["CashExchangeCode"] = task_data->CashExchangeCode;
		data["Digest"] = toUtf(task_data->Digest);
		data["BankAccType"] = task_data->BankAccType;
		data["DeviceID"] = toUtf(task_data->DeviceID);
		data["BankSecuAccType"] = task_data->BankSecuAccType;
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankSecuAcc"] = toUtf(task_data->BankSecuAcc);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["OperNo"] = toUtf(task_data->OperNo);
		data["TID"] = task_data->TID;
		data["UserID"] = toUtf(task_data->UserID);
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	this->onRtnCancelAccountByBank(data);
};

void TdApi::processRtnChangeAccountByBank(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcChangeAccountField *task_data = (CThostFtdcChangeAccountField*)task->task_data;
		data["TradeCode"] = toUtf(task_data->TradeCode);
		data["BankID"] = toUtf(task_data->BankID);
		data["BankBranchID"] = toUtf(task_data->BankBranchID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["BrokerBranchID"] = toUtf(task_data->BrokerBranchID);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["TradeTime"] = toUtf(task_data->TradeTime);
		data["BankSerial"] = toUtf(task_data->BankSerial);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["PlateSerial"] = task_data->PlateSerial;
		data["LastFragment"] = task_data->LastFragment;
		data["SessionID"] = task_data->SessionID;
		data["CustomerName"] = toUtf(task_data->CustomerName);
		data["IdCardType"] = task_data->IdCardType;
		data["IdentifiedCardNo"] = toUtf(task_data->IdentifiedCardNo);
		data["Gender"] = task_data->Gender;
		data["CountryCode"] = toUtf(task_data->CountryCode);
		data["CustType"] = task_data->CustType;
		data["Address"] = toUtf(task_data->Address);
		data["ZipCode"] = toUtf(task_data->ZipCode);
		data["Telephone"] = toUtf(task_data->Telephone);
		data["MobilePhone"] = toUtf(task_data->MobilePhone);
		data["Fax"] = toUtf(task_data->Fax);
		data["EMail"] = toUtf(task_data->EMail);
		data["MoneyAccountStatus"] = task_data->MoneyAccountStatus;
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["BankPassWord"] = toUtf(task_data->BankPassWord);
		data["NewBankAccount"] = toUtf(task_data->NewBankAccount);
		data["NewBankPassWord"] = toUtf(task_data->NewBankPassWord);
		data["AccountID"] = toUtf(task_data->AccountID);
		data["Password"] = toUtf(task_data->Password);
		data["BankAccType"] = task_data->BankAccType;
		data["InstallID"] = task_data->InstallID;
		data["VerifyCertNoFlag"] = task_data->VerifyCertNoFlag;
		data["CurrencyID"] = toUtf(task_data->CurrencyID);
		data["BrokerIDByBank"] = toUtf(task_data->BrokerIDByBank);
		data["BankPwdFlag"] = task_data->BankPwdFlag;
		data["SecuPwdFlag"] = task_data->SecuPwdFlag;
		data["TID"] = task_data->TID;
		data["Digest"] = toUtf(task_data->Digest);
		data["ErrorID"] = task_data->ErrorID;
		data["ErrorMsg"] = toUtf(task_data->ErrorMsg);
		data["LongCustomerName"] = toUtf(task_data->LongCustomerName);
		delete task_data;
	}
	this->onRtnChangeAccountByBank(data);
};

void TdApi::processRspQryClassifiedInstrument(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInstrumentField *task_data = (CThostFtdcInstrumentField*)task->task_data;
		data["reserve1"] = toUtf(task_data->reserve1);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentName"] = toUtf(task_data->InstrumentName);
		data["reserve2"] = toUtf(task_data->reserve2);
		data["reserve3"] = toUtf(task_data->reserve3);
		data["ProductClass"] = task_data->ProductClass;
		data["DeliveryYear"] = task_data->DeliveryYear;
		data["DeliveryMonth"] = task_data->DeliveryMonth;
		data["MaxMarketOrderVolume"] = task_data->MaxMarketOrderVolume;
		data["MinMarketOrderVolume"] = task_data->MinMarketOrderVolume;
		data["MaxLimitOrderVolume"] = task_data->MaxLimitOrderVolume;
		data["MinLimitOrderVolume"] = task_data->MinLimitOrderVolume;
		data["VolumeMultiple"] = task_data->VolumeMultiple;
		data["PriceTick"] = task_data->PriceTick;
		data["CreateDate"] = toUtf(task_data->CreateDate);
		data["OpenDate"] = toUtf(task_data->OpenDate);
		data["ExpireDate"] = toUtf(task_data->ExpireDate);
		data["StartDelivDate"] = toUtf(task_data->StartDelivDate);
		data["EndDelivDate"] = toUtf(task_data->EndDelivDate);
		data["InstLifePhase"] = task_data->InstLifePhase;
		data["IsTrading"] = task_data->IsTrading;
		data["PositionType"] = task_data->PositionType;
		data["PositionDateType"] = task_data->PositionDateType;
		data["LongMarginRatio"] = task_data->LongMarginRatio;
		data["ShortMarginRatio"] = task_data->ShortMarginRatio;
		data["MaxMarginSideAlgorithm"] = task_data->MaxMarginSideAlgorithm;
		data["reserve4"] = toUtf(task_data->reserve4);
		data["StrikePrice"] = task_data->StrikePrice;
		data["OptionsType"] = task_data->OptionsType;
		data["UnderlyingMultiple"] = task_data->UnderlyingMultiple;
		data["CombinationType"] = task_data->CombinationType;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["ProductID"] = toUtf(task_data->ProductID);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryClassifiedInstrument(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryCombPromotionParam(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcCombPromotionParamField *task_data = (CThostFtdcCombPromotionParamField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["CombHedgeFlag"] = toUtf(task_data->CombHedgeFlag);
		data["Xparameter"] = task_data->Xparameter;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombPromotionParam(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryRiskSettleInvstPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRiskSettleInvstPositionField *task_data = (CThostFtdcRiskSettleInvstPositionField*)task->task_data;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["PosiDirection"] = task_data->PosiDirection;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["PositionDate"] = task_data->PositionDate;
		data["YdPosition"] = task_data->YdPosition;
		data["Position"] = task_data->Position;
		data["LongFrozen"] = task_data->LongFrozen;
		data["ShortFrozen"] = task_data->ShortFrozen;
		data["LongFrozenAmount"] = task_data->LongFrozenAmount;
		data["ShortFrozenAmount"] = task_data->ShortFrozenAmount;
		data["OpenVolume"] = task_data->OpenVolume;
		data["CloseVolume"] = task_data->CloseVolume;
		data["OpenAmount"] = task_data->OpenAmount;
		data["CloseAmount"] = task_data->CloseAmount;
		data["PositionCost"] = task_data->PositionCost;
		data["PreMargin"] = task_data->PreMargin;
		data["UseMargin"] = task_data->UseMargin;
		data["FrozenMargin"] = task_data->FrozenMargin;
		data["FrozenCash"] = task_data->FrozenCash;
		data["FrozenCommission"] = task_data->FrozenCommission;
		data["CashIn"] = task_data->CashIn;
		data["Commission"] = task_data->Commission;
		data["CloseProfit"] = task_data->CloseProfit;
		data["PositionProfit"] = task_data->PositionProfit;
		data["PreSettlementPrice"] = task_data->PreSettlementPrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["OpenCost"] = task_data->OpenCost;
		data["ExchangeMargin"] = task_data->ExchangeMargin;
		data["CombPosition"] = task_data->CombPosition;
		data["CombLongFrozen"] = task_data->CombLongFrozen;
		data["CombShortFrozen"] = task_data->CombShortFrozen;
		data["CloseProfitByDate"] = task_data->CloseProfitByDate;
		data["CloseProfitByTrade"] = task_data->CloseProfitByTrade;
		data["TodayPosition"] = task_data->TodayPosition;
		data["MarginRateByMoney"] = task_data->MarginRateByMoney;
		data["MarginRateByVolume"] = task_data->MarginRateByVolume;
		data["StrikeFrozen"] = task_data->StrikeFrozen;
		data["StrikeFrozenAmount"] = task_data->StrikeFrozenAmount;
		data["AbandonFrozen"] = task_data->AbandonFrozen;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["YdStrikeFrozen"] = task_data->YdStrikeFrozen;
		data["InvestUnitID"] = toUtf(task_data->InvestUnitID);
		data["PositionCostOffset"] = task_data->PositionCostOffset;
		data["TasPosition"] = task_data->TasPosition;
		data["TasPositionCost"] = task_data->TasPositionCost;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryRiskSettleInvstPosition(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryRiskSettleProductStatus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRiskSettleProductStatusField *task_data = (CThostFtdcRiskSettleProductStatusField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ProductID"] = toUtf(task_data->ProductID);
		data["ProductStatus"] = task_data->ProductStatus;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryRiskSettleProductStatus(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQrySPBMFutureParameter(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSPBMFutureParameterField *task_data = (CThostFtdcSPBMFutureParameterField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ProdFamilyCode"] = toUtf(task_data->ProdFamilyCode);
		data["Cvf"] = task_data->Cvf;
		data["TimeRange"] = task_data->TimeRange;
		data["MarginRate"] = task_data->MarginRate;
		data["LockRateX"] = task_data->LockRateX;
		data["AddOnRate"] = task_data->AddOnRate;
		data["PreSettlementPrice"] = task_data->PreSettlementPrice;
		data["AddOnLockRateX2"] = task_data->AddOnLockRateX2;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySPBMFutureParameter(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQrySPBMOptionParameter(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSPBMOptionParameterField *task_data = (CThostFtdcSPBMOptionParameterField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ProdFamilyCode"] = toUtf(task_data->ProdFamilyCode);
		data["Cvf"] = task_data->Cvf;
		data["DownPrice"] = task_data->DownPrice;
		data["Delta"] = task_data->Delta;
		data["SlimiDelta"] = task_data->SlimiDelta;
		data["PreSettlementPrice"] = task_data->PreSettlementPrice;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySPBMOptionParameter(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQrySPBMIntraParameter(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSPBMIntraParameterField *task_data = (CThostFtdcSPBMIntraParameterField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ProdFamilyCode"] = toUtf(task_data->ProdFamilyCode);
		data["IntraRateY"] = task_data->IntraRateY;
		data["AddOnIntraRateY2"] = task_data->AddOnIntraRateY2;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySPBMIntraParameter(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQrySPBMInterParameter(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSPBMInterParameterField *task_data = (CThostFtdcSPBMInterParameterField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["SpreadId"] = task_data->SpreadId;
		data["InterRateZ"] = task_data->InterRateZ;
		data["Leg1ProdFamilyCode"] = toUtf(task_data->Leg1ProdFamilyCode);
		data["Leg2ProdFamilyCode"] = toUtf(task_data->Leg2ProdFamilyCode);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySPBMInterParameter(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQrySPBMPortfDefinition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSPBMPortfDefinitionField *task_data = (CThostFtdcSPBMPortfDefinitionField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["PortfolioDefID"] = task_data->PortfolioDefID;
		data["ProdFamilyCode"] = toUtf(task_data->ProdFamilyCode);
		data["IsSPBM"] = task_data->IsSPBM;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySPBMPortfDefinition(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQrySPBMInvestorPortfDef(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSPBMInvestorPortfDefField *task_data = (CThostFtdcSPBMInvestorPortfDefField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["PortfolioDefID"] = task_data->PortfolioDefID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySPBMInvestorPortfDef(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInvestorPortfMarginRatio(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInvestorPortfMarginRatioField *task_data = (CThostFtdcInvestorPortfMarginRatioField*)task->task_data;
		data["InvestorRange"] = task_data->InvestorRange;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["MarginRatio"] = task_data->MarginRatio;
		data["ProductGroupID"] = toUtf(task_data->ProductGroupID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorPortfMarginRatio(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInvestorProdSPBMDetail(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInvestorProdSPBMDetailField *task_data = (CThostFtdcInvestorProdSPBMDetailField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ProdFamilyCode"] = toUtf(task_data->ProdFamilyCode);
		data["IntraInstrMargin"] = task_data->IntraInstrMargin;
		data["BCollectingMargin"] = task_data->BCollectingMargin;
		data["SCollectingMargin"] = task_data->SCollectingMargin;
		data["IntraProdMargin"] = task_data->IntraProdMargin;
		data["NetMargin"] = task_data->NetMargin;
		data["InterProdMargin"] = task_data->InterProdMargin;
		data["SingleMargin"] = task_data->SingleMargin;
		data["AddOnMargin"] = task_data->AddOnMargin;
		data["DeliveryMargin"] = task_data->DeliveryMargin;
		data["CallOptionMinRisk"] = task_data->CallOptionMinRisk;
		data["PutOptionMinRisk"] = task_data->PutOptionMinRisk;
		data["OptionMinRisk"] = task_data->OptionMinRisk;
		data["OptionValueOffset"] = task_data->OptionValueOffset;
		data["OptionRoyalty"] = task_data->OptionRoyalty;
		data["RealOptionValueOffset"] = task_data->RealOptionValueOffset;
		data["Margin"] = task_data->Margin;
		data["ExchMargin"] = task_data->ExchMargin;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorProdSPBMDetail(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInvestorCommoditySPMMMargin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInvestorCommoditySPMMMarginField *task_data = (CThostFtdcInvestorCommoditySPMMMarginField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["CommodityID"] = toUtf(task_data->CommodityID);
		data["MarginBeforeDiscount"] = task_data->MarginBeforeDiscount;
		data["MarginNoDiscount"] = task_data->MarginNoDiscount;
		data["LongPosRisk"] = task_data->LongPosRisk;
		data["LongOpenFrozenRisk"] = task_data->LongOpenFrozenRisk;
		data["LongCloseFrozenRisk"] = task_data->LongCloseFrozenRisk;
		data["ShortPosRisk"] = task_data->ShortPosRisk;
		data["ShortOpenFrozenRisk"] = task_data->ShortOpenFrozenRisk;
		data["ShortCloseFrozenRisk"] = task_data->ShortCloseFrozenRisk;
		data["IntraCommodityRate"] = task_data->IntraCommodityRate;
		data["OptionDiscountRate"] = task_data->OptionDiscountRate;
		data["PosDiscount"] = task_data->PosDiscount;
		data["OpenFrozenDiscount"] = task_data->OpenFrozenDiscount;
		data["NetRisk"] = task_data->NetRisk;
		data["CloseFrozenMargin"] = task_data->CloseFrozenMargin;
		data["FrozenCommission"] = task_data->FrozenCommission;
		data["Commission"] = task_data->Commission;
		data["FrozenCash"] = task_data->FrozenCash;
		data["CashIn"] = task_data->CashIn;
		data["StrikeFrozenMargin"] = task_data->StrikeFrozenMargin;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorCommoditySPMMMargin(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInvestorCommodityGroupSPMMMargin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInvestorCommodityGroupSPMMMarginField *task_data = (CThostFtdcInvestorCommodityGroupSPMMMarginField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["CommodityGroupID"] = toUtf(task_data->CommodityGroupID);
		data["MarginBeforeDiscount"] = task_data->MarginBeforeDiscount;
		data["MarginNoDiscount"] = task_data->MarginNoDiscount;
		data["LongRisk"] = task_data->LongRisk;
		data["ShortRisk"] = task_data->ShortRisk;
		data["CloseFrozenMargin"] = task_data->CloseFrozenMargin;
		data["InterCommodityRate"] = task_data->InterCommodityRate;
		data["MiniMarginRatio"] = task_data->MiniMarginRatio;
		data["AdjustRatio"] = task_data->AdjustRatio;
		data["IntraCommodityDiscount"] = task_data->IntraCommodityDiscount;
		data["InterCommodityDiscount"] = task_data->InterCommodityDiscount;
		data["ExchMargin"] = task_data->ExchMargin;
		data["InvestorMargin"] = task_data->InvestorMargin;
		data["FrozenCommission"] = task_data->FrozenCommission;
		data["Commission"] = task_data->Commission;
		data["FrozenCash"] = task_data->FrozenCash;
		data["CashIn"] = task_data->CashIn;
		data["StrikeFrozenMargin"] = task_data->StrikeFrozenMargin;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorCommodityGroupSPMMMargin(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQrySPMMInstParam(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSPMMInstParamField *task_data = (CThostFtdcSPMMInstParamField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["InstMarginCalID"] = task_data->InstMarginCalID;
		data["CommodityID"] = toUtf(task_data->CommodityID);
		data["CommodityGroupID"] = toUtf(task_data->CommodityGroupID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySPMMInstParam(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQrySPMMProductParam(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSPMMProductParamField *task_data = (CThostFtdcSPMMProductParamField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ProductID"] = toUtf(task_data->ProductID);
		data["CommodityID"] = toUtf(task_data->CommodityID);
		data["CommodityGroupID"] = toUtf(task_data->CommodityGroupID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySPMMProductParam(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQrySPBMAddprocessInterParameter(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSPBMAddOnInterParameterField *task_data = (CThostFtdcSPBMAddOnInterParameterField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["SpreadId"] = task_data->SpreadId;
		data["AddOnInterRateZ2"] = task_data->AddOnInterRateZ2;
		data["Leg1ProdFamilyCode"] = toUtf(task_data->Leg1ProdFamilyCode);
		data["Leg2ProdFamilyCode"] = toUtf(task_data->Leg2ProdFamilyCode);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySPBMAddonInterParameter(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryRCAMSCombProductInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRCAMSCombProductInfoField *task_data = (CThostFtdcRCAMSCombProductInfoField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ProductID"] = toUtf(task_data->ProductID);
		data["CombProductID"] = toUtf(task_data->CombProductID);
		data["ProductGroupID"] = toUtf(task_data->ProductGroupID);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryRCAMSCombProductInfo(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryRCAMSInstrParameter(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRCAMSInstrParameterField *task_data = (CThostFtdcRCAMSInstrParameterField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ProductID"] = toUtf(task_data->ProductID);
		data["HedgeRate"] = task_data->HedgeRate;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryRCAMSInstrParameter(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryRCAMSIntraParameter(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRCAMSIntraParameterField *task_data = (CThostFtdcRCAMSIntraParameterField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["CombProductID"] = toUtf(task_data->CombProductID);
		data["HedgeRate"] = task_data->HedgeRate;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryRCAMSIntraParameter(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryRCAMSInterParameter(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRCAMSInterParameterField *task_data = (CThostFtdcRCAMSInterParameterField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ProductGroupID"] = toUtf(task_data->ProductGroupID);
		data["Priority"] = task_data->Priority;
		data["CreditRate"] = task_data->CreditRate;
		data["CombProduct1"] = toUtf(task_data->CombProduct1);
		data["CombProduct2"] = toUtf(task_data->CombProduct2);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryRCAMSInterParameter(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryRCAMSShortOptAdjustParam(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRCAMSShortOptAdjustParamField *task_data = (CThostFtdcRCAMSShortOptAdjustParamField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["CombProductID"] = toUtf(task_data->CombProductID);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["AdjustValue"] = task_data->AdjustValue;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryRCAMSShortOptAdjustParam(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryRCAMSInvestorCombPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRCAMSInvestorCombPositionField *task_data = (CThostFtdcRCAMSInvestorCombPositionField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["PosiDirection"] = task_data->PosiDirection;
		data["CombInstrumentID"] = toUtf(task_data->CombInstrumentID);
		data["LegID"] = task_data->LegID;
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["TotalAmt"] = task_data->TotalAmt;
		data["ExchMargin"] = task_data->ExchMargin;
		data["Margin"] = task_data->Margin;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryRCAMSInvestorCombPosition(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInvestorProdRCAMSMargin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInvestorProdRCAMSMarginField *task_data = (CThostFtdcInvestorProdRCAMSMarginField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["CombProductID"] = toUtf(task_data->CombProductID);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["ProductGroupID"] = toUtf(task_data->ProductGroupID);
		data["RiskBeforeDiscount"] = task_data->RiskBeforeDiscount;
		data["IntraInstrRisk"] = task_data->IntraInstrRisk;
		data["BPosRisk"] = task_data->BPosRisk;
		data["SPosRisk"] = task_data->SPosRisk;
		data["IntraProdRisk"] = task_data->IntraProdRisk;
		data["NetRisk"] = task_data->NetRisk;
		data["InterProdRisk"] = task_data->InterProdRisk;
		data["ShortOptRiskAdj"] = task_data->ShortOptRiskAdj;
		data["OptionRoyalty"] = task_data->OptionRoyalty;
		data["MMSACloseFrozenMargin"] = task_data->MMSACloseFrozenMargin;
		data["CloseCombFrozenMargin"] = task_data->CloseCombFrozenMargin;
		data["CloseFrozenMargin"] = task_data->CloseFrozenMargin;
		data["MMSAOpenFrozenMargin"] = task_data->MMSAOpenFrozenMargin;
		data["DeliveryOpenFrozenMargin"] = task_data->DeliveryOpenFrozenMargin;
		data["OpenFrozenMargin"] = task_data->OpenFrozenMargin;
		data["UseFrozenMargin"] = task_data->UseFrozenMargin;
		data["MMSAExchMargin"] = task_data->MMSAExchMargin;
		data["DeliveryExchMargin"] = task_data->DeliveryExchMargin;
		data["CombExchMargin"] = task_data->CombExchMargin;
		data["ExchMargin"] = task_data->ExchMargin;
		data["UseMargin"] = task_data->UseMargin;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorProdRCAMSMargin(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryRULEInstrParameter(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRULEInstrParameterField *task_data = (CThostFtdcRULEInstrParameterField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["InstrumentClass"] = task_data->InstrumentClass;
		data["StdInstrumentID"] = toUtf(task_data->StdInstrumentID);
		data["BSpecRatio"] = task_data->BSpecRatio;
		data["SSpecRatio"] = task_data->SSpecRatio;
		data["BHedgeRatio"] = task_data->BHedgeRatio;
		data["SHedgeRatio"] = task_data->SHedgeRatio;
		data["BAddOnMargin"] = task_data->BAddOnMargin;
		data["SAddOnMargin"] = task_data->SAddOnMargin;
		data["CommodityGroupID"] = task_data->CommodityGroupID;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryRULEInstrParameter(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryRULEIntraParameter(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRULEIntraParameterField *task_data = (CThostFtdcRULEIntraParameterField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ProdFamilyCode"] = toUtf(task_data->ProdFamilyCode);
		data["StdInstrumentID"] = toUtf(task_data->StdInstrumentID);
		data["StdInstrMargin"] = task_data->StdInstrMargin;
		data["UsualIntraRate"] = task_data->UsualIntraRate;
		data["DeliveryIntraRate"] = task_data->DeliveryIntraRate;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryRULEIntraParameter(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryRULEInterParameter(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRULEInterParameterField *task_data = (CThostFtdcRULEInterParameterField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["SpreadId"] = task_data->SpreadId;
		data["InterRate"] = task_data->InterRate;
		data["Leg1ProdFamilyCode"] = toUtf(task_data->Leg1ProdFamilyCode);
		data["Leg2ProdFamilyCode"] = toUtf(task_data->Leg2ProdFamilyCode);
		data["Leg1PropFactor"] = task_data->Leg1PropFactor;
		data["Leg2PropFactor"] = task_data->Leg2PropFactor;
		data["CommodityGroupID"] = task_data->CommodityGroupID;
		data["CommodityGroupName"] = toUtf(task_data->CommodityGroupName);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryRULEInterParameter(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInvestorProdRULEMargin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInvestorProdRULEMarginField *task_data = (CThostFtdcInvestorProdRULEMarginField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["ProdFamilyCode"] = toUtf(task_data->ProdFamilyCode);
		data["InstrumentClass"] = task_data->InstrumentClass;
		data["CommodityGroupID"] = task_data->CommodityGroupID;
		data["BStdPosition"] = task_data->BStdPosition;
		data["SStdPosition"] = task_data->SStdPosition;
		data["BStdOpenFrozen"] = task_data->BStdOpenFrozen;
		data["SStdOpenFrozen"] = task_data->SStdOpenFrozen;
		data["BStdCloseFrozen"] = task_data->BStdCloseFrozen;
		data["SStdCloseFrozen"] = task_data->SStdCloseFrozen;
		data["IntraProdStdPosition"] = task_data->IntraProdStdPosition;
		data["NetStdPosition"] = task_data->NetStdPosition;
		data["InterProdStdPosition"] = task_data->InterProdStdPosition;
		data["SingleStdPosition"] = task_data->SingleStdPosition;
		data["IntraProdMargin"] = task_data->IntraProdMargin;
		data["InterProdMargin"] = task_data->InterProdMargin;
		data["SingleMargin"] = task_data->SingleMargin;
		data["NonCombMargin"] = task_data->NonCombMargin;
		data["AddOnMargin"] = task_data->AddOnMargin;
		data["ExchMargin"] = task_data->ExchMargin;
		data["AddOnFrozenMargin"] = task_data->AddOnFrozenMargin;
		data["OpenFrozenMargin"] = task_data->OpenFrozenMargin;
		data["CloseFrozenMargin"] = task_data->CloseFrozenMargin;
		data["Margin"] = task_data->Margin;
		data["FrozenMargin"] = task_data->FrozenMargin;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorProdRULEMargin(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInvestorPortfSetting(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInvestorPortfSettingField *task_data = (CThostFtdcInvestorPortfSettingField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["UsePortf"] = task_data->UsePortf;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorPortfSetting(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryInvestorInfoCommRec(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInvestorInfoCommRecField *task_data = (CThostFtdcInvestorInfoCommRecField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["OrderCount"] = task_data->OrderCount;
		data["OrderActionCount"] = task_data->OrderActionCount;
		data["ForQuoteCnt"] = task_data->ForQuoteCnt;
		data["InfoComm"] = task_data->InfoComm;
		data["IsOptSeries"] = task_data->IsOptSeries;
		data["ProductID"] = toUtf(task_data->ProductID);
		data["InfoCnt"] = task_data->InfoCnt;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryInvestorInfoCommRec(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryCombLeg(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcCombLegField *task_data = (CThostFtdcCombLegField*)task->task_data;
		data["CombInstrumentID"] = toUtf(task_data->CombInstrumentID);
		data["LegID"] = task_data->LegID;
		data["LegInstrumentID"] = toUtf(task_data->LegInstrumentID);
		data["Direction"] = task_data->Direction;
		data["LegMultiple"] = task_data->LegMultiple;
		data["ImplyLevel"] = task_data->ImplyLevel;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryCombLeg(data, error, task->task_id, task->task_last);
};

void TdApi::processRspOffsetSetting(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputOffsetSettingField *task_data = (CThostFtdcInputOffsetSettingField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["ProductID"] = toUtf(task_data->ProductID);
		data["OffsetType"] = task_data->OffsetType;
		data["Volume"] = task_data->Volume;
		data["IsOffset"] = task_data->IsOffset;
		data["RequestID"] = task_data->RequestID;
		data["UserID"] = toUtf(task_data->UserID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOffsetSetting(data, error, task->task_id, task->task_last);
};

void TdApi::processRspCancelOffsetSetting(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputOffsetSettingField *task_data = (CThostFtdcInputOffsetSettingField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["ProductID"] = toUtf(task_data->ProductID);
		data["OffsetType"] = task_data->OffsetType;
		data["Volume"] = task_data->Volume;
		data["IsOffset"] = task_data->IsOffset;
		data["RequestID"] = task_data->RequestID;
		data["UserID"] = toUtf(task_data->UserID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspCancelOffsetSetting(data, error, task->task_id, task->task_last);
};

void TdApi::processRtnOffsetSetting(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcOffsetSettingField *task_data = (CThostFtdcOffsetSettingField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["ProductID"] = toUtf(task_data->ProductID);
		data["OffsetType"] = task_data->OffsetType;
		data["Volume"] = task_data->Volume;
		data["IsOffset"] = task_data->IsOffset;
		data["RequestID"] = task_data->RequestID;
		data["UserID"] = toUtf(task_data->UserID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["ExchangeSerialNo"] = toUtf(task_data->ExchangeSerialNo);
		data["ExchangeProductID"] = toUtf(task_data->ExchangeProductID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["OrderSubmitStatus"] = task_data->OrderSubmitStatus;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["ExecResult"] = task_data->ExecResult;
		data["SequenceNo"] = task_data->SequenceNo;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ActiveUserID"] = toUtf(task_data->ActiveUserID);
		data["BrokerOffsetSettingSeq"] = task_data->BrokerOffsetSettingSeq;
		data["ApplySrc"] = task_data->ApplySrc;
		delete task_data;
	}
	this->onRtnOffsetSetting(data);
};

void TdApi::processErrRtnOffsetSetting(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcInputOffsetSettingField *task_data = (CThostFtdcInputOffsetSettingField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["ProductID"] = toUtf(task_data->ProductID);
		data["OffsetType"] = task_data->OffsetType;
		data["Volume"] = task_data->Volume;
		data["IsOffset"] = task_data->IsOffset;
		data["RequestID"] = task_data->RequestID;
		data["UserID"] = toUtf(task_data->UserID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnOffsetSetting(data, error);
};

void TdApi::processErrRtnCancelOffsetSetting(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcCancelOffsetSettingField *task_data = (CThostFtdcCancelOffsetSettingField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["ProductID"] = toUtf(task_data->ProductID);
		data["OffsetType"] = task_data->OffsetType;
		data["Volume"] = task_data->Volume;
		data["IsOffset"] = task_data->IsOffset;
		data["RequestID"] = task_data->RequestID;
		data["UserID"] = toUtf(task_data->UserID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["ExchangeSerialNo"] = toUtf(task_data->ExchangeSerialNo);
		data["ExchangeProductID"] = toUtf(task_data->ExchangeProductID);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["OrderActionStatus"] = task_data->OrderActionStatus;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ActionLocalID"] = toUtf(task_data->ActionLocalID);
		data["ActionDate"] = toUtf(task_data->ActionDate);
		data["ActionTime"] = toUtf(task_data->ActionTime);
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onErrRtnCancelOffsetSetting(data, error);
};

void TdApi::processRspQryOffsetSetting(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcOffsetSettingField *task_data = (CThostFtdcOffsetSettingField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["ProductID"] = toUtf(task_data->ProductID);
		data["OffsetType"] = task_data->OffsetType;
		data["Volume"] = task_data->Volume;
		data["IsOffset"] = task_data->IsOffset;
		data["RequestID"] = task_data->RequestID;
		data["UserID"] = toUtf(task_data->UserID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["IPAddress"] = toUtf(task_data->IPAddress);
		data["MacAddress"] = toUtf(task_data->MacAddress);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["ExchangeSerialNo"] = toUtf(task_data->ExchangeSerialNo);
		data["ExchangeProductID"] = toUtf(task_data->ExchangeProductID);
		data["ParticipantID"] = toUtf(task_data->ParticipantID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["TraderID"] = toUtf(task_data->TraderID);
		data["InstallID"] = task_data->InstallID;
		data["OrderSubmitStatus"] = task_data->OrderSubmitStatus;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["SettlementID"] = task_data->SettlementID;
		data["InsertDate"] = toUtf(task_data->InsertDate);
		data["InsertTime"] = toUtf(task_data->InsertTime);
		data["CancelTime"] = toUtf(task_data->CancelTime);
		data["ExecResult"] = task_data->ExecResult;
		data["SequenceNo"] = task_data->SequenceNo;
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["StatusMsg"] = toUtf(task_data->StatusMsg);
		data["ActiveUserID"] = toUtf(task_data->ActiveUserID);
		data["BrokerOffsetSettingSeq"] = task_data->BrokerOffsetSettingSeq;
		data["ApplySrc"] = task_data->ApplySrc;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOffsetSetting(data, error, task->task_id, task->task_last);
};


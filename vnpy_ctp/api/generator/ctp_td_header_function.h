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

int reqQryUserSession(const dict &req, int reqid);

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

int reqQryInvestorInfoCommRec(const dict &req, int reqid);

int reqQryCombLeg(const dict &req, int reqid);

int reqOffsetSetting(const dict &req, int reqid);

int reqCancelOffsetSetting(const dict &req, int reqid);

int reqQryOffsetSetting(const dict &req, int reqid);


from time import sleep
from threading import Condition
from collections.abc import Generator

import pytest

from vnpy_ctp.api import (
    TdApi,
    THOST_FTDC_OPT_LimitPrice,
    THOST_FTDC_TC_GFD,
    THOST_FTDC_VC_AV,
    THOST_FTDC_D_Buy,
    THOST_FTDC_OF_Open,
    THOST_FTDC_HF_Speculation,
    THOST_FTDC_CC_Immediately,
    THOST_FTDC_FCC_NotForceClose,
    THOST_FTDC_OST_Canceled,
    THOST_FTDC_OST_AllTraded,
    THOST_FTDC_AF_Delete
)


# 测试参数
SYMBOL = "rb2601"
EXCHANGE = "SHFE"
ALL_TRADED_PRICE = 3128
NOT_TRADED_PRICE = 3118
VOLUME = 2


TD_SETTING = {
    "UserID": "xxx",                             # 用户名
    "Password": "xxx",                           # 密码
    "BrokerID": "9999",                          # 经纪商代码
    "AppID": "simnow_client_test",               # 产品名称
    "AuthCode": "0000000000000000"               # 授权码
}
TD_ADDRESS = "tcp://180.168.146.187:10130"       # 交易服务器地址
WAIT_TIME = 10                                   # 回调等待时间


class MyTdApi(TdApi):
    """继承实现API接口类"""

    def __init__(self) -> None:
        """构造函数"""
        super().__init__()

        self.callback_result: list = []
        self.callback_done: Condition = Condition()

        self.reqid: int = 0
        self.order_ref: int = 0
        self.connect_status: bool = False
        self.login_status: bool = False
        self.auth_status: bool = False

        self.order_data: dict[str, dict] = {}
        self.trade_data: dict[str, dict] = {}

    def onFrontConnected(self) -> None:
        """服务器连接成功回报"""
        self.connect_status = True

    def onFrontDisconnected(self, reason: int) -> None:
        """服务器连接断开回报"""
        self.login_status = False

    def onRspAuthenticate(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """用户授权验证回报"""
        self.callback_result = [data, error, reqid, last]

        with self.callback_done:
            self.callback_done.notify()

    def onRspUserLogin(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """用户登录请求回报"""
        self.callback_result = [data, error, reqid, last]

        with self.callback_done:
            self.callback_done.notify()

    def onRspOrderInsert(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """委托下单回报"""
        pass

    def onRspOrderAction(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """委托撤单回报"""
        pass

    def onRspQryInvestorPosition(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """持仓查询回报"""
        if last:
            self.callback_result = [data, error, reqid, last]

            with self.callback_done:
                self.callback_done.notify()

    def onRspQryTradingAccount(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """资金查询回报"""
        if last:
            self.callback_result = [data, error, reqid, last]

            with self.callback_done:
                self.callback_done.notify()

    def onRspQryInstrument(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """合约查询回报"""
        if last:
            self.callback_result = [data, error, reqid, last]
            with self.callback_done:
                self.callback_done.notify()

    def onRspSettlementInfoConfirm(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """结算单确认回报"""
        self.callback_result = [data, error, reqid, last]

        with self.callback_done:
            self.callback_done.notify()

    def onRtnOrder(self, data: dict) -> None:
        """委托更新推送"""
        orderid: str = data["OrderRef"]
        self.order_data[orderid] = data

    def onRtnTrade(self, data: dict) -> None:
        """成交数据推送"""
        tradeid: str = data["TradeID"]
        self.trade_data[tradeid] = data


@pytest.fixture(scope="session")
def login_api() -> Generator[MyTdApi, None, None]:
    """初始化API对象"""
    # 实例化API对象
    api: MyTdApi = MyTdApi()

    # 创建API对象
    api.createFtdcTraderApi("")

    api.subscribePrivateTopic(2)
    api.subscribePublicTopic(2)

    # 注册前端
    api.registerFront(TD_ADDRESS)
    api.init()

    # 等待连接成功
    count = 0
    while not api.connect_status:
        sleep(1)
        count += 1
        if count >= WAIT_TIME:
            pytest.exit("CTP交易服务器连接超时，请检查端口能否连接")

    # 发送授权请求
    if TD_SETTING["AuthCode"]:
        api.reqid += 1
        auth_req: dict = {
            "UserID": TD_SETTING["UserID"],
            "BrokerID": TD_SETTING["BrokerID"],
            "AuthCode": TD_SETTING["AuthCode"],
            "AppID": TD_SETTING["AppID"]
        }
        api.reqAuthenticate(auth_req, api.reqid)

        # 等待授权结果
        with api.callback_done:
            api.callback_done.wait(WAIT_TIME)

        error: dict = api.callback_result[1]
        if error["ErrorID"] != 0:
            pytest.fail(f"CTP交易服务器授权失败，错误代码：{error['ErrorID']}")
        else:
            api.auth_status = True

    # 发送登录请求
    api.reqid += 1
    login_req: dict = {
        "UserID": TD_SETTING["UserID"],
        "BrokerID": TD_SETTING["BrokerID"],
        "Password": TD_SETTING["Password"]
    }
    api.reqUserLogin(login_req, api.reqid)

    # 等待登录结果
    with api.callback_done:
        api.callback_done.wait(WAIT_TIME)

    error = api.callback_result[1]
    if error["ErrorID"] != 0:
        pytest.exit(f"CTP交易服务器登录失败，错误代码：{error['ErrorID']}")
    else:
        api.login_status = True

    yield api

    # 测试结束后关闭API
    api.exit()


def test_login(login_api: MyTdApi) -> None:
    """测试API登录"""
    assert login_api.login_status is True


def test_confirm_settlement(login_api: MyTdApi) -> None:
    """测试结算单确认"""
    login_api.reqid += 1
    confirm_req: dict = {
      "BrokerID": TD_SETTING["BrokerID"],
      "InvestorID": TD_SETTING["UserID"]
    }
    login_api.reqSettlementInfoConfirm(confirm_req, login_api.reqid)

    # 等待确认结果
    with login_api.callback_done:
        login_api.callback_done.wait(WAIT_TIME)

    error: dict = login_api.callback_result[1]
    assert error["ErrorID"] == 0


def test_query_instrument(login_api: MyTdApi) -> None:
    """测试合约查询"""
    # 由于流控，单次查询可能失败，通过while循环持续尝试，直到成功发出请求
    while True:
        login_api.reqid += 1
        n: int = login_api.reqQryInstrument({}, login_api.reqid)

        if not n:
            break
        else:
            sleep(1)

    # 等待查询结果
    with login_api.callback_done:
        login_api.callback_done.wait(WAIT_TIME * 6)

    error: dict = login_api.callback_result[1]
    assert not error                              # 检查error是否为空字典


def test_query_account(login_api: MyTdApi) -> None:
    """测试资金查询"""
    login_api.reqid += 1
    login_api.reqQryTradingAccount({}, login_api.reqid)

    with login_api.callback_done:
        login_api.callback_done.wait(WAIT_TIME)

    error: dict = login_api.callback_result[1]
    data: dict = login_api.callback_result[0]
    assert not error                              # 检查error是否为空字典
    assert data["AccountID"]


def test_query_position(login_api: MyTdApi) -> None:
    """测试持仓查询"""
    login_api.reqid += 1
    position_req = {
        "BrokerID": TD_SETTING["BrokerID"],
        "InvestorID": TD_SETTING["UserID"]
    }
    login_api.reqQryInvestorPosition(position_req, login_api.reqid)

    with login_api.callback_done:
        login_api.callback_done.wait(WAIT_TIME)

    error: dict = login_api.callback_result[1]
    assert not error                              # 检查error是否为空字典


def test_insert_order(login_api: MyTdApi) -> None:
    """测试委托下单"""
    # 构造委托请求
    login_api.order_ref += 1
    order_id: str = str(login_api.order_ref)
    order_req = {
        "InstrumentID": SYMBOL,
        "ExchangeID": EXCHANGE,
        "LimitPrice": ALL_TRADED_PRICE,
        "VolumeTotalOriginal": int(VOLUME),
        "OrderPriceType": THOST_FTDC_OPT_LimitPrice,
        "Direction": THOST_FTDC_D_Buy,
        "CombOffsetFlag": THOST_FTDC_OF_Open,
        "OrderRef": order_id,
        "InvestorID": TD_SETTING["UserID"],
        "UserID": TD_SETTING["UserID"],
        "BrokerID": TD_SETTING["BrokerID"],
        "CombHedgeFlag": THOST_FTDC_HF_Speculation,
        "ContingentCondition": THOST_FTDC_CC_Immediately,
        "ForceCloseReason": THOST_FTDC_FCC_NotForceClose,
        "IsAutoSuspend": 0,
        "TimeCondition": THOST_FTDC_TC_GFD,
        "VolumeCondition": THOST_FTDC_VC_AV,
        "MinVolume": 1
    }
    login_api.reqid += 1
    error_code: int = login_api.reqOrderInsert(order_req, login_api.reqid)
    if error_code:
        pytest.fail(f"委托下单失败，错误代码：{error_code}")

    # 等待委托回报
    sleep(WAIT_TIME)

    data: dict = login_api.order_data[order_id]
    assert isinstance(data, dict)                                # 检查收到委托回报
    assert data["OrderStatus"] == THOST_FTDC_OST_AllTraded       # 检查状态为已成交

    trade_data: list[dict] = [d for d in login_api.trade_data.values() if d["OrderRef"] == order_id]
    assert len(trade_data) > 0                                    # 检查收到成交回报


def test_cancel_order(login_api: MyTdApi) -> None:
    """测试委托撤单"""
    # 构造委托请求
    login_api.order_ref += 1
    order_id: str = str(login_api.order_ref)
    order_req = {
        "InstrumentID": SYMBOL,
        "ExchangeID": EXCHANGE,
        "LimitPrice": NOT_TRADED_PRICE,
        "VolumeTotalOriginal": int(VOLUME),
        "OrderPriceType": THOST_FTDC_OPT_LimitPrice,
        "Direction": THOST_FTDC_D_Buy,
        "CombOffsetFlag": THOST_FTDC_OF_Open,
        "OrderRef": order_id,
        "InvestorID": TD_SETTING["UserID"],
        "UserID": TD_SETTING["UserID"],
        "BrokerID": TD_SETTING["BrokerID"],
        "CombHedgeFlag": THOST_FTDC_HF_Speculation,
        "ContingentCondition": THOST_FTDC_CC_Immediately,
        "ForceCloseReason": THOST_FTDC_FCC_NotForceClose,
        "IsAutoSuspend": 0,
        "TimeCondition": THOST_FTDC_TC_GFD,
        "VolumeCondition": THOST_FTDC_VC_AV,
        "MinVolume": 1
    }
    login_api.reqid += 1
    error_code: int = login_api.reqOrderInsert(order_req, login_api.reqid)
    if error_code:
        pytest.fail(f"委托下单失败，错误代码：{error_code}")

    # 等待委托回报
    sleep(WAIT_TIME)

    data: dict = login_api.order_data[order_id]
    assert isinstance(data, dict)                                # 检查收到委托回报

    # 构造撤单请求
    cancel_req = {
        "InstrumentID": data["InstrumentID"],
        "ExchangeID": data["ExchangeID"],
        "OrderRef": data["OrderRef"],
        "FrontID": data["FrontID"],
        "SessionID": data["SessionID"],
        "ActionFlag": THOST_FTDC_AF_Delete,
        "BrokerID": TD_SETTING["BrokerID"],
        "InvestorID": TD_SETTING["UserID"]
    }
    login_api.reqid += 1
    error_code = login_api.reqOrderAction(cancel_req, login_api.reqid)
    assert error_code == 0

    # 等待撤单回报
    sleep(WAIT_TIME)
    data = login_api.order_data[order_id]
    assert data["OrderStatus"] == THOST_FTDC_OST_Canceled         # 检查状态为已撤销

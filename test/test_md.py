import time
from threading import Condition
from collections.abc import Generator

import pytest

from vnpy_ctp.api import (
    MdApi
)


# 测试参数
MD_SETTING = {
    "UserID": "xxx",                             # 用户名
    "Password": "xxx",                           # 密码
    "BrokerID": "9999",                          # 经纪商代码
}
MD_ADDRESS = "tcp://180.168.146.187:10131"       # 行情服务器地址
SYMBOL = "rb2601"                                # 合约代码
WAIT_TIME = 10                                   # 回调等待时间


class MyMdApi(MdApi):
    """继承实现API接口类"""

    def __init__(self) -> None:
        """构造函数"""
        super().__init__()

        self.callback_result: list = []
        self.callback_done: Condition = Condition()

        self.reqid: int = 0
        self.connect_status: bool = False
        self.login_status: bool = False

    def onFrontConnected(self) -> None:
        """服务器连接成功回报"""
        self.connect_status = True

    def onFrontDisconnected(self, reason: int) -> None:
        """服务器连接断开回报"""
        self.login_status = False

    def onRspUserLogin(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """用户登录请求回报"""
        self.callback_result = [data, error, reqid, last]

        with self.callback_done:
            self.callback_done.notify()

    def onRspError(self, error: dict, reqid: int, last: bool) -> None:
        """请求报错回报"""
        self.callback_result = [error, reqid, last]

        with self.callback_done:
            self.callback_done.notify()

    def onRspSubMarketData(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """订阅行情回报"""
        pass

    def onRtnDepthMarketData(self, data: dict) -> None:
        """行情数据推送"""
        self.callback_result = [data]

        with self.callback_done:
            self.callback_done.notify()


@pytest.fixture(scope="session")
def login_api() -> Generator[MyMdApi, None, None]:
    """初始化API对象"""
    # 实例化API对象
    api: MyMdApi = MyMdApi()

    # 创建API对象
    api.createFtdcMdApi("")

    # 注册前端
    api.registerFront(MD_ADDRESS)
    api.init()

    # 等待连接成功
    count: int = 0
    while not api.connect_status:
        time.sleep(1)
        count += 1
        if count >= WAIT_TIME:
            pytest.exit("CTP行情服务器连接超时，请检查端口能否连接")

    # 发送登录请求
    api.reqid += 1
    api.reqUserLogin(MD_SETTING, api.reqid)

    # 等待登录结果
    with api.callback_done:
        api.callback_done.wait(WAIT_TIME)

    error: dict = api.callback_result[1]
    if error["ErrorID"] != 0:
        pytest.exit(f"CTP行情服务器登录失败，错误代码：{error['ErrorID']}")
    else:
        api.login_status = True

    yield api

    # 测试结束后关闭API
    api.exit()


def test_login(login_api: MyMdApi) -> None:
    """测试API登录"""
    assert login_api.login_status is True


def test_subscribe(login_api: MyMdApi) -> None:
    """测试订阅行情"""
    login_api.subscribeMarketData(SYMBOL)

    with login_api.callback_done:
        login_api.callback_done.wait(WAIT_TIME)

    symbol: str = login_api.callback_result[0]["InstrumentID"]
    assert symbol == SYMBOL      # 检查推送的合约代码是否一致

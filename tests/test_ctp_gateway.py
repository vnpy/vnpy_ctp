from collections.abc import Callable, Iterator
from datetime import datetime
from typing import Any

import pytest

pytest.importorskip("vnpy_ctp.api", reason="缺少原生扩展")

from vnpy.event import EventEngine  # noqa: E402
from vnpy.trader.constant import (  # noqa: E402
    Direction,
    Exchange,
    Offset,
    OrderType,
    Product,
    Status,
)
from vnpy.trader.object import (  # noqa: E402
    ContractData,
    OrderData,
    OrderRequest,
    PositionData,
    TickData,
)

from vnpy_ctp.api import (  # noqa: E402
    THOST_FTDC_D_Buy,
    THOST_FTDC_OF_Open,
    THOST_FTDC_OPT_LimitPrice,
    THOST_FTDC_OSS_InsertRejected,
    THOST_FTDC_OST_AllTraded,
    THOST_FTDC_OST_Canceled,
    THOST_FTDC_OST_NoTradeQueueing,
    THOST_FTDC_OST_PartTradedQueueing,
    THOST_FTDC_OST_Unknown,
    THOST_FTDC_PD_Long,
    THOST_FTDC_TC_GFD,
    THOST_FTDC_VC_AV,
)
from vnpy_ctp.gateway import ctp_gateway  # noqa: E402
from vnpy_ctp.gateway.ctp_gateway import (  # noqa: E402
    CHINA_TZ,
    MAX_FLOAT,
    CtpGateway,
    CtpMdApi,
    CtpTdApi,
)


class Sink:
    def __init__(self) -> None:
        self.logs: list[str] = []
        self.ticks: list[TickData] = []
        self.orders: list[OrderData] = []
        self.positions: list[PositionData] = []

    def attach(self, gateway: CtpGateway) -> None:
        gateway.write_log = self.logs.append
        gateway.on_tick = self.ticks.append
        gateway.on_order = self.orders.append
        gateway.on_position = self.positions.append


class CallRecorder:
    def __init__(self) -> None:
        self.calls: list[tuple[str, Any]] = []

    def patch(self, monkeypatch: pytest.MonkeyPatch, api: object, names: list[str]) -> None:
        for name in names:
            monkeypatch.setattr(api, name, self.make_stub(name))

    def make_stub(self, name: str) -> Callable[..., int]:
        def stub(*args: Any) -> int:
            self.calls.append((name, args[0] if args else None))
            return 0
        return stub

    def names(self) -> list[str]:
        return [name for name, _ in self.calls]


TD_METHODS: list[str] = [
    "createFtdcTraderApi",
    "subscribePrivateTopic",
    "subscribePublicTopic",
    "registerFront",
    "init",
    "exit",
    "reqAuthenticate",
    "reqUserLogin",
    "reqQryInstrument",
    "reqOrderInsert",
    "reqOrderAction",
    "reqQryTradingAccount",
    "reqQryInvestorPosition",
]

MD_METHODS: list[str] = [
    "createFtdcMdApi",
    "registerFront",
    "init",
    "exit",
    "reqUserLogin",
    "subscribeMarketData",
]


@pytest.fixture(autouse=True)
def clear_contracts() -> Iterator[None]:
    ctp_gateway.symbol_contract_map.clear()
    yield
    ctp_gateway.symbol_contract_map.clear()


@pytest.fixture
def sink() -> Sink:
    return Sink()


@pytest.fixture
def recorder() -> CallRecorder:
    return CallRecorder()


@pytest.fixture
def gateway(sink: Sink, recorder: CallRecorder, monkeypatch: pytest.MonkeyPatch) -> CtpGateway:
    engine: EventEngine = EventEngine()
    gateway: CtpGateway = CtpGateway(engine, "CTP")
    sink.attach(gateway)
    recorder.patch(monkeypatch, gateway.td_api, TD_METHODS)
    recorder.patch(monkeypatch, gateway.md_api, MD_METHODS)
    return gateway


@pytest.fixture
def td_api(gateway: CtpGateway) -> CtpTdApi:
    return gateway.td_api


@pytest.fixture
def md_api(gateway: CtpGateway) -> CtpMdApi:
    return gateway.md_api


def add_contract(
    symbol: str = "rb2510",
    exchange: Exchange = Exchange.SHFE,
    size: int = 10,
) -> None:
    contract: ContractData = ContractData(
        symbol=symbol,
        exchange=exchange,
        name=symbol,
        product=Product.FUTURES,
        size=size,
        pricetick=1,
        gateway_name="CTP",
    )
    ctp_gateway.symbol_contract_map[symbol] = contract


def order_request() -> OrderRequest:
    return OrderRequest(
        symbol="rb2510",
        exchange=Exchange.SHFE,
        direction=Direction.LONG,
        type=OrderType.LIMIT,
        volume=2,
        price=3000,
        offset=Offset.OPEN,
    )


def depth_data(**overrides: Any) -> dict[str, Any]:
    data: dict[str, Any] = {
        "InstrumentID": "rb2510",
        "UpdateTime": "09:30:00",
        "UpdateMillisec": 500,
        "ActionDay": "20200101",
        "Volume": 10,
        "Turnover": 30000,
        "OpenInterest": 100,
        "LastPrice": 3000,
        "UpperLimitPrice": 3300,
        "LowerLimitPrice": 2700,
        "OpenPrice": 2990,
        "HighestPrice": 3010,
        "LowestPrice": 2980,
        "PreClosePrice": 2985,
        "BidPrice1": 2999,
        "AskPrice1": 3001,
        "BidVolume1": 5,
        "AskVolume1": 6,
        "BidPrice2": 2998,
        "BidPrice3": 2997,
        "BidPrice4": 2996,
        "BidPrice5": 2995,
        "AskPrice2": 3002,
        "AskPrice3": 3003,
        "AskPrice4": 3004,
        "AskPrice5": 3005,
        "BidVolume2": 0,
        "BidVolume3": 0,
        "BidVolume4": 0,
        "BidVolume5": 0,
        "AskVolume2": 0,
        "AskVolume3": 0,
        "AskVolume4": 0,
        "AskVolume5": 0,
    }
    data.update(overrides)
    return data


def rtn_order(**overrides: Any) -> dict[str, Any]:
    data: dict[str, Any] = {
        "InstrumentID": "rb2510",
        "InsertDate": "20250926",
        "InsertTime": "09:30:00",
        "OrderStatus": THOST_FTDC_OST_NoTradeQueueing,
        "OrderSubmitStatus": "",
        "StatusMsg": "已撤单",
        "FrontID": 1,
        "SessionID": 2,
        "OrderRef": "7",
        "OrderPriceType": THOST_FTDC_OPT_LimitPrice,
        "TimeCondition": THOST_FTDC_TC_GFD,
        "VolumeCondition": THOST_FTDC_VC_AV,
        "Direction": THOST_FTDC_D_Buy,
        "CombOffsetFlag": THOST_FTDC_OF_Open,
        "LimitPrice": 3000,
        "VolumeTotalOriginal": 2,
        "VolumeTraded": 0,
        "OrderSysID": "SYS1",
    }
    data.update(overrides)
    return data


def position_data(**overrides: Any) -> dict[str, Any]:
    data: dict[str, Any] = {
        "InstrumentID": "rb2510",
        "PosiDirection": THOST_FTDC_PD_Long,
        "YdPosition": 1,
        "TodayPosition": 0,
        "Position": 2,
        "PositionProfit": 12.5,
        "PositionCost": 60000,
        "ShortFrozen": 1,
        "LongFrozen": 4,
    }
    data.update(overrides)
    return data


def test_connect_prefixes_bare_address(gateway: CtpGateway, monkeypatch: pytest.MonkeyPatch) -> None:
    seen: dict[str, str] = {}
    monkeypatch.setattr(gateway.td_api, "connect", lambda *args: seen.__setitem__("td", args[0]))
    monkeypatch.setattr(gateway.md_api, "connect", lambda *args: seen.__setitem__("md", args[0]))

    setting: dict[str, Any] = dict(CtpGateway.default_setting)
    setting["交易服务器"] = "127.0.0.1:41205"
    setting["行情服务器"] = "ssl://127.0.0.1:41213"
    gateway.connect(setting)

    assert seen["td"] == "tcp://127.0.0.1:41205"
    assert seen["md"] == "ssl://127.0.0.1:41213"


def test_connect_keeps_socks_prefix(gateway: CtpGateway, monkeypatch: pytest.MonkeyPatch) -> None:
    seen: dict[str, str] = {}
    monkeypatch.setattr(gateway.td_api, "connect", lambda *args: seen.__setitem__("td", args[0]))
    monkeypatch.setattr(gateway.md_api, "connect", lambda *args: seen.__setitem__("md", args[0]))

    setting: dict[str, Any] = dict(CtpGateway.default_setting)
    setting["交易服务器"] = "socks://127.0.0.1:1080"
    setting["行情服务器"] = "socks://127.0.0.1:1080"
    gateway.connect(setting)

    assert seen["td"] == "socks://127.0.0.1:1080"
    assert seen["md"] == "socks://127.0.0.1:1080"


def test_send_order_returns_local_id(td_api: CtpTdApi, sink: Sink, recorder: CallRecorder) -> None:
    td_api.frontid = 1
    td_api.sessionid = 2

    vt_orderid: str = td_api.send_order(order_request())

    assert vt_orderid == "CTP.1_2_1"
    request: dict[str, Any] = recorder.calls[0][1]
    assert recorder.names() == ["reqOrderInsert"]
    assert request["OrderRef"] == "1"
    assert sink.orders[0].orderid == "1_2_1"
    assert sink.orders[0].status == Status.SUBMITTING


@pytest.mark.parametrize(
    ("ctp_status", "vt_status"),
    [
        (THOST_FTDC_OST_NoTradeQueueing, Status.NOTTRADED),
        (THOST_FTDC_OST_PartTradedQueueing, Status.PARTTRADED),
        (THOST_FTDC_OST_AllTraded, Status.ALLTRADED),
        (THOST_FTDC_OST_Canceled, Status.CANCELLED),
        (THOST_FTDC_OST_Unknown, Status.SUBMITTING),
    ],
)
def test_order_status_mapping(td_api: CtpTdApi, sink: Sink, ctp_status: str, vt_status: Status) -> None:
    add_contract()
    td_api.contract_inited = True
    td_api.onRtnOrder(rtn_order(OrderStatus=ctp_status))

    order: OrderData = sink.orders[0]
    assert order.orderid == "1_2_7"
    assert order.status == vt_status
    assert order.direction == Direction.LONG
    assert order.offset == Offset.OPEN
    assert order.type == OrderType.LIMIT
    assert order.datetime == datetime(2025, 9, 26, 9, 30, tzinfo=CHINA_TZ)


def test_insert_rejected_cancel_maps_to_rejected(td_api: CtpTdApi, sink: Sink) -> None:
    add_contract()
    td_api.contract_inited = True
    td_api.onRtnOrder(rtn_order(
        OrderStatus=THOST_FTDC_OST_Canceled,
        OrderSubmitStatus=THOST_FTDC_OSS_InsertRejected,
    ))

    assert sink.orders[0].status == Status.REJECTED


def test_unsupported_order_status_is_logged(td_api: CtpTdApi, sink: Sink) -> None:
    add_contract()
    td_api.contract_inited = True
    td_api.onRtnOrder(rtn_order(OrderStatus="Z"))

    assert sink.orders == []
    assert "不支持的委托状态" in sink.logs[0]


def test_shfe_yd_position_uses_position_when_only_yesterday(td_api: CtpTdApi, sink: Sink) -> None:
    add_contract(exchange=Exchange.SHFE, size=10)
    td_api.onRspQryInvestorPosition(position_data(), {}, 1, True)

    position: PositionData = sink.positions[0]
    assert position.exchange == Exchange.SHFE
    assert position.direction == Direction.LONG
    assert position.yd_volume == 2
    assert position.volume == 2
    assert position.price == 3000
    assert position.frozen == 1
    assert position.pnl == 12.5
    assert td_api.positions == {}


def test_ine_yd_position_matches_shfe(td_api: CtpTdApi, sink: Sink) -> None:
    add_contract(symbol="sc2510", exchange=Exchange.INE, size=10)
    td_api.onRspQryInvestorPosition(
        position_data(InstrumentID="sc2510", TodayPosition=0, YdPosition=1, Position=4, PositionCost=120000),
        {},
        1,
        True,
    )

    assert sink.positions[0].yd_volume == 4
    assert sink.positions[0].volume == 4


def test_dce_yd_position_subtracts_today(td_api: CtpTdApi, sink: Sink) -> None:
    add_contract(symbol="m2501", exchange=Exchange.DCE, size=10)
    td_api.onRspQryInvestorPosition(
        position_data(InstrumentID="m2501", Position=5, TodayPosition=2, YdPosition=9),
        {},
        1,
        True,
    )

    assert sink.positions[0].yd_volume == 3
    assert sink.positions[0].volume == 5


def test_shfe_today_position_does_not_set_yd(td_api: CtpTdApi, sink: Sink) -> None:
    add_contract()
    td_api.onRspQryInvestorPosition(position_data(TodayPosition=2, YdPosition=1), {}, 1, True)

    assert sink.positions[0].yd_volume == 0
    assert sink.positions[0].volume == 2


def test_empty_position_tail_returns_without_flush(td_api: CtpTdApi, sink: Sink) -> None:
    add_contract()
    td_api.onRspQryInvestorPosition(position_data(), {}, 1, False)
    assert sink.positions == []

    td_api.onRspQryInvestorPosition({}, {}, 1, True)

    assert sink.positions == []
    assert len(td_api.positions) == 1


def test_depth_without_time_is_ignored(md_api: CtpMdApi, sink: Sink) -> None:
    add_contract()
    md_api.onRtnDepthMarketData(depth_data(UpdateTime=""))

    assert sink.ticks == []


def test_depth_without_contract_is_ignored(md_api: CtpMdApi, sink: Sink) -> None:
    md_api.onRtnDepthMarketData(depth_data())

    assert sink.ticks == []


def test_dce_depth_uses_local_date(md_api: CtpMdApi, sink: Sink) -> None:
    add_contract(symbol="m2501", exchange=Exchange.DCE)
    md_api.current_date = "20250926"
    md_api.onRtnDepthMarketData(depth_data(InstrumentID="m2501", ActionDay="19990101"))

    tick: TickData = sink.ticks[0]
    assert tick.exchange == Exchange.DCE
    assert tick.datetime == datetime(2025, 9, 26, 9, 30, 0, 500000, tzinfo=CHINA_TZ)


def test_shfe_depth_uses_action_day(md_api: CtpMdApi, sink: Sink) -> None:
    add_contract()
    md_api.current_date = "20250926"
    md_api.onRtnDepthMarketData(depth_data(LastPrice=MAX_FLOAT))

    tick: TickData = sink.ticks[0]
    assert tick.datetime == datetime(2020, 1, 1, 9, 30, 0, 500000, tzinfo=CHINA_TZ)
    assert tick.last_price == 0


def test_close_without_connection_does_not_exit(
    td_api: CtpTdApi,
    md_api: CtpMdApi,
    recorder: CallRecorder,
) -> None:
    td_api.close()
    md_api.close()

    assert recorder.calls == []

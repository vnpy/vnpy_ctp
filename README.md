# VeighNa框架的CTP底层接口

<p align="center">
  <img src ="https://vnpy.oss-cn-shanghai.aliyuncs.com/vnpy-logo.png"/>
</p>

<p align="center">
    <img src ="https://img.shields.io/badge/version-6.7.2.0-blueviolet.svg"/>
    <img src ="https://img.shields.io/badge/platform-windows|linux|macos-yellow.svg"/>
    <img src ="https://img.shields.io/badge/python-3.10|3.11|3.12-blue.svg" />
    <img src ="https://img.shields.io/github/license/vnpy/vnpy.svg?color=orange"/>
</p>

## 说明

基于CTP期货版的6.7.2接口封装开发，接口中自带的是【穿透式实盘环境】的dll文件。

## 安装

安装环境推荐基于3.9.0版本以上的【[**VeighNa Studio**](https://www.vnpy.com)】。

直接使用pip命令：

```
pip install vnpy_ctp
```


或者下载源代码后，解压后在cmd中运行：

```
pip install .
```

使用源代码安装时需要进行C++编译，因此在执行上述命令之前请确保已经安装了【Visual Studio（Windows）】、【GCC（Linux）】、【XCode（Mac）】编译器。

## 使用

以脚本方式启动（script/run.py）：

```
from vnpy.event import EventEngine
from vnpy.trader.engine import MainEngine
from vnpy.trader.ui import MainWindow, create_qapp

from vnpy_ctp import CtpGateway


def main():
    """主入口函数"""
    qapp = create_qapp()

    event_engine = EventEngine()
    main_engine = MainEngine(event_engine)
    main_engine.add_gateway(CtpGateway)
    
    main_window = MainWindow(main_engine, event_engine)
    main_window.showMaximized()

    qapp.exec()


if __name__ == "__main__":
    main()
```

## Mac系统支持

由于6.7.2版本CTP的Mac系统API项目结构发生了较大变化，改为了使用framework目录的结构，因此无法再直接从PyPI下载预编译好的wheel二进制包进行安装。

用户需要克隆（或下载）本仓库的源代码到本地后自行编译安装，具体命令如下：

```
git clone https://github.com/vnpy/vnpy_ctp.git

cd vnpy_ctp

pip3 install -e .
```

相关注意事项如下：

源码编译需要依赖XCode开发工具中的C++编译器，请务必先安装好。

编译过程中，会指定克隆到本地的源码目录中的framework文件夹路径，为API运行时动态库的加载路径。因此后续运行时，*该源码目录不能删除，也不能移动位置，否则会导致动态库加载找不到的报错*。

由于当前新版本Mac系统的安全机制，编译完成后需要在【访达】中找到下述两个动态库文件，分别手动打开一次后添加到操作系统信任名单，才能在启动Python时成功加载：

* vnpy_ctp/api/libs/thostmduserapi_se.framework/Versions/A/thostmduserapi_se
* vnpy_ctp/api/libs/thosttraderapi_se.framework/Versions/A/thosttraderapi_se

以上两个文件由于本身是二进制格式，并不能正常打开，但不影响添加到系统信任名单。


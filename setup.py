""""""

import ast
import platform
import re

from setuptools import Extension, find_packages, setup


def get_version_string() -> str:
    """获取版本号"""
    with open("vnpy_ctp/__init__.py", "rb") as f:
        content = f.read().decode("utf-8")
        version_line = re.search(r"__version__\s+=\s+(.*)", content).group(1)
        return str(ast.literal_eval(version_line))


def get_ext_modules() -> list:
    """
    获取三方模块

    Linux需要编译封装接口
    Windows直接使用预编译的pyd即可
    Mac由于缺乏二进制库支持无法使用
    """
    if platform.system != "Linux":
        return []

    compiler_flags = [
        "-std=c++17",  # standard
        "-O3",  # Optimization
        "-Wno-delete-incomplete", "-Wno-sign-compare",
    ]
    extra_link_args = ["-lstdc++"]
    runtime_library_dirs = ["$ORIGIN"]

    vnctpmd = Extension(
        "vnpy_ctp.api.vnctpmd",
        [
            "vnpy_ctp/api/vnctp/vnctpmd/vnctpmd.cpp",
        ],
        include_dirs=["vnpy_ctp/api/include",
                      "vnpy_ctp/api/vnctp"],
        define_macros=[],
        undef_macros=[],
        library_dirs=["vnpy_ctp/api/libs", "vnpy_ctp/api"],
        libraries=["thostmduserapi_se", "thosttraderapi_se"],
        extra_compile_args=compiler_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    vnctptd = Extension(
        "vnpy_ctp.api.vnctptd",
        [
            "vnpy_ctp/api/vnctp/vnctptd/vnctptd.cpp",
        ],
        include_dirs=["vnpy_ctp/api/include",
                      "vnpy_ctp/api/vnctp"],
        define_macros=[],
        undef_macros=[],
        library_dirs=["vnpy_ctp/api/libs", "vnpy_ctp/api"],
        libraries=["thostmduserapi_se", "thosttraderapi_se"],
        extra_compile_args=compiler_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    return [vnctptd, vnctpmd]


setup(
    name="vnpy",
    version=get_version_string(),
    author="vn.py team",
    author_email="vn.py@foxmail.com",
    license="MIT",
    url="https://www.vnpy.com",
    description="A framework for developing quant trading systems.",
    long_description=__doc__,
    keywords='quant quantitative investment trading algotrading',
    include_package_data=True,
    packages=find_packages(),
    package_data={"": [
        "*.dll",
        "*.so",
        "*.pyd",
    ]},
    install_requires=["vnpy"],
    classifiers=[
        "Development Status :: 5 - Production/Stable",
        "Operating System :: Microsoft :: Windows :: Windows 10",
        "Operating System :: Microsoft :: Windows :: Windows Server 2019",
        "Operating System :: POSIX :: Linux"
        "Programming Language :: Python :: 3",
        "Programming Language :: Python :: 3.7",
        "Topic :: Office/Business :: Financial :: Investment",
        "Programming Language :: Python :: Implementation :: CPython",
        "License :: OSI Approved :: MIT License",
        "Natural Language :: Chinese (Simplified)"
    ],
    ext_modules=get_ext_modules(),
)

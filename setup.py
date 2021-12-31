import platform

from setuptools import Extension, setup


def get_ext_modules() -> list:
    """
    获取三方模块

    Mac由于缺乏二进制库支持无法使用
    """

    compiler_flags = [
        "-std=c++17",
        "-O3",
        "-Wno-delete-incomplete", "-Wno-sign-compare",
    ]
    extra_link_args = ["-lstdc++"]
    runtime_library_dirs = ["$ORIGIN"]
    if platform.system() == "Linux":
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
    elif platform.system() == "Windows":
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
            depends=[],
            language="cpp",
        )
        
        return [vnctptd, vnctpmd]
    else:
        return []

    
setup(
    ext_modules=get_ext_modules(),
)

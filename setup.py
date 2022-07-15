import platform

from setuptools import Extension, setup


def get_ext_modules() -> list:
    """
    获取三方模块
    Windows需要编译封装接口
    Linux和Mac由于缺乏二进制库支持无法使用
    """
    if platform.system() != "Windows":
        return []

    extra_compile_flags = ["-O2", "-MT"]
    extra_link_args = []
    runtime_library_dirs = []

    vnhtsmd = Extension(
        "vnpy_hts.api.vnhtsmd",
        [
            "vnpy_hts/api/vnhts/vnhtsmd/vnhtsmd.cpp",
        ],
        include_dirs=["vnpy_hts/api/include",
                      "vnpy_hts/api/include/hts",
                      "vnpy_hts/api/vnhts"],
        define_macros=[],
        undef_macros=[],
        library_dirs=["vnpy_hts/api/libs", "vnpy_hts/api"],
        libraries=["DFITCSECMdApi", "DFITCSECTraderApi", "HsFutuSystemInfo", "InformationCollect"],
        extra_compile_args=extra_compile_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    vnhtstd = Extension(
        "vnpy_hts.api.vnhtstd",
        [
            "vnpy_hts/api/vnhts/vnhtstd/vnhtstd.cpp",
        ],
        include_dirs=["vnpy_hts/api/include",
                      "vnpy_hts/api/include/hts",
                      "vnpy_hts/api/vnhts"],
        define_macros=[],
        undef_macros=[],
        library_dirs=["vnpy_hts/api/libs", "vnpy_hts/api"],
        libraries=["DFITCSECMdApi", "DFITCSECTraderApi", "HsFutuSystemInfo", "InformationCollect"],
        extra_compile_args=extra_compile_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    return [vnhtstd, vnhtsmd]


setup(
    ext_modules=get_ext_modules(),
)

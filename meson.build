project(
  'vnpy_ctp',
  'cpp',
  version: '6.7.7.0',
  license: 'MIT',
  meson_version: '>=1.7.0',
  default_options: [
    'buildtype=release',
    'cpp_std=c++17',
    'warning_level=2',
  ],
)

# 导入文件系统和Python模块
fs = import('fs')
py = import('python').find_installation(pure: false)
py_dep = py.dependency()

# 获取pybind11路径（替换原来的依赖方式）
pybind11_include_dir = run_command('python', '-c', 'import pybind11; print(pybind11.get_include())', check: true).stdout().strip()
message('使用pybind11路径: ' + pybind11_include_dir)

# 获取编译器信息
cpp = meson.get_compiler('cpp')
compiler_id = cpp.get_id()

# 输出构建目标系统信息
message('构建目标系统: ' + host_machine.system())

# 设置include目录
include_dirs = include_directories(
  'vnpy_ctp/api/include',
  'vnpy_ctp/api/vnctp',
  pybind11_include_dir,  # 添加pybind11包的路径
)

# 设置Windows特定编译选项
if host_machine.system() == 'windows'
  # Windows编译器设置
  add_project_arguments('/MT', language : 'cpp')
  
  # 设置库目录
  lib_dir = meson.current_source_dir() / 'vnpy_ctp/api/libs'
  api_dir = meson.current_source_dir() / 'vnpy_ctp/api'
  
  # 定义CTP库
  thostmduserapi_lib = cpp.find_library('thostmduserapi_se', 
                                       dirs: [lib_dir, api_dir],
                                       required: true)
  thosttraderapi_lib = cpp.find_library('thosttraderapi_se', 
                                       dirs: [lib_dir, api_dir],
                                       required: true)
endif

# 创建MD模块扩展
md_module = py.extension_module(
  'vnctpmd',
  sources: ['vnpy_ctp/api/vnctp/vnctpmd/vnctpmd.cpp'],
  include_directories: include_dirs,
  dependencies: [py_dep, thostmduserapi_lib],
  install: true,
  subdir: 'vnpy_ctp/api'
)

# 创建TD模块扩展
td_module = py.extension_module(
  'vnctptd',
  sources: ['vnpy_ctp/api/vnctp/vnctptd/vnctptd.cpp'],
  include_directories: include_dirs,
  dependencies: [py_dep, thosttraderapi_lib],
  install: true,
  subdir: 'vnpy_ctp/api'
)

# 安装Python源代码
python_files = [
  ['vnpy_ctp/__init__.py', 'vnpy_ctp'],
  ['vnpy_ctp/api/__init__.py', 'vnpy_ctp/api'],
  ['vnpy_ctp/api/ctp_constant.py', 'vnpy_ctp/api'],
  ['vnpy_ctp/gateway/__init__.py', 'vnpy_ctp/gateway'],
  ['vnpy_ctp/gateway/ctp_gateway.py', 'vnpy_ctp/gateway'],
]

foreach file : python_files
  py.install_sources(
    [file[0]],
    pure: false,
    subdir: file[1]
  )
endforeach

# 安装API动态库文件
api_libs = [
  'vnpy_ctp/api/thostmduserapi_se.dll',
  'vnpy_ctp/api/thosttraderapi_se.dll',
]

install_data(
  api_libs,
  install_dir: py.get_install_dir() / 'vnpy_ctp/api'
) 
project(
  'vnpy_ctp',
  'cpp',
  version: '6.7.11.1',
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

# 获取pybind11路径
python_cmd = host_machine.system() == 'windows' ? 'python' : 'python3'
pybind11_include_dir = run_command(python_cmd, '-c', 'import pybind11; print(pybind11.get_include())', check: true).stdout().strip()
message('使用pybind11路径: ' + pybind11_include_dir)

# 获取编译器信息
cpp = meson.get_compiler('cpp')
compiler_id = cpp.get_id()

# 输出构建目标系统信息
message('构建目标系统: ' + host_machine.system())

# 初始化变量
thostmduserapi_lib = []
thosttraderapi_lib = []
extra_cpp_args = []
extra_link_args = []

# 初始化库变量
thostmduserapi_lib = []
thosttraderapi_lib = []

# 初始化其他编译选项
extra_link_args = []
install_rpath_value = ''

# 设置Windows特定编译选项
if host_machine.system() == 'windows'
  # Windows编译器设置
  add_project_arguments('/MT', language : 'cpp')
  
  # 设置库目录
  lib_dir = meson.current_source_dir() / 'vnpy_ctp/api/libs'
  api_dir = meson.current_source_dir() / 'vnpy_ctp/api'
  
  # 设置include目录
  include_dirs = include_directories(
    'vnpy_ctp/api/include',
    'vnpy_ctp/api/vnctp',
    pybind11_include_dir,
  )
  
  # 定义CTP库
  thostmduserapi_lib = cpp.find_library('thostmduserapi_se', 
                                       dirs: [lib_dir, api_dir],
                                       required: true)
  thosttraderapi_lib = cpp.find_library('thosttraderapi_se', 
                                       dirs: [lib_dir, api_dir],
                                       required: true)
                                       
# 设置Mac特定编译选项
elif host_machine.system() == 'darwin'
  # Mac编译器设置
  extra_cpp_args = [
    '-std=c++11',
    '-mmacosx-version-min=10.12',
  ]
  
  # 设置链接参数，包括@rpath到@loader_path的修改
  extra_link_args = [
    '-mmacosx-version-min=10.12',
    '-Wl,-rpath,@loader_path',
  ]
  
  # 设置库目录
  lib_dir = meson.current_source_dir() / 'vnpy_ctp/api/libs'
  api_dir = meson.current_source_dir() / 'vnpy_ctp/api'

  # 设置include目录
  include_dirs = include_directories(
    'vnpy_ctp/api/include/mac',
    'vnpy_ctp/api/vnctp',
    pybind11_include_dir,
  )
  
  # 定义Mac Framework依赖
  thostmduserapi_lib = declare_dependency(
    dependencies: [py_dep],
    link_args: [
      '-F', meson.current_source_dir() / 'vnpy_ctp/api',
      '-framework', 'thostmduserapi_se'
    ]
  )
  
  thosttraderapi_lib = declare_dependency(
    dependencies: [py_dep],
    link_args: [
      '-F', meson.current_source_dir() / 'vnpy_ctp/api',
      '-framework', 'thosttraderapi_se'
    ]
  )

# 设置Linux特定编译选项
else  # Linux
  # Linux编译器设置
  extra_cpp_args = [
    '-std=c++17',
    '-O3',
    '-Wno-delete-incomplete',
    '-Wno-sign-compare',
  ]
  
  extra_link_args = [
    '-lstdc++',
  ]
  
  # 设置库目录
  lib_dir = meson.current_source_dir() / 'vnpy_ctp/api'
  
  # 设置include目录
  include_dirs = include_directories(
    'vnpy_ctp/api/include',
    'vnpy_ctp/api/vnctp',
    pybind11_include_dir,
  )
  
  # 定义CTP库
  thostmduserapi_lib = cpp.find_library('thostmduserapi_se', 
                                       dirs: [lib_dir],
                                       required: true)
  thosttraderapi_lib = cpp.find_library('thosttraderapi_se', 
                                       dirs: [lib_dir],
                                       required: true)
endif

# 创建MD模块扩展
md_module = py.extension_module(
  'vnctpmd',
  sources: ['vnpy_ctp/api/vnctp/vnctpmd/vnctpmd.cpp'],
  include_directories: include_dirs,
  dependencies: [py_dep],
  cpp_args: extra_cpp_args,
  link_args: extra_link_args + [
    '-L' + lib_dir,
    '-lthostmduserapi_se',
    '-Wl,-rpath,$ORIGIN'
  ],
  install: true,
  install_rpath: '$ORIGIN',
  subdir: 'vnpy_ctp/api'
)

# 创建TD模块扩展
td_module = py.extension_module(
  'vnctptd',
  sources: ['vnpy_ctp/api/vnctp/vnctptd/vnctptd.cpp'],
  include_directories: include_dirs,
  dependencies: [py_dep],
  cpp_args: extra_cpp_args,
  link_args: extra_link_args + [
    '-L' + lib_dir,
    '-lthosttraderapi_se',
    '-Wl,-rpath,$ORIGIN'
  ],
  install: true,
  install_rpath: '$ORIGIN',
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
if host_machine.system() == 'windows'
  api_libs = [
    'vnpy_ctp/api/thostmduserapi_se.dll',
    'vnpy_ctp/api/thosttraderapi_se.dll',
  ]
  
  install_data(
    api_libs,
    install_dir: py.get_install_dir() / 'vnpy_ctp/api'
  )
elif host_machine.system() == 'darwin'
  # 安装Mac Framework文件夹
  install_subdir(
    'vnpy_ctp/api/thostmduserapi_se.framework',
    install_dir: py.get_install_dir() / 'vnpy_ctp/api'
  )
  
  install_subdir(
    'vnpy_ctp/api/thosttraderapi_se.framework',
    install_dir: py.get_install_dir() / 'vnpy_ctp/api'
  )
else  # Linux
  api_libs = [
    'vnpy_ctp/api/libthostmduserapi_se.so',
    'vnpy_ctp/api/libthosttraderapi_se.so',
  ]
  
  install_data(
    api_libs,
    install_dir: py.get_install_dir() / 'vnpy_ctp/api'
  )
endif
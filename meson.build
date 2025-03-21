project('vnpy_ctp',
  'cpp',
  version: '6.7.2.1',
  default_options: [
    'cpp_std=c++17',
    'warning_level=1',
    'buildtype=release',
  ],
)

# 基础配置
host_system = host_machine.system()
message('构建目标系统: ' + host_system)

# 工具导入
py_mod = import('python')
py = py_mod.find_installation(pure: false)
py_dep = py.dependency()
fs = import('fs')

# 基础路径定义
api_rel_dir = join_paths('vnpy_ctp', 'api')
include_rel_dir = join_paths(api_rel_dir, 'include')
libs_rel_dir = join_paths(api_rel_dir, 'libs')
vnctp_rel_dir = join_paths(api_rel_dir, 'vnctp')
vnctpmd_rel_dir = join_paths(vnctp_rel_dir, 'vnctpmd')
vnctptd_rel_dir = join_paths(vnctp_rel_dir, 'vnctptd')

# 查找pybind11包含路径
pybind11_cmd = run_command(py, '-c', 'import pybind11; print(pybind11.get_include())', check: true)
pybind11_path = pybind11_cmd.stdout().strip()
message('使用pybind11路径: ' + pybind11_path)

# 库名称定义
lib_names = ['thostmduserapi_se', 'thosttraderapi_se']

# 平台配置
platform_config = {
  'linux': {
    'cpp_args': ['-std=c++17', '-O3', '-Wno-delete-incomplete', '-Wno-sign-compare'],
    'link_args': ['-lstdc++', '-Wl,-rpath,$ORIGIN'],
    'lib_prefix': 'lib',
    'lib_suffix': '.so',
    'link_prefix': '-l'
  },
  'windows': {
    'cpp_args': ['/O2', '/MD', '/EHsc', '/bigobj', '/utf-8', '/wd4828'],
    'link_args': [],
    'include_pybind': true,
    'lib_prefix': '',
    'lib_suffix': '.lib',
    'shared_suffix': '.dll'
  },
  'darwin': {
    'cpp_args': ['-std=c++11', '-mmacosx-version-min=10.12'],
    'link_args': ['-mmacosx-version-min=10.12', '-Wl,-rpath,@loader_path/../api/libs'],
    'lib_prefix': 'lib',
    'lib_suffix': '.dylib',
    'link_prefix': '-l',
    'extra_include': join_paths(include_rel_dir, 'mac')
  }
}

# 基础编译配置
include_dirs = [include_rel_dir, vnctp_rel_dir, api_rel_dir]
lib_dirs = [api_rel_dir, libs_rel_dir]
cpp_args = []
link_args = []
lib_link_args = []
shared_libs = []

# 检查平台配置
if not platform_config.has_key(host_system)
  error('不支持的系统: ' + host_system)
endif

# 应用平台配置
cfg = platform_config[host_system]
cpp_args += cfg['cpp_args']
link_args += cfg.get('link_args', [])

# 额外的include路径
if cfg.has_key('extra_include')
  include_dirs += [cfg['extra_include']]
endif

# Windows需要pybind11路径
if cfg.get('include_pybind', false)
  include_dirs += [pybind11_path]
endif

# 生成库链接参数和共享库列表
if cfg.has_key('link_prefix')
  foreach lib : lib_names
    lib_link_args += [cfg['link_prefix'] + lib]
  endforeach
endif

if cfg.has_key('lib_prefix') and cfg.has_key('lib_suffix')
  foreach lib : lib_names
    shared_libs += [cfg['lib_prefix'] + lib + cfg['lib_suffix']]
  endforeach
endif

# Windows特殊处理
if cfg.has_key('shared_suffix')
  lib_files = []
  shared_libs = []
  
  foreach lib : lib_names
    lib_files += [lib + cfg['lib_suffix']]
    shared_libs += [lib + cfg['shared_suffix']]
  endforeach
  
  # 查找库文件
  foreach lib_file : lib_files
    lib_path = ''
    foreach search_dir : [api_rel_dir, libs_rel_dir]
      if fs.exists(join_paths(meson.current_source_dir(), search_dir, lib_file))
        lib_path = join_paths(meson.current_source_dir(), search_dir, lib_file)
        break
      endif
    endforeach
    
    if lib_path == ''
      error('找不到所需的库文件: ' + lib_file)
    endif
    
    lib_link_args += [lib_path]
  endforeach
endif

# 配置编译器和链接器参数
include_args = []
foreach d : include_dirs
  include_args += ['-I' + d]
endforeach

lib_dir_args = []
foreach d : lib_dirs
  lib_dir_args += ['-L' + d]
endforeach

add_global_arguments(include_args + cpp_args, language: 'cpp')
add_global_link_arguments(lib_dir_args + link_args, language: 'cpp')

# 包含API子目录
subdir('vnpy_ctp/api')

# 源文件路径
vnctpmd_src = join_paths(api_rel_dir, 'vnctp', 'vnctpmd', 'vnctpmd.cpp')
vnctptd_src = join_paths(api_rel_dir, 'vnctp', 'vnctptd', 'vnctptd.cpp')

# 在Windows上确保目录存在
if host_system == 'windows'
  run_command('cmd', '/c', 'mkdir', '-p', join_paths(meson.current_source_dir(), vnctpmd_rel_dir), check: false)
  run_command('cmd', '/c', 'mkdir', '-p', join_paths(meson.current_source_dir(), vnctptd_rel_dir), check: false)
endif

# 构建模块
modules = [
  {'name': 'vnctpmd', 'src': vnctpmd_src},
  {'name': 'vnctptd', 'src': vnctptd_src},
]

foreach module : modules
  py.extension_module(module['name'], 
                     sources: [module['src']], 
                     dependencies: [py_dep],
                     link_args: lib_link_args,
                     include_directories: include_directories(vnctp_rel_dir),
                     install: true,
                     subdir: 'vnpy_ctp/api')
endforeach

# 安装目标路径
api_install_dir = py.get_install_dir() / 'vnpy_ctp/api'
vnctp_install_dir = api_install_dir / 'vnctp'
vnctpmd_install_dir = vnctp_install_dir / 'vnctpmd'
vnctptd_install_dir = vnctp_install_dir / 'vnctptd'

# 安装平台特定的库文件
if shared_libs.length() > 0
  foreach lib_file : shared_libs
    foreach search_dir : [api_rel_dir, libs_rel_dir]
      lib_path = join_paths(search_dir, lib_file)
      if fs.exists(lib_path)
        install_data(lib_path, install_dir: api_install_dir)
        break
      endif
    endforeach
  endforeach
endif

# 安装包含文件和库目录
install_subdir('vnpy_ctp/api/include', install_dir: api_install_dir)
install_subdir('vnpy_ctp/api/libs', install_dir: api_install_dir)

# 安装脚本 - 创建__init__.py文件和复制vnctp.h
install_dirs = [api_install_dir, vnctp_install_dir, vnctpmd_install_dir, vnctptd_install_dir]
dir_list = '"' + '","'.join(install_dirs) + '"'
vnctp_h_path = join_paths(meson.current_source_dir(), vnctp_rel_dir, 'vnctp.h')

install_script = '''
import os, shutil
# 创建目录和__init__.py文件
dirs = [''' + dir_list + ''']
for dir_path in dirs:
    os.makedirs(dir_path, exist_ok=True)
    open(os.path.join(dir_path, "__init__.py"), "w").close()

# 复制vnctp.h文件
src_file = "''' + vnctp_h_path + '''"
if os.path.exists(src_file):
    for target_dir in dirs[1:]:
        shutil.copy(src_file, os.path.join(target_dir, "vnctp.h"))
else:
    print("警告: 找不到源vnctp.h文件")
'''

meson.add_install_script('python3', '-c', install_script)
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
proj_root = meson.current_source_dir()
api_dir = proj_root / 'vnpy_ctp/api'
vnctp_dir = api_dir / 'vnctp'
message('构建目标系统: ' + host_system)

# 模块与库定义
lib_names = ['thostmduserapi_se', 'thosttraderapi_se']
module_types = ['md', 'td']
sources = {}
foreach type : module_types
  sources += {type: vnctp_dir / ('vnctp' + type) / ('vnctp' + type + '.cpp')}
endforeach

# Python和pybind11环境
py_mod = import('python')
py = py_mod.find_installation(pure: false)
py_dep = py.dependency()
pybind11_cmd = run_command(py, '-c', 'import pybind11; print(pybind11.get_include())', check: false)
if pybind11_cmd.returncode() != 0
  error('无法找到pybind11，请确保已安装')
endif
pybind11_path = pybind11_cmd.stdout().strip()

# 平台配置
platform_configs = {
  'linux': {
    'include_dirs': [api_dir / 'include', api_dir],
    'lib_dirs': [api_dir],
    'cpp_args': ['-O3', '-Wno-delete-incomplete', '-Wno-sign-compare'],
    'link_args': ['-lstdc++', '-Wl,-rpath,$ORIGIN'],
    'lib_prefix': 'lib',
    'lib_suffix': '.so'
  },
  'windows': {
    'include_dirs': [api_dir / 'include', vnctp_dir, api_dir, pybind11_path],
    'lib_dirs': [api_dir / 'libs', api_dir],
    'cpp_args': ['/EHsc', '/bigobj', '/utf-8', '/wd4828'],
    'link_args': [],
    'lib_prefix': '',
    'lib_suffix': '.dll'
  },
  'darwin': {
    'include_dirs': [api_dir / 'include/mac', vnctp_dir],
    'lib_dirs': [api_dir / 'libs'],
    'cpp_args': ['-mmacosx-version-min=10.12'],
    'link_args': ['-mmacosx-version-min=10.12', '-Wl,-rpath,@loader_path/../api/libs'],
    'lib_prefix': 'lib',
    'lib_suffix': '.dylib'
  }
}

# 检查系统支持
if not platform_configs.has_key(host_system)
  error('不支持的系统: ' + host_system)
endif

# 应用平台特定配置
config = platform_configs[host_system]
include_dirs = config['include_dirs']
lib_dirs = config['lib_dirs']
cpp_args = config['cpp_args']
link_args = config.get('link_args', [])
lib_prefix = config['lib_prefix']
lib_suffix = config['lib_suffix']

# 平台特定库处理
lib_link_args = []
lib_files = []

if host_system == 'windows'
  # Windows库文件处理
  foreach lib_path : lib_dirs
    if import('fs').exists(lib_path / (lib_names[0] + '.lib'))
      foreach lib : lib_names
        lib_link_args += [lib_path / (lib + '.lib')]
      endforeach
      break
    endif
  endforeach
  
  if lib_link_args.length() == 0
    error('无法找到必需的.lib文件')
  endif
  
  # Windows目录创建
  fs = import('fs')
  if not fs.exists(vnctp_dir)
    run_command('cmd', '/c', 'mkdir', '-p', vnctp_dir.split(':')[1], check: false)
  endif
  
  foreach type : module_types
    module_dir = vnctp_dir / ('vnctp' + type)
    if not fs.exists(module_dir)
      run_command('cmd', '/c', 'mkdir', '-p', module_dir.split(':')[1], check: false)
    endif
  endforeach
else
  # 非Windows库文件设置
  foreach lib : lib_names
    lib_link_args += ['-l' + lib]
    lib_files += [lib_prefix + lib + lib_suffix]
  endforeach
endif

# 应用编译参数
foreach dir : include_dirs
  add_project_arguments('-I' + dir, language: 'cpp')
endforeach
foreach dir : lib_dirs
  add_project_link_arguments('-L' + dir, language: 'cpp')
endforeach
add_project_arguments(cpp_args, language: 'cpp')
add_project_link_arguments(link_args, language: 'cpp')

# API子目录
subdir('vnpy_ctp/api')

# 构建扩展模块
foreach type, source : sources
  py.extension_module('vnctp' + type,
    sources: [source],
    dependencies: [py_dep],
    link_args: lib_link_args,
    include_directories: include_directories('vnpy_ctp/api/vnctp'),
    install: true,
    subdir: 'vnpy_ctp/api',
  )
endforeach

# 安装配置
api_install_dir = py.get_install_dir() / 'vnpy_ctp/api'
vnctp_install_dir = api_install_dir / 'vnctp'
init_dirs = [api_install_dir, vnctp_install_dir]
foreach type : module_types
  init_dirs += [vnctp_install_dir / ('vnctp' + type)]
endforeach

# 库文件安装
if host_system != 'darwin' and lib_files.length() > 0
  foreach lib_file : lib_files
    foreach lib_path : lib_dirs
      lib_full_path = lib_path / lib_file
      if import('fs').exists(lib_full_path)
        install_data(lib_full_path, install_dir: api_install_dir)
        break
      endif
    endforeach
  endforeach
endif

# 安装API文件和目录
install_subdir('vnpy_ctp/api/include', install_dir: api_install_dir)
install_subdir('vnpy_ctp/api/libs', install_dir: api_install_dir)

# 安装脚本
vnctp_h_src = vnctp_dir / 'vnctp.h'
init_dirs_str = ''
foreach dir : init_dirs
  init_dirs_str += '    "' + dir + '",\n'
endforeach

install_script = '''
import os, shutil

# 初始化目录
init_dirs = [
''' + init_dirs_str + ''']
vnctp_h_src = "''' + vnctp_h_src + '''"
api_dir = "''' + api_install_dir + '''"

# 创建目录和初始化文件
for dir in init_dirs:
    os.makedirs(dir, exist_ok=True)
    with open(os.path.join(dir, "__init__.py"), "w") as f:
        pass
    
    # 复制vnctp.h到模块目录
    if dir != api_dir and os.path.exists(vnctp_h_src):
        shutil.copy(vnctp_h_src, os.path.join(dir, "vnctp.h"))
'''

meson.add_install_script('python3', '-c', install_script) 

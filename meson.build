project('vnpy_ctp',
  'cpp',
  version: '6.7.2.1',
  default_options: [
    'cpp_std=c++17',
    'warning_level=1',
    'buildtype=release',
  ],
)

# Get system information
host_system = host_machine.system()
message('Building for ' + host_system)

# Define common dependencies
py_mod = import('python')
py = py_mod.find_installation(pure: false)
py_dep = py.dependency()

# Find pybind11 include path directly using Python
pybind11_path = ''
pybind11_cmd = run_command(py, '-c', 'import pybind11; print(pybind11.get_include())', check: false)
if pybind11_cmd.returncode() == 0
  pybind11_path = pybind11_cmd.stdout().strip()
  message('Using pybind11 from: ' + pybind11_path)
else
  error('Could not find pybind11. Make sure it is installed.')
endif

# Platform-specific configurations
if host_system == 'linux'
  # Linux configurations
  include_dirs = [
    'vnpy_ctp/api/include',
    'vnpy_ctp/api',
  ]
  lib_dirs = [
    'vnpy_ctp/api',
  ]
  cpp_args = [
    '-std=c++17',
    '-O3',
    '-Wno-delete-incomplete',
    '-Wno-sign-compare',
  ]
  link_args = [
    '-lstdc++',
    '-Wl,-rpath,$ORIGIN',
  ]
  lib_link_args = []
  foreach lib : ['thostmduserapi_se', 'thosttraderapi_se']
    lib_link_args += ['-l' + lib]
  endforeach
elif host_system == 'windows'
  # Windows configurations
  # Adjust include paths to ensure they work correctly
  proj_root = meson.current_source_dir()
  api_dir = proj_root / 'vnpy_ctp/api'
  include_dir = api_dir / 'include'
  
  message('Project root: ' + proj_root)
  message('API directory: ' + api_dir)
  message('Include directory: ' + include_dir)
  
  include_dirs = [
    include_dir,                # vnpy_ctp/api/include - for standard header files
    api_dir / 'vnctp',          # vnpy_ctp/api/vnctp - for vnctp.h
    api_dir,                    # vnpy_ctp/api - general location
  ]
  
  # Add pybind11 include path
  if pybind11_path != ''
    include_dirs += [pybind11_path]
  endif
  
  lib_dirs = [
    api_dir / 'libs',
    api_dir,
  ]
  
  # Use consistent compile flags - choose either /MD or /MT
  cpp_args = [
    '/O2',
    '/MD',  # Use /MD (multithreaded DLL) consistently
    '/EHsc',
    '/bigobj',
    '/utf-8',  # Use UTF-8 character encoding
    '/wd4828', # Disable warnings for invalid characters
  ]
  
  link_args = []
  
  # On Windows, we need to link the libraries directly as .lib files
  # Use absolute paths
  vnctp_api_path = meson.current_source_dir() / 'vnpy_ctp/api'
  vnctp_api_libs_path = vnctp_api_path / 'libs'
  
  if import('fs').exists(vnctp_api_path / 'thostmduserapi_se.lib')
    lib_link_args = [
      vnctp_api_path / 'thostmduserapi_se.lib',
      vnctp_api_path / 'thosttraderapi_se.lib'
    ]
  elif import('fs').exists(vnctp_api_libs_path / 'thostmduserapi_se.lib')
    lib_link_args = [
      vnctp_api_libs_path / 'thostmduserapi_se.lib',
      vnctp_api_libs_path / 'thosttraderapi_se.lib'
    ]
  else
    error('Could not find the required .lib files')
  endif
elif host_system == 'darwin'
  # MacOS configurations
  include_dirs = [
    'vnpy_ctp/api/include/mac',
    'vnpy_ctp/api/vnctp',
  ]
  lib_dirs = [
    'vnpy_ctp/api/libs',
  ]
  cpp_args = [
    '-std=c++11',
    '-mmacosx-version-min=10.12',
  ]
  link_args = [
    '-mmacosx-version-min=10.12',
  ]
  # Add framework path for runtime libraries
  link_args += ['-Wl,-rpath,@loader_path/../api/libs']
  
  lib_link_args = []
  foreach lib : ['thostmduserapi_se', 'thosttraderapi_se']
    lib_link_args += ['-l' + lib]
  endforeach
else
  error('Unsupported system: ' + host_system)
endif

# Configure compiler and linker
foreach include_dir : include_dirs
  add_project_arguments('-I' + include_dir, language: 'cpp')
endforeach

foreach lib_dir : lib_dirs
  add_project_link_arguments('-L' + lib_dir, language: 'cpp')
endforeach

foreach cpp_arg : cpp_args
  add_project_arguments(cpp_arg, language: 'cpp')
endforeach

foreach link_arg : link_args
  add_project_link_arguments(link_arg, language: 'cpp')
endforeach

# Include API subdirectory meson.build
subdir('vnpy_ctp/api')

# Get source paths
vnctpmd_src = meson.current_source_dir() / 'vnpy_ctp/api/vnctp/vnctpmd/vnctpmd.cpp'
vnctptd_src = meson.current_source_dir() / 'vnpy_ctp/api/vnctp/vnctptd/vnctptd.cpp'

# Add a custom target to copy vnctp.h to correct location if needed
if host_system == 'windows'
  vnctp_h = meson.current_source_dir() / 'vnpy_ctp/api/vnctp/vnctp.h'
  vnctpmd_dir = meson.current_source_dir() / 'vnpy_ctp/api/vnctp/vnctpmd'
  vnctptd_dir = meson.current_source_dir() / 'vnpy_ctp/api/vnctp/vnctptd'
  
  # Create directories if they don't exist
  run_command('cmd', '/c', 'mkdir', '-p', vnctpmd_dir.split(':')[1], check: false)
  run_command('cmd', '/c', 'mkdir', '-p', vnctptd_dir.split(':')[1], check: false)
  
  # No longer copy vnctp.h - we'll use the main file instead
  # Instead, we'll update include paths for both modules
endif

# Build vnctpmd extension
py.extension_module('vnctpmd',
  sources: [vnctpmd_src],
  dependencies: [py_dep],
  link_args: lib_link_args,
  include_directories: include_directories('vnpy_ctp/api/vnctp'), # Add the main vnctp directory as include path
  install: true,
  subdir: 'vnpy_ctp/api',
)

# Build vnctptd extension
py.extension_module('vnctptd',
  sources: [vnctptd_src],
  dependencies: [py_dep],
  link_args: lib_link_args,
  include_directories: include_directories('vnpy_ctp/api/vnctp'), # Add the main vnctp directory as include path
  install: true,
  subdir: 'vnpy_ctp/api',
)

# Install the package data
if host_system == 'windows'
  # Windows DLLs
  foreach dll_file : ['thostmduserapi_se.dll', 'thosttraderapi_se.dll']
    if import('fs').exists('vnpy_ctp/api/' + dll_file)
      install_data('vnpy_ctp/api/' + dll_file, install_dir: py.get_install_dir() / 'vnpy_ctp/api')
    elif import('fs').exists('vnpy_ctp/api/libs/' + dll_file)
      install_data('vnpy_ctp/api/libs/' + dll_file, install_dir: py.get_install_dir() / 'vnpy_ctp/api')
    endif
  endforeach
endif

if host_system == 'linux'
  # Linux shared libraries
  foreach so_file : ['libthostmduserapi_se.so', 'libthosttraderapi_se.so']
    if import('fs').exists('vnpy_ctp/api/' + so_file)
      install_data('vnpy_ctp/api/' + so_file, install_dir: py.get_install_dir() / 'vnpy_ctp/api')
    endif
  endforeach
endif

# Install directories with include files and libs
install_subdir('vnpy_ctp/api/include', install_dir: py.get_install_dir() / 'vnpy_ctp/api')
install_subdir('vnpy_ctp/api/libs', install_dir: py.get_install_dir() / 'vnpy_ctp/api')

# Create the required directory structure and __init__.py files
# This replaces functionality from meson_post_install.py
api_install_dir = py.get_install_dir() / 'vnpy_ctp/api'
vnctp_install_dir = api_install_dir / 'vnctp'
vnctpmd_install_dir = vnctp_install_dir / 'vnctpmd'
vnctptd_install_dir = vnctp_install_dir / 'vnctptd'

# Create __init__.py files for each directory
foreach dir_path : [api_install_dir, vnctp_install_dir, vnctpmd_install_dir, vnctptd_install_dir]
  meson.add_install_script('python3', '-c', 
    'import os; os.makedirs("' + dir_path + '", exist_ok=True); open("' + dir_path / '__init__.py' + '", "w").close()')
endforeach

# Copy vnctp.h file to required locations
vnctp_h = meson.current_source_dir() / 'vnpy_ctp/api/vnctp/vnctp.h'
foreach target_dir : [vnctp_install_dir, vnctpmd_install_dir, vnctptd_install_dir]
  meson.add_install_script('python3', '-c', 
    'import os, shutil; os.makedirs("' + target_dir + '", exist_ok=True); ' +
    'shutil.copy("' + vnctp_h + '", "' + target_dir / 'vnctp.h' + '") if os.path.exists("' + vnctp_h + '") else print("Warning: Could not find source vnctp.h at ' + vnctp_h + '")')
endforeach

# Copy DLL files on Windows if they exist
if host_system == 'windows'
  foreach dll_file : ['thostmduserapi_se.dll', 'thosttraderapi_se.dll']
    meson.add_install_script('python3', '-c',
      'import os, shutil; ' +
      'src_paths = ["' + meson.current_source_dir() / 'vnpy_ctp/api' / dll_file + '", "' + meson.current_source_dir() / 'vnpy_ctp/api/libs' / dll_file + '"]; ' +
      'dest_path = "' + api_install_dir / dll_file + '"; ' +
      'any(shutil.copy(src, dest_path) for src in src_paths if os.path.exists(src)) or print("Warning: Could not find DLL ' + dll_file + ' for copying")')
  endforeach
endif 

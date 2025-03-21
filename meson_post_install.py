#!/usr/bin/env python3
import os
import sys
import platform
import shutil
from pathlib import Path

# Get the installation prefix from the command line arguments
install_prefix = os.environ.get('MESON_INSTALL_PREFIX', '/usr/local')
print(f'Install prefix: {install_prefix}')

# Determine platform-specific paths
if platform.system() == 'Windows':
    # On Windows, use sitepackages directory
    python_path = os.path.join(install_prefix, 'Lib', 'site-packages')
else:
    # On Linux/Mac, use the appropriate site-packages directory
    python_path = os.path.join(install_prefix, 'lib', f'python{sys.version_info.major}.{sys.version_info.minor}', 'site-packages')

# Make sure python_path exists
if not os.path.exists(python_path):
    destdir_prefix = os.environ.get('MESON_INSTALL_DESTDIR_PREFIX')
    if destdir_prefix:
        # Try with DESTDIR prefix if available
        if platform.system() == 'Windows':
            python_path = os.path.join(destdir_prefix, 'Lib', 'site-packages')
        else:
            python_path = os.path.join(destdir_prefix, 'lib', f'python{sys.version_info.major}.{sys.version_info.minor}', 'site-packages')
    else:
        # If we still don't have a valid path, try to find it
        import site
        site_packages = site.getsitepackages()
        if site_packages:
            python_path = site_packages[0]
        else:
            # Last resort - use the current directory
            python_path = os.path.dirname(os.path.abspath(__file__))
            print('Warning: Could not find site-packages directory, using current directory')
    
    print(f'Using python path: {python_path}')

# Define the vnpy_ctp API directory path
api_dir = os.path.join(python_path, 'vnpy_ctp', 'api')
vnctp_dir = os.path.join(api_dir, 'vnctp')
vnctpmd_dir = os.path.join(vnctp_dir, 'vnctpmd')
vnctptd_dir = os.path.join(vnctp_dir, 'vnctptd')

print(f'API directory: {api_dir}')

# Create necessary directories if they don't exist
for directory in [api_dir, vnctp_dir, vnctpmd_dir, vnctptd_dir]:
    os.makedirs(directory, exist_ok=True)
    print(f'Created directory: {directory}')

# Create empty __init__.py files
def ensure_init_file(directory):
    init_file = os.path.join(directory, '__init__.py')
    if not os.path.exists(init_file):
        with open(init_file, 'w') as f:
            pass  # Create an empty file
        print(f'Created __init__.py in {directory}')

ensure_init_file(api_dir)
ensure_init_file(vnctp_dir)
ensure_init_file(vnctpmd_dir)
ensure_init_file(vnctptd_dir)

# Copy vnctp.h file to required locations
source_dir = os.path.dirname(os.path.abspath(__file__))
vnctp_h_source = os.path.join(source_dir, 'vnpy_ctp', 'api', 'vnctp', 'vnctp.h')

if os.path.exists(vnctp_h_source):
    # Copy to the main vnctp directory
    shutil.copy(vnctp_h_source, os.path.join(vnctp_dir, 'vnctp.h'))
    print(f'Copied vnctp.h to {vnctp_dir}')
    
    # Copy to vnctpmd directory
    shutil.copy(vnctp_h_source, os.path.join(vnctpmd_dir, 'vnctp.h'))
    print(f'Copied vnctp.h to {vnctpmd_dir}')
    
    # Copy to vnctptd directory
    shutil.copy(vnctp_h_source, os.path.join(vnctptd_dir, 'vnctp.h'))
    print(f'Copied vnctp.h to {vnctptd_dir}')
else:
    print(f'Warning: Could not find source vnctp.h at {vnctp_h_source}')

# Copy DLL files on Windows
if platform.system() == 'Windows':
    dll_files = ['thostmduserapi_se.dll', 'thosttraderapi_se.dll']
    
    for dll_file in dll_files:
        # Try to find the DLL in different possible locations
        source_paths = [
            os.path.join(source_dir, 'vnpy_ctp', 'api', dll_file),
            os.path.join(source_dir, 'vnpy_ctp', 'api', 'libs', dll_file)
        ]
        
        dll_found = False
        for source_path in source_paths:
            if os.path.exists(source_path):
                dest_path = os.path.join(api_dir, dll_file)
                if not os.path.exists(dest_path):
                    shutil.copy(source_path, dest_path)
                    print(f'Copied {dll_file} to {api_dir}')
                dll_found = True
                break
        
        if not dll_found:
            print(f'Warning: Could not find DLL {dll_file} for copying')

print('Post-installation process completed successfully.') 
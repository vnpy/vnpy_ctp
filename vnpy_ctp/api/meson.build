# This file will be included from the main meson.build
# It contains the specific configuration for the API modules

# Ensure __init__.py exists for the Python module
if not import('fs').exists('__init__.py')
  init_py = configure_file(
    output: '__init__.py',
    command: ['touch', '@OUTPUT@'],
  )
endif 
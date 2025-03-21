"""
Re-export CTP constants with type annotations.
This module helps static type checkers understand the constants.
"""
from typing import Dict, Any

# Import everything from original module
from .ctp_constant import *

# Create a dictionary of all variables that start with THOST_FTDC_
# This helps static type checkers understand these are all string constants
__all_constants__: Dict[str, str] = {
    name: value for name, value in globals().items() 
    if name.startswith('THOST_FTDC_') and isinstance(value, str)
}

# Export everything from the original module
__all__ = list(__all_constants__.keys()) 
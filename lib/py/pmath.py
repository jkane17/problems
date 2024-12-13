
"""
    File:
        pmath.py
    
    Description:
        Mathematical functions.
"""

import math

golden_ratio = 0.5 * (1 + math.sqrt(5))
golden_ratio_conjugate = 1 - golden_ratio

def fibn(n):
    """Compute the n-th number of the Fibonacci sequence"""
    return int((golden_ratio ** n - golden_ratio_conjugate ** n) / math.sqrt(5))


"""
    @file
        pmath.py
    
    @description
        Mathematical functions.
"""

import math

golden_ratio = 0.5 * (1 + math.sqrt(5))
golden_ratio_conjugate = 1 - golden_ratio

def fibn(n: int) -> int:
    """Compute the n-th number of the Fibonacci sequence."""
    return int((golden_ratio ** n - golden_ratio_conjugate ** n) / math.sqrt(5))

def get_primes(n: int) -> list[int]:
    """Get an array of primes less than or equal to some number."""
    prime = [True] * (n + 1)

    for p in range(2, 1 + math.isqrt(n)):
        if prime[p]:
            for i in range(p * p, n + 1, p):
                prime[i] = False
            
    primes = [i + 2 for i, isprime in enumerate(prime[2:]) if isprime]
    return primes

def is_palindrome(number: int) -> bool:
    """Is a number a palindrome?"""
    original = number
    reversed = 0
    while number != 0:
        remainder = number % 10               # Get the last digit
        reversed = reversed * 10 + remainder  # Build the reversed number
        number //= 10                         # Remove the last digit
    return original == reversed

def nsum(x):
    """Sum of the first x positive integers."""
    return int(.5 * x * (x + 1))

def n2sum(x):
    """Sum of the squares of the first x positive integers."""
    return (x * (1 + 2 * x) * (x + 1)) // 6

def prime_factorise(n: int) -> list[int]:
    """Get the prime factors of a given number (using trial division)."""
    factors = []
    remaining = n
    
    if n > 3:
        primes = get_primes(math.isqrt(n)) 
        for p in primes:
            while remaining % p == 0:
                remaining //= p
                factors.append(p)

        # If remaining is greater than 1, it is a prime factor
        if remaining > 1:
            factors.append(remaining)

    else:
        factors.append(n)

    return factors

def is_prime(n):
    """Check if a number is prime"""
    if n < 2: 
        return False
    for i in range(2, 1 + int(sqrt(n))):
        if n % i == 0: 
            return False
    return True

def nprimes(n):
    """Generate the first n primes"""
    if n < 1: 
        return []

    primes = [2, 3]
    k = 6

    while len(primes) < n:
        for candidate in (k - 1, k + 1):
            if is_prime(candidate):
                primes.append(candidate)
                if len(primes) == n:
                    break
        k += 6

    return primes[:n]


/*
    File:
        pmath.h
    
    Description:
        Mathematical functions.
*/

#ifndef PMATH_H_INCLUDED
#define PMATH_H_INCLUDED

#include <stdint.h>

/**
 * @brief Compute the n-th number of the Fibonacci sequence.
 * 
 * @param n N-th number to compute.
 * @return N-th number of the Fibonacci sequence.
 */
uint64_t pmath_fibn(uint64_t n);

/**
 * @brief Is a number a palindrome?
 * 
 * @param number Number to check.
 * @return true if number is a palindrome, false otherwise.
 */
bool pmath_isPalindrome(uint64_t number);

/**
 * @brief Get an array of primes less than or equal to some number.
 * 
 * @param n Primes less than or equal to this number.
 * @param nprimes Location to store size of output array.
 * @return Array of primes (user responsible for deallocation).
 */
uint64_t *pmath_getPrimes(uint64_t n, uint64_t *nprimes);

/**
 * @brief Get the prime factors of a given number (using trial division).
 * 
 * @param n Number to get prime factors of.
 * @param nfactors Location to store size of output array.
 * @return Array of prime factors (user responsible for deallocation).
 */
uint64_t *pmath_primeFactorise(uint64_t n, uint64_t *nfactors);

#endif // #ifndef PMATH_H_INCLUDED

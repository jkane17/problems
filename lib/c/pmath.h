
/*
    @file
        pmath.h
    
    @description
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
 * @brief brief Greatest common divisor of two numbers (Euclidean algorithm).
 * 
 * @param x First number.
 * @param y Second number.
 * @return Greatest common divisor. 
 */
uint64_t pmath_gcd(uint64_t x, uint64_t y);

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
 * @brief Sum of the first x positive integers.
 * 
 * @param x Number of positive integers.
 * @return Sum. 
 */
inline uint64_t pmath_nsum(uint64_t x);
 
/**
 * @brief Sum of the squares of the first x positive integers.
 * 
 * @param x Number of positive integers.
 * @return Sum. 
 */
inline uint64_t pmath_n2sum(uint64_t x);

/**
 * @brief Get the prime factors of a given number (using trial division).
 * 
 * @param n Number to get prime factors of.
 * @param nfactors Location to store size of output array.
 * @return Array of prime factors (user responsible for deallocation).
 */
uint64_t *pmath_primeFactorise(uint64_t n, uint64_t *nfactors);

/**
 * @brief Check if a number is prime.
 * 
 * @param n Number to check.
 * @return true if number is prime, false otherwise.
 */
bool isPrime(uint64_t n);

/**
 * @brief Generate the first n primes.
 * 
 * @param n Number of primes.
 * @return Primes array (user owns memory).
 */
uint64_t *nprimes(uint64_t n);

#endif // #ifndef PMATH_H_INCLUDED

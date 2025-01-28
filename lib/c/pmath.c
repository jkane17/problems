
/*
    @file
        pmath.c
    
    @description
        Mathematical functions.
*/

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "pmath.h"

const double GOLDEN_RATIO = 1.618033988749895;
const double GOLDEN_RATIO_CONJUGATE = -0.6180339887498949;

uint64_t pmath_fibn(uint64_t n) {
    return (pow(GOLDEN_RATIO, n) - pow(GOLDEN_RATIO_CONJUGATE, n)) / sqrt(5);
}

uint64_t pmath_gcd(uint64_t x, uint64_t y) {
    uint64_t tmp;
    while (y > 0) {
        tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}

bool pmath_isPalindrome(uint64_t number) {
    uint64_t remainder, original = number, reversed = 0;
    while (number != 0) {
        remainder = number % 10;              // Get the last digit
        reversed = reversed * 10 + remainder; // Build the reversed number
        number /= 10;                         // Remove the last digit
    }
    return original == reversed;
}

uint64_t *pmath_getPrimes(uint64_t n, uint64_t *nprimes) {
    bool *prime = (bool*)malloc((n + 1) * sizeof(bool));
    if (prime == NULL) return NULL;
    memset(prime, true, (n + 1) * sizeof(bool));
    
    for (uint64_t p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (uint64_t i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    
    *nprimes = 0;
    uint64_t *primes = (uint64_t*)malloc((n + 1) * sizeof(uint64_t));
    if (primes == NULL) {
        free(prime);
        return NULL;
    }

    for (uint64_t i = 2; i <= n; i++) {
        if (prime[i]) {
            primes[(*nprimes)++] = i;
        }
    }

    primes = (uint64_t*)realloc(primes, *nprimes * sizeof(uint64_t));
    free(prime);

    return primes;
}

inline uint64_t pmath_nsum(uint64_t x) { return .5 * x * (x + 1); }

inline uint64_t pmath_n2sum(uint64_t x) { return (x * (1 + 2 * x) * (x + 1)) / 6; }

uint64_t *pmath_primeFactorise(uint64_t n, uint64_t *nfactors) {
    uint64_t nf = 1;
    uint64_t allocatedSize = 10;
    uint64_t *factors = (uint64_t*)malloc(allocatedSize * sizeof(uint64_t));
    if (factors == NULL) return NULL;
    factors[0] = n;
    
    if (n > 3) {
        uint64_t i, p, nprimes;
        uint64_t *primes = pmath_getPrimes((uint64_t)floor(sqrt(n)), &nprimes);
        if (primes == NULL) {
            free(factors);
            return NULL;
        }
        for (i = 0; i < nprimes; i++) {
            p = primes[i];
            while (0 == factors[0] % p) {
                factors[0] /= p;
                if (nf >= allocatedSize) {
                    allocatedSize *= 2;
                    factors = (uint64_t*)realloc(factors, allocatedSize * sizeof(uint64_t));
                    if (factors == NULL) {
                        free(primes);
                        return NULL;
                    }
                }
                factors[nf++] = p;
            }
        }
        free(primes);
        // Remove the "leftover" 1 after division (if applicable)
        if (factors[0] < 2) {
            nf--;
            memmove(factors, factors + 1, nf * sizeof(uint64_t));
            factors = (uint64_t*)realloc(factors, nf * sizeof(uint64_t));
        }
    }

    // Reallocate to the exact size needed
    factors = (uint64_t*)realloc(factors, nf * sizeof(uint64_t));
    if (factors == NULL) return NULL;

    *nfactors = nf;
    return factors;
}

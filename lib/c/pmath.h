
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

#endif // #ifndef PMATH_H_INCLUDED

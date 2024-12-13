
/*
    File:
        pmath.c
    
    Description:
        Mathematical functions.
*/

#include <math.h>
#include <stdint.h>

#include "pmath.h"

const double GOLDEN_RATIO = 1.618033988749895;
const double GOLDEN_RATIO_CONJUGATE = -0.6180339887498949;

uint64_t pmath_fibn(uint64_t n) {
    return (pow(GOLDEN_RATIO, n) - pow(GOLDEN_RATIO_CONJUGATE, n)) / sqrt(5);
}

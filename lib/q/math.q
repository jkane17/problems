
/
    File:
        math.q
    
    Description:
        Mathematical functions.
\

// @brief First x+2 numbers in the Fibonacci sequence.
// @param x Long Number of additional (includes 0 & 1) numbers required.
// @return Longs Fibonacci numbers.
.math.fib:{x,sum -2#x}/[;0 1];

// @brief Fibonacci numbers below some maximum.
// @param x Long Maximum.
// @return Longs Fibonacci numbers.
.math.fibm:-1_.math.fib {x>last y}@;

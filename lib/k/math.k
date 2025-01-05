
/
    File:
        math.k
    
    Description:
        Mathematical functions.
\

// @brief First x+2 numbers in the Fibonacci sequence.
// @param x Long Number of additional (includes 0 & 1) numbers required.
// @return Longs Fibonacci numbers.
.math.fib:{x,+/-2#x}/[;0 1];

// @brief Fibonacci numbers below some maximum.
// @param x Long Maximum.
// @return Longs Fibonacci numbers.
.math.fibm:-1_.math.fib {x>(:/)y}@;

// @brief Prime factorisation using trial division.
// @param x Integer Number to factorise.
// @return Integers Prime factors.
.math.pfact:{$[x<4;x;1<*p:{(0={x-y*_x%y}[;y] (*:)@){x[0]:_x[0]%y;x,y}[;y]/x}/[1#x;.math.primes (-_-:)sqrt x];p;1_p]};

// @brief Get primes using Sieve of Eratosthenes (best where n > 10^5).
// @param x Integer Primes up to, and including, this number.
// @return Integers Primes.
.math.primes:{{x,1+&:y}. ({max z#y}[;;_sqrt x].) ({(x,n;@[y;1_-1+n*!1+_(#y)%n:1+y?1b;:;0b])}.)/(2;0b,1_x#10b)};

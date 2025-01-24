
/
    @file
        math.q
    
    @description
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

// @brief Greatest common divisor of two numbers (Euclidean algorithm).
// @param x Long|Int|Short First number.
// @param y Long|Int|Short Second number.
// @returns Long|Int Greatest common divisor.
.math.gcd:{first last({y,x mod y}.)/x,y};

// @brief Prime factorisation using trial division.
// @param x Integer Number to factorise.
// @return Integers Prime factors.
.math.pfact:{
    if[x<4;:x];
    p:{(0=mod[;y] first@){x[0]:x[0] div y;x,y}[;y]/x}/[1#x;.math.primes ceiling sqrt x];
    $[1<p 0;p;1_p]
 };

// @brief Get primes using Sieve of Eratosthenes (best where n > 10^5).
// @param x Integer Primes up to, and including, this number.
// @return Integers Primes.
.math.primes:{
    sieve:{(x,n; @[y;1_-1+n*til 1+count[y] div n:1+y?1b;:;0b])}.;
    {x,1+where y}. ({any z#y}[;;floor sqrt x].) sieve/(2;0b,1_x#10b)
 };

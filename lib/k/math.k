
/
    @file
        math.k
    
    @description
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

// @brief Greatest common divisor of two numbers (Euclidean algorithm)
// @param x Long|Int|Short First number.
// @param y Long|Int|Short Second number.
// @returns Long|Int Greatest common divisor.
,math.gcd:{*(:/)({y,.math.mod[x;y]}.)/x,y};

// @brief Modulo of two numbers.
// @param x Long|Int|Short First number.
// @param y Long|Int|Short Second number.
// @returns Long|Int Modulus.
.math.mod:{x-y*x div y};

// @brief Prime factorisation using trial division.
// @param x Integer Number to factorise.
// @return Integers Prime factors.
.math.pfact:{$[x<4;x;1<*p:{(0={x-y*_x%y}[;y] (*:)@){x[0]:_x[0]%y;x,y}[;y]/x}/[1#x;.math.primes (-_-:)sqrt x];p;1_p]};

// @brief Get primes using Sieve of Eratosthenes (best where n > 10^5).
// @param x Integer Primes up to, and including, this number.
// @return Integers Primes.
.math.primes:{{x,1+&:y}. ({max z#y}[;;_sqrt x].) ({(x,n;@[y;1_-1+n*!1+_(#y)%n:1+y?1b;:;0b])}.)/(2;0b,1_x#10b)};

// @brief Check if a number is prime.
// @param x Long|Int|Short Number to check.
// @return boolean 1b if number is prime, 0b otherwise.
.math.isPrime:{(~x=1)&~0 in .math.mod[x;] 1_1+!_sqrt x};

// @brief Generate the first n primes.
// @param n Long|Int|Short Number of primes.
// @return Longs Primes.
.math.nprimes:{[n] n#(:/)(n>#(:/)@){(x[0]+:1;x[1],p@&.math.isPrime'p:-1 1+6*x 0)}/(1;2 3)};

// @brief Get Pythagorean Triplets that satisfy a + b + c = x.
// @param Short|Int|Long Required result of a + b + c.
// @return List List of triplets that satisfy the a + b + c = x.
.math.pyTriplet:{m:range .(-_-:;_:)@'sqrt[x]%2,sqrt 2; n:(-m)+x div 2*m; a:2*m*n; b:(-). mn2:"j"$(m;n) xexp 2; c:+/mn2; i:&x=+/v:0|(a;b;c); +v[;i]};

/*
Objective : Find GCD of two numbers
        Find the GCD of 'm' and 'n'
        Input: Pre-condition Two non-negative or non-zero integers 'm' and 'n'. Basically  m > 0, n > 0 .
        Output: The GCD of two numbers 
// Algorithm 1: Euccid                               // This Algorithm is faster but it increments too much; ex. 60->24->12       
    while (n!=0) do:
                        r = (m mod n)                // r = reminder 
                        m = n
                        n = r
    return m
    // Ex.1: Find GCD of 60 and 24;  gcd(60,24)

            Loop 1: 
                    60 mod 24 = 12
                    r = 12
                    m = 24
                    n = 12
            Loop 2:
                    24 mod 12 = 0
                    r = 0
                    m = 12
                    n = 0
            return m                                 // since 'n' is '0'


*/
class Solution {
public:
    double binaryExp(double x, long long n) {
        if (n == 0) {
            return 1;
        }
       
        // Perform Binary Exponentiation.
        double result = 1;
        long long N = n;
        if(n < 0) N = -N;
        while (N) {
            // If 'n' is odd we multiply result with 'x' and reduce 'n' by '1'.
            if ( N % 2 == 1) {
                result = result * x;
                N -= 1;
            }
            // We square 'x' and reduce 'n' by half, x^n => (x^2)^(n/2).
            x = x * x;
            N = N / 2;
        }
        if(n < 0) return (double)1/(double)result;
        return result;
    }

    double myPow(double x, int n) {
        return binaryExp(x, (long long) n);
    }
};
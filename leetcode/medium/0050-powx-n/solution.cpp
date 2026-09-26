class Solution {
private:
    double helper(double x, long n) {
        if (n == 0) return 1.0;
        if (n < 0) return 1.0 / helper(x, -n);
        
        if (n % 2 == 0) {
            double half_pow = helper(x, n / 2);
            return half_pow * half_pow;
        }
        return x * helper(x, n - 1);
    }

public:
    double myPow(double x, int n) {
        return helper(x, n);
    }
};
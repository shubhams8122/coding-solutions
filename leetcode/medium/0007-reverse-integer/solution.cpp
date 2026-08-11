class Solution {
public:
    int reverse(int x) {
        int last_digit;
        int n = 0;
        while(x!=0){
            last_digit = x % 10;

            if(n > INT_MAX /10 || (n == INT_MAX / 10 && last_digit > 7)) return 0;
            if (n < INT_MIN / 10 || (n == INT_MIN / 10 && last_digit < -8)) return 0;
            n = n*10 + last_digit;
            x = x /10;
        }
        return n;
    }
};
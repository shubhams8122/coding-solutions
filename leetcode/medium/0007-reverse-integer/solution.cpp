class Solution {
public:
    int reverse(int x) {
        int last_digit;
        long n = 0;
        while(x!=0){
            last_digit = x % 10;
            n = n*10 + last_digit;
            x = x /10;
        }
        return n;
    }
};
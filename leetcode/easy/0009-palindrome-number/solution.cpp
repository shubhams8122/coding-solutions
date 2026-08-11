class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int n1 = x;
        long long n = 0; 
        
        while (x != 0) {
            int last_digit = x % 10;
            n = n * 10 + last_digit;
            x = x / 10;
        }
        
        return (n == n1);
    }
};
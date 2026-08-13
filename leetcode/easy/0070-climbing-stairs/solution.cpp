class Solution {
public:
    int climbStairs(int n) {
        if (n<=3) return n;
        int first = 2;
        int second = 1;
        int current = 0;
        for(int i = 3; i<=n ; ++i){
            current = second + first;
            second = first;
            first = current;
        }
        return first;
    }
};
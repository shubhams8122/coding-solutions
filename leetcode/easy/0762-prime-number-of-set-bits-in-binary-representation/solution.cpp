class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int primeMask = 665772;
        int count =0;

        for(int i = left; i <= right; i++){
            int setBits = __builtin_popcount(i);
            if((primeMask & (1 << setBits)) != 0){
                count++;
            }
        }
        return count;
    }
};
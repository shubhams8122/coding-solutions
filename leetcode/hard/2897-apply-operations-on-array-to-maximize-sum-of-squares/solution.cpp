class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;
        vector<int> bit_count(31,0);

        for(int num : nums){
            for(int i = 0; i < 31; ++i){
                if((num >> i) & 1){
                    bit_count[i]++;
                }
            }
        }
        long long total_sum = 0;

        for(int step = 0; step < k; ++step){
            long long current_num = 0;
            for(int i = 0; i < 31; ++i){
                if(bit_count[i] > 0){
                    current_num |= (1LL << i);
                    bit_count[i]--;
                }
            }
            total_sum = (total_sum + (current_num % MOD) *(current_num % MOD)) % MOD;
        }
        return total_sum;
    }
};
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long odd_count = 0;
        long long even_count = 1; // Base case: prefix sum 0 is even
        long long current_sum = 0;
        long long total_subarrays = 0;
        int MOD = 1e9 + 7;

        for (int num : arr) {
            current_sum += num;

            if (current_sum % 2 != 0) {
                // Current prefix sum is odd, add count of previous even prefix sums
                total_subarrays = (total_subarrays + even_count) % MOD;
                odd_count++;
            } else {
                // Current prefix sum is even, add count of previous odd prefix sums
                total_subarrays = (total_subarrays + odd_count) % MOD;
                even_count++;
            }
        }

        return total_subarrays;
    }
};
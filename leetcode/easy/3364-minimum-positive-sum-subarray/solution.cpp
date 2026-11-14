#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
        int min_sum = INT_MAX;
        int n = nums.size();
        
        // Iterate through all possible starting positions of the subarray
        for (int i = 0; i < n; ++i) {
            int current_sum = 0;
            // Extend the subarray length from i up to min(n - 1, i + r - 1)
            for (int j = i; j < n && (j - i + 1) <= r; ++j) {
                current_sum += nums[j];
                // Check if the length is at least l and sum is positive
                if ((j - i + 1) >= l && current_sum > 0) {
                    min_sum = std::min(min_sum, current_sum);
                }
            }
        }
        
        // Return -1 if no valid positive sum subarray was found
        return (min_sum == INT_MAX) ? -1 : min_sum;
    }
};
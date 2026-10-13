#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<long long> sq(n);
        
        // Step 1: Compute squares using static_cast to prevent 32-bit overflow
        for (int i = 0; i < n; ++i) {
            sq[i] = static_cast<long long>(nums[i]) * nums[i];
        }
        
        // Step 2: Sort the squared values in ascending order
        std::sort(sq.begin(), sq.end());
        
        // Step 3: Subtract the smaller half, add the larger half
        long long score = 0;
        int num_negative = n / 2;
        
        for (int i = 0; i < num_negative; ++i) {
            score -= sq[i];
        }
        for (int i = num_negative; i < n; ++i) {
            score += sq[i];
        }
        
        return score;
    }
};
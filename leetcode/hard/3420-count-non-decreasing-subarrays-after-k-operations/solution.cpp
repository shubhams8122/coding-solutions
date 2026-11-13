class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long ops = 0;
        deque<int> dq; // Stores indices of running maximums in increasing order
        
        int r = n - 1;
        for (int l = n - 1; l >= 0; --l) {
            // Merge smaller elements to the right up to nums[l]
            while (!dq.empty() && nums[dq.back()] <= nums[l]) {
                int curr = dq.back();
                dq.pop_back();
                int next_bound = dq.empty() ? r + 1 : dq.back();
                ops += 1LL * (next_bound - curr) * (nums[l] - nums[curr]);
            }
            dq.push_back(l);
            
            // Shrink window from the right if operations exceed k
            while (ops > k) {
                int max_idx = dq.front();
                ops -= (nums[max_idx] - nums[r]);
                if (max_idx == r) {
                    dq.pop_front();
                }
                r--;
            }
            
            ans += (r - l + 1);
        }
        
        return ans;
    }
};
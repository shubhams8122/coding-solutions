#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        unordered_map<int, int> dp;
        int ans = 0;
        
        for (int x : nums) {
            dp[x + 1] = dp[x] + 1;
            dp[x] = dp[x - 1] + 1;
            ans = max({ans, dp[x + 1], dp[x]});
        }
        
        return ans;
    }
};
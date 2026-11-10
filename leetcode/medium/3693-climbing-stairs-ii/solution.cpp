class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n+1, LLONG_MAX);
        dp[0] = 0;
        for (int j = 1; j <= n; ++j) {
            // Try transitioning from j - 1, j - 2, and j - 3
            for (int i = std::max(0, j - 3); i < j; ++i) {
                if (dp[i] != LLONG_MAX) {
                    // Note: costs array is 1-indexed, so costs[j] corresponds to costs[j-1] in 0-indexed vector.
                    long long cost = dp[i] + costs[j - 1] + (long long)(j - i) * (j - i);
                    dp[j] = std::min(dp[j], cost);
                }
            }
        }
        
        return dp[n];
    }
};
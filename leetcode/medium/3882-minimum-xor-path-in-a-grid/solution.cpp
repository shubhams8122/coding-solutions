class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[j] stores the set of possible XOR values to reach column j
        vector<unordered_set<int>> dp(n);
        
        // Initialize the top-left cell
        dp[0].insert(grid[0][0]);
        
        // Initialize the first row
        for (int j = 1; j < n; ++j) {
            for (int val : dp[j - 1]) {
                dp[j].insert(val ^ grid[0][j]);
            }
        }
        
        // Process the remaining rows
        for (int i = 1; i < m; ++i) {
            vector<unordered_set<int>> next_dp(n);
            
            // Initialize the first column of the current row (can only come from above)
            for (int val : dp[0]) {
                next_dp[0].insert(val ^ grid[i][0]);
            }
            
            // Fill the rest of the columns
            for (int j = 1; j < n; ++j) {
                // Paths coming from the left cell
                for (int val : next_dp[j - 1]) {
                    next_dp[j].insert(val ^ grid[i][j]);
                }
                // Paths coming from the top cell
                for (int val : dp[j]) {
                    next_dp[j].insert(val ^ grid[i][j]);
                }
            }
            // Move to the next row
            dp = move(next_dp);
        }
        
        // The answer is the minimum value in the bottom-right cell's set
        int min_xor = *min_element(dp[n - 1].begin(), dp[n - 1].end());
        return min_xor;
    }
};

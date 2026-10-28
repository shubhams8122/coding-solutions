# Minimum XOR Path in a Grid

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a 2D integer array `grid` of size `m * n`.

You start at the  **top-left**  cell `(0, 0)` and want to reach the  **bottom-right**  cell `(m - 1, n - 1)`.

At each step, you  **may**  move either  **right or down**.

The  **cost**  of a path is defined as the  **bitwise XOR**  of all the values in the cells along that path,  **including**  the start and end cells.

Return the  **minimum**  possible XOR value among all valid paths from `(0, 0)` to `(m - 1, n - 1)`.

 

 **Example 1:** 

 **Input:**  grid = [[1,2],[3,4]]

 **Output:**  6

 **Explanation:** 

There are two valid paths:

- (0, 0) → (0, 1) → (1, 1) with XOR: 1 XOR 2 XOR 4 = 7
- (0, 0) → (1, 0) → (1, 1) with XOR: 1 XOR 3 XOR 4 = 6

The minimum XOR value among all valid paths is 6.

 **Example 2:** 

 **Input:**  grid = [[6,7],[5,8]]

 **Output:**  9

 **Explanation:** 

There are two valid paths:

- (0, 0) → (0, 1) → (1, 1) with XOR: 6 XOR 7 XOR 8 = 9
- (0, 0) → (1, 0) → (1, 1) with XOR: 6 XOR 5 XOR 8 = 11

The minimum XOR value among all valid paths is 9.

 **Example 3:** 

 **Input:**  grid = [[2,7,5]]

 **Output:**  0

 **Explanation:** 

There is only one valid path:

- (0, 0) → (0, 1) → (0, 2) with XOR: 2 XOR 7 XOR 5 = 0

The XOR value of this path is 0, which is the minimum possible.

 

 **Constraints:** 

- 1 <= m == grid.length <= 1000
- 1 <= n == grid[i].length <= 1000
- m * n <= 1000
- 0 <= grid[i][j] <= 1023​

## Solution

**Language:** C++  
**Runtime:** 3046 ms (beats 5.38%)  
**Memory:** 495.3 MB (beats 6.20%)  
**Submitted:** 2026-10-28T16:52:00.755Z  

```cpp
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

```

---

[View on LeetCode](https://leetcode.com/problems/minimum-xor-path-in-a-grid/)
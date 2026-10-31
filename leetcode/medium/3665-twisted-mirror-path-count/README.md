# Twisted Mirror Path Count

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an `m x n` binary grid `grid` where:

- grid[i][j] == 0 represents an empty cell, and
- grid[i][j] == 1 represents a mirror.

A robot starts at the top-left corner of the grid `(0, 0)` and wants to reach the bottom-right corner `(m - 1, n - 1)`. It can move only  **right**  or  **down**. If the robot attempts to move into a mirror cell, it is  **reflected**  before entering that cell:

- If it tries to move right into a mirror, it is turned down and moved into the cell directly below the mirror.
- If it tries to move down into a mirror, it is turned right and moved into the cell directly to the right of the mirror.

If this reflection would cause the robot to move outside the `grid` boundaries, the path is considered invalid and should not be counted.

Return the number of unique valid paths from `(0, 0)` to `(m - 1, n - 1)`.

Since the answer may be very large, return it  **modulo**  `109 + 7`.

 **Note** : If a reflection moves the robot into a mirror cell, the robot is immediately reflected again based on the direction it used to enter that mirror: if it entered while moving right, it will be turned down; if it entered while moving down, it will be turned right. This process will continue until either the last cell is reached, the robot moves out of bounds or the robot moves to a non-mirror cell.

 

 **Example 1:** 

 **Input:**  grid = [[0,1,0],[0,0,1],[1,0,0]]

 **Output:**  5

 **Explanation:** 

Number	Full Path
1	(0, 0) → (0, 1) [M] → (1, 1) → (1, 2) [M] → (2, 2)
2	(0, 0) → (0, 1) [M] → (1, 1) → (2, 1) → (2, 2)
3	(0, 0) → (1, 0) → (1, 1) → (1, 2) [M] → (2, 2)
4	(0, 0) → (1, 0) → (1, 1) → (2, 1) → (2, 2)
5	(0, 0) → (1, 0) → (2, 0) [M] → (2, 1) → (2, 2)
- [M] indicates the robot attempted to enter a mirror cell and instead reflected.

 **Example 2:** 

 **Input:**  grid = [[0,0],[0,0]]

 **Output:**  2

 **Explanation:** 

Number	Full Path
1	(0, 0) → (0, 1) → (1, 1)
2	(0, 0) → (1, 0) → (1, 1)

 **Example 3:** 

 **Input:**  grid = [[0,1,1],[1,1,0]]

 **Output:**  1

 **Explanation:** 

Number	Full Path
1	(0, 0) → (0, 1) [M] → (1, 1) [M] → (1, 2)
`(0, 0) → (1, 0) [M] → (1, 1) [M] → (2, 1)` goes out of bounds, so it is invalid.

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 2 <= m, n <= 500
- grid[i][j] is either 0 or 1.
- grid[0][0] == grid[m - 1][n - 1] == 0

## Solution

**Language:** C++  
**Runtime:** 1179 ms (beats 18.34%)  
**Memory:** 489.5 MB (beats 21.67%)  
**Submitted:** 2026-10-31T16:58:51.542Z  

```cpp
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;

        // dp[i][j][dir]: number of paths arriving at (i, j) 
        // dir = 0: arrived by moving RIGHT
        // dir = 1: arrived by moving DOWN
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, 0)));

        // Base case: at start cell (0,0)
        // If (0,0) is empty, we can start moving Right or Down from here.
        // If (0,0) is a mirror, handle deflection accordingly.
        if (grid[0][0] == 0) {
            // From (0,0), we can initially move Right or Down
            if (n > 1) dp[0][1][0] = (dp[0][1][0] + 1) % MOD;
            if (m > 1) dp[1][0][1] = (dp[1][0][1] + 1) % MOD;
        } else {
            // Mirror at (0,0) deflects start moves
            if (m > 1) dp[1][0][1] = (dp[1][0][1] + 1) % MOD; // Right turns Down
            if (n > 1) dp[0][1][0] = (dp[0][1][0] + 1) % MOD; // Down turns Right
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int dir = 0; dir < 2; ++dir) {
                    if (dp[i][j][dir] == 0) continue;
                    
                    int count = dp[i][j][dir];

                    if (grid[i][j] == 0) {
                        // Regular cell: Can move Right or Down
                        // 1. Move Right to (i, j+1) with dir = 0
                        if (j + 1 < n) {
                            dp[i][j + 1][0] = (dp[i][j + 1][0] + count) % MOD;
                        }
                        // 2. Move Down to (i+1, j) with dir = 1
                        if (i + 1 < m) {
                            dp[i + 1][j][1] = (dp[i + 1][j][1] + count) % MOD;
                        }
                    } else {
                        // Mirror cell: Deflects based on incoming direction
                        if (dir == 0) {
                            // Arrived moving RIGHT -> Deflected DOWN to (i+1, j)
                            if (i + 1 < m) {
                                dp[i + 1][j][1] = (dp[i + 1][j][1] + count) % MOD;
                            }
                        } else {
                            // Arrived moving DOWN -> Deflected RIGHT to (i, j+1)
                            if (j + 1 < n) {
                                dp[i][j + 1][0] = (dp[i][j + 1][0] + count) % MOD;
                            }
                        }
                    }
                }
            }
        }

        // Total ways to reach (m-1, n-1) from either arrival direction
        int result = (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
        
        // Edge case: grid of size 1x1
        if (m == 1 && n == 1) return 1;

        return result;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/twisted-mirror-path-count/)
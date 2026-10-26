# Count Islands With Total Value Divisible by K

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an `m x n` matrix `grid` and a positive integer `k`. An  **island**  is a group of  **positive**  integers (representing land) that are  **4-directionally**  connected (horizontally or vertically).

The  **total value**  of an island is the sum of the values of all cells in the island.

Return the number of islands with a total value  **divisible by**  `k`.

 

 **Example 1:** 

 **Input:**  grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5

 **Output:**  2

 **Explanation:** 

The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted in red do not.

 **Example 2:** 

 **Input:**  grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3

 **Output:**  6

 **Explanation:** 

The grid contains six islands, each with a total value that is divisible by 3.

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 1000
- 1 <= m * n <= 105
- 0 <= grid[i][j] <= 106
- 1 <= k <= 106

## Solution

**Language:** C++  
**Runtime:** 1852 ms (beats 5.14%)  
**Memory:** 101.3 MB (beats 38.76%)  
**Submitted:** 2026-10-26T01:54:38.018Z  

```cpp
class Solution {
public:
    long long dfs(vector<vector<int>>& grid, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return 0;
        }

        long long sum = grid[r][c];
        grid[r][c] = 0; // Mark as visited in-place

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto& dir : dirs) {
            sum += dfs(grid, r + dir[0], c + dir[1], m, n);
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long totalValue = dfs(grid, i, j, m, n);
                    if (totalValue % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/)
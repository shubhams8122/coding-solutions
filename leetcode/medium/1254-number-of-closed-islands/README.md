# Number of Closed Islands

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Oracle
Google
Microsoft
Meta
Amazon

Given a 2D `grid` consists of `0s` (land) and `1s` (water).  An  *island*  is a maximal 4-directionally connected group of `0s` and a  *closed island*  is an island  **totally**  (all left, top, right, bottom) surrounded by `1s.`

Return the number of  *closed islands*.

 

 **Example 1:** 

```
Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
```

 **Example 2:** 

```
Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

```

 **Example 3:** 

```
Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

```

 

 **Constraints:** 

- 1 <= grid.length, grid[0].length <= 100
- 0 <= grid[i][j] <=1

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 13 MB (beats 95.61%)  
**Submitted:** 2026-10-25T07:07:24.591Z  

```cpp
#include <vector>

class Solution {
private:
    int rows, cols;
    
    void dfs(std::vector<std::vector<int>>& grid, int r, int c) {
        // Boundary check or water cell check
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 1) {
            return;
        }
        
        // Mark cell as visited (sink land to water)
        grid[r][c] = 1;
        
        // Explore 4-directional neighbors
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

public:
    int closedIsland(std::vector<std::vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        // Step 1: Remove all islands connected to the boundary
        // Top and Bottom boundaries
        for (int c = 0; c < cols; ++c) {
            if (grid[0][c] == 0) dfs(grid, 0, c);
            if (grid[rows - 1][c] == 0) dfs(grid, rows - 1, c);
        }
        
        // Left and Right boundaries
        for (int r = 0; r < rows; ++r) {
            if (grid[r][0] == 0) dfs(grid, r, 0);
            if (grid[r][cols - 1] == 0) dfs(grid, r, cols - 1);
        }
        
        // Step 2: Count remaining isolated islands
        int count = 0;
        for (int r = 1; r < rows - 1; ++r) {
            for (int c = 1; c < cols - 1; ++c) {
                if (grid[r][c] == 0) {
                    count++;
                    dfs(grid, r, c); // Sink this island
                }
            }
        }
        
        return count;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-closed-islands/)
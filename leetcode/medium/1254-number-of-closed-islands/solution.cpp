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
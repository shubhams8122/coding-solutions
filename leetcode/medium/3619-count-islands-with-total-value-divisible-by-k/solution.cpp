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
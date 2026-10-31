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
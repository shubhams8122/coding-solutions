class Solution {
    long long MOD = 1e9 + 7;
    vector<vector<long long>> table;

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        // Precompute Pascal's Triangle for combinations C(n, k) % MOD
        table.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            table[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
            }
        }
        
        // Subtract 1 to exclude the original array order
        return (dfs(nums) - 1 + MOD) % MOD;
    }

private:
    long long dfs(const vector<int>& nums) {
        int m = nums.size();
        if (m <= 2) return 1;

        vector<int> left, right;
        int root = nums[0];

        // Partition into left and right subtrees
        for (int i = 1; i < m; ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long leftWays = dfs(left);
        long long rightWays = dfs(right);

        // Ways to interleave left and right elements: C(left.size() + right.size(), left.size())
        long long comb = table[left.size() + right.size()][left.size()];

        return (comb % MOD * leftWays % MOD) % MOD * rightWays % MOD;
    }
};
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    struct WindowMedian {
        multiset<long long> left, right;
        long long left_sum = 0, right_sum = 0;
        int max_left_size;

        WindowMedian(int x) {
            max_left_size = (x + 1) / 2;
        }

        void balance() {
            while (left.size() > max_left_size) {
                auto it = prev(left.end());
                long long val = *it;
                left.erase(it);
                left_sum -= val;
                right.insert(val);
                right_sum += val;
            }
            while (left.size() < max_left_size && !right.empty()) {
                auto it = right.begin();
                long long val = *it;
                right.erase(it);
                right_sum -= val;
                left.insert(val);
                left_sum += val;
            }
        }

        void add(long long val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                left_sum += val;
            } else {
                right.insert(val);
                right_sum += val;
            }
            balance();
        }

        void remove(long long val) {
            auto it = left.find(val);
            if (it != left.end()) {
                left.erase(it);
                left_sum -= val;
            } else {
                it = right.find(val);
                if (it != right.end()) {
                    right.erase(it);
                    right_sum -= val;
                }
            }
            balance();
        }

        long long get_cost() {
            long long median = *left.rbegin();
            long long left_cost = (long long)left.size() * median - left_sum;
            long long right_cost = right_sum - (long long)right.size() * median;
            return left_cost + right_cost;
        }
    };

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> cost(n, 0);
        WindowMedian wm(x);

        for (int i = 0; i < n; ++i) {
            wm.add(nums[i]);
            if (i >= x) {
                wm.remove(nums[i - x]);
            }
            if (i >= x - 1) {
                cost[i] = wm.get_cost();
            }
        }

        // DP state: dp[j][i] = min cost to choose j non-overlapping windows up to index i
        const long long INF = 1e18;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
        
        // Base case: 0 operations needed to pick 0 subarrays
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; ++j) {
            for (int i = j * x; i <= n; ++i) {
                // Option 1: Do not pick a window ending at index i - 1
                dp[j][i] = dp[j][i - 1];

                // Option 2: Pick a window of size x ending at index i - 1
                long long current_cost = cost[i - 1];
                dp[j][i] = min(dp[j][i], dp[j - 1][i - x] + current_cost);
            }
        }

        return dp[k][n];
    }
};
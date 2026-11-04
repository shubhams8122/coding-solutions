# Minimum Operations to Make Elements Within K Subarrays Equal

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums` and two integers, `x` and `k`. You can perform the following operation any number of times (**including zero**):

- Increase or decrease any element of nums by 1.

Return the  **minimum**  number of operations needed to have  **at least**  `k`  *non-overlapping subarrays*  of size  **exactly**  `x` in `nums`, where all elements within each subarray are equal.

 

 **Example 1:** 

 **Input:**  nums = [5,-2,1,3,7,3,6,4,-1], x = 3, k = 2

 **Output:**  8

 **Explanation:** 

- Use 3 operations to add 3 to nums[1] and use 2 operations to subtract 2 from nums[3]. The resulting array is [5, 1, 1, 1, 7, 3, 6, 4, -1].
- Use 1 operation to add 1 to nums[5] and use 2 operations to subtract 2 from nums[6]. The resulting array is [5, 1, 1, 1, 7, 4, 4, 4, -1].
- Now, all elements within each subarray [1, 1, 1] (from indices 1 to 3) and [4, 4, 4] (from indices 5 to 7) are equal. Since 8 total operations were used, 8 is the output.

 **Example 2:** 

 **Input:**  nums = [9,-2,-2,-2,1,5], x = 2, k = 2

 **Output:**  3

 **Explanation:** 

- Use 3 operations to subtract 3 from nums[4]. The resulting array is [9, -2, -2, -2, -2, 5].
- Now, all elements within each subarray [-2, -2] (from indices 1 to 2) and [-2, -2] (from indices 3 to 4) are equal. Since 3 operations were used, 3 is the output.

 

 **Constraints:** 

- 2 <= nums.length <= 105
- -106 <= nums[i] <= 106
- 2 <= x <= nums.length
- 1 <= k <= 15
- 2 <= k * x <= nums.length

## Solution

**Language:** C++  
**Runtime:** 991 ms (beats 65.63%)  
**Memory:** 403.9 MB (beats 45.31%)  
**Submitted:** 2026-11-04T10:43:27.489Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/)
# Subarrays Distinct Element Sum of Squares II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a  **0-indexed** integer array `nums`.

The  **distinct count**  of a subarray of `nums` is defined as:

- Let nums[i..j] be a subarray of nums consisting of all the indices from i to j such that 0 <= i <= j < nums.length. Then the number of distinct values in nums[i..j] is called the distinct count of nums[i..j].

Return  *the sum of the  **squares**  of  **distinct counts**  of all subarrays of* `nums`.

Since the answer may be very large, return it  **modulo**  `109 + 7`.

A subarray is a contiguous  **non-empty**  sequence of elements within an array.

 

 **Example 1:** 

```
Input: nums = [1,2,1]
Output: 15
Explanation: Six possible subarrays are:
[1]: 1 distinct value
[2]: 1 distinct value
[1]: 1 distinct value
[1,2]: 2 distinct values
[2,1]: 2 distinct values
[1,2,1]: 2 distinct values
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 + 22 + 22 + 22 = 15.

```

 **Example 2:** 

```
Input: nums = [2,2]
Output: 3
Explanation: Three possible subarrays are:
[2]: 1 distinct value
[2]: 1 distinct value
[2,2]: 1 distinct value
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 = 3.
```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 416 ms (beats 32.47%)  
**Memory:** 148.6 MB (beats 46.75%)  
**Submitted:** 2026-10-16T01:29:37.472Z  

```cpp
class Solution {
    int MOD = 1e9 + 7;

    // Segment tree arrays
    vector<long long> tree_sum;
    vector<long long> tree_sq;
    vector<long long> lazy;

    void push(int node, int start, int end) {
        if (lazy[node] == 0) return;

        long long val = lazy[node];
        int mid = start + (end - start) / 2;
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;

        // Apply tag to left child
        long long len_left = mid - start + 1;
        tree_sq[left_child] = (tree_sq[left_child] + 2 * val * tree_sum[left_child] % MOD + val * val % MOD * len_left % MOD) % MOD;
        tree_sum[left_child] = (tree_sum[left_child] + val * len_left) % MOD;
        lazy[left_child] = (lazy[left_child] + val) % MOD;

        // Apply tag to right child
        long long len_right = end - mid;
        tree_sq[right_child] = (tree_sq[right_child] + 2 * val * tree_sum[right_child] % MOD + val * val % MOD * len_right % MOD) % MOD;
        tree_sum[right_child] = (tree_sum[right_child] + val * len_right) % MOD;
        lazy[right_child] = (lazy[right_child] + val) % MOD;

        lazy[node] = 0;
    }

    void update(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) return;

        if (l <= start && end <= r) {
            long long len = end - start + 1;
            tree_sq[node] = (tree_sq[node] + 2 * val * tree_sum[node] % MOD + val * val % MOD * len % MOD) % MOD;
            tree_sum[node] = (tree_sum[node] + val * len) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
            return;
        }

        push(node, start, end);
        int mid = start + (end - start) / 2;
        update(2 * node + 1, start, mid, l, r, val);
        update(2 * node + 2, mid + 1, end, l, r, val);

        tree_sum[node] = (tree_sum[2 * node + 1] + tree_sum[2 * node + 2]) % MOD;
        tree_sq[node] = (tree_sq[2 * node + 1] + tree_sq[2 * node + 2]) % MOD;
    }

    long long querySq(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;

        if (l <= start && end <= r) {
            return tree_sq[node];
        }

        push(node, start, end);
        int mid = start + (end - start) / 2;
        long long left_res = querySq(2 * node + 1, start, mid, l, r);
        long long right_res = querySq(2 * node + 2, mid + 1, end, l, r);

        return (left_res + right_res) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        tree_sum.assign(4 * n, 0);
        tree_sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last_pos;
        long long total_sum = 0;

        for (int j = 0; j < n; ++j) {
            int val = nums[j];
            int prev = last_pos.count(val) ? last_pos[val] : -1;

            // Range addition +1 for indices in range [prev + 1, j]
            update(0, 0, n - 1, prev + 1, j, 1);

            // Query sum of squares for all subarrays ending at j
            total_sum = (total_sum + querySq(0, 0, n - 1, 0, j)) % MOD;

            last_pos[val] = j;
        }

        return total_sum;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/)
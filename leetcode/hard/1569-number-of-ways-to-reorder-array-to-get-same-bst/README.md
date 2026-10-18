# Number of Ways to Reorder Array to Get Same BST

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Google

Given an array `nums` that represents a permutation of integers from `1` to `n`. We are going to construct a binary search tree (BST) by inserting the elements of `nums` in order into an initially empty BST. Find the number of different ways to reorder `nums` so that the constructed BST is identical to that formed from the original array `nums`.

- For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child. The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.

Return  *the number of ways to reorder*  `nums`  *such that the BST formed is identical to the original BST formed from*  `nums`.

Since the answer may be very large,  **return it modulo** `109 + 7`.

 

 **Example 1:** 

```
Input: nums = [2,1,3]
Output: 1
Explanation: We can reorder nums to be [2,3,1] which will yield the same BST. There are no other ways to reorder nums which will yield the same BST.

```

 **Example 2:** 

```
Input: nums = [3,4,5,1,2]
Output: 5
Explanation: The following 5 arrays will yield the same BST: 
[3,1,2,4,5]
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]

```

 **Example 3:** 

```
Input: nums = [1,2,3]
Output: 0
Explanation: There are no other orderings of nums that will yield the same BST.

```

 

 **Constraints:** 

- 1 <= nums.length <= 1000
- 1 <= nums[i] <= nums.length
- All integers in nums are distinct.

## Solution

**Language:** C++  
**Runtime:** 252 ms (beats 14.80%)  
**Memory:** 297.7 MB (beats 35.02%)  
**Submitted:** 2026-10-18T03:10:48.342Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/)
# Minimum Positive Sum Subarray

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an integer array `nums` and  **two**  integers `l` and `r`. Your task is to find the  **minimum**  sum of a  **subarray**  whose size is between `l` and `r` (inclusive) and whose sum is greater than 0.

Return the  **minimum**  sum of such a subarray. If no such subarray exists, return -1.

A  **subarray**  is a contiguous  **non-empty**  sequence of elements within an array.

 

Original
C++
 **Example 1:** 

 **Input:**  nums = [3, -2, 1, 4], l = 2, r = 3

 **Output:**  1

 **Explanation:** 

The subarrays of length between `l = 2` and `r = 3` where the sum is greater than 0 are:

- [3, -2] with a sum of 1
- [1, 4] with a sum of 5
- [3, -2, 1] with a sum of 2
- [-2, 1, 4] with a sum of 3

Out of these, the subarray `[3, -2]` has a sum of 1, which is the smallest positive sum. Hence, the answer is 1.

 **Example 2:** 

 **Input:**  nums = [-2, 2, -3, 1], l = 2, r = 3

 **Output:**  -1

 **Explanation:** 

There is no subarray of length between `l` and `r` that has a sum greater than 0. So, the answer is -1.

 **Example 3:** 

 **Input:**  nums = [1, 2, 3, 4], l = 2, r = 4

 **Output:**  3

 **Explanation:** 

The subarray `[1, 2]` has a length of 2 and the minimum sum greater than 0. So, the answer is 3.

 

 **Constraints:** 

- 1 <= nums.length <= 100
- 1 <= l <= r <= nums.length
- -1000 <= nums[i] <= 1000

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 46.41%)  
**Memory:** 29.5 MB (beats 63.40%)  
**Submitted:** 2026-11-14T15:12:48.217Z  

```cpp
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
        int min_sum = INT_MAX;
        int n = nums.size();
        
        // Iterate through all possible starting positions of the subarray
        for (int i = 0; i < n; ++i) {
            int current_sum = 0;
            // Extend the subarray length from i up to min(n - 1, i + r - 1)
            for (int j = i; j < n && (j - i + 1) <= r; ++j) {
                current_sum += nums[j];
                // Check if the length is at least l and sum is positive
                if ((j - i + 1) >= l && current_sum > 0) {
                    min_sum = std::min(min_sum, current_sum);
                }
            }
        }
        
        // Return -1 if no valid positive sum subarray was found
        return (min_sum == INT_MAX) ? -1 : min_sum;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-positive-sum-subarray/)
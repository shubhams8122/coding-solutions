# Maximum Alternating Sum of Squares

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums`. You may  **rearrange the elements**  in any order.

The  **alternating score**  of an array `arr` is defined as:

- score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 +...

Return an integer denoting the  **maximum possible alternating score**  of `nums` after rearranging its elements.

 

 **Example 1:** 

 **Input:**  nums = [1,2,3]

 **Output:**  12

 **Explanation:** 

A possible rearrangement for `nums` is `[2,1,3]`, which gives the maximum alternating score among all possible rearrangements.

The alternating score is calculated as:

`score = 22 - 12 + 32 = 4 - 1 + 9 = 12`

 **Example 2:** 

 **Input:**  nums = [1,-1,2,-2,3,-3]

 **Output:**  16

 **Explanation:** 

A possible rearrangement for `nums` is `[-3,-1,-2,1,3,2]`, which gives the maximum alternating score among all possible rearrangements.

The alternating score is calculated as:

`score = (-3)2 - (-1)2 + (-2)2 - (1)2 + (3)2 - (2)2 = 9 - 1 + 4 - 1 + 9 - 4 = 16`

 

 **Constraints:** 

- 1 <= nums.length <= 105
- -4  *104 <= nums[i] <= 4*  104

## Solution

**Language:** C++  
**Runtime:** 51 ms (beats 80.80%)  
**Memory:** 191.7 MB (beats 19.50%)  
**Submitted:** 2026-10-13T02:04:05.370Z  

```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<long long> sq(n);
        
        // Step 1: Compute squares using static_cast to prevent 32-bit overflow
        for (int i = 0; i < n; ++i) {
            sq[i] = static_cast<long long>(nums[i]) * nums[i];
        }
        
        // Step 2: Sort the squared values in ascending order
        std::sort(sq.begin(), sq.end());
        
        // Step 3: Subtract the smaller half, add the larger half
        long long score = 0;
        int num_negative = n / 2;
        
        for (int i = 0; i < num_negative; ++i) {
            score -= sq[i];
        }
        for (int i = num_negative; i < n; ++i) {
            score += sq[i];
        }
        
        return score;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-alternating-sum-of-squares/)
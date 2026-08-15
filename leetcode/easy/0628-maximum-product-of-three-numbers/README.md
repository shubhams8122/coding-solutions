# Maximum Product of Three Numbers

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer array `nums`,  *find three numbers whose product is maximum and return the maximum product*.

 

 **Example 1:** 

```
Input: nums = [1,2,3]
Output: 6

```

 **Example 2:** 

```
Input: nums = [1,2,3,4]
Output: 24

```

 **Example 3:** 

```
Input: nums = [-1,-2,-3]
Output: -6

```

 

 **Constraints:** 

- 3 <= nums.length <= 104
- -1000 <= nums[i] <= 1000

## Solution

**Language:** C++  
**Runtime:** 7 ms (beats 47.26%)  
**Memory:** 31.5 MB (beats 48.96%)  
**Submitted:** 2026-08-15T18:30:23.457Z  

```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int max_back = nums[n-1] * nums[0] * nums[1];
        int max_front = nums[n-1] * nums[n-2] * nums[n-3];
        return max(max_back,max_front);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-product-of-three-numbers/)
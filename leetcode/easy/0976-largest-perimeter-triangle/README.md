# Largest Perimeter Triangle

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Google
Bloomberg
Meta
Amazon

Given an integer array `nums`, return  *the largest perimeter of a triangle with a non-zero area, formed from three of these lengths*. If it is impossible to form any triangle of a non-zero area, return `0`.

 

 **Example 1:** 

```
Input: nums = [2,1,2]
Output: 5
Explanation: You can form a triangle with three side lengths: 1, 2, and 2.

```

 **Example 2:** 

```
Input: nums = [1,2,1,10]
Output: 0
Explanation: 
You cannot use the side lengths 1, 1, and 2 to form a triangle.
You cannot use the side lengths 1, 1, and 10 to form a triangle.
You cannot use the side lengths 1, 2, and 10 to form a triangle.
As we cannot use any three side lengths to form a triangle of non-zero area, we return 0.

```

 

 **Constraints:** 

- 3 <= nums.length <= 104
- 1 <= nums[i] <= 106

## Solution

**Language:** C++  
**Runtime:** 21 ms (beats 5.79%)  
**Memory:** 28.9 MB (beats 5.12%)  
**Submitted:** 2026-10-18T05:27:02.874Z  

```cpp
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(),nums.rend());
        for(int i = 0; i <= n -3; i++){
            if(nums[i] < nums[i+1]+nums[i+2]){
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }
        return 0;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/largest-perimeter-triangle/)
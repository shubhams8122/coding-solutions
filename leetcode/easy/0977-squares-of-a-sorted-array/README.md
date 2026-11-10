# Squares of a Sorted Array

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Instacart
Uber
Whatnot
Ozon
CrowdStrike

Given an integer array `nums` sorted in  **non-decreasing**  order, return  *an array of  **the squares of each number**  sorted in non-decreasing order*.

 

Original
C++
 **Example 1:** 

```
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

```

 **Example 2:** 

```
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

```

 

 **Constraints:** 

- 1 <= nums.length <= 104
- -104 <= nums[i] <= 104
- nums is sorted in non-decreasing order.

 

 **Follow up:**  Squaring each element and sorting the new array is very trivial, could you find an `O(n)` solution using a different approach?

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 67.15%)  
**Memory:** 30.1 MB (beats 95.86%)  
**Submitted:** 2026-11-10T12:21:14.369Z  

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0 , right = n - 1;
        for(int i = n - 1; i >= 0; i--){
            if(abs(nums[left]) > abs(nums[right])){
                result[i] = nums[left] * nums[left];
                left++;
            }
            else{
                result[i] = nums[right] * nums[right];
                right--;
            }
        }
        return result; 
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/squares-of-a-sorted-array/)
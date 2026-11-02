# Minimum Moves to Equal Array Elements II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Myntra
tcs
Microsoft
Google
Amazon

Given an integer array `nums` of size `n`, return  *the minimum number of moves required to make all array elements equal*.

In one move, you can increment or decrement an element of the array by `1`.

Test cases are designed so that the answer will fit in a  **32-bit**  integer.

 

 **Example 1:** 

```
Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

```

 **Example 2:** 

```
Input: nums = [1,10,2,9]
Output: 16

```

 

 **Constraints:** 

- n == nums.length
- 1 <= nums.length <= 105
- -109 <= nums[i] <= 109

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 29.19%)  
**Memory:** 15.6 MB (beats 79.95%)  
**Submitted:** 2026-11-02T02:07:07.553Z  

```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int moves = 0;
        int i = 0 , j = nums.size() - 1;
        while(i < j){
            moves += nums[j] - nums[i];
            i++;
            j--;
        }
        return moves;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)
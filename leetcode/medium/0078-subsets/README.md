# Subsets

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array `nums` of  **unique**  elements, return  *all possible*   *subsets*   *(the power set)*.

The solution set  **must not**  contain duplicate subsets. Return the solution in  **any order**.

 

 **Example 1:** 

```
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

```

 **Example 2:** 

```
Input: nums = [0]
Output: [[],[0]]

```

 

 **Constraints:** 

- 1 <= nums.length <= 10
- -10 <= nums[i] <= 10
- All the numbers of nums are unique.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.9 MB (beats 59.78%)  
**Submitted:** 2026-10-03T15:15:22.499Z  

```cpp
class Solution {
public:
      vector<vector<int>> output;
    void backtrack(int first, vector<int>& curr, vector<int> & activities){
        output.push_back(curr);
      
        for(int i =first; i<activities.size(); i++){
            curr.push_back(activities[i]);
            backtrack(i+1,curr,activities);
            curr.pop_back();
      }
  }
    vector<vector<int>> subsets(vector<int>& nums) {
        output.clear();
        vector<int> curr;
        backtrack(0,curr,nums);
        return output;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/subsets/)
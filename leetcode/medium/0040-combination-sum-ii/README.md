# Combination Sum II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.

Each number in `candidates` may only be used  **once**  in the combination.

 **Note:**  The solution set must not contain duplicate combinations.

 

 **Example 1:** 

```
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

```

 **Example 2:** 

```
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

```

 

 **Constraints:** 

- 1 <= candidates.length <= 100
- 1 <= candidates[i] <= 50
- 1 <= target <= 30

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 21.51%)  
**Memory:** 14.1 MB (beats 63.11%)  
**Submitted:** 2026-09-26T13:23:35.147Z  

```cpp
class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int> & tempList, vector<int> & candidates, int target, int start){
        if(target < 0){
            return;
        }
        if(target == 0){
            result.push_back(tempList);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            if(i > start && candidates[i] == candidates[i-1]){
                continue;
            }
            tempList.push_back(candidates[i]);
            backtrack(result,tempList,candidates,target-candidates[i],i+1);
            tempList.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> tempList;
        backtrack(result, tempList,candidates,target,0);
        return result;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/combination-sum-ii/)
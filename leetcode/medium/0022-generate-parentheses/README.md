# Generate Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given `n` pairs of parentheses, write a function to  *generate all combinations of well-formed parentheses*.

 

 **Example 1:** 

```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

```

 **Example 2:** 

```
Input: n = 1
Output: ["()"]

```

 

 **Constraints:** 

- 1 <= n <= 8

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 67.20%)  
**Memory:** 15.7 MB (beats 35.81%)  
**Submitted:** 2026-10-02T11:51:13.403Z  

```cpp
class Solution {
public:
    void backtrack(int n, int open, int close, string current, vector<string>& result){
        if(current.length() == 2* n){
            result.push_back(current);
            return;
        }
        if(open < n){
            backtrack(n,open+1,close,current+"(",result);
        }
        if(close < open){
            backtrack(n, open, close + 1, current+")", result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(n,0,0,"",result);
        return result;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/generate-parentheses/)
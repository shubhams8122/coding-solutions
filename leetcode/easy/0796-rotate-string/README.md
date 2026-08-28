# Rotate String

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given two strings `s` and `goal`, return `true`  *if and only if*  `s`  *can become*  `goal`  *after some number of  **shifts**  on*  `s`.

A  **shift**  on `s` consists of moving the leftmost character of `s` to the rightmost position.

- For example, if s = "abcde", then it will be "bcdea" after one shift.

 

 **Example 1:** 

```
Input: s = "abcde", goal = "cdeab"
Output: true

```

 **Example 2:** 

```
Input: s = "abcde", goal = "abced"
Output: false

```

 

 **Constraints:** 

- 1 <= s.length, goal.length <= 100
- s and goal consist of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8 MB (beats 83.07%)  
**Submitted:** 2026-08-28T17:25:08.782Z  

```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        s += s;
        if(s.contains(goal)) return true;
        else return false;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/rotate-string/)
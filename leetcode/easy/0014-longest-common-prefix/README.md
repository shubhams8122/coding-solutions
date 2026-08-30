# Longest Common Prefix

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

 

 **Example 1:** 

```
Input: strs = ["flower","flow","flight"]
Output: "fl"

```

 **Example 2:** 

```
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

```

 

 **Constraints:** 

- 1 <= strs.length <= 200
- 0 <= strs[i].length <= 200
- strs[i] consists of only lowercase English letters if it is non-empty.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 11.7 MB (beats 79.98%)  
**Submitted:** 2026-08-30T17:51:30.117Z  

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int k = 0;
        if(n==0) return "";
        if(n==1) return strs[0];
        while(true){
            for(int i = 1; i < n; i++){
                if(k == strs[i].size() || k == strs[0].size()) return strs[0].substr(0,k);
                if(strs[i][k] != strs[0][k]) return strs[0].substr(0,k);
            }
            k++;
        }
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-common-prefix/)
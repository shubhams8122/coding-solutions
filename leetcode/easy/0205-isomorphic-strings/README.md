# Isomorphic Strings

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given two strings `s` and `t`,  *determine if they are isomorphic*.

Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

 **Example 1:** 

 **Input:**  s = "egg", t = "add"

 **Output:**  true

 **Explanation:** 

The strings `s` and `t` can be made identical by:

- Mapping 'e' to 'a'.
- Mapping 'g' to 'd'.

 **Example 2:** 

 **Input:**  s = "f11", t = "b23"

 **Output:**  false

 **Explanation:** 

The strings `s` and `t` can not be made identical as `'1'` needs to be mapped to both `'2'` and `'3'`.

 **Example 3:** 

 **Input:**  s = "paper", t = "title"

 **Output:**  true

 

 **Constraints:** 

- 1 <= s.length <= 5 * 104
- t.length == s.length
- s and t consist of any valid ascii character.

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 54.37%)  
**Memory:** 9.6 MB (beats 7.69%)  
**Submitted:** 2026-08-26T18:00:25.976Z  

```cpp
class Solution {
public:
    bool help(string s, string t){
        if (s.size() != t.size()) return false;
        map<char, char> m;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(m.find(s[i])== m.end()){
                m[s[i]] = t[i];
            }
            else if(m[s[i]]!=t[i]){
                return false;
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return help(s,t) && help(t,s);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/isomorphic-strings/)
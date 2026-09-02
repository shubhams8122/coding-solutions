# Valid Anagram

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

 

 **Example 1:** 

 **Input:**  s = "anagram", t = "nagaram"

 **Output:**  true

 **Example 2:** 

 **Input:**  s = "rat", t = "car"

 **Output:**  false

 

 **Constraints:** 

- 1 <= s.length, t.length <= 5 * 104
- s and t consist of lowercase English letters.

 

 **Follow up:**  What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.8 MB (beats 49.17%)  
**Submitted:** 2026-09-02T17:41:44.006Z  

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int arr[26] = {0};
        for(char ch : s){
            arr[ch-'a']++;
        }
        for(char ch:t){
            arr[ch-'a']--;
        }
        for(int count : arr){
            if(count != 0) return false;
        }
        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-anagram/)
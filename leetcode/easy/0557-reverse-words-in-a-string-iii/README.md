# Reverse Words in a String III

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a string `s`, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

 **Example 1:** 

```
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

```

 **Example 2:** 

```
Input: s = "Mr Ding"
Output: "rM gniD"

```

 

 **Constraints:** 

- 1 <= s.length <= 5 * 104
- s contains printable ASCII characters.
- s does not contain any leading or trailing spaces.
- There is at least one word in s.
- All the words in s are separated by a single space.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 12.2 MB (beats 47.42%)  
**Submitted:** 2026-08-31T17:12:44.395Z  

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int start = 0;
        for(int i = 0; i<=n;i++){
            if(i == n || s[i] == ' '){
                reverse(s.begin() + start,s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/reverse-words-in-a-string-iii/)
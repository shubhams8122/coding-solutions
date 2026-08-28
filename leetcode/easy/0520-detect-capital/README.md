# Detect Capital

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

We define the usage of capitals in a word to be right when one of the following cases holds:

- All letters in this word are capitals, like "USA".
- All letters in this word are not capitals, like "leetcode".
- Only the first letter in this word is capital, like "Google".

Given a string `word`, return `true` if the usage of capitals in it is right.

 

 **Example 1:** 

```
Input: word = "USA"
Output: true

```

 **Example 2:** 

```
Input: word = "FlaG"
Output: false

```

 

 **Constraints:** 

- 1 <= word.length <= 100
- word consists of lowercase and uppercase English letters.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8 MB (beats 79.54%)  
**Submitted:** 2026-08-28T17:31:55.626Z  

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for(int i = 0; i < word.length();i++){
            if(isupper(word[i])){
                count++;
            }
        }
        return count == word.length() || count == 0 || count == 1 && isupper(word[0]);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/detect-capital/)
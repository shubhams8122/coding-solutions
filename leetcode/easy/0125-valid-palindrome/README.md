# Valid Palindrome

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

A phrase is a  **palindrome**  if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` *if it is a  **palindrome**, or* `false` *otherwise*.

 

 **Example 1:** 

```
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

```

 **Example 2:** 

```
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

```

 **Example 3:** 

```
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

```

 

 **Constraints:** 

- 1 <= s.length <= 2 * 105
- s consists only of printable ASCII characters.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 10.6 MB (beats 10.25%)  
**Submitted:** 2026-09-04T18:26:04.325Z  

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        string filtered = "";
        for(char ch : s){
            if(isalnum(ch)){
                filtered.push_back(tolower(ch));
            }
        }
        string reversed = filtered;
        reverse(reversed.begin(),reversed.end());
        return filtered == reversed;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-palindrome/)
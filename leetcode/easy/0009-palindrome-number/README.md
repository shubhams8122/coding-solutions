# Palindrome Number

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer `x`, return `true` if `x` is a  **palindrome**, and `false` otherwise.

 

 **Example 1:** 

```
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

```

 **Example 2:** 

```
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

```

 **Example 3:** 

```
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

```

 

 **Constraints:** 

- -231 <= x <= 231 - 1

 

 **Follow up:**  Could you solve it without converting the integer to a string?

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 57.73%)  
**Memory:** 8.6 MB (beats 65.42%)  
**Submitted:** 2026-08-11T19:01:34.895Z  

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int n1 = x;
        long long n = 0; 
        
        while (x != 0) {
            int last_digit = x % 10;
            n = n * 10 + last_digit;
            x = x / 10;
        }
        
        return (n == n1);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/palindrome-number/)
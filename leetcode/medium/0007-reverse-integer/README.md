# Reverse Integer

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a signed 32-bit integer `x`, return `x` *with its digits reversed*. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-231, 231 - 1]`, then return `0`.

 **Assume the environment does not allow you to store 64-bit integers (signed or unsigned).** 

 

 **Example 1:** 

```
Input: x = 123
Output: 321

```

 **Example 2:** 

```
Input: x = -123
Output: -321

```

 **Example 3:** 

```
Input: x = 120
Output: 21

```

 

 **Constraints:** 

- -231 <= x <= 231 - 1

## Solution

**Language:** C++  
**Runtime:** 2 ms  
**Memory:** 7.6 MB  
**Submitted:** 2026-08-11T18:40:07.290Z  

```cpp
class Solution {
public:
    int reverse(int x) {
        int last_digit;
        long n = 0;
        while(x!=0){
            last_digit = x % 10;
            n = n*10 + last_digit;
            x = x /10;
        }
        return n;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/reverse-integer/)
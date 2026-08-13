# Ugly Number

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

An  **ugly number**  is a  *positive*  integer which does not have a prime factor other than 2, 3, and 5.

Given an integer `n`, return `true`  *if*  `n`  *is an  **ugly number***.

 

 **Example 1:** 

```
Input: n = 6
Output: true
Explanation: 6 = 2 × 3

```

 **Example 2:** 

```
Input: n = 1
Output: true
Explanation: 1 has no prime factors.

```

 **Example 3:** 

```
Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.

```

 

 **Constraints:** 

- -231 <= n <= 231 - 1

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 6.18%)  
**Memory:** 8.1 MB (beats 8.44%)  
**Submitted:** 2026-08-13T19:25:44.909Z  

```cpp
class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;
        vector<int> factors ={2,3,5};
        for(int i : factors){
            while(n%i == 0){
                n /= i;
            }
        }
        return n == 1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/ugly-number/)
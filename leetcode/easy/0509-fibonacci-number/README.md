# Fibonacci Number

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

The  **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the  **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is,

```
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.

```

Given `n`, calculate `F(n)`.

 

 **Example 1:** 

```
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

```

 **Example 2:** 

```
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

```

 **Example 3:** 

```
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

```

 

 **Constraints:** 

- 0 <= n <= 30

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 77.62%)  
**Memory:** 7.6 MB (beats 99.02%)  
**Submitted:** 2026-08-15T18:37:42.096Z  

```cpp
class Solution {
public:
    int fib(int n) {
        int a = 0;
        int b = 1;
        int temp = 0;
        if(n == 0) return 0;
        if(n == 1) return 1;
        for(int i = 2; i<=n; i++){
            temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/fibonacci-number/)
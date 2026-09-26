# Pow(x, n)

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Implement pow(x, n), which calculates `x` raised to the power `n` (i.e., `xn`).

 

 **Example 1:** 

```
Input: x = 2.00000, n = 10
Output: 1024.00000

```

 **Example 2:** 

```
Input: x = 2.10000, n = 3
Output: 9.26100

```

 **Example 3:** 

```
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

```

 

 **Constraints:** 

- -100.0 < x < 100.0
- -231 <= n <= 231-1
- n is an integer.
- Either x is not zero or n > 0.
- -104 <= xn <= 104

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.7 MB (beats 44.04%)  
**Submitted:** 2026-09-26T13:03:08.240Z  

```cpp
class Solution {
private:
    double helper(double x, long n) {
        if (n == 0) return 1.0;
        if (n < 0) return 1.0 / helper(x, -n);
        
        if (n % 2 == 0) {
            double half_pow = helper(x, n / 2);
            return half_pow * half_pow;
        }
        return x * helper(x, n - 1);
    }

public:
    double myPow(double x, int n) {
        return helper(x, n);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/powx-n/)
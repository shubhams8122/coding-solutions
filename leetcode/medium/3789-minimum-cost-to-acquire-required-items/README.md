# Minimum Cost to Acquire Required Items

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given five integers `cost1`, `cost2`, `costBoth`, `need1`, and `need2`.

There are three types of items available:

- An item of type 1 costs cost1 and contributes 1 unit to the type 1 requirement only.
- An item of type 2 costs cost2 and contributes 1 unit to the type 2 requirement only.
- An item of type 3 costs costBoth and contributes 1 unit to both type 1 and type 2 requirements.

You must collect enough items so that the total contribution toward type 1 is  **at least**  `need1` and the total contribution toward type 2 is  **at least**  `need2`.

Return an integer representing the  **minimum**  possible total cost to achieve these requirements.

 

Original
C++
 **Example 1:** 

 **Input:**  cost1 = 3, cost2 = 2, costBoth = 1, need1 = 3, need2 = 2

 **Output:**  3

 **Explanation:** 

After buying three type 3 items, which cost `3 * 1 = 3`, the total contribution to type 1 is 3 (`>= need1 = 3`) and to type 2 is 3 (`>= need2 = 2`).
Any other valid combination would cost more, so the minimum total cost is 3.

 **Example 2:** 

 **Input:**  cost1 = 5, cost2 = 4, costBoth = 15, need1 = 2, need2 = 3

 **Output:**  22

 **Explanation:** 

We buy `need1 = 2` items of type 1 and `need2 = 3` items of type 2: `2  *5 + 3*  4 = 10 + 12 = 22`.
Any other valid combination would cost more, so the minimum total cost is 22.

 **Example 3:** 

 **Input:**  cost1 = 5, cost2 = 4, costBoth = 15, need1 = 0, need2 = 0

 **Output:**  0

 **Explanation:** 

Since no items are required (`need1 = need2 = 0`), we buy nothing and pay 0.

 

 **Constraints:** 

- 1 <= cost1, cost2, costBoth <= 106
- 0 <= need1, need2 <= 109

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.3 MB (beats 20.00%)  
**Submitted:** 2026-11-11T16:49:04.755Z  

```cpp
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // Effective costBoth cannot exceed the sum of individual costs
        long long cb = min((long long)costBoth, (long long)cost1 + cost2);
        long long total_cost = 0;
        
        // Step 1: Satisfy the overlapping requirement using the cheapest combined method
        long long common_need = min((long long)need1, (long long)need2);
        total_cost += common_need * cb;
        
        need1 -= common_need;
        need2 -= common_need;
        
        // Step 2: Satisfy remaining Type 1 requirement
        if (need1 > 0) {
            long long c1 = min((long long)cost1, cb);
            total_cost += need1 * c1;
        }
        
        // Step 3: Satisfy remaining Type 2 requirement
        if (need2 > 0) {
            long long c2 = min((long long)cost2, cb);
            total_cost += need2 * c2;
        }
        
        return total_cost;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-cost-to-acquire-required-items/)
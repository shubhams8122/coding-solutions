# Find N Unique Integers Sum up to Zero

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer `n`, return  **any**  array containing `n`  **unique**  integers such that they add up to `0`.

 

 **Example 1:** 

```
Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3], [-3,-1,2,-2,4].

```

 **Example 2:** 

```
Input: n = 3
Output: [-1,0,1]

```

 **Example 3:** 

```
Input: n = 1
Output: [0]

```

 

 **Constraints:** 

- 1 <= n <= 1000

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.6 MB (beats 54.19%)  
**Submitted:** 2026-08-15T14:08:14.392Z  

```cpp
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr;
        for(int i = 1; i <= n/2; i++){
            arr.push_back(i);
            arr.push_back(-i);
        }
        if(n%2 != 0){
            arr.push_back(0);
        }
        return arr;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/)
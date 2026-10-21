# Minimum Operations to Sort a String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a string `s` consisting of lowercase English letters.

In one operation, you can select any  **substring**  of `s` that is  **not**  the entire string and  **sort**  it in  **non-descending alphabetical**  order.

Return the  **minimum**  number of operations required to make `s` sorted in  **non-descending**  order. If it is not possible, return -1.

 

 **Example 1:** 

 **Input:**  s = "dog"

 **Output:**  1

 **Explanation:** ​​​​​​​

- Sort substring "og" to "go".
- Now, s = "dgo", which is sorted in ascending order. Thus, the answer is 1.

 **Example 2:** 

 **Input:**  s = "card"

 **Output:**  2

 **Explanation:** 

- Sort substring "car" to "acr", so s = "acrd".
- Sort substring "rd" to "dr", making s = "acdr", which is sorted in ascending order. Thus, the answer is 2.

 **Example 3:** 

 **Input:**  s = "gf"

 **Output:**  -1

 **Explanation:** 

- It is impossible to sort s under the given constraints. Thus, the answer is -1.

 

 **Constraints:** 

- 1 <= s.length <= 105
- s consists of only lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 14 ms (beats 61.95%)  
**Memory:** 27.4 MB (beats 79.65%)  
**Submitted:** 2026-10-21T02:49:49.630Z  

```cpp
class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if(is_sorted(s.begin(),s.end())) return 0;
        if(n == 2) return -1;
        char min_char = *min_element(s.begin(),s.end());
        char max_char = *max_element(s.begin(),s.end());
        if(s[0] == min_char || s[n-1] == max_char) return 1;
        bool max_only_at_0 = (s[0] == max_char);
        bool min_only_at_end = (s[n-1] == min_char);
        if(max_only_at_0 && min_only_at_end){
            for(int i = 1; i < n; ++i){
                if(s[i] == max_char) max_only_at_0 = false;
            }
            for(int i = 0; i < n-1; ++i){
                if(s[i] == min_char) min_only_at_end = false;
            }
            if(max_only_at_0 && min_only_at_end) return 3;
        }
        return 2;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-operations-to-sort-a-string/)
# Sort Characters By Frequency

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string `s`, sort it in  **decreasing order**  based on the  **frequency**  of the characters. The  **frequency**  of a character is the number of times it appears in the string.

Return  *the sorted string*. If there are multiple answers, return  *any of them*.

 

 **Example 1:** 

```
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

```

 **Example 2:** 

```
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.

```

 **Example 3:** 

```
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

```

 

 **Constraints:** 

- 1 <= s.length <= 5 * 105
- s consists of uppercase and lowercase English letters and digits.

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 62.63%)  
**Memory:** 11.5 MB (beats 30.49%)  
**Submitted:** 2026-09-01T18:17:28.516Z  

```cpp
class Solution {
public:
    string frequencySort(string s) {
       vector<pair<int,char>> arr(123,{0,0});
       for(char ch : s){
        arr[ch] = {arr[ch].first + 1, ch};
       } 
       sort(arr.begin(),arr.end(), greater<pair<int,char>>());
       string ans = "";
       for(int i = 0; i < 123;i++){
        ans.append(string(arr[i].first,arr[i].second));
       }
       return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sort-characters-by-frequency/)
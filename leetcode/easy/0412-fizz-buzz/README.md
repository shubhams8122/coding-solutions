# Fizz Buzz

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer `n`, return  *a string array* `answer` *(**1-indexed**) where* :

- answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
- answer[i] == "Fizz" if i is divisible by 3.
- answer[i] == "Buzz" if i is divisible by 5.
- answer[i] == i (as a string) if none of the above conditions are true.

 

 **Example 1:** 

```
Input: n = 3
Output: ["1","2","Fizz"]

```

 **Example 2:** 

```
Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]

```

 **Example 3:** 

```
Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

```

 

 **Constraints:** 

- 1 <= n <= 104

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 11.8 MB (beats 17.99%)  
**Submitted:** 2026-08-24T18:16:43.107Z  

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for(int i = 1; i <= n; i++){
            if(i%3==0 && i%5==0){
                answer.push_back("FizzBuzz");
            }
            else if(i%3==0){
                answer.push_back("Fizz");
            }
            else if(i%5==0){
                answer.push_back("Buzz");
            }
            else{
                answer.push_back(to_string(i));
            }
        }
        return answer;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/fizz-buzz/)
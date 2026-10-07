# Remove Invalid Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string `s` that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return  *a list of  **unique strings**  that are valid with the minimum number of removals*. You may return the answer in  **any order**.

 

 **Example 1:** 

```
Input: s = "()())()"
Output: ["(())()","()()()"]

```

 **Example 2:** 

```
Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]

```

 **Example 3:** 

```
Input: s = ")("
Output: [""]

```

 

 **Constraints:** 

- 1 <= s.length <= 25
- s consists of lowercase English letters and parentheses '(' and ')'.
- There will be at most 20 parentheses in s.

## Solution

**Language:** C++  
**Runtime:** 57 ms (beats 62.99%)  
**Memory:** 20 MB (beats 46.50%)  
**Submitted:** 2026-10-07T03:18:24.516Z  

```cpp
class Solution {
public:
    bool isValid(const string&s){
        int count = 0;
        for(char ch : s){
            if(ch == '(') count++;
            else if(ch==')') {
                count--;
                if(count < 0) return false;
            }
        }
        return count == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);

        bool found = false;

        while(!q.empty()){
            int levelSize = q.size();
            for(int i = 0; i < levelSize; ++i){
                string curr = q.front();
                q.pop();

                if(isValid(curr)){
                    result.push_back(curr);
                    found = true;
                }
                if(found)  continue;
                for (int j = 0; j < curr.length(); ++j) {
                    if (curr[j] != '(' && curr[j] != ')') continue;

                    string nextStr = curr.substr(0, j) + curr.substr(j + 1);
                    if (!visited.count(nextStr)) {
                        visited.insert(nextStr);
                        q.push(nextStr);
                    }
                }
            }
            if (found) break;
            }
            return result;
        }
};
```

---

[View on LeetCode](https://leetcode.com/problems/remove-invalid-parentheses/)
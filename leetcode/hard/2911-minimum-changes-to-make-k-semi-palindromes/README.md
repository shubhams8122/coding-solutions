# Minimum Changes to Make K Semi-palindromes

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string `s` and an integer `k`, partition `s` into `k`  **substrings**  such that the letter changes needed to make each substring a  **semi-palindrome**  are minimized.

Return the  ***minimum**  number of letter changes *required*.*

A  **semi-palindrome**  is a special type of string that can be divided into  **palindromes**  based on a repeating pattern. To check if a string is a semi-palindrome:​

- Choose a positive divisor d of the string's length. d can range from 1 up to, but not including, the string's length. For a string of length 1, it does not have a valid divisor as per this definition, since the only divisor is its length, which is not allowed.
- For a given divisor d, divide the string into groups where each group contains characters from the string that follow a repeating pattern of length d. Specifically, the first group consists of characters at positions 1, 1 + d, 1 + 2d, and so on; the second group includes characters at positions 2, 2 + d, 2 + 2d, etc.
- The string is considered a semi-palindrome if each of these groups forms a palindrome.

Consider the string `"abcabc"`:

- The length of "abcabc" is 6. Valid divisors are 1, 2, and 3.
- For d = 1: The entire string "abcabc" forms one group. Not a palindrome.
- For d = 2: Group 1 (positions 1, 3, 5): "acb" Group 2 (positions 2, 4, 6): "bac" Neither group forms a palindrome.
- For d = 3: Group 1 (positions 1, 4): "aa" Group 2 (positions 2, 5): "bb" Group 3 (positions 3, 6): "cc" All groups form palindromes. Therefore, "abcabc" is a semi-palindrome.

 

Original
C++
 **Example 1:** 

 **Input:**  s = "abcac", k = 2

 **Output:**  1

 **Explanation:**  Divide `s` into `"ab"` and `"cac"`. `"cac"` is already semi-palindrome. Change `"ab"` to `"aa"`, it becomes semi-palindrome with `d = 1`.

 **Example 2:** 

 **Input:**  s = "abcdef", k = 2

 **Output:**  2

 **Explanation:**  Divide `s` into substrings `"abc"` and `"def"`. Each needs one change to become semi-palindrome.

 **Example 3:** 

 **Input:**  s = "aabbaa", k = 3

 **Output:**  0

 **Explanation:**  Divide `s` into substrings `"aa"`, `"bb"` and `"aa"`. All are already semi-palindromes.

 

 **Constraints:** 

- 2 <= s.length <= 200
- 1 <= k <= s.length / 2
- s contains only lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 212 ms (beats 36.92%)  
**Memory:** 9.1 MB (beats 83.08%)  
**Submitted:** 2026-11-17T16:25:42.982Z  

```cpp
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
      
        // minChanges[i][j] = minimum changes to make substring s[i-1...j-1] a semi-palindrome
        // A semi-palindrome is a string that becomes palindromic when read with period d
        int minChanges[n + 1][n + 1];
      
        // dp[i][j] = minimum changes to partition s[0...i-1] into j semi-palindromes
        int dp[n + 1][k + 1];
      
        // Initialize with large values (infinity)
        memset(minChanges, 0x3f, sizeof(minChanges));
        memset(dp, 0x3f, sizeof(dp));
      
        // Base case: empty string with 0 partitions needs 0 changes
        dp[0][0] = 0;
      
        // Precompute minimum changes for all substrings to become semi-palindromes
        for (int start = 1; start <= n; ++start) {
            for (int end = start; end <= n; ++end) {
                int length = end - start + 1;
              
                // Try all possible divisors of length as the period
                for (int period = 1; period < length; ++period) {
                    if (length % period == 0) {
                        int changesNeeded = 0;
                      
                        // Check pairs of characters that should be equal in a semi-palindrome
                        // with the given period
                        for (int leftIdx = 0; leftIdx < length; ++leftIdx) {
                            // Calculate corresponding right index for semi-palindrome check
                            int rightIdx = (length / period - 1 - leftIdx / period) * period + leftIdx % period;
                          
                            // Only check each pair once (avoid double counting)
                            if (leftIdx >= rightIdx) {
                                break;
                            }
                          
                            // Count mismatches that need to be changed
                            if (s[start - 1 + leftIdx] != s[start - 1 + rightIdx]) {
                                ++changesNeeded;
                            }
                        }
                      
                        // Update minimum changes for this substring
                        minChanges[start][end] = min(minChanges[start][end], changesNeeded);
                    }
                }
            }
        }
      
        // Dynamic programming to find minimum changes for k partitions
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                // Try all possible positions for the (j-1)th partition endpoint
                for (int prevEnd = 0; prevEnd < i - 1; ++prevEnd) {
                    // dp[i][j] = min(previous j-1 partitions + cost of jth partition)
                    dp[i][j] = min(dp[i][j], dp[prevEnd][j - 1] + minChanges[prevEnd + 1][i]);
                }
            }
        }
      
        // Return minimum changes to partition entire string into k semi-palindromes
        return dp[n][k];
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/)
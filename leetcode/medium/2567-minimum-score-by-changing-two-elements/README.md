# Minimum Score by Changing Two Elements

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums`.

- The low score of nums is the minimum absolute difference between any two integers.
- The high score of nums is the maximum absolute difference between any two integers.
- The score of nums is the sum of the high and low scores.

Return the  **minimum score**  after  **changing two elements**  of `nums`.

 

Original
C++
 **Example 1:** 

 **Input:**  nums = [1,4,7,8,5]

 **Output:**  3

 **Explanation:** 

- Change nums[0] and nums[1] to be 6 so that nums becomes [6,6,7,8,5].
- The low score is the minimum absolute difference: |6 - 6| = 0.
- The high score is the maximum absolute difference: |8 - 5| = 3.
- The sum of high and low score is 3.

 **Example 2:** 

 **Input:**  nums = [1,4,3]

 **Output:**  0

 **Explanation:** 

- Change nums[1] and nums[2] to 1 so that nums becomes [1,1,1].
- The sum of maximum absolute difference and minimum absolute difference is 0.

 

 **Constraints:** 

- 3 <= nums.length <= 105
- 1 <= nums[i] <= 109

## Solution

**Language:** C++  
**Runtime:** 14 ms (beats 77.72%)  
**Memory:** 37.7 MB (beats 96.37%)  
**Submitted:** 2026-11-19T16:27:56.212Z  

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) return 0;

        sort(nums.begin(), nums.end());

        // 1. Change two smallest -> new min is nums[2], max is nums[n - 1]
        int changeTwoSmallest = nums[n - 1] - nums[2];

        // 2. Change two largest -> new min is nums[0], max is nums[n - 3]
        int changeTwoLargest = nums[n - 3] - nums[0];

        // 3. Change one smallest and one largest -> new min is nums[1], max is nums[n - 2]
        int changeBothEnds = nums[n - 2] - nums[1];

        return min({changeTwoSmallest, changeTwoLargest, changeBothEnds});
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-score-by-changing-two-elements/)
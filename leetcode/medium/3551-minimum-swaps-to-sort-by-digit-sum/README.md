# Minimum Swaps to Sort by Digit Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an array `nums` of  **distinct**  positive integers. You need to sort the array in  **increasing**  order based on the sum of the digits of each number. If two numbers have the same digit sum, the  **smaller**  number appears first in the sorted order.

Return the  **minimum**  number of swaps required to rearrange `nums` into this sorted order.

A  **swap**  is defined as exchanging the values at two distinct positions in the array.

 

 **Example 1:** 

 **Input:**  nums = [37,100]

 **Output:**  1

 **Explanation:** 

- Compute the digit sum for each integer: [3 + 7 = 10, 1 + 0 + 0 = 1] → [10, 1]
- Sort the integers based on digit sum: [100, 37]. Swap 37 with 100 to obtain the sorted order.
- Thus, the minimum number of swaps required to rearrange nums is 1.

 **Example 2:** 

 **Input:**  nums = [22,14,33,7]

 **Output:**  0

 **Explanation:** 

- Compute the digit sum for each integer: [2 + 2 = 4, 1 + 4 = 5, 3 + 3 = 6, 7 = 7] → [4, 5, 6, 7]
- Sort the integers based on digit sum: [22, 14, 33, 7]. The array is already sorted.
- Thus, the minimum number of swaps required to rearrange nums is 0.

 **Example 3:** 

 **Input:**  nums = [18,43,34,16]

 **Output:**  2

 **Explanation:** 

- Compute the digit sum for each integer: [1 + 8 = 9, 4 + 3 = 7, 3 + 4 = 7, 1 + 6 = 7] → [9, 7, 7, 7]
- Sort the integers based on digit sum: [16, 34, 43, 18]. Swap 18 with 16, and swap 43 with 34 to obtain the sorted order.
- Thus, the minimum number of swaps required to rearrange nums is 2.

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109
- nums consists of distinct positive integers.

## Solution

**Language:** C++  
**Runtime:** 204 ms (beats 70.37%)  
**Memory:** 149.8 MB (beats 70.68%)  
**Submitted:** 2026-10-17T05:27:23.225Z  

```cpp
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        struct Element {
            int digitSum;
            int val;
            int originalIdx;
        };
        
        // Step 1: Precompute digit sum and store metadata
        vector<Element> elements(n);
        for (int i = 0; i < n; ++i) {
            elements[i] = {getDigitSum(nums[i]), nums[i], i};
        }
        
        // Step 2: Sort by digit sum first, then by value
        sort(elements.begin(), elements.end(), [](const Element& a, const Element& b) {
            if (a.digitSum != b.digitSum) {
                return a.digitSum < b.digitSum;
            }
            return a.val < b.val;
        });
        
        // Step 3: Map original indices to target indices
        vector<int> targetIdx(n);
        for (int i = 0; i < n; ++i) {
            targetIdx[elements[i].originalIdx] = i;
        }
        
        // Step 4: Count minimum swaps via cycle detection
        vector<bool> visited(n, false);
        int totalSwaps = 0;
        
        for (int i = 0; i < n; ++i) {
            if (visited[i] || targetIdx[i] == i) {
                continue;
            }
            
            int cycleSize = 0;
            int curr = i;
            
            while (!visited[curr]) {
                visited[curr] = true;
                curr = targetIdx[curr];
                cycleSize++;
            }
            
            if (cycleSize > 0) {
                totalSwaps += (cycleSize - 1);
            }
        }
        
        return totalSwaps;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/)
# Sum of Sortable Integers

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums` of length `n`.

An integer `k` is called  **sortable**  if `k`  **divides**  `n` and you can sort `nums` in  **non-decreasing**  order by sequentially performing the following operations:

- Partition nums into consecutive subarrays of length k.
- Cyclically rotate each subarray independently any number of times to the left or to the right.

Return an integer denoting the sum of all possible sortable integers `k`.

 

 **Example 1:** 

 **Input:**  nums = [3,1,2]

 **Output:**  3

 **Explanation:** ​​​​​​​

- For n = 3, possible divisors are 1 and 3.
- For k = 1: each subarray has one element. No rotation can sort the array.
- For k = 3: the single subarray [3, 1, 2] can be rotated once to produce [1, 2, 3], which is sorted.
- Only k = 3 is sortable. Hence, the answer is 3.

 **Example 2:** 

 **Input:**  nums = [7,6,5]

 **Output:**  0

 **Explanation:** 

- For n = 3, possible divisors are 1 and 3.
- For k = 1: each subarray has one element. No rotation can sort the array.
- For k = 3: the single subarray [7, 6, 5] cannot be rotated into non-decreasing order.
- No k is sortable. Hence, the answer is 0.

 **Example 3:** 

 **Input:**  nums = [5,8]

 **Output:**  3

 **Explanation:** ​​​​​​​

- For n = 2, possible divisors are 1 and 2.
- Since [5, 8] is already sorted, every divisor is sortable. Hence, the answer is 1 + 2 = 3.

 

 **Constraints:** 

- 1 <= n == nums.length <= 105
- 1 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 35 ms (beats 90.44%)  
**Memory:** 106.4 MB (beats 30.88%)  
**Submitted:** 2026-10-20T10:07:35.056Z  

```cpp
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int sortableIntegers(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> sorted_nums = nums;
        std::sort(sorted_nums.begin(), sorted_nums.end());

        // Prefix sums to verify multiset sum equality in O(1)
        std::vector<long long> prefNums(n + 1, 0), prefSorted(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefNums[i + 1] = prefNums[i] + nums[i];
            prefSorted[i + 1] = prefSorted[i] + sorted_nums[i];
        }

        // Precalculate drops: drops[i] = 1 if nums[i] > nums[i+1]
        std::vector<int> prefDrops(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            prefDrops[i + 1] = prefDrops[i] + (nums[i] > nums[i + 1] ? 1 : 0);
        }

        int totalSum = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool isPossible = true;

            for (int i = 0; i < n; i += k) {
                // 1. Check if block elements sum matches target sorted block sum
                long long sumBlock = prefNums[i + k] - prefNums[i];
                long long sumTarget = prefSorted[i + k] - prefSorted[i];
                if (sumBlock != sumTarget) {
                    isPossible = false;
                    break;
                }

                // 2. Count internal drops within the range [i, i + k - 1]
                int numDrops = prefDrops[i + k - 1] - prefDrops[i];

                if (numDrops > 1) {
                    isPossible = false;
                    break;
                } 
                else if (numDrops == 1) {
                    // If there's 1 drop, wrap-around condition must hold: last <= first
                    if (nums[i + k - 1] > nums[i]) {
                        isPossible = false;
                        break;
                    }
                }
            }

            if (isPossible) {
                totalSum += k;
            }
        }

        return totalSum;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sum-of-sortable-integers/)
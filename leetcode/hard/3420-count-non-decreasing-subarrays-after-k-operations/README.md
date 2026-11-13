# Count Non-Decreasing Subarrays After K Operations

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an array `nums` of `n` integers and an integer `k`.

For each subarray of `nums`, you can apply  **up to**  `k` operations on it. In each operation, you increment any element of the subarray by 1.

 **Note**  that each subarray is considered independently, meaning changes made to one subarray do not persist to another.

Return the number of subarrays that you can make  **non-decreasing**  ​​​​​after performing at most `k` operations.

An array is said to be  **non-decreasing**  if each element is greater than or equal to its previous element, if it exists.

 

Original
C++
 **Example 1:** 

 **Input:**  nums = [6,3,1,2,4,4], k = 7

 **Output:**  17

 **Explanation:** 

Out of all 21 possible subarrays of `nums`, only the subarrays `[6, 3, 1]`, `[6, 3, 1, 2]`, `[6, 3, 1, 2, 4]` and `[6, 3, 1, 2, 4, 4]` cannot be made non-decreasing after applying up to k = 7 operations. Thus, the number of non-decreasing subarrays is `21 - 4 = 17`.

 **Example 2:** 

 **Input:**  nums = [6,3,1,3,6], k = 4

 **Output:**  12

 **Explanation:** 

The subarray `[3, 1, 3, 6]` along with all subarrays of `nums` with three or fewer elements, except `[6, 3, 1]`, can be made non-decreasing after `k` operations. There are 5 subarrays of a single element, 4 subarrays of two elements, and 2 subarrays of three elements except `[6, 3, 1]`, so there are `1 + 5 + 4 + 2 = 12` subarrays that can be made non-decreasing.

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109
- 1 <= k <= 109

## Solution

**Language:** C++  
**Runtime:** 38 ms (beats 83.16%)  
**Memory:** 142.2 MB (beats 95.79%)  
**Submitted:** 2026-11-13T00:42:52.222Z  

```cpp
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long ops = 0;
        deque<int> dq; // Stores indices of running maximums in increasing order
        
        int r = n - 1;
        for (int l = n - 1; l >= 0; --l) {
            // Merge smaller elements to the right up to nums[l]
            while (!dq.empty() && nums[dq.back()] <= nums[l]) {
                int curr = dq.back();
                dq.pop_back();
                int next_bound = dq.empty() ? r + 1 : dq.back();
                ops += 1LL * (next_bound - curr) * (nums[l] - nums[curr]);
            }
            dq.push_back(l);
            
            // Shrink window from the right if operations exceed k
            while (ops > k) {
                int max_idx = dq.front();
                ops -= (nums[max_idx] - nums[r]);
                if (max_idx == r) {
                    dq.pop_front();
                }
                r--;
            }
            
            ans += (r - l + 1);
        }
        
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/)
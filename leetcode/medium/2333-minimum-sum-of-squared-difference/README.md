# Minimum Sum of Squared Difference

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given two positive  **0-indexed**  integer arrays `nums1` and `nums2`, both of length `n`.

The  **sum of squared difference**  of arrays `nums1` and `nums2` is defined as the  **sum**  of `(nums1[i] - nums2[i])2` for each `0 <= i < n`.

You are also given two positive integers `k1` and `k2`. You can modify any of the elements of `nums1` by `+1` or `-1` at most `k1` times. Similarly, you can modify any of the elements of `nums2` by `+1` or `-1` at most `k2` times.

Return  *the minimum  **sum of squared difference**  after modifying array* `nums1` *at most* `k1` *times and modifying array* `nums2` *at most* `k2` *times*.

 **Note** : You are allowed to modify the array elements to become  **negative**  integers.

 

 **Example 1:** 

```
Input: nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
Output: 579
Explanation: The elements in nums1 and nums2 cannot be modified because k1 = 0 and k2 = 0. 
The sum of square difference will be: (1 - 2)2 + (2 - 10)2 + (3 - 20)2 + (4 - 19)2 = 579.

```

 **Example 2:** 

```
Input: nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
Output: 43
Explanation: One way to obtain the minimum sum of square difference is: 
- Increase nums1[0] once.
- Increase nums2[2] once.
The minimum of the sum of square difference will be: 
(2 - 5)2 + (4 - 8)2 + (10 - 7)2 + (12 - 9)2 = 43.
Note that, there are other ways to obtain the minimum of the sum of square difference, but there is no way to obtain a sum smaller than 43.
```

 

 **Constraints:** 

- n == nums1.length == nums2.length
- 1 <= n <= 105
- 0 <= nums1[i], nums2[i] <= 105
- 0 <= k1, k2 <= 109

## Solution

**Language:** C++  
**Runtime:** 12 ms (beats 69.27%)  
**Memory:** 136.4 MB (beats 24.58%)  
**Submitted:** 2026-10-10T03:46:39.778Z  

```cpp
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1+k2;

        int maxDiff = 0;
        vector<int> freq(100001,0);

        for(int i = 0; i<n;i++){
            int diff = abs(nums1[i] - nums2[i]);
            freq[diff]++;
            maxDiff = max(maxDiff,diff);
        }

        for(int d = maxDiff; d>0 && k > 0; --d){
            if(freq[d] == 0) continue;

            long long take = min((long long)freq[d], k);
            freq[d] -= take;
            freq[d-1] += take;
            k -= take; 
        }
        long long ans = 0;
        for(long long d = 1; d <= maxDiff; ++d){
            if(freq[d] > 0){
                ans += freq[d] * d *d;
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-sum-of-squared-difference/)
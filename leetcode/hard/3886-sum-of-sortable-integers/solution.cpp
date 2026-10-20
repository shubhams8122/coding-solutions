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
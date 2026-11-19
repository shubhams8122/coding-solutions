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
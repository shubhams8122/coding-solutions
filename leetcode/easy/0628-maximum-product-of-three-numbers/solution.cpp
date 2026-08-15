class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int max_back = nums[n-1] * nums[0] * nums[1];
        int max_front = nums[n-1] * nums[n-2] * nums[n-3];
        return max(max_back,max_front);
    }
};
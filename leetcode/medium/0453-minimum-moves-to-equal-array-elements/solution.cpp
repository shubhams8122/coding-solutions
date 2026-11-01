class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_val = *min_element(nums.begin(),nums.end());
        long long sum = 0;
        for(int num : nums){
            sum += (num - min_val);
        }
        return sum;
    }
};
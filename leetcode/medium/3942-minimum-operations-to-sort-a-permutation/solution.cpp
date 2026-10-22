class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;
        bool increasing = true;
        bool decreasing = true;
        for(int k = 0; k < n; ++k){
            if(nums[(k+1)%n] != (nums[k]+1)%n){
                increasing = false;
            }
            if(nums[(k+1)%n] != (nums[k] - 1 + n) % n){
                decreasing  = false;
            }
        }
        if(!increasing && !decreasing) return -1;
        int pos = 0;
        for(int k = 0; k < n; ++k){
            if(nums[k] == 0){
                pos = k;
                break;
            }
        }
        if(increasing){
            return min(pos, n- pos +2);
        }
        else{
            return min(n -pos, pos + 2);
        }
    }
};
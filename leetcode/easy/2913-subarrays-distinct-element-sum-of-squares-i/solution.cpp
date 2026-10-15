class Solution {
public:
    int totalSum = 0;

    void helper(vector<int>& nums, int start, int end, unordered_set<int>& st){
        if(end==nums.size()) return;
        st.insert(nums[end]);
        totalSum += st.size() * st.size();
        helper(nums,start,end+1,st);
    }
    int sumCounts(vector<int>& nums) {
        for(int i = 0; i< nums.size();i++){
            unordered_set<int> st;
            helper(nums, i, i, st);
        }
        return totalSum;
    }
};
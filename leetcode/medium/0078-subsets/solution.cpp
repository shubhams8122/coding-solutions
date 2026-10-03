class Solution {
public:
      vector<vector<int>> output;
    void backtrack(int first, vector<int>& curr, vector<int> & activities){
        output.push_back(curr);
      
        for(int i =first; i<activities.size(); i++){
            curr.push_back(activities[i]);
            backtrack(i+1,curr,activities);
            curr.pop_back();
      }
  }
    vector<vector<int>> subsets(vector<int>& nums) {
        output.clear();
        vector<int> curr;
        backtrack(0,curr,nums);
        return output;
    }
};
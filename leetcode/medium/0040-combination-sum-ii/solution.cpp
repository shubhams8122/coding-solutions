class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int> & tempList, vector<int> & candidates, int target, int start){
        if(target < 0){
            return;
        }
        if(target == 0){
            result.push_back(tempList);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            if(i > start && candidates[i] == candidates[i-1]){
                continue;
            }
            tempList.push_back(candidates[i]);
            backtrack(result,tempList,candidates,target-candidates[i],i+1);
            tempList.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> tempList;
        backtrack(result, tempList,candidates,target,0);
        return result;
    }
};
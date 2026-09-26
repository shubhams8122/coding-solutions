class Solution {
private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Skip candidates that exceed the remaining target
            if (candidates[i] > target) continue;

            current.push_back(candidates[i]);
            // Pass 'i' instead of 'i + 1' to allow reusing the same candidate
            backtrack(candidates, target - candidates[i], i, current, result);
            current.pop_back(); // Backtrack
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};
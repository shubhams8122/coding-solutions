class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s : strs){
            string sorted_S =s;
            sort(sorted_S.begin(),sorted_S.end());
            mp[sorted_S].push_back(s);
        }
        vector<vector<string>> result;
        for(auto& pair : mp){
            result.push_back(pair.second);
        }
        return result;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int k = 0;
        if(n==0) return "";
        if(n==1) return strs[0];
        while(true){
            for(int i = 1; i < n; i++){
                if(k == strs[i].size() || k == strs[0].size()) return strs[0].substr(0,k);
                if(strs[i][k] != strs[0][k]) return strs[0].substr(0,k);
            }
            k++;
        }
    }
};
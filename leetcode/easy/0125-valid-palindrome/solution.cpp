class Solution {
public:
    bool isPalindrome(string s) {
        string filtered = "";
        for(char ch : s){
            if(isalnum(ch)){
                filtered.push_back(tolower(ch));
            }
        }
        string reversed = filtered;
        reverse(reversed.begin(),reversed.end());
        return filtered == reversed;
    }
};
class Solution {
public:
    bool help(string s, string t){
        if (s.size() != t.size()) return false;
        map<char, char> m;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(m.find(s[i])== m.end()){
                m[s[i]] = t[i];
            }
            else if(m[s[i]]!=t[i]){
                return false;
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return help(s,t) && help(t,s);
    }
};
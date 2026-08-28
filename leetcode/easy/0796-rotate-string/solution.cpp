class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        s += s;
        if(s.contains(goal)) return true;
        else return false;
    }
};
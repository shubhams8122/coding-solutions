class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if(is_sorted(s.begin(),s.end())) return 0;
        if(n == 2) return -1;
        char min_char = *min_element(s.begin(),s.end());
        char max_char = *max_element(s.begin(),s.end());
        if(s[0] == min_char || s[n-1] == max_char) return 1;
        bool max_only_at_0 = (s[0] == max_char);
        bool min_only_at_end = (s[n-1] == min_char);
        if(max_only_at_0 && min_only_at_end){
            for(int i = 1; i < n; ++i){
                if(s[i] == max_char) max_only_at_0 = false;
            }
            for(int i = 0; i < n-1; ++i){
                if(s[i] == min_char) min_only_at_end = false;
            }
            if(max_only_at_0 && min_only_at_end) return 3;
        }
        return 2;
    }
};
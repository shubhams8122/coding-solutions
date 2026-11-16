class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k){
            string new_string = "";
            for(int i = 0;i < s.length();i+=k){
                int sum = 0;
                for(int j = i; j < i + k && j < s.length(); ++j){
                    sum += s[j] - '0';
                }
                new_string += to_string(sum);
            }
            s = new_string;
        }
        return s;
    }
};
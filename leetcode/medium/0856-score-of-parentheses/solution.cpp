class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(char ch:s){
            if(ch=='('){
                st.push(0);
            }
            else{
                int innerScore = st.top();
                st.pop();
                int val = max(2*innerScore,1);
                st.top() += val;
            }
        }
        return st.top();
    }
};
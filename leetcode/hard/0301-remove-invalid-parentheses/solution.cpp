class Solution {
public:
    bool isValid(const string&s){
        int count = 0;
        for(char ch : s){
            if(ch == '(') count++;
            else if(ch==')') {
                count--;
                if(count < 0) return false;
            }
        }
        return count == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);

        bool found = false;

        while(!q.empty()){
            int levelSize = q.size();
            for(int i = 0; i < levelSize; ++i){
                string curr = q.front();
                q.pop();

                if(isValid(curr)){
                    result.push_back(curr);
                    found = true;
                }
                if(found)  continue;
                for (int j = 0; j < curr.length(); ++j) {
                    if (curr[j] != '(' && curr[j] != ')') continue;

                    string nextStr = curr.substr(0, j) + curr.substr(j + 1);
                    if (!visited.count(nextStr)) {
                        visited.insert(nextStr);
                        q.push(nextStr);
                    }
                }
            }
            if (found) break;
            }
            return result;
        }
};
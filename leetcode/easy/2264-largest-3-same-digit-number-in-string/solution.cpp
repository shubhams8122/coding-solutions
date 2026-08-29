class Solution {
public:
    string largestGoodInteger(string num) {
        string maxStr ="";
        for(int i = 0; i<=num.length()-3;i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                string current = num.substr(i,3);
                if(current > maxStr){
                    maxStr = current;
                }
            }
        }
        return maxStr;
    }
};
class Solution {
public:
    string frequencySort(string s) {
       vector<pair<int,char>> arr(123,{0,0});
       for(char ch : s){
        arr[ch] = {arr[ch].first + 1, ch};
       } 
       sort(arr.begin(),arr.end(), greater<pair<int,char>>());
       string ans = "";
       for(int i = 0; i < 123;i++){
        ans.append(string(arr[i].first,arr[i].second));
       }
       return ans;
    }
};
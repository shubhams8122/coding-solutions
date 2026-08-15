class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int totalSum = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int currentSum = 0;
            for(int j = i; j < n; ++j){
                currentSum += arr[j];
                if((j-i+1)%2 != 0){
                    totalSum += currentSum;
                }
            }
        }
        return totalSum;
    }
};
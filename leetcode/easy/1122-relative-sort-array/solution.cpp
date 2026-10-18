class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        for(int num : arr2){
            for(int i = 0; i < arr1.size(); i++){
                if(arr1[i] == num){
                    result.push_back(arr1[i]);
                    arr1[i] = -1;
                }
            }
        }
        sort(arr1.begin(),arr1.end());
        
        for(int num : arr1){
            if(num >= 0){
                result.push_back(num);
            }
        }
        return result;
    }
};
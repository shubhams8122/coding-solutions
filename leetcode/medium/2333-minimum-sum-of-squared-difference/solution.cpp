class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1+k2;

        int maxDiff = 0;
        vector<int> freq(100001,0);

        for(int i = 0; i<n;i++){
            int diff = abs(nums1[i] - nums2[i]);
            freq[diff]++;
            maxDiff = max(maxDiff,diff);
        }

        for(int d = maxDiff; d>0 && k > 0; --d){
            if(freq[d] == 0) continue;

            long long take = min((long long)freq[d], k);
            freq[d] -= take;
            freq[d-1] += take;
            k -= take; 
        }
        long long ans = 0;
        for(long long d = 1; d <= maxDiff; ++d){
            if(freq[d] > 0){
                ans += freq[d] * d *d;
            }
        }
        return ans;
    }
};
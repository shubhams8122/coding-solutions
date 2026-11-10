class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) return;

        // Store the last k elements
        vector<int> temp(k);
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }

        // Shift the remaining elements to the right
        for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }

        // Place the temp elements at the beginning
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};
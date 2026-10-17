#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        struct Element {
            int digitSum;
            int val;
            int originalIdx;
        };
        
        // Step 1: Precompute digit sum and store metadata
        vector<Element> elements(n);
        for (int i = 0; i < n; ++i) {
            elements[i] = {getDigitSum(nums[i]), nums[i], i};
        }
        
        // Step 2: Sort by digit sum first, then by value
        sort(elements.begin(), elements.end(), [](const Element& a, const Element& b) {
            if (a.digitSum != b.digitSum) {
                return a.digitSum < b.digitSum;
            }
            return a.val < b.val;
        });
        
        // Step 3: Map original indices to target indices
        vector<int> targetIdx(n);
        for (int i = 0; i < n; ++i) {
            targetIdx[elements[i].originalIdx] = i;
        }
        
        // Step 4: Count minimum swaps via cycle detection
        vector<bool> visited(n, false);
        int totalSwaps = 0;
        
        for (int i = 0; i < n; ++i) {
            if (visited[i] || targetIdx[i] == i) {
                continue;
            }
            
            int cycleSize = 0;
            int curr = i;
            
            while (!visited[curr]) {
                visited[curr] = true;
                curr = targetIdx[curr];
                cycleSize++;
            }
            
            if (cycleSize > 0) {
                totalSwaps += (cycleSize - 1);
            }
        }
        
        return totalSwaps;
    }
};
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";
        
        string result = "";
        result.reserve(num);
        
        int nines = sum / 9;
        int rem = sum % 9;
        
        result.append(nines, '9');
        if (rem > 0) {
            result.push_back('0' + rem);
        }
        
        int zeros = num - result.length();
        result.append(zeros, '0');
        
        return result;
    }
};
class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        int mondayMoney= 1;
        int dailyMoney = 1;
        for(int i = 1; i <= n; i++){
            total += dailyMoney;
            dailyMoney++;
            if(i%7==0){
                mondayMoney++;
                dailyMoney = mondayMoney;
            }
        }
        return total;
    }
};
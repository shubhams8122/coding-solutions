class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // Effective costBoth cannot exceed the sum of individual costs
        long long cb = min((long long)costBoth, (long long)cost1 + cost2);
        long long total_cost = 0;
        
        // Step 1: Satisfy the overlapping requirement using the cheapest combined method
        long long common_need = min((long long)need1, (long long)need2);
        total_cost += common_need * cb;
        
        need1 -= common_need;
        need2 -= common_need;
        
        // Step 2: Satisfy remaining Type 1 requirement
        if (need1 > 0) {
            long long c1 = min((long long)cost1, cb);
            total_cost += need1 * c1;
        }
        
        // Step 3: Satisfy remaining Type 2 requirement
        if (need2 > 0) {
            long long c2 = min((long long)cost2, cb);
            total_cost += need2 * c2;
        }
        
        return total_cost;
    }
};
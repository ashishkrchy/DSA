class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long totalCost1 =  1LL * cost1 * need1 + 1LL * cost2 * need2;

        int minNeed = min(need1, need2);

        long long totalCost2 = 1LL * minNeed * costBoth + 1LL * (need1 - minNeed) * cost1 + 1LL * (need2 - minNeed) * cost2;

        long long totalCost3 = 1LL * max(need1, need2) * costBoth;
        
        return min({totalCost1, totalCost2, totalCost3});
    }
};
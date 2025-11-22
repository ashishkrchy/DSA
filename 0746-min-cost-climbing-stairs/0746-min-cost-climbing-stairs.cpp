class Solution {
public:

    

    int helper(vector<int>& cost, int idx, vector<int> &dp){

        if(idx >= cost.size()){
            return 0;
        }

        if(dp[idx] != -1) return dp[idx];

        int oneStep = cost[idx] + helper(cost, idx + 1, dp);
        int twoStep = cost[idx] + helper(cost, idx + 2, dp);

        return dp[idx] = min(oneStep, twoStep);
    }

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        vector<int> dp1(n + 1, -1);

        vector<int> dp2(n + 1, -1);

        return min(helper(cost, 0, dp1), helper(cost, 1, dp2));
    }
};
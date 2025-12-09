class Solution {
public:
    int minimumCost(vector<int>& cost) {

        int n = cost.size();

        sort(cost.begin(), cost.end());

        int minCost = 0;
        int take = 0;

        for(int i = n - 1; i >= 0; i--){

            if(take < 2) {
                minCost += cost[i];
                take++;
            }
            else{
                take = 0;
            }
        }

        return minCost;
    }
};
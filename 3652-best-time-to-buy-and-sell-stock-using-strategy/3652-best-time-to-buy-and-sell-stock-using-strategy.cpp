class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {

        int n = prices.size();

        vector<long long> prefixSumPrices(n + 1, 0);
        vector<long long> prefixSumstrategy(n + 1, 0);

        for(int i = 1; i <= n; i++){
            prefixSumPrices[i] = prices[i - 1] + prefixSumPrices[i - 1];
            prefixSumstrategy[i] = (prices[i - 1] * strategy[i - 1]) + prefixSumstrategy[i - 1];
        }

        int m = k / 2;

        long long maxProfit = prefixSumstrategy[n];

        for(int i = 0; i <= n - k; i++){

            int l = i;
            int r = i + k;

            long long startSum = prefixSumstrategy[l];

            long long modifyRight = prefixSumPrices[r] - prefixSumPrices[l + m];

            long long endSum = prefixSumstrategy[n] - prefixSumstrategy[r];

            long long totalProfit = startSum + modifyRight + endSum; 


            maxProfit = max(maxProfit, totalProfit);
        }
        

        return maxProfit;
    }
};
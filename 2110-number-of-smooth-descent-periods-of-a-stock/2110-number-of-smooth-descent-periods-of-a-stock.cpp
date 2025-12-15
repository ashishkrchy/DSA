class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();

        if(n == 1) return 1;

        int left = 0;
        int right = 1;

        long long count = 0;

        while(right < n){

            while(right < n && (prices[right - 1] - prices[right]) == 1) right++;

            int m = right - left;

            count = count + (1LL * m * (m + 1) / 2);

            if(right == n - 1){
                return count + 1;
            }

            left = right;

            right++;
        }

        return count;
    }
};
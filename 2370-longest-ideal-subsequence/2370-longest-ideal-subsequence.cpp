class Solution {
public:
    int longestIdealString(string s, int k) {

        vector<int> dp(26, 0);

        for(char ch : s) {
            int curr = ch - 'a';

            int best = 0;

            for(int i = max(0, curr - k); i <= min(25, curr + k); i++) {
                best = max(best, dp[i]);
            }

            dp[curr] = max(dp[curr], 1 + best);
        }

        return *max_element(dp.begin(), dp.end());
    }
};

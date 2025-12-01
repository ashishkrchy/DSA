class Solution {
public:

    long long dp[12][2][1<<10];

    long long solve(string &s, int idx, int tight, int mask) {
        if (idx == s.size()) {
            return 1; 
        }

        if (dp[idx][tight][mask] != -1)
            return dp[idx][tight][mask];

        int limit = tight ? s[idx] - '0' : 9;

        long long ans = 0;

        for (int d = 0; d <= limit; d++) {

            int newTight = tight && (d == limit);

            if (mask == 0 && d == 0) {
                ans += solve(s, idx + 1, newTight, 0);
            }
            else {
                
                if (mask & (1 << d)) continue;

                int newMask = mask | (1 << d);

                ans += solve(s, idx + 1, newTight, newMask);
            }
        }

        return dp[idx][tight][mask] = ans;
    }

    int countNumbersWithUniqueDigits(int n) {
        
        string s = string(n, '9'); 

        memset(dp, -1, sizeof(dp));

        return solve(s, 0, 1, 0);
    }
};

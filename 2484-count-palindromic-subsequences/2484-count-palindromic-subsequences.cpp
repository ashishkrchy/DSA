class Solution {
public:
    int dp[10001][5];
    const int MOD = 1e9 + 7;

    int countWays(int i, string &s, int j, vector<char> &pattern){
        if(j == 5) return 1;

        if(i == s.size()) return 0;

        // int res = dp[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int take = 0;

        if(pattern[j] == '_' || s[i] == pattern[j]){
            take = countWays(i + 1, s, j + 1, pattern);
        }

        int skip = countWays(i + 1, s, j, pattern);

        return dp[i][j] = (take + skip) % MOD;
    }

    int countPalindromes(string s) {

        int n = s.size();

        int count = 0;

        for(char x = '0' ; x <= '9' ; x++){

            for(char y = '0'; y <= '9'; y++){

                vector<char> pattern = {x, y, '_', y, x};

                memset(dp, -1, sizeof(dp));

                count = (count + countWays(0, s, 0, pattern)) % MOD;
            }
        }

        return count;
    }
};
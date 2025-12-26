class Solution {
public:
    static const int MOD = 1e9 + 7;

    // dp[pos][patIdx]: number of ways to match pattern[patIdx..4]
    // using s[pos..end]
    int dp[10001][5];

    int countWays(int pos, int patIdx, const string &s, const vector<char> &pattern) {
        if (patIdx == 5) return 1;          // pattern fully matched
        if (pos == s.size()) return 0;      // string exhausted

        int &res = dp[pos][patIdx];
        if (res != -1) return res;

        long long take = 0, skip = 0;

        // Take current character if it matches,
        // or if we are at the wildcard position (index 2)
        if (patIdx == 2 || s[pos] == pattern[patIdx]) {
            take = countWays(pos + 1, patIdx + 1, s, pattern);
        }

        // Skip current character
        skip = countWays(pos + 1, patIdx, s, pattern);

        return res = (take + skip) % MOD;
    }

    int countPalindromes(string s) {
        int n = s.size();
        long long answer = 0;

        // Fix x and y in palindrome pattern: x y _ y x
        for (char x = '0'; x <= '9'; x++) {
            
            for (char y = '0'; y <= '9'; y++) {

                vector<char> pattern = {x, y, 0, y, x};

                memset(dp, -1, sizeof(dp));
                answer = (answer + countWays(0, 0, s, pattern)) % MOD;
            }
        }

        return answer;
    }
};

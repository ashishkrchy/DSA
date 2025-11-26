class Solution {
public:
    int m, n;
    const long long MOD = 1e9 + 7;

    vector<vector<vector<long long>>> dp;

    long long helper(vector<vector<int>>& grid, int k, int x, int y, int rem) {

        if (x == m || y == n) return 0;

        if (dp[x][y][rem] != -1) return dp[x][y][rem];

        if (x == m - 1 && y == n - 1) {
            int finalRem = (rem + grid[x][y]) % k;
            return dp[x][y][rem] = (finalRem == 0 ? 1 : 0);
        }

        long long ways = 0;

        int newRem = (rem + grid[x][y]) % k;


        if (y + 1 < n)
            ways = (ways + helper(grid, k, x, y + 1, newRem)) % MOD;


        if (x + 1 < m)
            ways = (ways + helper(grid, k, x + 1, y, newRem)) % MOD;

        return dp[x][y][rem] = ways;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {

        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<long long>>(n, vector<long long>(k, -1)));

        return helper(grid, k, 0, 0, 0);
    }
};

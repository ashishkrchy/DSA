class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i <= m - 3; i++) {

            for (int j = 0; j <= n - 3; j++) {

                if (grid[i+1][j+1] != 5) continue;

                vector<int> freq(10, 0);
                bool valid = true;

                for (int r = i; r < i + 3; r++) {
                    for (int c = j; c < j + 3; c++) {
                        int val = grid[r][c];
                        if (val < 1 || val > 9 || freq[val]++) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) break;
                }

                if (!valid) continue;

                int r1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                int r2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
                int r3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];

                int c1 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
                int c2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
                int c3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];

                int d1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
                int d2 = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];

                if (r1 == 15 && r2 == 15 && r3 == 15 &&
                    c1 == 15 && c2 == 15 && c3 == 15 &&
                    d1 == 15 && d2 == 15) {
                    count++;
                }
            }
        }
        return count;
    }
};

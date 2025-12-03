class Solution {
public:
    int m,n;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    long long dfs(int x, int y, vector<vector<int>>& grid) {

        long long sum = grid[x][y];

        grid[x][y] = 0;   

        for(int d = 0; d < 4; d++) {

            int newX = x + dx[d];
            int newY = y + dy[d];

            if(newX >= 0 && newY >= 0 && newX < m && newY < n &&
            grid[newX][newY] != 0) {

                sum += dfs(newX, newY, grid);
            }
        }
        return sum;
    }



    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0){
                    
                    long long sum = dfs(i, j, grid);

                    if(sum % k == 0) count++;
                }
            }
        }

        return count;
    }
};
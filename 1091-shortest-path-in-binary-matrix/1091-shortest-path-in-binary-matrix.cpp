class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
            return -1;

        vector<int> dx = {-1, 1, 0, 0, -1, 1, -1, 1};
        vector<int> dy = {0, 0, -1, 1, -1, 1, 1, -1};

        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        q.push({0,0});
        dist[0][0] = 1;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (i == m - 1 && j == n - 1)
                return dist[i][j];

            for (int d = 0; d < 8; d++) {
                int x = i + dx[d];
                int y = j + dy[d];

                if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 0 && dist[x][y] == -1) {
                    dist[x][y] = dist[i][j] + 1;
                    q.push({x, y});
                }
            }
        }

        return -1; 
    }
};

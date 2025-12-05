class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        
        visited[node] = 1;

        for (int v = 0; v < isConnected.size(); v++) {
            if (isConnected[node][v] == 1 && !visited[v]) {
                dfs(v, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<int> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                count++;
            }
        }

        return count;
    }
};

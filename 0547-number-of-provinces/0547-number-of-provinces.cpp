class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited){

        visited[node] = 1;

        for(auto v : adj[node]){
            if(!visited[v]){
                dfs(v, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;

                if(isConnected[i][j] == 1){
                    int u = i;
                    int v = j;

                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }

        vector<int> visited(n, 0);
        int count = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                count++;
            }
        }

        return count;
    }
};
class Solution {
public:
    int dfs(int node, vector<vector<pair<int,int>>>& adj, vector<bool>& visited) {

        visited[node] = true;
        
        int count = 0;

        for (auto& p : adj[node]) {
            int neigh = p.first;
            int cost = p.second;

            if (!visited[neigh]) {
                count += cost + dfs(neigh, adj, visited);
            }
        }

        return count;
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto& c : connections) {

            int u = c[0];
            int v = c[1];

            adj[u].push_back({v, 1}); 
            adj[v].push_back({u, 0});
        }

        vector<bool> visited(n, false);

        return dfs(0, adj, visited);
    }
};

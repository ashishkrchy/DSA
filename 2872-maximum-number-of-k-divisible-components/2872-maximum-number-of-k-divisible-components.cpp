class Solution {
public:
    int ans = 0;

    int dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& values, int k) {
        
        long long sum = values[node] % k;

        for(int child : adj[node]) {
            if(child == parent) continue;

            long long childSum = dfs(child, node, adj, values, k);

            if(childSum % k == 0) {
                ans++;    
            } else {
                sum = (sum + childSum) % k;   
            }
        }

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, adj, values, k);

        return ans + 1;
    }
};

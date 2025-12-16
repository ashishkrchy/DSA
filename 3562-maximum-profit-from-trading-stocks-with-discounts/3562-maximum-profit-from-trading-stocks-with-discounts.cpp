class Solution {
public:
    int n;
    int B;   // budget
    vector<int> present, future;
    vector<vector<int>> g;

    // dfs(u) returns:
    // dp0 -> parent NOT bought
    // dp1 -> parent bought
    // uSize -> subtree size (max cost bound)
    
    tuple<vector<int>, vector<int>, int> dfs(int u) {

        int cost = present[u];
        int dCost = cost / 2;

        vector<int> dp0(B + 1, 0);
        vector<int> dp1(B + 1, 0);

        vector<int> subProfit0(B + 1, 0);
        vector<int> subProfit1(B + 1, 0);

        int uSize = cost;

        // Process children
        for (int v : g[u]) {
            auto [subDp0, subDp1, vSize] = dfs(v);
            uSize += vSize;

            for (int i = B; i >= 0; i--) {
                for (int sub = 0; sub <= min(vSize, i); sub++) {
                    subProfit0[i] = max(
                        subProfit0[i],
                        subProfit0[i - sub] + subDp0[sub]
                    );

                    subProfit1[i] = max(
                        subProfit1[i],
                        subProfit1[i - sub] + subDp1[sub]
                    );
                }
            }
        }

        // Decide whether to buy u
        for (int i = 0; i <= B; i++) {

            // not buying u
            dp0[i] = dp1[i] = subProfit0[i];

            // parent bought → discounted purchase
            if (i >= dCost) {
                dp1[i] = max(
                    dp1[i],
                    subProfit1[i - dCost] + future[u] - dCost
                );
            }

            // parent not bought → full price
            if (i >= cost) {
                dp0[i] = max(
                    dp0[i],
                    subProfit1[i - cost] + future[u] - cost
                );
            }
        }

        return {dp0, dp1, uSize};
    }

    int maxProfit(int n_, vector<int>& present_, vector<int>& future_, vector<vector<int>>& hierarchy, int budget) {

        n = n_;
        B = budget;
        present = present_;
        future = future_;

        g.assign(n, {});
        for (auto &e : hierarchy) {
            int p = e[0] - 1;
            int c = e[1] - 1;
            g[p].push_back(c);
        }

        auto [dp0, dp1, _] = dfs(0);

        // root has no parent
        return dp0[B];
    }
};

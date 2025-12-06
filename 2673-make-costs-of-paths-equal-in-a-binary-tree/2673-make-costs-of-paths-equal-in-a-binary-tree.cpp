class Solution {
public:

    int dfs(int i, vector<int>& cost, int &ans) {

        if (i > cost.size()) return 0;

        int left = dfs(2 * i, cost, ans);

        int right = dfs(2 * i + 1, cost, ans);

        ans += abs(left - right);
    
        return cost[i - 1] + max(left, right);
    }

    int minIncrements(int n, vector<int>& cost) {

        int ans = 0;

        dfs(1, cost, ans);

        return ans;
    }
};

struct TrieNode {
    TrieNode* next[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    int n;
    vector<int> dp;

    void insert(string& word) {

        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->next[idx])
                node->next[idx] = new TrieNode();
            node = node->next[idx];
        }
        node->isEnd = true;
    }

    int solve(int i, string& target) {

        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        TrieNode* node = root;
        
        int ans = INT_MAX;

        for (int j = i; j < n; j++) {

            int idx = target[j] - 'a';
            
            if (!node->next[idx]) break;

            node = node->next[idx];

            int sub = solve(j + 1, target);
            if (sub != INT_MAX) {
                ans = min(ans, 1 + sub);
            }
        }

        return dp[i] = ans;
    }

    int minValidStrings(vector<string>& words, string target) {
        for (auto& w : words) insert(w);

        n = target.size();
        dp.assign(n, -1);

        int res = solve(0, target);
        return res == INT_MAX ? -1 : res;
    }
};

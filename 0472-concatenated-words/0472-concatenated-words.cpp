class Solution {
public:

    bool dfs(string &word, int idx, unordered_set<string> &st, vector<int> &dp) {
        
        if (idx == word.size()) return true;

        if (dp[idx] != -1) return dp[idx];

        string cur = "";

        for (int i = idx; i < word.size(); i++) {

            cur += word[i];

            if (st.count(cur)) {

                if (dfs(word, i + 1, st, dp)) {
                    return dp[idx] = true;
                }
            }
        }
        return dp[idx] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        unordered_set<string> st(words.begin(), words.end());

        vector<string> res;

        for (string &w : words) {

            st.erase(w); 

            vector<int> dp(w.size(), -1);

            if (dfs(w, 0, st, dp)) {
                res.push_back(w);
            }

            st.insert(w);
        }

        return res;
    }
};

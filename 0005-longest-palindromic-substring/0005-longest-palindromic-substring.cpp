class Solution {
public:
    int t[1001][1001];
    
    bool solve(string &s, int i, int j){
        if(i >= j) return 1;

        if(t[i][j] != -1) return t[i][j];

        if(s[i] == s[j]) return t[i][j] = solve(s, i+1, j-1);
        return t[i][j] = 0;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0;
        int startingP = 0;

        memset(t, -1, sizeof(t));

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if (solve(s, i, j)) {
                    if (maxLen < j - i + 1) {
                        maxLen = j - i + 1;
                        startingP = i;
                    }
                }
            }
        }
        return s.substr(startingP, maxLen);
    }
};

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.size();

        vector<vector<int>> res;

        int i = 0;
        int j = 0;

        while(j < n){
            while(j < n && s[i] == s[j]) j++;

            if(j - i >= 3){
                res.push_back({i, j - 1});
            }

            i = j;
        }

        return res;
    }
};
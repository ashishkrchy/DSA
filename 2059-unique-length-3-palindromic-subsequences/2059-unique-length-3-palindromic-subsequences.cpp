class Solution {
public:
    int countPalindromicSubsequence(string s) {

        vector<int> first(26, -1), last(26, -1);

        int n = s.size();

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        int count = 0;

        for (int c = 0; c < 26; c++) {

            if (first[c] == -1 || last[c] - first[c] < 2) continue;

            unordered_set<char> mid;
            for (int i = first[c] + 1; i < last[c]; i++) {
                mid.insert(s[i]);
            }
            count += mid.size();
        }

        return count;
    }
};

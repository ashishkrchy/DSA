class Solution {
public:
    
    void expand(string &s, int left, int right, int &start, int &maxLen) {
        int n = s.size();
        
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++) {
            // Odd length
            expand(s, i, i, start, maxLen);
            
            // Even length
            expand(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }
};

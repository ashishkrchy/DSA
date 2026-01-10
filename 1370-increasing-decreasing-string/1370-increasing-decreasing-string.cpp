class Solution {
public:
    string sortString(string s) {

        vector<int> freq(26, 0);
        string result;

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int remaining = s.size();

        while (remaining > 0) {
            
            for (int i = 0; i < 26 && remaining > 0; i++) {
                if (freq[i] > 0) {
                    result.push_back(char('a' + i));
                    freq[i]--;
                    remaining--;
                }
            }

            for (int i = 25; i >= 0 && remaining > 0; i--) {
                if (freq[i] > 0) {
                    result.push_back(char('a' + i));
                    freq[i]--;
                    remaining--;
                }
            }
        }

        return result;
    }
};

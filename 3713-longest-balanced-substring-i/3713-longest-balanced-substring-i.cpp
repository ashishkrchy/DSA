class Solution {
public:

    int longestBalanced(string s) {
        int n = s.size();

        int maxLen = 0;

        for(int i = 0; i < n; i++){

            vector<int> freq(26, 0);

            for(int j = i; j < n; j++){

                freq[s[j] - 'a']++;

                int maxFreq = INT_MIN;
                int minFreq = INT_MAX;

                for(int i = 0; i < 26; i++){
                    if(freq[i] == 0) continue;

                    maxFreq = max(maxFreq, freq[i]);
                    minFreq = min(minFreq, freq[i]);
                }

                if(maxFreq == minFreq){
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};
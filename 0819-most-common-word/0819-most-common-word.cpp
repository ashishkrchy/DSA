class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int n = paragraph.size();

        unordered_set<string> bannedWords;
        for(auto word: banned){
            bannedWords.insert(word);
        }

        unordered_map<string, int> freq;

        int i = 0;

        while(i < n){
            
            string temp = "";
            while(i < n && isalpha(paragraph[i])){
                temp += tolower(paragraph[i]);
                i++;
            }

            while(i < n && !isalpha(paragraph[i])) i++;

            if(!bannedWords.count(temp)){
                freq[temp]++;

            } 
        }

        int count = 0;
        string ans = "";

        for(auto [word, fr]: freq){
            if(count < fr){
                count = fr;
                ans = word;
            }
        }

        return ans;
    }
};
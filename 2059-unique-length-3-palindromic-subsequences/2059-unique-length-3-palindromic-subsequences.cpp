class Solution {
public:
    int countPalindromicSubsequence(string s) {

        int n = s.size();

        unordered_map<char, tuple<int,int,int>> mp;

        for(int i = 0; i < n; i++){
            if(!mp.count(s[i])){
                mp[s[i]] = {i, i, 1};
            }
            else{
                get<1>(mp[s[i]]) = i; 
                get<2>(mp[s[i]]) ++; 
            }

        }

        int count = 0;

        for(auto &[ch, t]: mp){

            auto &[start, end, freq] = t;

            unordered_set<char> unique;

            if(end - start + 1 >= 3){

                for(int i = start + 1; i < end; i++){
                    unique.insert(s[i]);
                }

                count = count + (int)unique.size();
            } 
        }

        return count;

    }
};
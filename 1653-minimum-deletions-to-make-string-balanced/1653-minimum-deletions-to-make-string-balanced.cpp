class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        int count = 0;

        int curr = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == 'b'){
                curr++;
            }
            else if(curr && s[i] == 'a'){
                curr--;
                count++;
            }
        }

        return count;
    }
};
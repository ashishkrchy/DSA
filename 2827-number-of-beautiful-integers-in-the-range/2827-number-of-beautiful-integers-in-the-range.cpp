class Solution {
public:

    int dp[11][2][2][21][21];

    int solve(string &s, int idx, int k, int tight, int started, int mod, int diff){
        

        if(idx == s.size()){
            if(started == 1 && diff == 0 && mod == 0)
                return 1;
            return 0;
        }

        int diffIndex = diff + 10;

        if(dp[idx][tight][started][mod][diffIndex] != -1) return dp[idx][tight][started][mod][diffIndex];

        int ans = 0;

        int limit = tight ? (s[idx] - '0') : 9;

        for(int d = 0; d <= limit; d++){
            
            int newTight = tight && (d == limit);

            if(started == 0 && d == 0){
                ans += solve(s, idx+1, k, newTight, 0, 0, 0);
            } 
            else {
            
                int newMod = (mod * 10 + d) % k;
                int newDiff = diff + ((d % 2 == 0) ? +1 : -1);

                ans += solve(s, idx+1, k, newTight, 1, newMod, newDiff);
            }
        }

        return dp[idx][tight][started][mod][diffIndex] = ans;
    }

    int countUpTo(long long x, int k){
        if(x < 0) return 0;

        string s = to_string(x);

        memset(dp, -1, sizeof(dp));

        return solve(s, 0, k, 1, 0, 0, 0);
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {

        return countUpTo(high, k) - countUpTo(low - 1, k);

    }
};

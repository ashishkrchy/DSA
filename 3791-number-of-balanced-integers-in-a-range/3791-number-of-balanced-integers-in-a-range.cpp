class Solution {
public:
    long long dp[20][2][181][20];

    long long helper(string &s, int idx, int tight, int diff, int digits){

        if(idx == s.size()){
            return (diff == 0 && digits >= 2);
        }

        long long &res = dp[idx][tight][diff + 90][digits];

        if(res != -1) return res;

        res = 0;

        int limit = tight ? (s[idx] - '0') : 9;

        for(int d = 0; d <= limit; d++){

            int newDigits = digits + (d  != 0);

            int newDiff = diff;

            int newTight = tight && (d == limit);
            
            int rightIdx = s.size() - idx;

            if(d != 0){
                if(rightIdx % 2 == 0) newDiff += d;
                else newDiff -= d;
            }

            res += helper(s, idx + 1, newTight, newDiff, newDigits);

        }

        return res;
    }

    long long count(long long num){
        
        string s = to_string(num);

        memset(dp, -1, sizeof(dp));

        return helper(s, 0, 1, 0, 0);
    }
    
    long long countBalanced(long long low, long long high) {

        return count(high) - count(low - 1);
    }
};
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        long long MOD = 1000000007;

        for(auto q: queries){

            int i = q[0];
            int j = q[1];
            int val = q[3];
            int jump = q[2];

            while(i <= j){

               long long modifiedVal = (1LL * nums[i] * val) % MOD;

               nums[i] = (int)modifiedVal; 

               i += jump;
            }
        }

        int totalXOR = 0;

        for(auto ele: nums){
            totalXOR ^= ele;
        }

        return totalXOR;
    }
};
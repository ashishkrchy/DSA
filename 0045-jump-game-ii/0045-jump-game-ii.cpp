class Solution {
public:
    vector<int> dp;

    long long helper(vector<int>& nums, int idx){

        if(idx >= nums.size() - 1){
            return 0;
        }

        if(dp[idx] != -1) return dp[idx];

        long long minSteps = INT_MAX;

        for(int i = 1; i <= nums[idx]; i++){
            if(idx + i < nums.size()){
                minSteps = min(minSteps, (long long)1 + helper(nums, idx + i)); 
            }
        }

        return dp[idx] = minSteps;
    }

    int jump(vector<int>& nums) {

        int n = nums.size();

        dp.assign(n, -1);

        return (int)helper(nums, 0);
    }
};
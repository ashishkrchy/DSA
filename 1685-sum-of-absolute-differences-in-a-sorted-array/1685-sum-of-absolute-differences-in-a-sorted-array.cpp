class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);

        for(int i = 1; i <= n; i++){
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        vector<int> res(n, 0);

        int currSum = 0;

        for(int i = 0; i < n; i++){


            int left = (nums[i] * i) - currSum;
            int right = (nums[i] * (n - i - 1)) - (prefixSum[n] - prefixSum[i + 1]);

            res[i] = abs(left) + abs(right);

            currSum += nums[i];
      
        }

        return res;
            
    }
};
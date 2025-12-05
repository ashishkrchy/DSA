class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixSum(n + 1, 0);

        for(int i = 0; i < n; i++){
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        int count = 0;

        for(int i = 0; i < n - 1; i++){

            int leftSum = prefixSum[i + 1];

            int rightSum = prefixSum[n] - prefixSum[i + 1];


            if((rightSum - leftSum) % 2 == 0) count++;
        }

        return count;
    }
};
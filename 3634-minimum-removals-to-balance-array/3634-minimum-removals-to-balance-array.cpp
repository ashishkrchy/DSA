class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();

        if(n == 1) return 0;

        sort(nums.begin(), nums.end());

        int minRem = n;

        for(int i = 0; i < n - 1; i++){
            int toRem = nums.end() - upper_bound(nums.begin(), nums.end(), 1LL * nums[i] * k) + i;

            minRem = min(minRem, toRem);
        }
        
        return minRem;
    }
};
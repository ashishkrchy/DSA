class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == 1) return 0;

        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;
        
        int i = 0;
        int j = k - 1;

        while(i < n && j < n){
            
            minDiff = min(minDiff, abs(nums[i] - nums[j]));
            
            i++;
            j++;  
        }
 
        return minDiff;
    }
};
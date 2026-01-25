class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1) return 0; 

        int rightSum=accumulate(nums.begin()+1, nums.end(), 0);

        if(rightSum==0) return 0;
        int leftSum=0;

        for(int i=1; i<n; ++i){
            leftSum+=nums[i-1];
            rightSum-=nums[i];
            if(leftSum==rightSum) return i;
        }
        return -1;
    }
};
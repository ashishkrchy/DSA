class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        
        int n = nums.size();

        int maxLen = 0;

        for(int i = 0; i < n; i++){
            
            int cntEven = 0;
            int cntOdd = 0;
            
            unordered_set<int> distinct;
            
            for(int j = i; j < n; j++){

                if(!distinct.count(nums[j]) && nums[j] % 2 == 0) cntEven++;
                else if(!distinct.count(nums[j]) && nums[j] % 2 != 0) cntOdd++;
                
                distinct.insert(nums[j]);

                if(cntEven == cntOdd) maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};
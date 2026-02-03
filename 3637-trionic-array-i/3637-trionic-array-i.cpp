class Solution {
public:
    bool isIncreasing(vector<int>& nums, int start, int end){
        for(int i = start; i < end; i++){
            if(nums[i] == nums[i + 1]  || nums[i] > nums[i + 1]) return false;
        }
        return true;
    }

    bool isDecreasing(vector<int>& nums, int start, int end){
        for(int i = start; i < end; i++){
            if(nums[i] == nums[i + 1] || nums[i] < nums[i + 1]) return false;
        }
        return true;
    }

    bool isTrionic(vector<int>& nums) {

        int n  = nums.size();
        
        for(int i = 1; i < n; i++){
            if(isIncreasing(nums, 0, i)){
                cout<<i<<" ";
                for(int j = i + 1; j < n - 1; j++){
                    if(isDecreasing(nums, i, j) && isIncreasing(nums, j, n - 1)){
                        cout<<j<<endl;
                        return true;
                    } 
                }
            } 
        }
        return false;
    }
};
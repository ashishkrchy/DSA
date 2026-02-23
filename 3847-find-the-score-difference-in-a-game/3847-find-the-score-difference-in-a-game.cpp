class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();

        int first = 0;
        int second = 0;

        bool activeFirst = true;   

        for(int i = 0; i < n; i++){

            if(nums[i] & 1) activeFirst = !activeFirst;

            if(i % 6 == 5) activeFirst = !activeFirst;

            if(activeFirst) first += nums[i];
            else second += nums[i];
        }

        return first - second;
    }
};
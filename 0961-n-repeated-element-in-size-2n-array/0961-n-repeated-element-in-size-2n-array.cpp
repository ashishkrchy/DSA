class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        int n  = nums.size();

        unordered_map<int,int> freq;
        int req =  n / 2;

        for(int i = 0; i < n; i++){
            freq[nums[i]]++;

            if(freq[nums[i]] == req) return nums[i];
        }

        return -1;
    }
};
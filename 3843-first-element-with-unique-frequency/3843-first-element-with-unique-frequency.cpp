class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> freq;

        for(auto num: nums){
            freq[num]++;
        }

        unordered_map<int, int> map;

        for(auto [num, count]: freq){
            map[count]++;
        }

        for(auto num: nums){
            if(map[freq[num]] == 1){
                return num;
            } 
        }

        return -1;
    }
};
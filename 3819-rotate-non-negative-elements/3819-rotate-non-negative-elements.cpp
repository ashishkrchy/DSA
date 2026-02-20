class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {

        vector<int> pos;  
        int n = nums.size();

        for(int x : nums) {
            if(x >= 0) pos.push_back(x);
        }

        if(pos.empty()) return nums;

        k %= pos.size();

        reverse(pos.begin(), pos.begin() + k);
        reverse(pos.begin() + k, pos.end());
        reverse(pos.begin(), pos.end());

        vector<int> res = nums;

        int j = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] >= 0) {
                res[i] = pos[j++];
            }
        }

        return res;
    }
};
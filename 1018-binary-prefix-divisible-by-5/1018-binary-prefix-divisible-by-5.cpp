class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {

        int n = nums.size();

        vector<bool> res;

        int rem = 0;

        for (int bit : nums) {
            rem = (rem * 2 + bit) % 5;
            res.push_back(rem == 0);
        }

        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        int ans = 0;
        int mask = 0;

        for(int bit = 31; bit >= 0; bit--) {
            mask |= (1 << bit);

            unordered_set<int> s;
            for(int x : nums) s.insert(x & mask);

            int guess = ans | (1 << bit);

            for(int prefix : s) {
                if(s.count(prefix ^ guess)) {
                    ans = guess;
                    break;
                }
            }
        }
        return ans;

    }
};
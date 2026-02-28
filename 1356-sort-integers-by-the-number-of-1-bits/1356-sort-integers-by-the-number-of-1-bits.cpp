class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();

        vector<pair<int,int>> bits;

        for(auto x: arr){
            int bit =  __builtin_popcount(x);
            bits.push_back({bit, x});
        }

        sort(bits.begin(), bits.end());

        vector<int> ans;

        for(auto x: bits){
            ans.push_back(x.second);
        }

        return ans;
    }
};
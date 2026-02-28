class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        int n = nums.size();

        vector<pair<int,int>> temp;

        for(int i = 0; i < n; i++){
            temp.push_back({nums[i], i});
        }
        
        sort(temp.begin(), temp.end());

        vector<pair<int,int>> res;

        int i = n - 1;

        while(i >= 0 && k--){
            res.push_back({temp[i].second, temp[i].first});
            i--;
        }

        sort(res.begin(), res.end());

        vector<int> ans;

        for(auto x: res){
            ans.push_back(x.second);
        }

        return ans;
    }
};
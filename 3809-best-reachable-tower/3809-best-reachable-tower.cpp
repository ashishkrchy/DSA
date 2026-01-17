class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int n = towers.size();

        vector<int> ans(2);

        unordered_map<int,set<pair<int,int>>> mp;

        for(int i = 0; i < n; i++){

            int dist = abs(towers[i][0] - center[0]) + abs(towers[i][1] - center[1]);

            if(dist <= radius){

                mp[towers[i][2]].insert({towers[i][0], towers[i][1]});    

            }
        }

        int maxQ = INT_MIN;

        if(mp.empty()){
            return {-1, -1};
        }

        for(auto &[q, st]: mp){
            if(maxQ <= q){
                auto it = *st.begin();
                ans[0] = it.first;
                ans[1] = it.second;
                maxQ = q;
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        vector<vector<int>> ans;

        int n = arr.size();

        int minDif = INT_MAX;

        sort(arr.begin(), arr.end());

        for(int i=1; i<n; i++){

            int dif = arr[i] - arr[i-1];
            
            minDif = min(minDif, dif); 
        }

        for (int i = 1; i < n; ++i) {
            if (arr[i] - arr[i - 1] == minDif) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};
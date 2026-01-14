class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        int m = bookings.size();
        
        vector<int> diffArr(n + 1, 0);

        for(int i = 0; i < m; i++){
            int left = bookings[i][0] - 1;
            int right = bookings[i][1];

            diffArr[left] += bookings[i][2];
            diffArr[right] -= bookings[i][2];
        }

        vector<int> ans(n, 0);

        for(int i = 1; i <= n; i++){
            diffArr[i] += diffArr[i-1];
            ans[i - 1] = diffArr[i - 1];
        }

        return ans;
    }
};
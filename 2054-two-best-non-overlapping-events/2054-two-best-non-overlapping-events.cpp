class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {

        int n = events.size();

        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        vector<int> maxVal(n);
        maxVal[n - 1] = events[n - 1][2];

        for (int i = n - 2; i >= 0; i--) {
            maxVal[i] = max(maxVal[i + 1], events[i][2]);
        }

        vector<int> starts(n);
        for (int i = 0; i < n; i++){
            starts[i] = events[i][0];
        }

        int maxSum = 0;

        for (int i = 0; i < n; i++) {
            int idx = upper_bound(starts.begin(), starts.end(), events[i][1]) - starts.begin();

            if (idx < n) {
                maxSum = max(maxSum, events[i][2] + maxVal[idx]);
            }
        }

        return max(maxSum, maxVal[0]);
    }
};

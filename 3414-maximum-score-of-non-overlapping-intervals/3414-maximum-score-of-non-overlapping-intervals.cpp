class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Attach original index to each interval
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        // Sort intervals by end time
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        // dp[i][k] = { maxWeight, chosenIndices }
        // considering intervals[0..i], choosing exactly k intervals
        vector<vector<pair<long long, vector<int>>>> dp(
            n, vector<pair<long long, vector<int>>>(5, {0, {}})
        );

        // Base case: first interval alone
        dp[0][1] = {intervals[0][2], {intervals[0][3]}};
        long long maxWeight = intervals[0][2];

        for (int i = 1; i < n; i++) {

            // Find last interval that doesn't overlap with i
            int left = 0, right = i - 1, prev = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (intervals[mid][1] < intervals[i][0]) {
                    prev = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            for (int k = 1; k <= 4; k++) {

                // Option 1: inherit previous best
                dp[i][k] = dp[i - 1][k];

                // Option 2: extend previous compatible interval
                if (prev != -1 && k > 1) {
                    long long candidateWeight =
                        dp[prev][k - 1].first + intervals[i][2];

                    vector<int> candidateIndices = dp[prev][k - 1].second;
                    candidateIndices.push_back(intervals[i][3]);
                    sort(candidateIndices.begin(), candidateIndices.end());

                    if (dp[i][k].first < candidateWeight ||
                        (dp[i][k].first == candidateWeight &&
                         candidateIndices < dp[i][k].second)) {
                        dp[i][k] = {candidateWeight, candidateIndices};
                    }
                }

                // Option 3: take only this interval
                if (k == 1) {
                    long long singleWeight = intervals[i][2];
                    vector<int> singleIndex = {intervals[i][3]};

                    if (dp[i][k].first < singleWeight ||
                        (dp[i][k].first == singleWeight &&
                         singleIndex < dp[i][k].second)) {
                        dp[i][k] = {singleWeight, singleIndex};
                    }
                }

                maxWeight = max(maxWeight, dp[i][k].first);
            }
        }

        // Pick lexicographically smallest among max-weight solutions
        vector<int> answer = {INT_MAX};
        for (int k = 1; k <= 4; k++) {
            if (dp[n - 1][k].first == maxWeight) {
                answer = min(answer, dp[n - 1][k].second);
            }
        }

        return answer;
    }
};

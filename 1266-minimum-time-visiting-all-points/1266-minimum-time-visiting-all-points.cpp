class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();

        int totalTime = 0;

        for(int i = 1; i < n; i++){
            int x1 = points[i-1][0];
            int y1 = points[i-1][1];

            int x2 = points[i][0];
            int y2 = points[i][1];

            totalTime += max(abs(x1-x2), abs(y1-y2));
        }

        return totalTime;
    }
};
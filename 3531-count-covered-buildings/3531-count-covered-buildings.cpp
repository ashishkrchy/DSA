class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        unordered_map<int, int> rowMin, rowMax;
        unordered_map<int, int> colMin, colMax;

        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            if (!rowMin.count(x)) rowMin[x] = y;
            else rowMin[x] = min(rowMin[x], y);

            if (!rowMax.count(x)) rowMax[x] = y;
            else rowMax[x] = max(rowMax[x], y);

            if (!colMin.count(y)) colMin[y] = x;
            else colMin[y] = min(colMin[y], x);

            if (!colMax.count(y)) colMax[y] = x;
            else colMax[y] = max(colMax[y], x);
        }

        int covered = 0;

        for (auto& b : buildings) {
            int x = b[0], y = b[1];

            bool hasLeftRight = (rowMin[x] < y && y < rowMax[x]);
            bool hasUpDown   = (colMin[y] < x && x < colMax[y]);

            if (hasLeftRight && hasUpDown) covered++;
        }

        return covered;
    }
};

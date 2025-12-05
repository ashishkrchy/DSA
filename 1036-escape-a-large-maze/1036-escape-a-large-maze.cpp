class Solution {
public:

    const int MAXN = 1000000;
    const int LIMIT = 20000;  

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    string getKey(int x, int y){
        return to_string(x) + "_" + to_string(y);
    }

    
    bool bfs(vector<int>& start, vector<int>& end, unordered_set<string>& blockedSet) {

        unordered_set<string> visited;
        queue<pair<int,int>> q;

        q.push({start[0], start[1]});
        visited.insert(getKey(start[0], start[1]));

        while (!q.empty() && visited.size() <= LIMIT) {

            auto [i, j] = q.front();
            q.pop();


            if (i == end[0] && j == end[1])
                return true;

            for (int d = 0; d < 4; d++) {
                int x = i + dx[d];
                int y = j + dy[d];

                if (x >= 0 && y >= 0 && x < MAXN && y < MAXN) {

                    string key = getKey(x, y);

                    if (!blockedSet.count(key) && !visited.count(key)) {
                        visited.insert(key);
                        q.push({x, y});
                    }
                }
            }
        }

        return visited.size() > LIMIT;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {

        unordered_set<string> blockedSet;


        for (auto &b : blocked)
            blockedSet.insert(getKey(b[0], b[1]));


        return bfs(source, target, blockedSet) && bfs(target, source, blockedSet);
    }
};

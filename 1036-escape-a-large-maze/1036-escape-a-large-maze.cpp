class Solution {
public:

    const int LIMIT = 20000;

    long long makeKey(int x, int y){
        return (long long)1000000 * x + y;
    }

    bool bfs(vector<int>& start, vector<int>& target, unordered_set<long long>& blockedSet) {

        vector<int> dx = {0, 0, -1, 1}; 
        vector<int> dy = {-1, 1, 0, 0}; 

        queue<pair<int,int>> q;
        unordered_set<long long> visited;


        q.push({start[0], start[1]});
        visited.insert(makeKey(start[0], start[1]));

        while(!q.empty() && visited.size() <= LIMIT){

            auto [i, j] = q.front();
            q.pop();

            if(i == target[0] && j == target[1])
                return true;

            for(int d = 0; d < 4; d++){
                int x = i + dx[d];
                int y = j + dy[d];

                if(x < 0 || y < 0 || x >= 1000000 || y >= 1000000) 
                    continue;

                long long key = makeKey(x, y);

                if(!blockedSet.count(key) && !visited.count(key)){
                    visited.insert(key);
                    q.push({x, y});
                }
            }
        }

        return visited.size() > LIMIT;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {

        unordered_set<long long> blockedSet;

        for (auto &b : blocked) {
            long long key = makeKey(b[0], b[1]);
            blockedSet.insert(key);
        }
    
        return bfs(source, target, blockedSet) && bfs(target, source, blockedSet);
    }
};

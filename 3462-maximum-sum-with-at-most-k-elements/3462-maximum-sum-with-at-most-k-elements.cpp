class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {

        int n = grid.size();
        int m = grid[0].size();

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < n; i++){

            priority_queue<int, vector<int>, greater<int>> temp;

            for(int j = 0; j < m; j++){

                temp.push(grid[i][j]);

                if(temp.size() > limits[i]) temp.pop();
            }

            while(!temp.empty()){
                pq.push(temp.top());
                temp.pop();

                if(pq.size() > k) pq.pop();
            }

        }

        long long sum = 0;

        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};
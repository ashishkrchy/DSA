class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> available;

        for (int i = 0; i < n; i++) available.push(i);

        priority_queue<pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>> busy;

        vector<int> usage(n, 0);

        for (auto &m : meetings) {
            
            long long start = m[0], end = m[1];
            long long duration = end - start;

            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                int room = available.top();
                available.pop();
                busy.push({end, room});
                usage[room]++;
            } else {
                auto [endTime, room] = busy.top();
                busy.pop();
                busy.push({endTime + duration, room});
                usage[room]++;
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (usage[i] > usage[ans]){
                ans = i;
            }     
        }

        return ans;
    }
};

class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {

        int n = damage.size();

        vector<pair<int,int>> enemy;
        for (int i = 0; i < n; i++) {
            enemy.push_back({damage[i], health[i]});
        }

        long long totalDamage = 0;
        for (int d : damage) totalDamage += d;

        sort(enemy.begin(), enemy.end(), [&](auto &a, auto &b) {
            long long timeA = (a.second + power - 1) / power;
            long long timeB = (b.second + power - 1) / power;
            return (long long)a.first * timeB > (long long)b.first * timeA;
        });

        long long currDamage = 0;
        long long cost = 0;

    
        for (int i = 0; i < n; i++) {

            //cout<<enemy[i].first<<" : "<<enemy[i].second<<endl;

            long long timeReq = (enemy[i].second + power - 1) / power;

            cost += (totalDamage - currDamage) * timeReq;

            currDamage += enemy[i].first;
        }

        return cost;
    }
};

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {


        vector<int> mentions(numberOfUsers, 0);

        vector<int> nextOnline(numberOfUsers, 0);
        
        int allCount = 0;

        sort(events.begin(), events.end(), [](auto &a, auto &b){
            int ta = stoi(a[1]), tb = stoi(b[1]);
            if (ta == tb) return a[0] == "OFFLINE";
            return ta < tb;
        });

        for (auto &e : events) {
            string &type    = e[0];
            int time        = stoi(e[1]);
            string &data    = e[2];

            if (type == "OFFLINE") {
                int uid = stoi(data);
                nextOnline[uid] = time + 60;
            } 
            else { 
                if (data == "ALL") {
                    allCount++;
                }
                else if (data == "HERE") {
                    for (int uid = 0; uid < numberOfUsers; uid++) {
                        if (nextOnline[uid] <= time) {
                            mentions[uid]++;
                        }
                    }
                } 
                else {
                
                    stringstream ss(data);
                    string token;
                    while (ss >> token) {
                        int uid = stoi(token.substr(2));
                        mentions[uid]++;
                    }
                }
            }
        }

        for (int i = 0; i < numberOfUsers; i++) {
            mentions[i] += allCount;
        }

        return mentions;
    }
};

class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {

        int n = arrivals.size();
        
        unordered_map<int,int> map;
        unordered_set<int> idx;

        int countDiscard = 0;

        for(int i = 0; i < n; i++){

            if(i >= w && idx.count(i - w)){
                map[arrivals[i - w]]--;
                if(map[arrivals[i - w]] <= 0) map.erase(arrivals[i - w]);

            }

            if(map.count(arrivals[i]) && map[arrivals[i]] >= m) countDiscard++;
            else{
                map[arrivals[i]]++;
                idx.insert(i);
            } 

        }

        return countDiscard;
    }
};
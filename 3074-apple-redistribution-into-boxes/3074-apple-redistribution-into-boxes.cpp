class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        int n = capacity.size();

        int totalApple = 0;

        for(auto a: apple){
            totalApple += a;
        }

        sort(capacity.begin(), capacity.end());

        int i = n - 1;

        int currSum = 0;
        int count  = 0;

        while(i >= 0 && currSum < totalApple){
            currSum += capacity[i];
            count++;
            i--;
        }

        return count;
    }
};
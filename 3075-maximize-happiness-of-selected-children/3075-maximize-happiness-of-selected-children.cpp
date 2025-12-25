class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();

        sort(happiness.rbegin(), happiness.rend());

        long long sum = 0;
        int dec = 0;

        for(int i = 0; i < k; i++){
            sum += max(0, happiness[i] - dec);
            dec++;
        }

        return sum; 
    }
};
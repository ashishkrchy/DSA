class Solution {
public:
    bool isDigitorialPermutation(int n) {
        
        vector<int> factorials = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

        int x = n;

        long long sum = 0;

        while(x > 0){
            int d = x % 10;

            sum += factorials[d];

            x /= 10;
        }

        string nums = to_string(n);
        sort(nums.begin(), nums.end());

        string factNums = to_string(sum);
        sort(factNums.begin(), factNums.end());

        return nums == factNums;
    }
};
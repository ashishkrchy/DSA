class Solution {
public:
    int smallestRepunitDivByK(int k) {
        
        int n = 0;

        for(int i = 1; i <= k; i++){
            n = n * 10 + 1;

            if(n % k == 0) return i;
            else n = n % k;
        }
        return -1;
    }
};
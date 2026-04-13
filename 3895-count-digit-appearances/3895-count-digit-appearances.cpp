class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();

        int count = 0;

        for(auto m: nums){
            
            while(m > 0){
                if(m % 10 == digit) count++;
                m /= 10;
            }
        }

        return count;
    }
};
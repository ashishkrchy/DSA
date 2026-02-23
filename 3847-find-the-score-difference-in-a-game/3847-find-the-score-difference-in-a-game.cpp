class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();

        int first = 0;
        int second = 0;

        int turn = true;

        for(int i = 0; i < n; i++){

            if(nums[i] % 2 != 0 && (i + 1) % 6 == 0){

                if(turn){
                    first += nums[i];
                }
                else{
                    second += nums[i];
                }

            }
            else if(nums[i] % 2 != 0 || (i + 1) % 6 == 0){

                if(turn){
                    second += nums[i];
                }
                else{
                    first += nums[i];
                }

                turn = !turn;
            }
            else{

                if(turn){
                    first += nums[i];
                }
                else{
                    second += nums[i];
                }

            }
        }

        return first - second;
    }
};
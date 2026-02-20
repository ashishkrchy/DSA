class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {

        int n = nums.size();
        
        vector<int> temp;

        for(int i = 0; i < n; i++){
            if(nums[i] >= 0) temp.push_back(i);
        }

        if(temp.empty()) return nums;

        k = k > temp.size() ? k % temp.size(): k;

        reverse(temp.begin(), temp.begin() + k);
        reverse(temp.begin() + k, temp.end());
        reverse(temp.begin(), temp.end());

        vector<int> res(n, 0);

        int j = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] < 0) res[i] = nums[i];
            else{
                res[i] = nums[temp[j]];
                j++;
            }
        }

        return res;
    }
};
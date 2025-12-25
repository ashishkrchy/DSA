class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int mid) {
        int count = 1;
        long long currSum = 0;

        for (int x : nums) {
            if (currSum + x > mid) {
                count++;
                currSum = x;
            } else {
                currSum += x;
            }
        }

        return count <= k;
    }


    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

};
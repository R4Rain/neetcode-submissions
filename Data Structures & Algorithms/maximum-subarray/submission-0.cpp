class Solution {
public:
    // Case
    // All Negative Numbers

    int maxSubArray(vector<int>& nums) {
        int maxi = -1001;

        for (int i = 0;i < nums.size();i++) {
            maxi = max(maxi, nums[i]);
        }

        int curr = 0;
        for (int i = 0;i < nums.size();i++) {
            int tmp = curr + nums[i];
            maxi = max(maxi, tmp);

            if (tmp >= 0) {
                curr = tmp;
            } else {
                curr = 0;
            }
        }
        return maxi;
    }
};

class Solution {
public:
    vector<vector<int>> dp;

    int lis(int idx, int prev, vector<int>& nums) {
        if (idx >= nums.size()) {
            return 0;
        }

        if (dp[idx][prev+1] != -1) {
            return dp[idx][prev+1];
        }

        int notTake = lis(idx+1, prev, nums), take = 0;
        if (prev == -1 || nums[prev] < nums[idx]) {
            take = lis(idx+1, idx, nums) + 1;
        }

        return dp[idx][prev+1] = max(take, notTake);
    }
 

    int lengthOfLIS(vector<int>& nums) {
        dp.assign(nums.size()+1, vector<int>(nums.size()+1, -1));
        return lis(0, -1, nums);
    }
};

#include <bits/stdc++.h>
class Solution {
public:
    int dp[200];
    int solve(int idx, vector<int>& nums) {
        if (idx < 0) {
            return 0;
        }
        if (idx == 0) {
            return dp[idx] = nums[idx];
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }

        return dp[idx] = max(nums[idx] + solve(idx-2, nums), solve(idx-1, nums));
    }

    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums.size() - 1, nums);
    }
};

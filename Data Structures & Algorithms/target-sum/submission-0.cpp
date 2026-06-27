#include <bits/stdc++.h>

class Solution {
public:
    const static int maxi = 20000;
    int dp[25][maxi + 50000];

    int solve(int idx, vector<int>& nums, int target) {
        if (idx < 0) {
            if (target == maxi) {
                return 1;
            } else {
                return 0;
            }
        }
        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }

        return dp[idx][target] = solve(idx-1, nums, target+nums[idx]) + solve(idx-1, nums, target-nums[idx]);
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(nums.size()-1, nums, target + maxi);
    }
};

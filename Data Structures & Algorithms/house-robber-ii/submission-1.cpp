#include <bits/stdc++.h>

class Solution {
public:
    int dp1[250];
    int dp2[250];

    int solve1(int idx, vector<int>& nums) {
        if (idx <= 0) {
            return 0;
        }
        if (dp1[idx] != -1) {
            return dp1[idx];
        }
        return dp1[idx] = max(nums[idx] + solve1(idx-2, nums), solve1(idx-1, nums));
    }

    int solve2(int idx, vector<int>& nums) {
        if (idx < 0) {
            return 0;
        }
        if (dp2[idx] != -1) {
            return dp2[idx];
        }
        return dp2[idx] = max(nums[idx] + solve2(idx-2, nums), solve2(idx-1, nums));
    }

    int rob(vector<int>& nums) {
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        if (nums.size() == 1) {
            return nums[0];
        }

        return max(solve1(nums.size() - 1, nums), solve2(nums.size() - 2, nums));
    }
};

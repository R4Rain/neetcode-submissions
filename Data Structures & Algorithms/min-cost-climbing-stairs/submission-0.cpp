#include <bits/stdc++.h>
class Solution {
public:
    int dp[1000] = {0};
    int solve(int idx, vector<int>& cost) {
        if (idx <= 1) {
            return dp[idx] = cost[idx];
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }
        if (idx == cost.size()) {
            return dp[idx] = min(solve(idx-1,cost), solve(idx-2,cost));
        } else {
            return dp[idx] = cost[idx] + min(solve(idx-1,cost), solve(idx-2,cost));
        }
    }


    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        return solve(cost.size(), cost);
    }
};

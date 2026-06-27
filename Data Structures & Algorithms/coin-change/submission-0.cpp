#include <bits/stdc++.h>

class Solution {
public:
    int dp[200000];
    const int MAX_N = 10000000;

    int solve(vector<int> &coins, int amount) {
        if (amount == 0) {
            return 0;
        } else if (amount < 0) {
            return MAX_N;
        }

        if (dp[amount] >= MAX_N) {
            return MAX_N;
        } else if (dp[amount] != 0) {
            return dp[amount];
        }
        
        int res = MAX_N;
        for (int i = 0;i < coins.size();i++) {
            if (amount >= coins[i]) {
                res = min(solve(coins, amount - coins[i]) + 1, res);
            }
        }
        return dp[amount] = res;
    }


    int coinChange(vector<int>& coins, int amount) {
        memset(dp, 0, sizeof(dp));
        int res = solve(coins, amount);
        if (res >= MAX_N) {
            return -1;
        } else {
            return res;
        }
    }
};

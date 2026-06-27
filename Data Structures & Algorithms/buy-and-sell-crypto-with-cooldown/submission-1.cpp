#include <bits/stdc++.h>

class Solution {
public:
    // cooldown +1? jumping index?
    // [1, 3, 4, 0, 4]
    // buy (cheap) -> sell (expensive) -> cooldown -> buy

    // 100, 1, 2, 3, 4

    // f(idx)
    int dp[2000][2];

    int solve(int idx, vector<int>& prices, int coin) {
        if (idx >= prices.size()) {
            return 0;
        }    
        bool isSelling = (coin >= 0) ? 1 : 0;

        // if (dp[idx][isSelling] != -1) {
        //     cout << "hi: " << idx << ' ' << dp[idx][isSelling] << endl;
        //     return dp[idx][isSelling];
        // }

        // SELL
        if (isSelling == 1) {
            if (coin > prices[idx]) {
                return dp[idx][isSelling] = solve(idx+1, prices, coin);
            } else {
                int profit = prices[idx] - coin;
                cout << "Profit: " << idx << ' ' << prices[idx] << ' ' << coin << " = " << profit << endl;
                dp[idx][isSelling] = max(solve(idx+1, prices, coin), solve(idx+2, prices, -1) + profit);
                // cout << idx << ' ' << dp[idx] << endl;
                return dp[idx][isSelling];
            }
        } else {
            return dp[idx][isSelling] = max(solve(idx+1, prices, coin), solve(idx+1, prices, prices[idx]));
        }
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(0, prices, -1);
    }
};

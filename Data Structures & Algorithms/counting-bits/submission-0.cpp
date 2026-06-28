#include<bits/stdc++.h>

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp (n+1, 0);
        if (n == 0) return dp;
        
        dp[1] = 1;
        for (int i = 2;i <= n;i++) {
            int tmp = i;
            if (i % 2) {
                dp[i] = dp[i-1] + 1;
            } else {
                dp[i] = dp[i/2];
            }
        }
        return dp;
    }
};

// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
// 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1



// 12 -> 6 -> 3 -> 2 -> 1 -> 0 (2)
// 14 -> 7 -> 6 -> 3 -> 2 -> 1 -> 0 (3)

// 8 -> 4 -> 2 -> 1 (1)

// 
#include<bits/stdc++.h>

class Solution {
public:
    const static int MAX_SIZE = 1001;
    int dp[MAX_SIZE][MAX_SIZE];

    int lcs(int idx1, int idx2, string text1, string text2) {
        if (idx1 >= text1.size() || idx2 >= text2.size()) {
            return 0;
        }
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];

        int res = 0;
        if (text1[idx1] != text2[idx2]) {
            res = max(lcs(idx1+1, idx2, text1, text2), lcs(idx1, idx2+1, text1, text2));
        } else {
            res = lcs(idx1+1, idx2+1, text1, text2) + 1;
        }

        return dp[idx1][idx2] = res;
    }


    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return lcs(0, 0, text1, text2);
    }
};

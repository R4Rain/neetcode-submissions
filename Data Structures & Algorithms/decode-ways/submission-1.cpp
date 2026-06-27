#include <bits/stdc++.h>

class Solution {
public:
    int dp[105];   

    int dfs(int idx, string s) {
        if (dp[idx] != -1) {
            return dp[idx];
        }
        if (idx > s.size() - 1) {
            return 1;
        }

        if (idx == s.size() - 1) {
            if (s[idx] <= '0') {
                return dp[idx] = 0;
            } else {
                return dp[idx] = 1;
            }
        } else {
            int res = 0;
            if (s[idx] >= '1' && s[idx] <= '9') {
                res += dfs(idx+1, s);
            }

            if (s[idx] == '1' && s[idx+1] >= '0' && s[idx+1] <= '9') {
                res += dfs(idx+2, s);
            } else if(s[idx] == '2' && s[idx+1] >= '0' && s[idx+1] <= '6') {
                res += dfs(idx+2, s);
            }
            return dp[idx] = res;
        }
    }


    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return dfs(0, s);
    }
};

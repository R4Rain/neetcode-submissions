class Solution {
public:
    int dp[50] = {0};
    int climbStairs(int n) {
       if (n <= 0) {
          return 1;  
       }

       if (dp[n] != 0) {
        return dp[n];
       }

       int res = 0;
       if (n <= 1) {
         res = climbStairs(n-1);
       } else {
         res = climbStairs(n-1) + climbStairs(n-2);
       }
       return dp[n] = res;
    }
};

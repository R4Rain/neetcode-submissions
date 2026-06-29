class Solution {
public:
    vector<vector<int>> dp;
    // dp[i][j] = getUniquePaths(i+1, j) + getUniquePaths(i, j+1)

    int getUniquePaths(int i, int j, int m, int n) {
        // base case
        if (i >= m || j >= n) {
            return 0;
        } 
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] = getUniquePaths(i+1, j, m, n) + getUniquePaths(i, j+1, m, n);
    }

    int uniquePaths(int m, int n) {
        dp.assign(m, vector<int>(n, -1));
        return getUniquePaths(0, 0, m, n);
    }
};

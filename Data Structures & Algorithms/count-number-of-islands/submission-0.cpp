class Solution {
public:
    vector<int> adjX = {1, 0, -1, 0};
    vector<int> adjY = {0, 1, 0, -1};

    void backtrack(int i, int j, vector<vector<int>>& used, vector<vector<char>>& grid, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m) return;
        if (used[i][j] == 1 || grid[i][j] == '0') return;
        used[i][j] = 1;

        for (int idx = 0;idx < adjX.size();idx++) {
            int new_i = i + adjX[idx];
            int new_j = j + adjY[idx];

            backtrack(new_i, new_j, used, grid, n, m);
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> used (n, vector<int> (m, 0));
        int ans = 0;

        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                if (used[i][j] == 0 && grid[i][j] == '1') {
                    backtrack(i, j, used, grid, n, m);
                    ans += 1;
                }
            }
        }
        return ans;
    }
};

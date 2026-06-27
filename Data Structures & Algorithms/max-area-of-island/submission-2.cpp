class Solution {
private:
    int n, m;
    vector<int> directionX {1, 0, -1, 0};
    vector<int> directionY {0, 1, 0, -1};
public:
    // DFS
    int dfs(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0) {
            return 0;
        }
        grid[x][y] = 0;
        int result = 1;
        for (int i = 0;i < 4;i++) {
            int xi = x + directionX[i];
            int yi = y + directionY[i];

            result += dfs(xi, yi, grid);
        }
        return result;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int answer = 0;
        n = grid.size(), m = grid[0].size();

        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                answer = max(dfs(i, j, grid), answer);
            }
        }
        return answer;
    }
};

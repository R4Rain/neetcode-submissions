class Solution {
private:
    int n, m;
    vector<vector<bool>> visited;
    vector<int> directionX {1, 0, -1, 0};
    vector<int> directionY {0, 1, 0, -1};
public:
    // DFS
    int dfs(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0 || visited[x][y] == 1) {
            return 0;
        }
        visited[x][y] = 1;
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
        visited.assign(n, vector<bool>(m, 0));

        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    answer = max(dfs(i, j, grid), answer);
                }
            }
        }
        return answer;
    }
};

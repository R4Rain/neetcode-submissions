class Solution {
public:
    void dfs(int x, vector<vector<int>> &adj_graph, vector<int> &visited) {
        visited[x] = 1;

        for (int i = 0; i < adj_graph[x].size();i++) {
            int next = adj_graph[x][i];
            if (visited[next] == 0) {
                dfs(next, adj_graph, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited (n, 0);
        vector<vector<int>> adj_graph (n, vector<int>());

        for (int i = 0;i < edges.size();i++) {
            adj_graph[edges[i][0]].push_back(edges[i][1]);
            adj_graph[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0;
        for (int i = 0;i < n;i++) {
            if (visited[i] == 0) {
                dfs(i, adj_graph, visited);
                ans++;
            }
        }
        return ans;
    }
};

class Solution {
   public:
    void dfs(int n, int root, vector<int>& visited, vector<int> adj_graph[], bool& result) {
        visited[n] = 1;

        for (int i = 0; i < adj_graph[n].size(); i++) {
            int next = adj_graph[n][i];
            // cout << "From: " << n << " Next: " << next << endl;
            if (visited[next] == 1 && next == root) {
                // cout << "Test" << endl;
                result = false;
                return;
            }

            if (visited[next] == 0) {
                dfs(next, root, visited, adj_graph, result);
            }
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj_graph[numCourses];
        vector<int> dep(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            adj_graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            dep[prerequisites[i][0]] += 1;
        }

        bool result = true;
        for (int i = 0; i < numCourses; i++) {
            vector<int> visited(numCourses, 0);
            dfs(i, i, visited, adj_graph, result);
        }
        return result;
    }
};
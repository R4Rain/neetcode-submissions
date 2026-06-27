#define DEBUG 0

// Debug logger function
#if DEBUG
    #define DBG(x) do { cout << x << endl; } while(0)
#else
    #define DBG(x) do {} while(0)
#endif

class Solution {
   private:
    unordered_map<int, vector<int>> adj_graph;
    unordered_set<int> visited;
   public:
    bool dfs(int curr) {
        DBG("I am in the current value: " << curr);
        if (visited.count(curr) != 0) {
            DBG("Hmm curr: " << curr);
            return false;
        }

        if (adj_graph[curr].empty()) {
            return true;
        }

        visited.insert(curr);
        for (int i = 0;i < adj_graph[curr].size();i++) {
            int next = adj_graph[curr][i];
            DBG("Go to the next value: " << next);
            if (!dfs(next)) {
                return false;
            }
        }
        visited.erase(curr);
        adj_graph[curr].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        for (int i = 0;i < prerequisites.size();i++) {
            adj_graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0;i < numCourses;i++) {
            if (!dfs(i)) {
                return false;
            }
        }

        return true;
    }
};
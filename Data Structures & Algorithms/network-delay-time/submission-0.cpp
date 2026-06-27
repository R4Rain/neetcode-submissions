class Solution {
public:
    const int INF = 1e8;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<pair<int,int>> adj_graph[n+1];

       for (int i = 0;i < times.size();i++) {
          adj_graph[times[i][0]].push_back({times[i][1], times[i][2]});
       }

       priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
       vector<int> dist (n+1, INF);
       pq.push({0, k});
       dist[k] = 0;
       while (!pq.empty()) {
        int d_v = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if (d_v != dist[v]) {
            continue;
        }

        for (int i = 0;i < adj_graph[v].size();i++) {
            int to = adj_graph[v][i].first;
            int cost = adj_graph[v][i].second;

            if (dist[v] + cost < dist[to]) {
                dist[to] = dist[v] + cost;
                pq.push({dist[to], to});
            }
        }
       }

       int maxi_dist = 0;
       for (int i = 1;i <= n;i++) {
        cout << dist[i] << endl;
        if (dist[i] >= INF) {
            return -1;
        }
        maxi_dist = max(dist[i], maxi_dist);
       }
       return maxi_dist;
    }
};

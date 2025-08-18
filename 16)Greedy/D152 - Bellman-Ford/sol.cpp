// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        const long long INF = (long long)1e18;
        vector<long long> dist(V, INF);
        dist[src] = 0;
        
        for (int i = 0; i < V - 1; i++) {
            bool updated = false;
            for (auto &e : edges) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }
            if (!updated) break;
        }
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                return vector<int>{-1};
        }
    }
    vector<int> ans(V);
    for (int i = 0 ; i < V; i++){
       ans[i] = (dist[i] == INF)  ? 100000000 : (int)dist[i];
    }
    return ans;
    }
};

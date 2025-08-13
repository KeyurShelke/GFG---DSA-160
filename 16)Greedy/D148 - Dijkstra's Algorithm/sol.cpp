// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0],v = e[1], w= e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
    }
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});
    
    while (!pq.empty()) {
        pair<int,int> top = pq.top();
        pq.pop();
        int d = top.first;
        int u = top.second;
        
        if (d > dist[u]) continue;
        
        for (auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
    }
};
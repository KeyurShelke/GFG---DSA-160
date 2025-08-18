class Solution {
  public:
    int findMinCycle(int V, vector<vector<int>> &edges) {
        const long long INF = 1e15;
        vector<vector<long long>> adj(V, vector<long long>(V, INF));
        vector<vector<long long>> dist(V, vector<long long>(V, INF));
        
        for (auto &e : edges){
                int u = e[0], v = e[1],w = e[2];
                adj[u][v] = min(adj[u][v], (long long)w);
                adj[v][u] = min(adj[v][u], (long long)w);
                dist[u][v] = adj[u][v];
                dist[v][u] = adj[v][u];
        }
        for(int i = 0; i<V; i++) dist[i][i] = 0;
        long long ans = INF;
        
        for(int k = 0; k<V; k++) {
            for(int i = 0; i<k;i++) {
                for(int j = i + 1; j<k;j++) {
                    if (dist[i][j] < INF && adj [i][k] < INF && adj [k][j] < INF) {
                        ans = min(ans, dist[i][j] + adj[i][k] + adj [k][j]);
                    }
                } 
            }
            for(int i = 0; i<V; i++){
                for(int j = 0; j<V; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        
                    }
                }
            }
        }
        return (ans == INF ? -1 : (int)ans);
    }
};
    
    
      
 
        v
class Solution {
  public:
    void dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low,
            vector<bool>& ap, int& time) {
                disc[u] = low[u] = ++time;
                int children = 0;
                
                for( int v : adj[u]) {
                    if (v == parent) continue;
                    
                    if (disc[v] == -1) {
                        children++;
                        dfs(v, u, adj, disc, low, ap, time);
                        
                        low[u] = min(low[u], low[v]);
                        
                        if (parent != -1 && low[v] >= disc[u])
                        ap[u] = true;
                    }
                    else {
                        low[u] = min(low[u], disc[v]);
                    }
                }        
                
                if (parent == -1 && children > 1)
                ap[u] = true;
            }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> ap(V, false);
        int time = 0;
        
        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                dfs(i, -1, adj, disc,low, ap, time);
            }
        }
        
        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (ap[i]) result.push_back(i);
        }
        
        if (result.empty()) return{-1};
        return result;
    } 
};
class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        for (auto neigh : adj[node]) {
            if (!visited[neigh]) {
                dfs(neigh, adj, visited);
            }
        }
    } 
    
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj [e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        adj[c].erase(remove(adj[c].begin(), adj[c].end(), d), adj[c].end());
        adj[d].erase(remove(adj[d].begin(), adj[d].end(), c), adj[d].end());
        
        vector<int> visited(V,0);
        dfs(c, adj, visited);
        
        return !visited[d];
    }
};
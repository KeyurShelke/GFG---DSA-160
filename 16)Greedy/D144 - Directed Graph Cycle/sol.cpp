class Solution {
  public:
  bool dfs(int node, vector<vector<int>> & adj, vector<int>& visited, vector<int>& recStack){
    visited[node] = 1;
    recStack[node] = 1;
    
    for(auto neigh : adj[node]) {
        if (!visited[neigh]) {
            if (dfs(neigh, adj, visited, recStack))
            return true;
        }
        else if (recStack[neigh]) {
            return true;
        }
    }
    
    recStack[node] = 0;
    return false;
}
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        
        vector<int> visited(V,0);
        vector<int> recStack(V, 0);
        
        for (int i = 0; i<V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, recStack))
                return true;
            }
        }
        return false;
    }
};
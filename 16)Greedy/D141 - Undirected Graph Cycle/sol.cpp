class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(V,false);
        for(int start=0; start<V; start++){
            if(!visited[start]){
                queue<pair<int,int>> q;
                q.push({start, -1});
                visited[start]=true;
                while(!q.empty()){
                    auto[N,P]=q.front();
                    q.pop();
                    for(int nbr:adj[N]){
                        if(!visited[nbr]){
                            visited[nbr]=true;
                            q.push({nbr,N});
                        } else if(nbr!=P) return true;
                    }
                }
            }
        }
    return false;
    }
};
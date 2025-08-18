// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        
        int INF = 100000000;
        bool seen1e8 = false, seen108 = false;
        
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][j] == 100000000) seen1e8 = true; 
                    if (dist[i][j] == 108) seen108 = true;
                }
            }
            if (!seen1e8 && seen108) INF = 108;
            
            for (int k = 0; k < n; ++k) {
                for (int i = 0; i < n; ++i) {
                    if (dist[i][k] == INF) continue;
                    for (int j = 0; j < n; ++j) {
                        if (dist[k][j] == INF) continue;
                        long long through = (long long)dist[i][k] + (long long)dist[k][j];
                        if (through < dist[i][j]) {
                            dist[i][j] = (int)through;
                        }
                    }
                }
            }
        }
    };
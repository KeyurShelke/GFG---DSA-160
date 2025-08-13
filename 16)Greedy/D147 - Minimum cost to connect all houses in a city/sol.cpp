class Solution {
  public:
    int manhattan(vector<int>& a,vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n = houses.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> inMST(n, false);
        
        minDist[0] = 0;
        int totalCost = 0;
        
        for (int count = 0; count < n; count++) {
            int u = -1;
            for (int i = 0; i < n; i++) {
                if (!inMST[i] && (u == -1 || minDist[i] < minDist[u])) {
                    u =  i;
                }
            }
            
            inMST[u] = true;
            totalCost += minDist[u];
            
            for (int v =0; v < n; v++) {
                if (!inMST[v]) {
                    int dist = manhattan(houses[u], houses[v]);
                    if (dist < minDist[v]) {
                        minDist[v] = dist;
                    }
                }
            }
            
        }
        return totalCost;
        
    }
};
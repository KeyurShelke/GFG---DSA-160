#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int, int>> q; // store positions of rotten oranges
        int freshCount = 0; // count fresh oranges
        
        // Step 1: Push all rotten oranges to queue, count fresh ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) {
                    q.push({i, j});
                } else if (mat[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        if (freshCount == 0) return 0; // no fresh oranges
        
        int time = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        // Step 2: BFS traversal
        while (!q.empty()) {
            int size = q.size();
            bool rottedThisMinute = false;
            
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] == 1) {
                        mat[nx][ny] = 2;
                        freshCount--;
                        q.push({nx, ny});
                        rottedThisMinute = true;
                    }
                }
            }
            
            if (rottedThisMinute) time++;
        }
        
        return (freshCount == 0) ? time : -1;
    }
};

class Solution {
  public:
    int n, m;
    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        visited[x][y] = 1;
        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (nx >= 0 && nx < n && ny < m && 
            !visited[nx][ny] && grid[nx][ny] =='L'){
                dfs(nx, ny, grid, visited);
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 'L') {
                    count++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return count;
        
    }
};
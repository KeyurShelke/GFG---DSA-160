class Solution {
  public:
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat);
    }
    
    bool solve(vector<vector<int>> &mat){
        for(int i = 0; i<9; i++){
            for(int j=0; j<9; j++){
                if(mat[i][j]==0){
                    for(int k=1; k<=9; k++){
                        if(isValid(mat, i, j, k)){
                            mat[i][j]=k;
                            if(solve(mat)) return true;
                        mat[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
bool isValid(vector<vector<int>> &mat, int row, int col, int num){
    for(int x=0;x<9;x++){
        if(mat[row][x]==num || mat[x][col]==num) return false;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for(int i = 0; i<3;i++){
        for(int j=0;j<3;j++){
            if(mat[startRow + i][startCol + j] == num) return false;
        }
    }
    return true;
}
};
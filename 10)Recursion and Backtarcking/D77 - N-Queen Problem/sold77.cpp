// User function Template for C++

class Solution {
  public:
  bool isSafe(int row,int col,int rows, int ld,int rd,int n){
      return !((rows>>row) &1) && !((ld>> (row+col))&1) && !((rd >> (row-col+n))&1);
  }
  void nQueenUntil(int col,int n,vector<int>&board,vector<vector<int>>&res,int rows,int ld,int rd){
      if(col>n){
          res.push_back(board);
          return;
      }
      for(int row=1;row<=n;row++){
          if(isSafe(row,col,rows,ld,rd,n)){
              board.push_back(row);
              nQueenUntil(col+1,n,board,res,rows|(1<<row),(ld|(1<<(row+col))),
              (rd|(1<<(row-col+n))));
              board.pop_back();
          }
      }
  }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>res;
        vector<int>board;
        nQueenUntil(1,n,board,res,0,0,0);
        return res;
    }
};
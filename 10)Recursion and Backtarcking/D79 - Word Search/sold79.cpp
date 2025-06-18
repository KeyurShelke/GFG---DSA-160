class Solution {
  public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        for (int i = 0; i < board.size(); i++){
            for ( int j = 0; j < board[0].size(); j++){
                if (board[i][j] == word[0] && searchWord(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
}

private:
bool searchWord(vector<vector<char>>& board, string& word, int row, int col, int index) {
    if (index == word.length()) {
        return true;
    }
    if (row < 0 || col < 0 || row>=board.size() || col >= board[0].size() ||
        board[row][col] != word[index]) {
        return false;
    }
    
    char current = board[row][col];
    board[row][col] = '#';
    
    bool found = searchWord(board,word ,row + 1, col, index + 1) ||
                 searchWord(board,word ,row - 1, col, index + 1) ||
                 searchWord(board,word ,row , col + 1, index + 1) ||
                 searchWord(board,word ,row , col - 1, index + 1);
    
    board[row][col] = current;
    return found;
        }
    };

/*

Word Search Board

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell. 

The same letter cell may be used more than once.

Example :

Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns 1,
word = "SEE", -> returns 1,
word = "ABCB", -> returns 1,
word = "ABFSAB" -> returns 1
word = "ABCD" -> returns 0
Note that 1 corresponds to true, and 0 corresponds to false.

*/

bool dfs(
    int i,
    int j, 
    std::vector<std::vector<char>> &board, 
    std::string &pattern, 
    int pos
) {
    if (pos == pattern.size()) {
        return true;
    }

    int n = board.size();
    int m = board[0].size();
    
    if (i >= n || j >= m || i < 0 || j < 0 || board[i][j] != pattern[pos]) {
        return false;
    }

    std::vector<int> x = { -1, 0, 0, 1 };
    std::vector<int> y = { 0, -1, 1, 0 };
    
    for (int k = 0; k < 4; ++k) {
        if (dfs(x[k] + i, y[k] + j, board, pattern, pos + 1)) {
            return true;
        }
    }
    
    return false;
}

int Solution::exist(vector<string> &A, string B) {
    int n = A.size();
    int m = A[0].size();

    std::vector<std::vector<char>> board(n, std::vector<char>(m));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            board[i][j] = A[i][j];
        }
    }
    
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (dfs(i, j, board, B, 0)) {
                return 1;
            }
        }
    }
    
    return 0;
}

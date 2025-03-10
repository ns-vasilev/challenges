/*

289. Game of Life

According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.

Given the current state of the board, update the board to reflect its next state.

Note that you do not need to return anything.

*/

class Solution {
    public:
        void gameOfLife(vector<vector<int>>& board) {
            int n = board.size();
            int m = board[0].size();
    
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    int count = 0;
    
                    for (int x = std::max(0, i - 1); x < std::min(n, i + 2); ++x) {
                        for (int y = std::max(0, j - 1); y < std::min(m, j + 2); ++y) {
                            count += board[x][y] & 1;
                        }
                    }
    
                    if (board[i][j] == 1 && (count == 3 || count == 4)) {
                        board[i][j] |= 0b10;
                    }
    
                    if (board[i][j] == 0 && (count == 3)) {
                        board[i][j] |= 0b10;
                    }
                }
            }
    
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    board[i][j] >>= 1;
                }
            }
        }
    };
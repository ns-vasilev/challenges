/*

52. N-Queens II

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

*/

class Solution {
    private:
        void backtracking(
            int row, 
            int n, 
            std::vector<bool> &cols,
            std::vector<bool> &ld,
            std::vector<bool> &rd,
            int &count
        ) {
            if (row == n) {
                count++;
                return;
            }
    
            for (int i = 0; i < n; ++i) {
                int r = row - i + n;
                int l = row + i;
    
                if (cols[i] || ld[l] || rd[r]) { continue; }
    
                ld[i] = rd[r] = cols[i] = true;
    
                backtracking(row + 1, n, cols, ld, rd, count);
    
                ld[i] = rd[r] = cols[i] = false;
            }
        }
    public:
        int totalNQueens(int n) {
            std::vector<bool> cols(n, false);
            std::vector<bool> ld(2 * n, false);
            std::vector<bool> rd(2 * n, false);
    
            int count = 0;
    
            backtracking(0, n, cols, ld, rd, count);
    
            return count;
        }
    };
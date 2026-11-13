/*

1504. Count Submatrices With All Ones

Given an m x n binary matrix mat, return the number of submatrices that have all ones.

Example 1:

Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
Output: 13
Explanation: 
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2. 
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.

Constraints:

- 1 <= m, n <= 150
- mat[i][j] is either 0 or 1.

*/

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int res = 0;
        
        std::vector<std::vector<int>> row(n, std::vector<int>(m));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j == 0) {
                    row[i][j] = mat[i][j];
                } else {
                    row[i][j] = (mat[i][j] == 0) ? 0 : row[i][j - 1] + 1;
                }
                
                int cur = row[i][j];
                
                for (int k = i; k >= 0; --k) {
                    cur = std::min(cur, row[k][j]);
                    
                    if (cur == 0) {
                        break;
                    }
                    
                    res += cur;
                }
            }
        }
        
        return res;
    }
};
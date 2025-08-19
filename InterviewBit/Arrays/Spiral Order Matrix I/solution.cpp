/*

Spiral Order Matrix I

Given a matrix of M * N elements (M rows, N columns), return all elements of the matrix in spiral order.

*/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    std::vector<int> res;
    
    if (A.empty()) return res;
    
    int top = 0;
    int left = 0;
    int bottom = A.size() - 1;
    int right = A[0].size() - 1;
    
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i) {
            res.push_back(A[top][i]);
        }
        top++;
        
        for (int i = top; i <= bottom; ++i) {
            res.push_back(A[i][right]);
        }
        right--;
        
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                res.push_back(A[bottom][i]);
            }
            bottom--;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                res.push_back(A[i][left]);
            }
            left++;
        }
    }
    
    return res;
}

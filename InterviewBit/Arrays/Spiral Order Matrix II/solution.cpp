/*

Spiral Order Matrix II

Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order and return the generated square matrix.

*/

vector<vector<int> > Solution::generateMatrix(int A) {
    std::vector<std::vector<int>> m(A, std::vector<int>(A));
    
    int top = 0;
    int left = 0;
    int right = A - 1;
    int bottom = A - 1;
    
    int num = 1;
    
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i) {
            m[top][i] = num++;
        }
        ++top;
        
        for (int i = top; i <= bottom; ++i) {
            m[i][right] = num++;
        }
        --right;
        
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                m[bottom][i] = num++;
            }
            --bottom;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                m[i][left] = num++;
            }
            ++left;
        }
    }
    
    return m;
}

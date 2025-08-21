/*

Matrix Search

Given a matrix of integers A of size N x M and an integer B. Write an efficient algorithm that searches for integer B in matrix A. 

This matrix A has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Return 1 if B is present in A, else return 0.

NOTE: Rows are numbered from top to bottom, and columns are from left to right.

*/

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int N = A.size();
    int M = A[0].size();
    
    int L = 0;
    int R = N * M - 1;
    
    while (L <= R) {
        int mid = (L + R) / 2;
        
        int row = mid / M;
        int col = mid % M;
        
        if (A[row][col] == B) {
            return 1;
        } else if (A[row][col] < B) {
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    
    return 0;
}

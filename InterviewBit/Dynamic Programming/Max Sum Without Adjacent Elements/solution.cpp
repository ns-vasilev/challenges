/*

Max Sum Without Adjacent Elements

Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

Note: You can choose more than 2 numbers.

Input Format:

The first and the only argument of input contains a 2d matrix, A.
Output Format:

Return an integer, representing the maximum possible sum.
Constraints:

1 <= N <= 20000
1 <= A[i] <= 2000

*/

int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    if (n == 0) { return 0; }

    int prev1 = std::max(A[0][0], A[1][0]);
    
    if (n == 1) { return prev1; }
    
    int prev2 = std::max(prev1, std::max(A[0][1], A[1][1]));
    
    if (n == 2) { return prev2; }

    int current = std::max(prev1, prev2);

    for (int i = 2; i < n; ++i) {
        int max_in_col = std::max(A[0][i], A[1][i]);

        current = std::max(prev2, prev1 + max_in_col);
        
        prev1 = prev2;
        prev2 = current;
    }
    
    return current;
}

/*

Disjoint Intervals

Given a set of N intervals denoted by 2D array A of size N x 2, the task is to find the length of maximal set of mutually disjoint intervals.

Two intervals [x, y] & [p, q] are said to be disjoint if they do not have any point in common.

Return a integer denoting the length of maximal set of mutually disjoint intervals.

*/

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    
    if (n <= 1) {
        return n;
    }
    
    std::sort(A.begin(), A.end(), cmp);
    
    int count = 1;
    int last_end_time = A[0][1];
    
    for (int i = 1; i < n; i++) {
        if (A[i][0] > last_end_time) {
            count++;
            last_end_time = A[i][1];
        }
    }
    
    return count;
}

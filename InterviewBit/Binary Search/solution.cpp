/*

Smaller or equal elements

Given an sorted array A of size N. Find number of elements which are less than or equal to B.

NOTE: Expected Time Complexity O(log N)

Problem Constraints
1 <= N <= 10^6
1 <= A[i], B <= 10^9

*/

int binary_search(std::vector<int> &v, int k) {
    int l = 0;
    int r = v.size() - 1;
    
    while (l <= r) {
        int m = (l + r) / 2;

        if (v[m] <= k) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    
    return l;
}

int Solution::solve(vector<int> &A, int B) {
    return binary_search(A, B);
}

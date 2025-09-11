/*

Longest Increasing Subsequence

Find the longest increasing subsequence of a given array of integers, A.

In other words, find a subsequence of array in which the subsequence's elements are in strictly increasing order, and in which the subsequence is as long as possible.

In this case, return the length of the longest increasing subsequence.

*/

int Solution::lis(const vector<int> &A) {
    if (A.size() <= 1) {
        return 1;
    }

    std::vector<int> v;
    v.push_back(A[0]);
    
    for (int i = 1; i < A.size(); ++i) {
        if (v.back() < A[i]) {
            v.push_back(A[i]);
        } else {
            int low = std::lower_bound(v.begin(), v.end(), A[i]) - v.begin();
            v[low] = A[i];
        }
    }
    
    return v.size();
}

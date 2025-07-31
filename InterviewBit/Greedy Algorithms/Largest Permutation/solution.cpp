/*

Largest Permutation

Given an integer array A of size N consisting of unique integers from 1 to N. You can swap any two integers atmost B times.

Return the largest lexicographical value array that can be created by executing atmost B swaps.

*/

vector<int> Solution::solve(vector<int> &A, int B) {
    int N = A.size();
    
    std::unordered_map<int, int> m;
    
    for (int i = 0; i < N; ++i) {
        m[A[i]] = i;
    }
    
    for (int i = 0; i < N && B > 0; ++i) {
        int exp = N - i;
        
        if (A[i] == exp) { continue; }
        
        int idx = m[exp];
        
        m[A[i]] = idx;
        m[exp] = i;
        
        std::swap(A[i], A[idx]);
        
        B--;
    }
    
    return A;
}

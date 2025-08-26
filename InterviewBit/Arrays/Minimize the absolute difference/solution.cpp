/*

Minimize the absolute difference

Given three sorted arrays A, B  and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.

i.e. minimize | max(a,b,c) - min(a,b,c) |.

*/

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i = 0;
    int j = 0;
    int k = 0;
    
    int minDiff = INT_MAX;
    
    while (i < A.size() && j < B.size() && k < C.size()) {
        int min = std::min({ A[i], B[j], C[k] });
        int max = std::max({ A[i], B[j], C[k] });
        
        minDiff = std::min(minDiff, max - min);
        
        if (min == A[i]) {
            i++;
        } else if (min == B[j]) {
            j++;
        } else {
            k++;
        }
    }
    
    return minDiff;
}

/*

Rain Water Trapped

Problem Description

Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Problem Constraints
1 <= |A| <= 100000

*/

int Solution::trap(const vector<int> &A) {
    int l = 0;
    int r = A.size() - 1;
    
    int max_left = A[l];
    int max_right = A[r];
    
    int res = 0;
    
    while (l < r) {
        if (max_left < max_right) {
            l++;
            max_left = std::max(max_left, A[l]);
            res += max_left - A[l];
        } else {
            r--;
            max_right = std::max(max_right, A[r]);
            res += max_right - A[r];
        }
    }
    
    return res;
}

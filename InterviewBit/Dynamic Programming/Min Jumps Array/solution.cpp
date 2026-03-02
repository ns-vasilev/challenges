/*

Min Jumps Array

Problem Description

Given an array of non-negative integers, A, of length N, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Return the minimum number of jumps required to reach the last index.
If it is not possible to reach the last index, return -1.

Problem Constraints
- 1 <= N <= 106
- 0 <= A[i] <= 50000

Input Format
The first and the only argument contains an integer array, A.

Output Format
Return an integer, representing the answer as described in the problem statement.

*/

int Solution::jump(vector<int> &A) {
    int n = A.size();
    
    if (n <= 1) {
        return 0;
    }
    
    if (A[0] == 0) {
        return -1;
    }
    
    int jumps = 0;
    int current_end = 0;
    int farthest = 0;
    
    for (int i = 0; i < n - 1; ++i) {
        farthest = std::max(farthest, i + A[i]);
        
        if (i == current_end) {
            jumps++;
            current_end = farthest;
            
            if (current_end >= n - 1) {
                return jumps;
            }
        }
        
        if (i >= farthest) {
            return -1;
        }
    }
    
    return (current_end >= n - 1) ? jumps : -1;
}

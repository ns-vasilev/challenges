/*

Assign Mice to Holes

There are N Mice and N holes that are placed in a straight line. Each hole can accomodate only 1 mouse.

The positions of Mice are denoted by array A and the position of holes are denoted by array B.

A mouse can stay at his position, move one step right from x to x + 1, or move one step left from x to x − 1. Any of these moves consumes 1 minute.

Assign mice to holes so that the time when the last mouse gets inside a hole is minimized.

*/

int Solution::mice(vector<int> &A, vector<int> &B) {
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    
    int max_time = 0;
    
    for (int i = 0; i < A.size(); ++i) {
        max_time = std::max(max_time, std::abs(A[i] - B[i]));
    }
    
    return max_time;
}

/*

Meeting rooms

Problem Description

Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

Where:
- A[i][0] = start time of the ith meeting.
- A[i][1] = end time of the ith meeting.

Find the minimum number of conference rooms required so that all meetings can be done.

Note :- If a meeting ends at time t, another meeting starting at time t can use the same conference room

*/

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    
    if (n == 0) {
        return 0;
    }
    
    std::vector<int> start;
    std::vector<int> end;
    
    for (int i = 0; i < A.size(); ++i) {
        start.push_back(A[i][0]);
        end.push_back(A[i][1]);
    }
    
    std::sort(start.begin(), start.end());
    std::sort(end.begin(), end.end());
    
    int end_ptr = 0;
    int rooms = 0;
    
    for (int start_ptr = 0; start_ptr < n; ++start_ptr) {
        if (start[start_ptr] >= end[end_ptr]) {
            end_ptr++;
        } else {
            rooms++;
        }
    }

    return rooms;
}

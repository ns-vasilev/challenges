/*

N/3 Repeat Number

Problem Description

You're given a read-only array of N integers. Find out if any integer occurs more than N/3 times in the array in linear time and constant additional space.
If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Problem Constraints
1 <= N <= 7*10^5
1 <= A[i] <= 10^9

*/

int Solution::repeatedNumber(const vector<int> &A) {
    int cand1 = 0;
    int count1 = 0;
    int cand2 = 0;
    int count2 = 0;
    
    for (auto a: A) {
        if (a == cand1) {
            count1++;
        } else if (a == cand2) {
            count2++;
        } else if (count1 == 0) {
            cand1 = a;
            count1 = 1;
        } else if (count2 == 0) {
            cand2 = a;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }
    
    count1 = 0;
    count2 = 0;
    
    for (auto a: A) {
        if (a == cand1) { count1++; }
        if (a == cand2) { count2++; }
    }
    
    if (count1 > A.size() / 3) { return cand1; }
    if (count2 > A.size() / 3) { return cand2; }
    
    return -1;
}

/*

Majority Element

Given an array of size N, find the majority element. The majority element is the element that appears more than floor(N/2) times.
You may assume that the array is non-empty and the majority element always exist in the array.

Problem Constraints

1 <= |A| <= 10^6
1 <= A_i <= 10^9

*/

int Solution::majorityElement(const vector<int> &A) {
    int cnt = 0;
    int i = 0;
    
    for (auto n: A) {
        if (cnt == 0) { i = n; }
        if (i == n) { cnt += 1; }
        if (i != n) { cnt -= 1; }
    }
    
    return i;
}

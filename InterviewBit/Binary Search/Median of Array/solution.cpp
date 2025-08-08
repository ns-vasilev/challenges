/*

Median of Array

There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both arrays ).

The overall run time complexity should be O(log (m+n)).

NOTE: If the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element. For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5

*/

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    if (A.size() > B.size()) { return findMedianSortedArrays(B, A); }
    
    int m = A.size();
    int n = B.size();
    
    int total_left = (m + n + 1) / 2;
    
    int left = 0;
    int right = m;
    
    while (left <= right) {
        int i = (left + right) / 2;
        int j = total_left - i;
        
        int a_left = (i == 0) ? INT_MIN : A[i - 1];
        int a_right = (i == m) ? INT_MAX : A[i];
        
        int b_left = (j == 0) ? INT_MIN : B[j - 1];
        int b_right = (j == n) ? INT_MAX : B[j];
        
        if (a_left <= b_right && b_left <= a_right) {
            if ((m + n) % 2 == 0) {
                return (std::max(a_left, b_left) + min(a_right, b_right)) / 2.0;
            } else {
                return std::max(a_left, b_left);
            }
        } else if (a_left > b_right) {
            right = i - 1;
        } else {
            left = i + 1;
        }
    }
    
    return -1;
}

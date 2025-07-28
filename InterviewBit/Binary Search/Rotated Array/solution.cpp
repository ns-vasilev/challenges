/*

Rotated Array

Suppose a sorted array A is rotated at some pivot unknown to you beforehand.

(i.e., 1 2 4 5 6 7 might become 4 5 6 7 1 2).

Find the minimum element.

The array will not contain duplicates.

Note:- Use the circular rotated property of the array to solve the problem.

*/

int Solution::findMin(const vector<int> &A) {
    int l = 0;
    int r = A.size() - 1;

    while (l < r) {
        int m = (l + r) / 2;
        
        if (A[m] > A[r]) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    
    return A[l];
}

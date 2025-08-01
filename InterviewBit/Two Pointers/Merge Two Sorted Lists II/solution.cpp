/*

Merge Two Sorted Lists II

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
TIP: C users, please malloc the result into a new array and return the result.

If the number of elements initialized in A and B is m and n respectively, the resulting size of array A after your code is executed should be m + n

*/

void Solution::merge(vector<int> &A, vector<int> &B) {
    int m = A.size();
    int n = B.size();

    A.resize(m + n);

    int i = m - 1;    
    int j = n - 1;     
    int k = m + n - 1; 

    while (i >= 0 && j >= 0) {
        if (A[i] > B[j]) {
            A[k--] = A[i--];
        } else {
            A[k--] = B[j--];
        }
    }

    while (j >= 0) {
        A[k--] = B[j--];
    }
}

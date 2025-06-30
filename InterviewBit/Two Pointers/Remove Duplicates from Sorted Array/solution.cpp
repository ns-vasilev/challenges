/*

Remove Duplicates from Sorted Array

Given a sorted array A consisting of duplicate elements.

Your task is to remove all the duplicates and return the length of the sorted array of distinct elements consisting of all distinct elements present in A.

Note: You need to update the elements of array A by removing all the duplicates

Problem Constraints

1 <= |A| <= 10^6
1 <= Ai <= 2 * 10^9

*/

int Solution::removeDuplicates(vector<int> &A) {
    if (A.size() == 0 || A.size() == 1) {
        return 1;
    }

    int k = 0;
    
    for (int i = 1; i < A.size(); ++i) {
        if (A[i] != A[k]) {
            A[++k] = A[i];
        }
    }
    
    return k + 1;
}

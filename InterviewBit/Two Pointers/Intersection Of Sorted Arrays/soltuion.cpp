/*

Intersection Of Sorted Arrays

Find the intersection of two sorted arrays OR in other words, given 2 sorted arrays, find all the elements which occur in both arrays.

NOTE: For the purpose of this problem ( as also conveyed by the sample case ), assume that elements that appear more than once in both arrays should be included multiple times in the final output.

Problem Constraints
1 <= |A| <= 10^6
1 <= |B| <= 10^6

*/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int i = 0, j = 0;
    vector<int> result;

    while (i < A.size() && j < B.size()) {
        if (A[i] == B[j]) {
            result.push_back(A[i]);
            i++;
            j++;
        } else if (A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
    }

    return result;
}

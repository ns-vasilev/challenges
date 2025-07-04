/*

Highest Product

Given an array A, of N integers A.
Return the highest product possible by multiplying 3 numbers from the array.
NOTE: The solution will fit in a 32-bit signed integer.

*/

int Solution::maxp3(vector<int> &A) {
    sort(A.begin(), A.end());

    int n = A.size();

    int product1 = A[n - 1] * A[n - 2] * A[n - 3];
    int product2 = A[0] * A[1] * A[n - 1];

    return max(product1, product2);
}

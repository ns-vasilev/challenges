/*

Square Root of Integer

Given an integer A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY.

NOTE: Do not use sort function from standard library. Users are expected to solve this in O(log(A)) time.

*/

int Solution::sqrt(int A) {
    if (A < 2) {
        return A;
    }

    int l = 1;
    int r = A / 2;
    
    int ans = 1;
    
    while (l <= r) {
        int m = (l + r) / 2;
        
        long long square = 1LL * m * m;
        
        if (square == A) {
            return m;
        } else if (square < A) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    
    return ans;
}

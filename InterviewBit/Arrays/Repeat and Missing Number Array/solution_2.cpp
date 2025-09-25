/*

Repeat and Missing Number Array

You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4

*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int ab = 0;
    
    for (int i = 0; i < A.size(); ++i) {
        ab ^= A[i];
        ab ^= (i + 1);
    }
    
    int b = ab & -ab;
    
    int x = 0;
    int y = 0;
    
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] & b) { x ^= A[i]; }
        else { y ^= A[i]; }
    }
    
    for (int i = 1; i <= A.size(); ++i) {
        if (i & b) { x ^= i; }
        else { y ^= i; }
    }
    
    int c = std::count(A.begin(), A.end(), x);
    
    if (c == 2) { return { x, y }; }
    else { return { y, x }; }
}
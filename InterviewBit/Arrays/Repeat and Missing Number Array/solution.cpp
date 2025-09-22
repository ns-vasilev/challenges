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
    long long n = A.size();
    
    long long sum_a = 0;
    long long sum_sq_a = 0;
    
    for (int i = 0; i < n; ++i) {
        sum_a += A[i];
        sum_sq_a += 1LL * A[i] * A[i];
    }
    
    long long s = n * (n + 1) / 2;
    long long s_sq = n * (n + 1) * (2 * n + 1) / 6;
    
    long long diff = sum_a - s;
    long long sum_ab = (sum_sq_a - s_sq) / diff;
    
    long long a = (diff + sum_ab) / 2;
    long long b = a - diff;
    
    return { (int)a, (int)b };
}

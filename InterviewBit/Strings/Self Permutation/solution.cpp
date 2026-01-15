/*

Self Permutation

Problem Description

You are given two strings A and B.
Check whether there exists any permutation of both A and B such that they are equal.

Return a single integer 1 if its exists, 0 otherwise.

Problem Constraints
1 <= |A|, |B| <= 105
Both strings contain only lowercase english alphabets.

Input Format
The first argument is the string A. The second argument is the string B.

Output Format
Return a single integer 1 if a permutation exists, 0 otherwise.

*/

int Solution::permuteStrings(string A, string B) {
    if (A.length() != B.length()) {
        return 0;
    }
    
    int counts[256] = {0};
    
    for (int i = 0; i < A.length(); ++i) {
        counts[(int)A[i]]++;
        counts[(int)B[i]]--;
    }
    
    for (int i = 0; i < 256; ++i) {
        if (counts[i] != 0) {
            return 0;
        }
    }
    
    return 1;
}

/*

Longest Common Prefix

Given the array of strings A, you need to find the longest string S which is the prefix of ALL the strings in the array.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

For Example: longest common prefix of "abcdefgh" and "abcefgh" is "abc".

*/

string Solution::longestCommonPrefix(vector<string> &A) {
    if (A.size() == 0) {
        return "";
    }
    
    std::string prefix = "";
    
    int min_len = A[0].size();
    
    for (int i = 0; i < A.size(); ++i) {
        if (min_len < A[i].size()) {
            min_len = A[i].size();
        }
    }
    
    for (int i = 0; i < min_len; ++i) {
        char curr_char = A[0][i];
        
        for (int j = 1; j < A.size(); ++j) {
            if (curr_char != A[j][i]) {
                return prefix;
            }
        }
        
        prefix += curr_char;
    }
    
    return prefix;
}

/*

1143. Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        int res = 0;

        std::vector<int> dp(n);

        for (int i = 0; i < m; ++i) {
            int curr = 0;

            for (int j = 0; j < n; ++j) {
                if (curr < dp[j]) {
                    curr = dp[j];
                } else if (text2[i] == text1[j]) {
                    dp[j] = curr + 1;
                    res = std::max(res, dp[j]);
                }
            }
        }


        return res;
    }
};
/*

Minimum Appends for Palindrome!

Problem Description

Given a string A consisting of lowercase characters.

We need to tell minimum characters to be appended (insertion at end) to make the string A a palindrome.



Problem Constraints
1 <= |A| <= 10^5

A consists only of lower-case characters.



Input Format
First argument is an string A.



Output Format
Return a integer denoting the minimum characters to be appended (insertion at end) to make the string A a palindrome.

*/

int Solution::solve(string A) {
    int n = A.size();

    std::string rev = A;
    std::reverse(rev.begin(), rev.end());

    std::string s = rev + "#" + A;

    int m = s.size();
    std::vector<int> lps(m, 0);

    for (int i = 1; i < m; ++i) {
        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = lps[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        lps[i] = j;
    }

    return n - lps[m - 1];
}

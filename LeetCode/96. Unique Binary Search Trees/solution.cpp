/*

96. Unique Binary Search Trees

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

*/

class Solution {
private:
    long long catalan(int n) {
        if (n <= 1) return 1;

        std::vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }

        return dp[n];
    }
public: 
    int numTrees(int n) {
        return catalan(n);
    }
};
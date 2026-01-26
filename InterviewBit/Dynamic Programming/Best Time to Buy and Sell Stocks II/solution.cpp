/*

Best Time to Buy and Sell Stocks II

Say you have an array, A, for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.

You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

int Solution::maxProfit(const vector<int> &A) {
    if (A.size() < 2) {
        return 0;
    }

    int res = 0;
    int v = A[0];
    
    for (int i = 1; i < A.size(); ++i) {
        if (v > A[i]) {
            v = A[i];
        } else {
            res += A[i] - v;
            v = A[i];
        }
    }
    
    return res;
}

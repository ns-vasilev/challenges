/*

714. Best Time to Buy and Sell Stock with Transaction Fee

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.

*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n0 = 0; 
        int n1 = 0;

        for (int i = prices.size() - 1; i >= 0; --i) {
            n1 = std::max(-prices[i] + n0, n1);
            n0 = std::max(prices[i] - fee + n1, n0);
        }

        return n1;
    }
};
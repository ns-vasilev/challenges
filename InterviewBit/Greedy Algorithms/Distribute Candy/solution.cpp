/*

Distribute Candy

N children are standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum number of candies you must give?

*/

int Solution::candy(vector<int> &A) {
    if (A.size() == 0) {
        return 0;
    }
    
    int n = A.size();
    std::vector<int> candies(n, 1);
    
    for (int i = 1; i < n; ++i) {
        if (A[i] > A[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    
    for (int i = n - 2; i >= 0; --i) {
        if (A[i] > A[i + 1]) {
            candies[i] = std::max(candies[i], candies[i + 1] + 1);
        }
    }
    
    int total = 0;
    
    for (int i = 0; i < n; ++i) {
        total += candies[i];
    }
    
    return total;
}

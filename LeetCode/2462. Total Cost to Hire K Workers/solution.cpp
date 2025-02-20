/*

2462. Total Cost to Hire K Workers

You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.

You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:

- You will run k sessions and hire exactly one worker in each session.
- In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last candidates workers. Break the tie by the smallest index.
  - For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].
  - In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.
- If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.
- A worker can only be chosen once.

Return the total cost to hire exactly k workers.

*/

class Solution {
    public:
        long long totalCost(vector<int>& costs, int k, int candidates) {
            std::priority_queue<int, std::vector<int>, std::greater<int>> q1;
            std::priority_queue<int, std::vector<int>, std::greater<int>> q2;
    
            int i = 0;
            int j = costs.size() - 1;
    
            long long res = 0;
    
            while (k--) {
                while (q1.size() < candidates && i <= j) {
                    q1.push(costs[i++]);
                }
    
                while (q2.size() < candidates && i <= j) {
                    q2.push(costs[j--]);
                }
    
                int t1 = q1.size() > 0 ? q1.top() : INT_MAX;
                int t2 = q2.size() > 0 ? q2.top() : INT_MAX;
    
                if (t1 <= t2) {
                    res += t1;
                    q1.pop();
                } else {
                    res += t2;
                    q2.pop();
                }
            }
    
            return res;
        }
    };
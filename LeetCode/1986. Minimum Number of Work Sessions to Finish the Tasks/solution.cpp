/*

1986. Minimum Number of Work Sessions to Finish the Tasks

There are n tasks assigned to you. The task times are represented as an integer array tasks of length n, where the ith task takes tasks[i] hours to finish. A work session is when you work for at most sessionTime consecutive hours and then take a break.

You should finish the given tasks in a way that satisfies the following conditions:

- If you start a task in a work session, you must complete it in the same work session.
- You can start a new task immediately after finishing the previous one.
- You may complete the tasks in any order.

Given tasks and sessionTime, return the minimum number of work sessions needed to finish all the tasks following the conditions above.

The tests are generated such that sessionTime is greater than or equal to the maximum element in tasks[i].

*/

class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int total_masks = 1 << n;

        std::vector<bool> valid(total_masks, false);
        for (int mask = 1; mask < total_masks; ++mask) {
            int sum = 0;

            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    sum += tasks[i];
                }
            }

            if (sum <= sessionTime) {
                valid[mask] = true;
            }
        }

        std::vector<int> dp(total_masks, INT_MAX);
        dp[0] = 0;

        for (int mask = 1; mask < total_masks; ++mask) {
            for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
                if (valid[submask]) {
                    dp[mask] = std::min(dp[mask], 1 + dp[mask ^ submask]);
                }
            }
        }

        return dp[total_masks - 1];
    }
};
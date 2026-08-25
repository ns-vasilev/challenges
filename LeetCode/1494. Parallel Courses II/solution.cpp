/*

1494. Parallel Courses II

You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given an array relations where relations[i] = [prevCoursei, nextCoursei], representing a prerequisite relationship between course prevCoursei and course nextCoursei: course prevCoursei has to be taken before course nextCoursei. Also, you are given the integer k.

In one semester, you can take at most k courses as long as you have taken all the prerequisites in the previous semesters for the courses you are taking.

Return the minimum number of semesters needed to take all courses. The testcases will be generated such that it is possible to take every course.

*/

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        std::vector<int> preq(n, 0);

        for (int i = 0; i < relations.size(); ++i) {
            int u = relations[i][0] - 1;
            int w = relations[i][1] - 1;

            preq[w] |= (1 << u);
        }

        const int INF = 1e9;

        int total_states = 1 << n;
        std::vector<int> dp(total_states, INF);

        dp[0] = 0;

        for (int mask = 0; mask < total_states; ++mask) {
            if (dp[mask] == INF) { continue; }

            int available = 0;

            for (int i = 0; i < n; ++i) {
                if (!(mask & (1 << i)) && (preq[i] & mask) == preq[i]) {
                    available |= (1 << i);
                }
            }

            for (int submask = available; submask > 0; submask = (submask - 1) & available) {
                if (__builtin_popcount(submask) <= k) {
                    dp[mask | submask] = min(dp[mask | submask], dp[mask] + 1);
                }
            }
        }

        return dp[(1 << n) - 1];
    }
};
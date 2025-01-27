/*

2352. Equal Row and Column Pairs

Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

*/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int res = 0;
        std::map<std::vector<int>, int> m;

        for (int i = 0; i < grid.size(); ++i) {
            m[grid[i]]++;
        }

        for (int i = 0; i < grid[0].size(); ++i) {
            std::vector<int> v;

            for (int j = 0; j < grid.size(); ++j) {
                v.push_back(grid[j][i]);
            }

            res += m[v];
        }

        return res;
    }
};
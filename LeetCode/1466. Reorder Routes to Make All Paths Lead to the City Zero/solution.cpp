/*

1466. Reorder Routes to Make All Paths Lead to the City Zero

There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.

*/

class Solution {
private:
    int dfs(std::vector<std::vector<int>> &v, std::vector<bool> &visited, int source) {
        int res = 0;

        visited[source] = true;

        for (auto u: v[source]) {
            if (!visited[std::abs(u)]) {
                res += dfs(v, visited, std::abs(u)) + (u > 0);
            }
        }

        return res;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        std::vector<std::vector<int>> v(n);
        std::vector<bool> visited(n, false);

        for (int i = 0; i < connections.size(); ++i) {
            v[connections[i][0]].push_back(connections[i][1]);
            v[connections[i][1]].push_back(-connections[i][0]);
        }

        return dfs(v, visited, 0);
    }
};
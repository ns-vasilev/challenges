/*

1207. Unique Number of Occurrences

Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int, int> m;

        for (auto n: arr) {
            m[n]++;
        }

        std::unordered_set<int> s;

        for (auto n: m) {
            s.insert(n.second);
        }

        return s.size() == m.size();
    }
};
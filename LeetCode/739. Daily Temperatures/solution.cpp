/*

739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int size = temperatures.size();

        std::vector<int> res(size);
        std::stack<int> s;

        for (int i = 0; i < size; ++i) {
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                res[s.top()] = i - s.top();
                s.pop();
            }

            s.push(i);
        }

        return res;
    }
};
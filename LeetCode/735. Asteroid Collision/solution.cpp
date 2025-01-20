/*

735. Asteroid Collision

We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> s;

        int i = 0;
        int n = asteroids.size();

        while (i < n) {
            if (s.empty() || asteroids[i] > 0 || s.top() < 0) {
                s.push(asteroids[i++]);
            } else if (s.top() > std::abs(asteroids[i])) {
                i++;
            } else if (s.top() < std::abs(asteroids[i])) {
                s.pop();
            } else {
                s.pop();
                i++;
            }
        }

        std::vector<int> v;

        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }

        std::reverse(v.begin(), v.end());

        return v;
    }
};
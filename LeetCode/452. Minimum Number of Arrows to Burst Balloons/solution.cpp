/*

452. Minimum Number of Arrows to Burst Balloons

There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const auto& a, const auto& b){
            return a[0] < b[0];
        });

        int res = 1;
        int k = points[0][1];

        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] <= k) {
                k = std::min(k, points[i][1]);
            } else {
                res += 1;
                k = points[i][1];
            }
        }

        return res;
    }
};
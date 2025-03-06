/*

42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

*/

class Solution {
    public:
        int trap(vector<int>& height) {
            int l = 0;
            int r = height.size() - 1;
    
            int max_left = height[l];
            int max_right = height[r];
    
            int res = 0;
    
            while (l < r) {
                if (max_left < max_right) {
                    l++;
                    max_left = std::max(max_left, height[l]);
                    res += max_left - height[l];
                } else {
                    r--;
                    max_right = std::max(max_right, height[r]);
                    res += max_right - height[r];
                }
            }
    
            return res;
        }
    };
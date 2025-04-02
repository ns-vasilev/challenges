/*

149. Max Points on a Line

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

*/

class Solution {
    public:
        int maxPoints(vector<vector<int>>& points) {
            int n = points.size();
    
            if (n <= 2) {
                return n;
            }
    
            int ans = 0;
    
            for (int i = 0; i < n; ++i) {
                std::unordered_map<double, int> m;
    
                double x1 = points[i][0];
                double y1 = points[i][1];
    
                for (int j = 0; j < n; ++j) {
                    double x2 = points[j][0];
                    double y2 = points[j][1];
    
                    if (i == j) {
                        continue;
                    }
    
                    double slope;
    
                    if (x2 - x1 == 0) {
                        slope = INT_MAX;
                    } else {
                        slope = (y2 - y1) / (x2 - x1);
                    }
    
                    m[slope]++;
                    ans = std::max(ans, m[slope]);
                }
            }
    
            return ans + 1;
        }
    };
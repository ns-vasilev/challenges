/*

Max Rectangle in Binary Matrix

Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
       0 1 1
       1 0 0 
    ]

Output : 4 

*/

int area(std::vector<int> heights) {
    std::stack<int> s;
    heights.push_back(0);

    int max_area = 0;

    for (int i = 0; i < heights.size(); ++i) {
        while (!s.empty() && heights[i] < heights[s.top()]) {
            int h = heights[s.top()];
            s.pop();
            int left = s.empty() ? -1 : s.top();
            int width = i - left - 1;
            max_area = std::max(max_area, h * width);
        }
        s.push(i);
    }

    heights.pop_back();
    return max_area;
}

int Solution::maximalRectangle(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int n = matrix.size();
    int m = matrix[0].size();

    std::vector<int> heights(m, 0);
    int max_area = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1)
                heights[j] += 1;
            else
                heights[j] = 0;
        }
        max_area = std::max(max_area, area(heights));
    }

    return max_area;
}

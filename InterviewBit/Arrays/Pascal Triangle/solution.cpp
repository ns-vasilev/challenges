/*

Pascal Triangle

Given an integer A, equal to numRows, generate the first numRows of Pascal's triangle.
Pascal's triangle: To generate A[C] in row R, sum up A'[C] and A'[C-1] from the previous row R - 1.

*/

vector<vector<int>> Solution::solve(int A) {
    vector<vector<int>> v;

    for (int i = 0; i < A; ++i) {
        vector<int> row(i + 1, 1);

        for (int j = 1; j < i; ++j) {
            row[j] = v[i - 1][j - 1] + v[i - 1][j];
        }

        v.push_back(row);
    }

    return v;
}
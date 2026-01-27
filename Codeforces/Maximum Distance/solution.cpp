/*

A. Maximum Distance
time limit per test 4 seconds
memory limit per test 256 megabytes

You are given 𝑁 (3≤𝑁≤5000) integer points on the coordinate plane. Find the square of the maximum Euclidean distance (aka length of the straight line) between any two of the points.

Input
The first line contains an integer 𝑁. The second line contains 𝑁 integers, the 𝑥-coordinates of the points: 𝑥1,𝑥2,…,𝑥𝑁 (−1000≤𝑥𝑖≤1000). The third line contains 𝑁 integers, the 𝑦-coordinates of the points: 𝑦1,𝑦2,…,𝑦𝑁 (−1000≤𝑦𝑖≤1000).

Output
Print one integer, the square of the maximum Euclidean distance between any two of the points.

*/

#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> x(n);
    std::vector<int> y(n);

    for (int &k: x) { std::cin >> k; }
    for (int &k: y) { std::cin >> k; }

    int result = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            
            int square = dx * dx + dy * dy;

            result = std::max(result, square);
        }
    }

    std::cout << result << std::endl;

    return 0;
}
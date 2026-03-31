/*

Meet in the Middle

You are given an array of n numbers. In how many ways can you choose a subset of the numbers with sum x?

Input
The first input line has two numbers n and x: the array size and the required sum.
The second line has n integers t_1,t_2,...,t_n: the numbers in the array.

Output
Print the number of ways you can create the sum x.

Constraints
1 <= n <= 40
1 <= x <= 10^9
1 <= t_i <= 10^9

Example

Input:
4 5
1 2 3 2

Output:
3

*/

#include <bits/stdc++.h>

int main() {
    long long cnt = 0;

    long long n, target_sum;
    std::cin >> n >> target_sum;

    std::vector<int> arr(n);
    std::vector<long long> left_sums;

    for (int i = 0; i < n; ++i) { std::cin >> arr[i]; }

    long long m = n / 2;

    left_sums.reserve(1 << m);

    for (int mask = 0; mask < (1 << m); ++mask) {
        long long current_sum = 0;

        for (int i = 0; i < m; ++i) {
            if ((mask >> i) & 1) {
                current_sum += arr[i];
            }
        }

        left_sums.push_back(current_sum);
    }

    std::sort(left_sums.begin(), left_sums.end());

    long long r = n - m;

    for (int mask = 0; mask < (1 << r); ++mask) {
        long long current_sum = 0;

        for (int i = 0; i < r; ++i) {
            if ((mask >> i) & 1) {
                current_sum += arr[m + i];
            }
        }

        long long needed = target_sum - current_sum;

        auto range = equal_range(left_sums.begin(), left_sums.end(), needed);
        cnt += distance(range.first, range.second);
    }

    std::cout << cnt << std::endl;

    return 0;
}
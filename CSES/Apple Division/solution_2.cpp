/*

Apple Division

There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.
Input
The first input line has an integer n: the number of apples.
The next line has n integers p_1,p_2,...,p_n: the weight of each apple.
Output
Print one integer: the minimum difference between the weights of the groups.
Constraints

1 <= n <= 20
1 <= p_i <= 10^9

Example
Input:
5
3 2 7 4 1

Output:
1

Explanation: Group 1 has weights 2, 3 and 4 (total weight 9), and group 2 has weights 1 and 7 (total weight 8).

*/

#include <bits/stdc++.h>

int main() {
    int N;
    std::vector<int> weights;

    std::cin >> N;

    weights.resize(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> weights[i];
    }

    long long answer = INT64_MAX;

    for (int mask = 0; mask < (1 << N); mask++) {
        long long sum1 = 0;
        long long sum2 = 0;

        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                sum1 += weights[i];
            } else {
                sum2 += weights[i];
            }
        }

        answer = std::min(answer, std::abs(sum1 - sum2));
    }

    std::cout << answer << std::endl;

    return 0;
}
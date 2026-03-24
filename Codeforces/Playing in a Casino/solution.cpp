#include <bits/stdc++.h>

long long solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<long long>> columns(m, std::vector<long long>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> columns[j][i];
        }
    }

    long long total_winnings = 0;

    for (int j = 0; j < m; ++j) {
        sort(columns[j].begin(), columns[j].end());

        for (int i = 0; i < n; ++i) {
            total_winnings += (1LL * i * columns[j][i]) - (1LL * (n - 1 - i) * columns[j][i]);
        }
    }

    return total_winnings;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::cout << solve() << std::endl;
    }

    return 0;
}
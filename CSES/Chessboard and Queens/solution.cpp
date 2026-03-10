/*

Chessboard and Queens

Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?

Input
The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).

Output
Print one integer: the number of ways you can place the queens.

Example

Input:
........
........
..*.....
........
........
.....**.
...*....
........

Output:
65

*/

#include <bits/stdc++.h>

const int N = 8;

std::vector<std::vector<bool>> blocked(N, std::vector<bool>(N, false));
std::vector<bool> diag1(2 * N - 1, false);
std::vector<bool> diag2(2 * N - 1, false);
std::vector<bool> row_taken(N, false);

int sum = 0;

void search(int c = 0) {
    if (c == N) {
        sum++;
        return;
    }

    for (int r = 0; r < N; ++r) {
        bool open = !row_taken[r];
        bool diag = !diag1[r + c] && !diag2[r - c + N - 1];

        if (!blocked[r][c] && open && diag) {
            row_taken[r] = diag1[r + c] = diag2[r - c + N - 1] = true;
            search(c + 1);
            row_taken[r] = diag1[r + c] = diag2[r - c + N - 1] = false;
        }
    }
}

int main() {
    for (int r = 0; r < N; ++r) {
        std::string row;
        std::cin >> row;

        for (int c = 0; c < N; ++c) {
            if (row[c] == '*') {
                blocked[r][c] = true;
            }
        }
    }

    search();

    std::cout << sum << std::endl;

    return 0;
}
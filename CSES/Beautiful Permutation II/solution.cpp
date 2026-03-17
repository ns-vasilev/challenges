/*

Beautiful Permutation II

A permutation of integers 1,2,...,n is called beautiful if there are no adjacent elements whose difference is 1.

Given n, construct the lexicographically minimal beautiful permutation if such a permutation exists.

Input
The only line contains an integer n.

Output
Print the lexicographically minimal beautiful permutation of integers 1,2,\ldots,n. If there is no such permutation, print "NO SOLUTION".

Constraints
1 <= n <= 10^6

Example 1

Input:
5

Output:
1 3 5 2 4

Example 2

Input:
3

Output:
NO SOLUTION

*/

#include <bits/stdc++.h>

std::vector<int> sequence;
std::vector<int> pool;

void find_permutation() {

    if (pool.empty()) {
        for (int val : sequence) {
            std::cout << val << (&val == &sequence.back() ? "" : " ");
        }
        std::cout << std::endl;
        exit(0);
    }

    for (int i = pool.size() - 1; i >= 0; --i) {
        int current_val = pool[i];

        if (sequence.empty() || std::abs(sequence.back() - current_val) != 1) {
            
            pool.erase(pool.begin() + i);
            sequence.push_back(current_val);
            
            find_permutation();

            sequence.pop_back();
            pool.insert(pool.begin() + i, current_val);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    if (n == 2 || n == 3) {
        std::cout << "NO SOLUTION" << "\n";
        return 0;
    }

    pool.reserve(n);
    for (int i = n; i >= 1; --i) {
        pool.push_back(i);
    }

    sequence.reserve(n);
    find_permutation();

    return 0;
}
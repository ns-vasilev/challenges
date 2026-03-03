/*

Creating Strings

Given a string, your task is to generate all different strings that can be created using its characters.

Input
The only input line has a string of length n. Each character is between a–z.

Output
First print an integer k: the number of strings. Then print k lines: the strings in alphabetical order.

Constraints
- 1 <= n <= 8

Example

Input:
aabac

Output:
20
aaabc
aaacb
aabac
aabca
aacab
aacba
abaac
abaca
abcaa
acaab
acaba
acbaa
baaac
baaca
bacaa
bcaaa
caaab
caaba
cabaa
cbaaa

*/

#include <bits/stdc++.h>

size_t N;
std::vector<int> w;
std::vector<std::string> perms;

void backtrack(const std::string &curr = "") {
    if (curr.size() == N) {
        perms.push_back(curr);
        return;
    }

    for (int i = 0; i < 26; ++i) {
        if (w[i] > 0) {
            w[i]--;
            backtrack(curr + (char)(i + 'a'));
            w[i]++;
        }
    }
}

int main() {
    std::string s;
    std::cin >> s;

    N = s.size();
    w = std::vector<int>(26, 0);

    for (auto ch: s) { w[ch - 'a']++; }

    backtrack();

    std::cout << perms.size() << std::endl;

    for (auto perm: perms) {
        std::cout << perm << std::endl;
    }

    return 0;
}
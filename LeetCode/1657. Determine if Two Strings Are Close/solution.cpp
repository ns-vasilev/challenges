/*

1657. Determine if Two Strings Are Close

Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        std::vector<int> v1(26, 0);
        std::vector<int> v2(26, 0);

        for (int i = 0; i < word1.size(); ++i) {
            v1[word1[i] - 'a']++;
        }

        for (int i = 0; i < word2.size(); ++i) {
            v2[word2[i] - 'a']++;
        }

        for (int i = 0; i < 26; ++i) {
            if ((v1[i] == 0 && v2[i] != 0) || (v1[i] != 0 && v2[i] == 0)) {
                return false;
            }
        }

        std::sort(v1.begin(), v1.end());
        std::sort(v2.begin(), v2.end());

        for (int i = 0; i < 26; ++i) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }

        return true;
    }
};
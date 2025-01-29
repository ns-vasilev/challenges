/*

1456. Maximum Number of Vowels in a Substring of Given Length

Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

*/

class Solution {
private:
    bool is_vowel(char c) {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int res = 0;
        int tmp = 0;
        int l = 0;

        for (int i = 0; i < s.size(); ++i) {
            tmp += is_vowel(s[i]);

            if (i >= k - 1) {
                res = std::max(res, tmp);
                tmp -= is_vowel(s[l]);
                l++;
            }
        }

        return res;
    }
};
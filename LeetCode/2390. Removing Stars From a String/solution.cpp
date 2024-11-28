/*

2390. Removing Stars From a String

You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.

*/

class Solution {
public:
    string removeStars(string s) {
        std::string w;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                w.pop_back();
            } else {
                w.push_back(s[i]);
            }
        }

        return w;
    }
};
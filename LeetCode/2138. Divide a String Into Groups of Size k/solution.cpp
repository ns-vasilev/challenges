/*

2138. Divide a String Into Groups of Size k

A string s can be partitioned into groups of size k using the following procedure:

The first group consists of the first k characters of the string, the second group consists of the next k characters of the string, and so on. Each element can be a part of exactly one group.
For the last group, if the string does not have k characters remaining, a character fill is used to complete the group.
Note that the partition is done so that after removing the fill character from the last group (if it exists) and concatenating all the groups in order, the resultant string should be s.

Given the string s, the size of each group k and the character fill, return a string array denoting the composition of every group s has been divided into, using the above procedure.

*/

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int cnt = std::ceil((float)s.size() / k);

        std::vector<std::string> vec(cnt);

        for (int i = 0; i < s.size(); ++i) {
            vec[i / k] += s[i];
        }

        if (s.size() % k != 0) {
            int len = cnt * k;

            for (int i = s.size(); i < len; ++i) {
                vec[cnt - 1] += fill;
            }
        }

        return vec;
    }
};
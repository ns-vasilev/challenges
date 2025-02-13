/*

1318. Minimum Flips to Make a OR b Equal to c

Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

*/

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;

        while (a > 0 || b > 0 || c > 0) {
            int b_a = a & 1;
            int b_b = b & 1;
            int b_c = c & 1;

            if (b_a == 0 && b_b == 0 && b_c != 0) {
                res++;
            } else if (b_c == 0) {
                res += (b_a + b_b);
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return res;
    }
};
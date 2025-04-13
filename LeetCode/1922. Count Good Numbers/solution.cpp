/*

1922. Count Good Numbers

A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

*/

class Solution {
    private:
        long long h(long long b, long long e, long long m) {
            long long res = 1;
    
            while (e > 0) {
                if (e % 2 == 0) {
                    b = (b * b) % m;
                    e /= 2;
                } else {
                    res = (res * b) % m;
                    e -= 1;
                }
            }
    
            return res;
        }
    public:
        int countGoodNumbers(long long n) {
            long long e = (n + 1) / 2;
            long long o = n / 2;
            long long m = 1e9 + 7;
    
            return (int)((h(5, e, m) * h(4, o, m)) % m);
        }
    };
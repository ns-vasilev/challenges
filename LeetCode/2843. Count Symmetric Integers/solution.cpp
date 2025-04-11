/*

2843. Count Symmetric Integers

You are given two positive integers low and high.

An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.

Return the number of symmetric integers in the range [low, high].

*/

class Solution {
    private:
        bool is_symmetric(int n) {
            std::string s = std::to_string(n);
            
            size_t len = s.size();
    
            if (len % 2 != 0) {
                return false;
            }
    
            int h = len / 2;
            int l = 0;
            int r = 0;
    
            for (int i = 0; i < h; ++i) {
                l += s[i] - '0';
                r += s[h + i] - '0';
            }
    
            return l == r;
        }
    public:
        int countSymmetricIntegers(int low, int high) {
            int count = 0;
    
            for (int i = low; i <= high; ++i) {
                if (is_symmetric(i)) {
                    count++;
                }
            }
    
            return count;
        }
    };
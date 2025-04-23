/*

1399. Count Largest Group

You are given an integer n.

Each number from 1 to n is grouped according to the sum of its digits.

Return the number of groups that have the largest size.

 

Example 1:

Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
There are 4 groups with largest size.
Example 2:

Input: n = 2
Output: 2
Explanation: There are 2 groups [1], [2] of size 1.
 

*/

class Solution {
    private:
        int h(int n) {
            if (n < 10) {  return n; }
    
            int res = 0;
    
            while (n) {
                res += n % 10;
                n /= 10;
            }
    
            return res;
        }
    public:
        int countLargestGroup(int n) {
            std::unordered_map<int, int> m;
    
            int cnt = 0;
            int max = 0;
    
            for (int i = 1; i <= n; ++i) {
                m[h(i)]++;
                max = std::max(max, m[h(i)]);
            }
    
            for (auto &n: m) {
                if (n.second == max) {
                    cnt++;
                }
            }
    
            return cnt;
        }
    };
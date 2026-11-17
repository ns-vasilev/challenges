/*

788. Rotated Digits

An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. For example:

- 0, 1, and 8 rotate to themselves,
- 2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
- 6 and 9 rotate to each other, and
-  the rest of the numbers do not rotate to any other number and become invalid.

Given an integer n, return the number of good integers in the range [1, n].

Example 1:

Input: n = 10
Output: 4
Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.

Example 2:

Input: n = 1
Output: 0
Example 3:

Input: n = 2
Output: 1
 

Constraints:

1 <= n <= 10^4

*/

class Solution {
public:
    int rotatedDigits(int n) {
        std::set<int> invalid_numbers = { 3, 4, 7 };
        std::unordered_map<int, int> rotation = {
            {0, 0}, {1, 1}, {8, 8},
            {2, 5}, {5, 2},
            {6, 9}, {9, 6}
        };
        
        int res = 0;
        
        for (int i = 1; i <= n; ++i) {
            int current_value = i;

            bool is_valid = true;
            bool is_changed = false;

            while (current_value) {
                int number = current_value % 10;
                current_value /= 10;
                
                if (invalid_numbers.contains(number)) {
                    is_valid = false;
                    break;
                }
                
                if (rotation[number] != number) {
                    is_changed = true;
                }
            }
            
            if (is_valid && is_changed) {
                res++;
            }
        }
        
        return res;
    }
};
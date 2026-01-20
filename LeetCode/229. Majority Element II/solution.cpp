/*

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.Example 1:

Input: nums = [3,2,3]
Output: [3]

Constraints:

1 <= nums.length <= 5 * 10^4
-10^9 <= nums[i] <= 10^9

*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0;
        int count1 = 0;

        int candidate2 = 0;
        int count2 = 0;

        for (int n: nums) {
            if (candidate1 == n) {
                count1++;
            } else if (candidate2 == n) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = n;
                count1++;
            } else if (count2 == 0) {
                candidate2 = n;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for (int n: nums) {
            if (n == candidate1) { count1++; }
            else if (n == candidate2) { count2++; }
        }

        std::vector<int> res;

        if (count1 > nums.size() / 3) {
            res.push_back(candidate1);
        }

        if (count2 > nums.size() / 3) {
            res.push_back(candidate2);
        }

        return res;
    }
};
/*

1004. Max Consecutive Ones III

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;

        while (j < nums.size()) {
            if (nums[j] == 0) {
                k--;
            }

            if (k < 0) {
                if (nums[i] == 0) {
                    k++;
                }

                i++;
            }

            j++;
        }

        return j - i;
    }
};
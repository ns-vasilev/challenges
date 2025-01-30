/*

334. Increasing Triplet Subsequence

Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f_small = INT_MAX;
        int s_small = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= f_small) {
                f_small = nums[i];
            } else if (nums[i] <= s_small) {
                s_small = nums[i];
            } else {
                return true;
            }
        }

        return false;
    }
};
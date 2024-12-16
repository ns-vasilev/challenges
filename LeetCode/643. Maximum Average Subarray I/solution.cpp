/*

643. Maximum Average Subarray I

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = 0;

        for (int i = 0; i < k; ++i) {
            res += nums[i];
        }

        double curr = res;

        for (int i = k; i < nums.size(); ++i) {
            curr -= nums[i - k];
            curr += nums[i];

            res = std::max(curr, res);
        }

        return res / k;
    }
};
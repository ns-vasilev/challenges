/*

1679. Max Number of K-Sum Pairs

You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

*/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int i = 0;
        int j = nums.size() - 1;

        int res = 0;

        while (i < j) {
            int sum = nums[i] + nums[j];

            if (sum == k) {
                res++;

                i++;
                j--;
            } else if (sum > k) {
                j--;
            } else {
                i++;
            }
        }

        return res;
    }
};
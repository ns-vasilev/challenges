/*

2874. Maximum Value of an Ordered Triplet II

You are given a 0-indexed integer array nums.

Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.

The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

*/

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long res = 0;
            int diff = 0;
            int max_i = INT_MIN;
    
            for (int i = 0; i < nums.size(); ++i) {
                max_i = std::max(max_i, nums[i]);
    
                if (i >= 2) {
                    res = std::max(res, (long long)diff * nums[i]);
                }
    
                if (i >= 1) {
                    diff = std::max(diff, max_i - nums[i]);
                }
            }
    
            return res;
        }
    };
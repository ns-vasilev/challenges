/*

1679. Max Number of K-Sum Pairs

You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

*/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        std::unordered_map<int, int> s;

        int res = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (s[k - nums[i]] > 0) {
                s[k - nums[i]]--;
                res++;
            } else {
                s[nums[i]]++;
            }
        }

        return res;
    }
};
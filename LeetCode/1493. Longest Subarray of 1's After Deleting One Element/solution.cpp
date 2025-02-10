/*

1493. Longest Subarray of 1's After Deleting One Element

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int z = 0;
        int res = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                z++;
            }

            while (z > 1) {
                if (nums[l] == 0) {
                    z--;
                }
                l++;
            }

            res = std::max(res, i - l + 1 - z);
        }

        return res == n ? (res - 1) : res;
    }
};
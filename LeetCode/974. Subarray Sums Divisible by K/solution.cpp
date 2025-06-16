/*

974. Subarray Sums Divisible by K

Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0

*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res = 0;
        int p = 0;

        std::vector<int> g(k);
        g[0] = 1;

        for (int i = 0; i < nums.size(); ++i) {
            p = (p + nums[i] % k + k) % k;

            res += g[p];
            g[p]++;
        }

        return res;
    }
};
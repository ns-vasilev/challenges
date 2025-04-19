/*

2563. Count the Number of Fair Pairs

Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper

*/

class Solution {
    private:
        long long count(std::vector<int> &nums, long long c) {
            long long res = 0;
    
            for (int i = 0, j = nums.size() - 1; i < j; ++i) {
                while (i < j && nums[i] + nums[j] > c) {
                    --j;
                }
                res += j - i;
            }
    
            return res;
        }
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            std::sort(nums.begin(), nums.end());
            return count(nums, upper) - count(nums, lower - 1);
        }
    };
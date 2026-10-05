/*

260. Single Number III

Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int diff = std::accumulate(nums.begin(), nums.end(), 0U, std::bit_xor<unsigned int>());

        diff &= -diff;

        std::vector<int> rets = {0, 0};
        for (int num : nums) {
            if ((num & diff) == 0) {
                rets[0] ^= num;
            }
            else {
                rets[1] ^= num;
            }
        }
        
        return rets;
    }
};
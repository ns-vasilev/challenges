/*

2799. Count Complete Subarrays in an Array

You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.

*/

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int l = 0;
            int res = 0;
            int k = std::unordered_set(nums.begin(), nums.end()).size();
            std::unordered_map<int, int> m;
    
            for (int i = 0; i < nums.size(); ++i) {
                m[nums[i]]++;
    
                while (m.size() == k) {
                    res += nums.size() - i;
                    m[nums[l]]--;
    
                    if (m[nums[l]] == 0) {
                        m.erase(nums[l]);
                    }
    
                    l++;
                }
            }
    
            return res;
        }
    };
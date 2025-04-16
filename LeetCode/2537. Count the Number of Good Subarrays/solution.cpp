/*

2537. Count the Number of Good Subarrays

Given an integer array nums and an integer k, return the number of good subarrays of nums.

A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

A subarray is a contiguous non-empty sequence of elements within an array.

*/

class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            long long res = 0;
            int l = 0;
    
            std::unordered_map<int, int> m;
    
            for (int i = 0; i < nums.size(); ++i) {
                k -= m[nums[i]]++;
    
                while (k <= 0) {
                    k += --m[nums[l++]];
                }
    
                res += l;
            }
    
            return res;
        }
    };
/*

2176. Count Equal and Divisible Pairs in an Array

Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) where 0 <= i < j < n, such that nums[i] == nums[j] and (i * j) is divisible by k.
 

Example 1:

Input: nums = [3,1,2,2,2,1,3], k = 2
Output: 4
Explanation:
There are 4 pairs that meet all the requirements:
- nums[0] == nums[6], and 0 * 6 == 0, which is divisible by 2.
- nums[2] == nums[3], and 2 * 3 == 6, which is divisible by 2.
- nums[2] == nums[4], and 2 * 4 == 8, which is divisible by 2.
- nums[3] == nums[4], and 3 * 4 == 12, which is divisible by 2.
Example 2:

Input: nums = [1,2,3,4], k = 1
Output: 0
Explanation: Since no value in nums is repeated, there are no pairs (i,j) that meet all the requirements.

*/

class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            std::unordered_map<int, std::vector<int>> m;
    
            int res = 0;
    
            for (int i = 0; i < nums.size(); ++i) {
                m[nums[i]].push_back(i);
            }
    
            std::vector<int> div;
    
            for (int d = 1; d * d <= k; ++d) {
                if (k % d == 0) {
                    div.push_back(d);
    
                    if (d != k / d) {
                        div.push_back(k / d);
                    }
                }
            }
    
            for (auto &[key, vec]: m) {
                std::unordered_map<int, int> mm;
    
                for (int n: vec) {
                    int g = std::gcd(n, k);
                    int mod = k / g;
    
                    res += mm[mod];
    
                    for (auto d: div) {
                        if (n % d == 0) {
                            mm[d]++;
                        }
                    }
                }
            }
    
            return res;
        }
    };
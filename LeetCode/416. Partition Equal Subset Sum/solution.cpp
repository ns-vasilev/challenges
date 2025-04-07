/*

416. Partition Equal Subset Sum

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

*/

class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int sum = 0;
    
            for (int num: nums) {
                sum += num;
            }
    
            if (sum % 2 != 0) {
                return false;
            }
    
            int t_sum = sum / 2;
    
            std::vector<bool> dp(t_sum + 1, false);
    
            dp[0] = true;
    
            for (int num: nums) {
                for (int i = t_sum; i >= num; --i) {
                    dp[i] = dp[i] || dp[i - num];
    
                    if (dp[t_sum]) {
                        return true;
                    }
                }
            }
    
            return dp[t_sum];
        }
    };
/*

3 Sum

Given an array A of N integers, find three integers in A such that the sum is closest to a given number B. Return the sum of those three integers.

Assume that there will only be one solution.

*/

int Solution::threeSumClosest(vector<int> &nums, int B) {
    std::sort(nums.begin(), nums.end());
    
    long long sum = nums[0] + nums[1] + nums[2];
    
    for (int i = 0; i < nums.size() - 2; ++i) {
        int lo = i + 1;
        int hi = nums.size() - 1;
        
        while (lo < hi) {
            int curr_sum = nums[i] + nums[lo] + nums[hi];
            
            if (abs(B - curr_sum) < abs(B - sum)) {
                sum = curr_sum;
            }
            
            if (curr_sum == B) {
                return B;
            } else if (curr_sum < B) {
                lo++;
            } else {
                hi--;
            }
        }
    }
    
    return sum;
}

/*

Rotated Sorted Array Search

Given an array of integers A of size N and an integer B.
array A is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).
You are given a target value B to search. If found in the array, return its index, otherwise, return -1.
You may assume no duplicate exists in the array.

NOTE:- Array A was sorted in non-decreasing order before rotation.

Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?

*/

int binary_search(const std::vector<int> &nums, int target, int l, int r) {
    int n = nums.size() - 1;
    
    while (l <= r) {
        int m = (l + r) / 2;
        
        if (nums[m] == target) {
            return m;
        } else if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    
    return -1;
}

int Solution::search(const vector<int> &nums, int target) {
    int n = nums.size() - 1;
    
    int l = 0;
    int r = n;
    
    while (l <= r) {
        int m = (l + r) / 2;
        
        if (nums[m] > nums[n]) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    
    int x = l;
    
    if (nums[n] < target) {
        l = 0;
        r = x;
    } else {
        l = x;
        r = n;
    }
    
    return binary_search(nums, target, l, r);
}

/*

Maximum Consecutive Gap

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Return 0 if the array contains less than 2 elements.

- You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
- You may also assume that the difference will not overflow.

Try to solve it in linear time/space

Problem Constraints
1 <= |A| <= 10^6
1 <= Ai <= 10^9

*/

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    
    if (n < 2) {
        return 0;
    }
    
    int min_val = A[0];
    int max_val = A[0];
    
    for (int x: A) {
        min_val = std::min(min_val, x);
        max_val = std::max(max_val, x);
    }
    
    if (min_val == max_val) {
        return 0;
    }
    
    int bucket_size = max(1, (max_val - min_val) / (n - 1));
    int bucket_count = (max_val - min_val) / bucket_size + 1;
    
    std::vector<int> bucket_min(bucket_count, INT_MAX);
    std::vector<int> bucket_max(bucket_count, INT_MIN);
    std::vector<bool> bucket_used(bucket_count, false);
    
    for (int x : A) {
        int idx = (x - min_val) / bucket_size;
        bucket_min[idx] = min(bucket_min[idx], x);
        bucket_max[idx] = max(bucket_max[idx], x);
        bucket_used[idx] = true;
    }
    
    int max_gap = 0;
    int prev_max = min_val; 
    for (int i = 0; i < bucket_count; ++i) {
        if (!bucket_used[i]) continue;
        
        max_gap = max(max_gap, bucket_min[i] - prev_max);
        prev_max = bucket_max[i];
    }

    return max_gap;
}

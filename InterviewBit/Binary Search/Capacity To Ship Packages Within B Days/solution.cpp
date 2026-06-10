/*

Capacity To Ship Packages Within B Days

A conveyor belt has packages that must be shipped from one port to another within B days.

The ith package on the conveyor belt has a weight of A[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within B days.

Problem Constraints
- 1 <= B <= |A| <= 5 * 105
- 1 <= A[i] <= 105

Input Format
- First argument is array of integers A denoting the weights.
- Second argument is the integer B denoting the number of days. 

Output Format
Return the least weight capacity of the ship.

*/

bool is_possible(int capacity, int B, std::vector<int> &A) {
    int days = 1;
    int cap = 0;
    
    for (auto a: A) {
        if (cap + a > capacity) {
            days += 1;
            cap = a;
        } else {
            cap += a;
        }
    }
    
    return days <= B;
} 

int Solution::solve(vector<int> &A, int B) {
    int low = *std::max_element(A.begin(), A.end());
    int high = std::accumulate(A.begin(), A.end(), 0);

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (is_possible(mid, B, A)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return low;
}

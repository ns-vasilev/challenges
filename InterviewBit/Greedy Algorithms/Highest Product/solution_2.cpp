/*

Highest Product

Given an array A, of N integers A.
Return the highest product possible by multiplying 3 numbers from the array.
NOTE: The solution will fit in a 32-bit signed integer.

*/

int Solution::maxp3(vector<int> &A) {
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;
    
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    
    for (auto n: A) {
        if (max1 < n) {
            max3 = max2;
            max2 = max1;
            max1 = n;
        } else if (max2 < n) {
            max3 = max2;
            max2 = n;
        } else if (max3 < n) {
            max3 = n;
        }
        
        if (min1 > n) {
            min2 = min1;
            min1 = n;
        } else if (min2 > n) {
            min2 = n;
        }
    }
    
    return std::max(
        max1 * max2 * max3,
        min1 * min2 * max1
    );
}

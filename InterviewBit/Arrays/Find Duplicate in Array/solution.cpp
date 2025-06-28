/*

Find Duplicate in Array

Given a read-only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
If there are multiple possible answers ( like in the sample case ), output any one, if there is no duplicate, output -1

Problem Constraints
1 <= |A| <= 105
1 <= Ai <= |A|

*/

int Solution::repeatedNumber(const vector<int> &A) {
    int l = 1;
    int r = A.size() - 1;
    
    bool f = false;
    
    while (l <= r) {
        int m = (l + r) / 2;
        int cnt = 0;
        
        for (auto n: A) {
            if (n <= m) {
                cnt++;
            }
        }
        
        if (cnt > m) {
            f = true;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    
    return f ? l : -1;
}

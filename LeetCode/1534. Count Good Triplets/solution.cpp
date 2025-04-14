/*

1534. Count Good Triplets

Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.

A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:

0 <= i < j < k < arr.length
|arr[i] - arr[j]| <= a
|arr[j] - arr[k]| <= b
|arr[i] - arr[k]| <= c
Where |x| denotes the absolute value of x.

Return the number of good triplets.

*/

class Solution {
    public:
        int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
            int count = 0;
    
            for (int i = 0; i < arr.size() - 2; ++i) {
                for (int k = i + 2; k < arr.size(); ++k) {
                    if (abs(arr[k] - arr[i]) > c) {
                        continue;
                    }
    
                    for (int j = i + 1; j < k; ++j) {
                        if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b) {
                            count++;
                        }
                    }
                }
            }
    
            return count;
        }
    };
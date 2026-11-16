/*

949. Largest Time for Given Digits

Given an array arr of 4 digits, find the latest 24-hour time that can be made using each digit exactly once.

24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.

Return the latest 24-hour time in "HH:MM" format. If no valid time can be made, return an empty string.

Example 1:

Input: arr = [1,2,3,4]
Output: "23:41"
Explanation: The valid 24-hour times are "12:34", "12:43", "13:24", "13:42", "14:23", "14:32", "21:34", "21:43", "23:14", and "23:41". Of these times, "23:41" is the latest.

Example 2:

Input: arr = [5,5,5,5]
Output: ""
Explanation: There are no valid 24-hour times as "55:55" is not valid.

Constraints:

arr.length == 4
0 <= arr[i] <= 9

*/

class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        
        int max_time = -1;
        std::string best_time = "";
        
        do {
            int hours = arr[0] * 10 + arr[1];
            int minutes = arr[2] * 10 + arr[3];
            
            if (hours < 24 && minutes < 60) {
                int total_minutes = hours * 60 + minutes;
                if (total_minutes > max_time) {
                    max_time = total_minutes;
                    best_time = std::to_string(arr[0]) + std::to_string(arr[1]) + ":" +
                                std::to_string(arr[2]) + std::to_string(arr[3]);
                }
            }
        } while (std::next_permutation(arr.begin(), arr.end()));
        
        return best_time;
    }
};
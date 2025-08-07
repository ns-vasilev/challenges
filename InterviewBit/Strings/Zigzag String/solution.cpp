/*

Zigzag String

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
**Example 2 : **

ABCD, 2 can be written as

A....C
...B....D
and hence the answer would be ACBD.

*/

string Solution::convert(string A, int B) {
    if (B == 1 || A.size() <= B) {
        return A;
    }
    
    std::vector<std::string> rows(std::min(int(A.length()), B));
    
    int curr_row = 0;
    bool going_down = false;

    for (char c: A) {
        rows[curr_row] += c;
        
        if (curr_row == 0 || curr_row == B - 1) {
            going_down = !going_down;
        }
        
        curr_row += going_down ? 1 : -1;
    }
    
    std::string result;
    
    for (std::string s: rows) {
        result += s;
    }
    
    return result;
}

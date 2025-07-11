/*

Minimum Parantheses!

Given a string A of parantheses  ‘(‘ or ‘)’.

The task is to find minimum number of parentheses ‘(‘ or ‘)’ (at any positions) we must add to make the resulting parentheses string valid.

An string is valid if:

Open brackets must be closed by the corresponding closing bracket.
Open brackets must be closed in the correct order.

*/

int Solution::solve(string A) {
    int open = 0;
    int k = 0;
    
    for (char ch: A) {
        if (ch == '(') {
            open++;
        } else {
            if (open > 0) {
                open--;
            } else {
                k++;
            }
        }
    }
    
    return open + k;
}

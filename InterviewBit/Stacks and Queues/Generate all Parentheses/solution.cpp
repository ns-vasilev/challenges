/*

Generate all Parentheses

Given a string A, containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem.
Note:  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/

int Solution::isValid(string A) {
    std::stack<char> s;
    
    for (int i = 0; i < A.size(); ++i) {
        char c = A[i];
        
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else {
            if (s.empty()) {
                return 0;
            }
            
            char t = s.top();
            s.pop();
            
            if ((c == ')' && t != '(') ||
                (c == '}' && t != '{') ||
                (c == ']' && t != '[')) {
                return 0;
            }
        }
    }
    
    return s.empty() ? 1 : 0;
}
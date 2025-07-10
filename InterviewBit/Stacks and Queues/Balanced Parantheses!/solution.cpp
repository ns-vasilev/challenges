/*

Balanced Parantheses!

Given a string A consisting only of '(' and ')'.

You need to find whether parantheses in A is balanced or not ,if it is balanced then return 1 else return 0.

*/

int Solution::solve(string A) {
    std::stack<char> s;
    
    for (auto ch: A) {
        if (ch == '(') {
            s.push('(');
        } else if (ch == ')' && !s.empty()) {
            char t = s.top();
            s.pop();
        } else {
            return 0;
        }
    }
    
    return s.empty() ? 1 : 0;
}

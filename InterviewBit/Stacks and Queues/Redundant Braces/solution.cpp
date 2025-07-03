/*

Redundant Braces

Given a string A denoting an expression. It contains the following operators '+', '-', '*', '/'.

Chech whether A has redundant braces or not.

NOTE: A will be always a valid expression.

Problem Constraints
1 <= |A| <= 10^5

*/

int Solution::braces(string A) {
    std::stack<char> st;
    
    for (int i = 0; i < A.size(); ++i) {
        char ch = A[i];
        bool is_redundant = true;

        if (ch == ')') {
            char t = st.top(); st.pop();
            
            while (t != '(') {
                if (t == '+' || t == '-' || t == '*' || t == '/') {
                    is_redundant = false;
                }
                
                t = st.top(); st.pop();
            }
            
            if (is_redundant) {
                return true;
            }
        } else {
            st.push(ch);
        }
    }
    
    return false;
}

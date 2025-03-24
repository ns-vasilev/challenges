/*

224. Basic Calculator

Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

*/

class Solution {
    public:
        int calculate(string s) {
            std::stack<int> st;
    
            int op = 0;
            int res = 0;
            int sign = 1;
    
            for (char ch: s) {
                if (isdigit(ch)) {
                    op = op * 10 + (ch - '0');
                } else if (ch == '+') {
                    res += op * sign;
                    sign = 1;
                    op = 0;
                } else if (ch == '-') {
                    res += op * sign;
                    sign = -1;
                    op = 0;
                } else if (ch == '(') {
                    st.push(res);
                    st.push(sign);
                    sign = 1;
                    res = 0;
                } else if (ch == ')') {
                    res += op * sign;
                    op = 0;
                    res *= st.top();
                    st.pop();
                    res += st.top();
                    st.pop();
                }
            }
    
            return res + (sign * op);
        }
    };
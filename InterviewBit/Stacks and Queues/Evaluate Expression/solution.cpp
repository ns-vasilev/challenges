/*

Evaluate Expression

An arithmetic expression is given by a string array A of size N. Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each string may be an integer or an operator.

*/

int Solution::evalRPN(vector<string> &A) {
    std::stack<int> st;
    
    for (auto & s: A) {
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            
            if (s == "+") { st.push(a + b); }
            else if (s == "-") { st.push(a - b); }
            else if (s == "*") { st.push(a * b); }
            else if (s == "/") { st.push(a / b); }
        } else {
            st.push(stoi(s));
        }
    }
    
    return st.top();
}

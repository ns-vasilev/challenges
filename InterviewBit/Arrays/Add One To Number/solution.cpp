/*

Add One To Number

Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer. For example: 
for this problem, following are some good questions to ask :

Q : Can the input have 0's before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0's before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

*/

vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size();
    
    for (int i = n - 1; i >= 0; --i) {
        if (A[i] < 9) {
            A[i]++;
            
            auto it = A.begin();
            while (it != A.end() && *it == 0) ++it;
            return vector<int>(it, A.end());
        }
        
        A[i] = 0;
    }
    
    A.insert(A.begin(), 1);
    
    auto it = A.begin();
    while (it != A.end() && *it == 0) ++it;
    return vector<int>(it, A.end());
}

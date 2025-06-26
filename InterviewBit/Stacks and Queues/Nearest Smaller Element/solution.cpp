/*

Nearest Smaller Element

Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

    G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.

Input Format

The only argument given is integer array A.
Output Format

Return the integar array G such that G[i] contains nearest smaller number than A[i].If no such element occurs G[i] should be -1.

*/

vector<int> Solution::prevSmaller(vector<int> &A) {
    std::vector<int> v;
    std::stack<int> s;
    
    for (int i = 0; i < A.size(); ++i) {
        while (!s.empty() && s.top() >= A[i]) {
            s.pop();
        }
        
        if (s.empty()) {
            v.push_back(-1);
        } else {
            v.push_back(s.top());
        }
        
        s.push(A[i]);
    }
    
    return v;
}

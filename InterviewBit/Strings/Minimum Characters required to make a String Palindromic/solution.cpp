/*

Minimum Characters required to make a String Palindromic

Given a string A. The only operation allowed is to insert characters at the beginning of the string.
Find how many minimum characters are needed to be inserted to make the string a palindrome string.

*/

std::vector<int> prefix_function(const std::string &s) {
    std::vector<int> p(s.size(), 0);
    
    int k = 0;
    
    for (int i = 1; i < s.size(); ++i) {
        while (k > 0 && s[i] != s[k]) {
            k = p[k - 1];
        }
        
        if (s[i] == s[k]) {
            k++;
        }
        
        p[i] = k;
    }
    
    return p;
}
int Solution::solve(string A) {
    string revA = A;
    std::reverse(revA.begin(), revA.end());
    string s = A + '#' + revA;

    std::vector<int> p = prefix_function(s);
    
    return A.size() - p.back();
}

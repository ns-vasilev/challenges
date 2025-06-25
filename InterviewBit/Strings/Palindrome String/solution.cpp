/*

Palindrome String

Given a string, determine if it is a palindrome. While checking for a palindrome, you have to ignore spaces, case, and all special characters; i.e. consider only alphanumeric characters.

Check the sample test case for reference.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/

int Solution::isPalindrome(string A) {
    int i = 0;
    int j = A.size() - 1;
    
    while (i < j) {
        while (i < j && !std::isalnum(A[i])) {
            i++;
        }
        
        while (i < j && !std::isalnum(A[j])) {
            j--;
        }
        
        if (std::tolower(A[i]) != std::tolower(A[j])) {
            return 0;
        }
        
        i++;
        j--;
    }
    
    return 1;
}

/*

First non-repeating character in a stream of characters

Given a string A denoting a stream of lowercase alphabets. You have to make new string B.

B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and append it at the end to B. If no non-repeating character is found then append '#' at the end of B.

*/

string Solution::solve(string A) {
    std::vector<int> freq(26, 0);
    std::queue<int> q;
    std::string res = "";
    
    for (char ch: A) {
        freq[ch - 'a']++;
        q.push(ch);
        
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }
        
        if (q.empty()) {
            res += "#";
        } else {
            res += q.front();
        }
    }
    
    return res;
}

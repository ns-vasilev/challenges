/*

Word Ladder I

Problem Description
 
Given two words A and B, and a dictionary C, find the length of shortest transformation sequence from A to B, such that:

You must change exactly one character in every transformation.
Each intermediate word must exist in the dictionary.

NOTE:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

Problem Constraints
1 <= length(A), length(B), length(C[i]) <= 25
1 <= length(C) <= 5000

Input Format
The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains an array of strings, C.

Output Format
Return an integer representing the minimum number of steps required to change string A to string B.

*/

int Solution::solve(string A, string B, vector<string> &C) {
    std::unordered_set<std::string> m(C.begin(), C.end());
    std::queue<std::pair<std::string, int>> q;
    
    q.push({ A, 1 });
    m.insert(B);
    m.erase(A);

    while (!q.empty()) {
        std::pair<std::string, int> u = q.front();
        q.pop();
        
        std::string word = u.first;
        int steps = u.second;

        if (word == B) {
            return steps;
        }
        
        for (int i = 0; i < word.size(); ++i) {
            char original_char = word[i];

            for (int j = 0; j < 26; ++j) {
                char new_char = 'a' + j;
                
                if (new_char == original_char) {
                    continue;
                }
                
                word[i] = new_char;
                
                if (auto it = m.find(word); it != m.end()) {
                    m.erase(it);
                    
                    q.push({ word, u.second + 1 });
                }
            }
            
            word[i] = original_char;
        }
    }
    
    return 0;
}

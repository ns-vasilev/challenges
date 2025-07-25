/*

Character Frequencies

Given a string A containing only lowercase characters.
Find the frequencies of the characters in order of their occurrence.

*/

vector<int> Solution::solve(string A) {
    std::unordered_map<char, int> freq;
    std::vector<char> order;

    for (char ch: A) {
        if (freq[ch] == 0) {
            order.push_back(ch);
        }
        freq[ch]++;
    }
    
    std::vector<int> result;

    for (char ch : order) {
        result.push_back(freq[ch]);
    }

    return result;
}

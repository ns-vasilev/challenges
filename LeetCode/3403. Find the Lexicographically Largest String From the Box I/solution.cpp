/*

3403. Find the Lexicographically Largest String From the Box I

You are given a string word, and an integer numFriends.

Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:

- word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
- All the split words are put into a box.

Find the lexicographically largest string from the box after all the rounds are finished.

*/

class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) { return word; }

        std::string str = "";

        for (int i = 0; i < word.size(); ++i) {
            str = std::max(str, word.substr(i, word.size() - numFriends + 1));
        }

        return str;
    }
};
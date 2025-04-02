/*

68. Text Justification

Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.

*/

class Solution {
    public:
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            std::vector<std::string> res;
    
            int n = words.size();
            int index = 0;
    
            while (index < n) {
                int total = words[index].size();
                int last = index + 1;
    
                while (last < n && total + words[last].size() + (last - index) <= maxWidth) {
                    total += words[last].size();
                    last++;
                }
    
                std::string line;
    
                int numWords = last - index;
                int numSpaces = maxWidth - total;
    
                if (last == n || numWords == 1) {
                    for (int i = index; i < last; ++i) {
                        line += words[i];
    
                        if (i < last - 1) {
                            line += " ";
                        }
                    }
    
                    line += std::string(maxWidth - line.size(), ' ');
                } else {
                    int spacePerWord = numSpaces / (numWords - 1);
                    int extraSpaces = numSpaces % (numWords - 1);
    
                    for (int i = index; i < last; ++i) {
                        line += words[i];
    
                        if (i < last - 1) {
                            line += std::string(spacePerWord + (i - index < extraSpaces ? 1 : 0), ' ');
                        }
                    }
                }
    
                res.push_back(line);
                index = last;
            }
    
            return res;
        }
    };
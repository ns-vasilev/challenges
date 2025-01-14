/*

1268. Search Suggestions System

You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.

 

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Explanation: The only word "havana" will be always suggested while typing the search word.

*/

class Solution {
private:
    struct Node {
        Node *v[26];
        int prefs = 0;
        int ends = 0;

        Node() {
            for (int i = 0; i < 26; ++i) {
                v[i] = nullptr;
            }
        }
    };

    class Trie {
    private:
        Node* root;

        void dfs(Node *node, std::string path, std::vector<std::string> &res) {
            if (res.size() >= 3) { return; }

            if (node->ends > 0) {
                res.push_back(path);
            }

            for (int i = 0; i < 26; ++i) {
                if (node->v[i]) {
                    dfs(node->v[i], path + char('a' + i), res);
                }
            }
        }
    public:
        Trie() {
            root = new Node();
        }

        void insert(std::string &word) {
            Node *curr = root;

            for (int i = 0; i < word.size(); ++i) {
                char ch = word[i];

                if (curr->v[ch - 'a'] == nullptr) {
                    curr->v[ch - 'a'] = new Node();
                }

                curr = curr->v[ch - 'a'];
                curr->prefs++;
            }

            curr->ends++;
        }

        std::vector<std::string> find(std::string &prefix) {
            std::vector<std::string> res;

            Node *curr = root;

            for (int i = 0; i < prefix.size(); ++i) {
                char ch = prefix[i];

                if (curr->v[ch - 'a'] == nullptr) {
                    return res;
                }

                curr = curr->v[ch - 'a'];
            }

            dfs(curr, prefix, res);

            return res;
        }
    };
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie tr;

        for (std::string s: products) {
            tr.insert(s);
        }

        std::vector<std::vector<std::string>> res;
        std::string prefix;

        for (char c: searchWord) {
            prefix += c;
            res.push_back(tr.find(prefix));
        }

        return res;
    }
};
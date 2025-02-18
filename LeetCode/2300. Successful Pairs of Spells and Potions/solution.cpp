/*

2300. Successful Pairs of Spells and Potions

You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

*/

class Solution {
    public:
        vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
            std::vector<int> res(spells.size());
    
            std::sort(potions.begin(), potions.end());
    
            for (int i = 0; i < spells.size(); ++i) {
                int l = 0;
                int r = potions.size() - 1;
    
                while (l <= r) {
                    int m = (l + r) / 2;
                    long v = (long)spells[i] * potions[m];
    
                    if (v >= success) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
    
                res[i] = potions.size() - l;
            }
    
            return res;
        }
    };
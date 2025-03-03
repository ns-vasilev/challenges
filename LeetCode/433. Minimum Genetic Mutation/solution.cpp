/*

433. Minimum Genetic Mutation

A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

*/

class Solution {
    public:
        int minMutation(string startGene, string endGene, vector<string>& bank) {
            std::queue<std::string> q;
            std::map<std::string, int> distance;
    
            q.push(startGene);
    
            distance[startGene] = 0;
    
            while (!q.empty()) {
                std::string s = q.front();
                q.pop();
    
                for (std::string &b: bank) {
                    if (distance.count(b)) {
                        continue;
                    }
    
                    int count = 0;
    
                    for (int i = 0; i < 8; ++i) {
                        if (b[i] != s[i]) {
                            count++;
                        }
                    }
    
                    if (count == 1) {
                        distance[b] = distance[s] + 1;
                        q.push(b);
                    }
                }
            }
    
            if (distance.count(endGene)) {
                return distance[endGene];
            }
    
            return -1;
        }
    };
/*

135. Candy

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

*/

class Solution {
    public:
        int candy(vector<int>& ratings) {
            int i = 1;
            int n = ratings.size();
    
            int res = n;
            
            while (i < n) {
                if (ratings[i] == ratings[i - 1]) {
                    i++;
                    continue;
                }
    
                int p = 0;
                while (ratings[i] > ratings[i - 1]) {
                    p++;
                    res += p;
                    i++;
    
                    if (i == n) {
                        return res;
                    }
                }
    
                int v = 0;
                while (i < n && ratings[i] < ratings[i - 1]) {
                    v++;
                    res += v;
                    i++;
                }
    
                res -= std::min(p, v);
            }
    
            return res;
        }
    };
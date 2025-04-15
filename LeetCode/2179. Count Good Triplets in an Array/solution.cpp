/*

2179. Count Good Triplets in an Array

You are given two 0-indexed arrays nums1 and nums2 of length n, both of which are permutations of [0, 1, ..., n - 1].

A good triplet is a set of 3 distinct values which are present in increasing order by position both in nums1 and nums2. In other words, if we consider pos1v as the index of the value v in nums1 and pos2v as the index of the value v in nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1, such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.

Return the total number of good triplets.

*/

class Solution {
    private:
        int query(std::vector<int> &v, int i) {
            int res = 0;
            for (; i > 0; i -= i & (-i)) {
                res += v[i];
            }
            return res;
        }
    
        void update(std::vector<int> &v, int i, int x) {
            for (; i < v.size(); i += i & (-i)) {
                v[i] += x;
            }
        }
    public:
        long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
    
            std::vector<int> p(n, 0);
            std::vector<int> m(n, 0);
    
            for (int i = 0; i < n; ++i) {
                p[nums2[i]] = i;
            }
    
            for (int i = 0; i < n; ++i) {
                m[i] = p[nums1[i]];
            }
    
            std::vector<long long> l(n, 0);
            std::vector<long long> r(n, 0);
            std::vector<int> b(n + 2, 0);
    
            for (int i = 0; i < n; ++i) {
                l[i] = query(b, m[i]);
                update(b, m[i] + 1, 1);
            }
    
            std::fill(b.begin(), b.end(), 0);
    
            for (int i = n - 1; i >= 0; --i) {
                r[i] = query(b, n) - query(b, m[i] + 1);
                update(b, m[i] + 1, 1);
            }
    
            long long res = 0;
            for (int i = 0; i < n; ++i) {
                res += l[i] * r[i];
            }
    
            return res;
        }
    };
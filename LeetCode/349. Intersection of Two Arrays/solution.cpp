/*

349. Intersection of Two Arrays

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::set<int> s1(nums1.begin(), nums1.end());
        std::set<int> s2;

        for (auto n: nums2) {
            if (s1.count(n)) {
                s2.insert(n);
            }
        }

        std::vector<int> res;

        for (auto n: s2) {
            res.push_back(n);
        }

        return res;
    }
};
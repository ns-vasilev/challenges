/*

2215. Find the Difference of Two Arrays

Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

- answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
- answer[1] is a list of all distinct integers in nums2 which are not present in nums1.

Note that the integers in the lists may be returned in any order.

*/

class Solution {
private:
    std::vector<int> unique(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> v;
        std::set<int> s1;
        std::set<int> s2;

        for (int i = 0; i < nums2.size(); ++i) {
            s1.insert(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); ++i) {
            if (s1.count(nums1[i]) == 0 && s2.count(nums1[i]) == 0) {
                v.push_back(nums1[i]);
                s2.insert(nums1[i]);
            }
        }

        return v;
    }
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> v1 = unique(nums1, nums2);
        std::vector<int> v2 = unique(nums2, nums1);

        return { v1, v2 };
    }
};
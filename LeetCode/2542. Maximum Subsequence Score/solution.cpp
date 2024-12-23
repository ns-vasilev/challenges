/*

2542. Maximum Subsequence Score

You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.

For chosen indices i0, i1, ..., ik - 1, your score is defined as:

The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
Return the maximum possible score.

A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.

*/

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        std::vector<std::pair<int, int>> p;

        for (int i = 0; i < nums1.size(); ++i) {
            p.push_back({ nums2[i], nums1[i] });
        }

        std::sort(p.rbegin(), p.rend());

        long long res = 0;
        long long sum = 0;

        std::priority_queue<int> q;

        for (int i = 0; i < k - 1; ++i) {
            sum += p[i].second;
            q.push(-p[i].second);
        }

        for (int i = k - 1; i < nums1.size(); ++i) {
            sum += p[i].second;
            q.push(-p[i].second);

            res = std::max(res, sum * p[i].first);

            sum += q.top();
            q.pop();
        }

        return res;
    }
};
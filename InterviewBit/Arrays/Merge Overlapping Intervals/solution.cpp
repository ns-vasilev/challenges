/*

Merge Overlapping Intervals

Problem Description

Given a collection of intervals, merge all overlapping intervals.

Problem Constraints

1 <= Total number of intervals <= 100000.

Input Format

First argument is a list of intervals.

Output Format

Return the sorted list of intervals after merging all the overlapping intervals.

*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::merge(vector<Interval> &intervals) {
    std::vector<Interval> res;

    std::sort(intervals.begin(), intervals.end(),
              [](const Interval &a, const Interval &b) {
                  return a.start < b.start;
              });

    for (int i = 0; i < intervals.size(); ++i) {
        if (res.empty() || intervals[i].start > res.back().end) {
            res.push_back(intervals[i]);
        } else {
            res.back().end = std::max(res.back().end, intervals[i].end);
        }
    }

    return res;
}
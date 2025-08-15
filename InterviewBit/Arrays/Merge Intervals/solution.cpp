/*

Merge Intervals

Given a set of non-overlapping intervals and a new interval.

Insert the new interval into the set of intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.
Note: Make sure the returned intervals are also sorted.

Problem Constraints

0 <= |intervals| <= 10^6
1 <= intervalsi.start < intervalsi.end <= 10^9
1 <= newInterval.start < newInteval.end <= 10^9

Input Format

The First argument is an array of Intervals.
The second argument is the new Interval.

Output Format

Return the array of merged intervals.

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
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    std::vector<Interval> res;
    bool inserted = false;

    for (auto interval: intervals) {
        if (interval.end < newInterval.start) {
            res.push_back(interval);
        } else if (interval.start > newInterval.end) {
            if (!inserted) {
                res.push_back(newInterval);
                inserted = true;
            }
            res.push_back(interval);
        } else {
            newInterval.start = min(newInterval.start, interval.start);
            newInterval.end   = max(newInterval.end, interval.end);
        }
    }

    if (!inserted) {
        res.push_back(newInterval);
    }
    
    return res;
}

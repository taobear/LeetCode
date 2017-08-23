/*
 Author: 		TaoBear
 Update:		Aug 22, 2017
 Problem: 		Insert Interval
 Difficulty: 	Hard
 Source:		https://leetcode.com/problems/insert-interval/description/
 Tags: 			Array, Sort
*/

// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

// You may assume that the intervals were initially sorted according to their start times.

// Example 1:
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

#include "leetcode.hpp"

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int size = intervals.size();
        if (size < 1)
        	return vector<Interval> {newInterval};

        int id = 0, cnt = 0;
        vector<Interval> rslt;
        for ( ; id < size; ++id) {
        	if (intervals[id].start >= newInterval.start)
        		break;
        }

        if (!id) { 
        	rslt.push_back(newInterval);
			cnt = 0;
		}
        else {
        	rslt.push_back(intervals[0]);
        	cnt = 1;
        }

        while (cnt < size) {
        	if (cnt == id) {
        		helper(rslt, newInterval);
        	} 
        	helper(rslt, intervals[cnt]);
        	cnt++;
        }

        if (cnt == size)
        	helper(rslt, newInterval);

        return rslt;
    }

    void helper(vector<Interval>& intervals, Interval& newInterval) {
    	if (newInterval.start > intervals.back().end)
     		intervals.push_back(newInterval);
     	else if (newInterval.end > intervals.back().end)
     		intervals.back().end = newInterval.end;
    }
};

int main(int argc, char **argv)
{

}
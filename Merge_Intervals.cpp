/*
 Author: 		TaoBear
 Update:		Aug 21, 2017
 Problem: 		Merge Intervals
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/merge-intervals/description/
 Tags: 			Array, Sort
*/

// Given a collection of intervals, merge all overlapping intervals.

// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].

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
    vector<Interval> merge(vector<Interval>& intervals) {
     	if (intervals.empty())
     		return vector<Interval>{};

     	vector<Interval> rslt;
     	sort(intervals.begin(), intervals.end(), 
     		[](Interval &lhs, Interval &rhs){
     			return lhs.start < rhs.start;
     		});

     	//Interval tmp;
     	rslt.push_back(intervals[0]);
     	for (int i = 1; i < intervals.size(); ++i) {
     		if (intervals[i].start > rslt.back().end)
     			rslt.push_back(intervals[i]);
     		else if (intervals[i].end > rslt.back().end)
     			rslt.back().end = intervals[i].end;
     	}
     	return rslt;
    }
};

int main(int argc, char **argv)
{

}
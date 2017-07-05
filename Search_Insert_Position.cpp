/*
 Author: 		TaoBear
 Update:		July 5, 2017
 Problem: 		Search Insert Position
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/search-insert-position/#/description
 Tags: 			Binary Search, Array
*/


// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You may assume no duplicates in the array.

// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0

#include "leetcode.hpp"
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 1) return 0;

        int i = 0, j = len - 1;
        int mid = 0;
        while (i <= j) {
        	mid = (i + j) / 2;
        	if (nums[mid] < target)
        		i = mid + 1;
        	else 
        		j = mid - 1;
        }
        return i;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {1, 3, 5, 6};

	int rslt1 = 2;

	VERIFY_IS_EQUAL(sln.searchInsert(input1, 5), 2);

}
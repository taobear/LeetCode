/*
 Author: 		TaoBear
 Update:		July 4, 2017
 Problem: 		Remove Duplicates from Sorted Array
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/remove-duplicates-from-sorted-array/#/description
 Tags: 			Array, Two Pointers
*/

// Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

// Do not allocate extra space for another array, you must do this in place with constant memory.

// For example,
// Given input array nums = [1,1,2],

// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
#include "leetcode.hpp"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len < 1)
        	return 0;

        int i = 0, j = 0;
        while (++j < len) {
        	if (nums[i] != nums[j])
        		nums[++i] = nums[j];
        }
        return ++i;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {1, 1, 2};

	int rslt1 = sln.removeDuplicates(input1);

	VERIFY_IS_EQUAL(rslt1, 2);
}
/*
 Author: 		TaoBear
 Update:		Aug 25, 2017
 Problem: 		Remove Duplicates from Sorted Array II
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
 Tags: 			Tow Pointer, Array
*/

// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?

// For example,
// Given sorted array nums = [1,1,1,2,2,3],

// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
#include "leetcode.hpp"

int removeDuplicates1(vector<int>& nums) {
	int n = nums.size();
	if (n < 3) return n;

	int index = 2;
	for (int i = 2; i < n; ++i) {
		if (nums[index - 2] != nums[i]) {
			nums[index++] = nums[i];
		}
	}
	return index;
}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	return removeDuplicates1(nums);
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {1, 1, 1, 2, 2, 3};
	vector<int> input2 = {1, 2, 2};
	vector<int> input3 = {1, 1, 1, 1, 3, 3};

	int target1 = 5;
	int target2 = 3;
	int target3 = 4;

	VERIFY_IS_EQUAL(sln.removeDuplicates(input1), target1);
	VERIFY_IS_EQUAL(sln.removeDuplicates(input2), target2);
	VERIFY_IS_EQUAL(sln.removeDuplicates(input3), target3);
}
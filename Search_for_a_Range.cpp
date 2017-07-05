/*
 Author: 		TaoBear
 Update:		July 5, 2017
 Problem: 		Search for a Range
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/search-for-a-range/#/description
 Tags: 			Binary Search, Array
*/

// Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].
#include "leetcode.hpp"

// 当找不到时，findMin 和 findMax 相同，且 i 必然大于 j
int findMin(vector<int>& nums, int target) {
	int i = 0, j = nums.size() - 1;
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

int findMax(vector<int>& nums, int target) {
	int i = 0, j = nums.size() - 1;
	int mid = 0;
	while (i <= j) {
		mid = (i + j) / 2;
		if (nums[mid] <= target)
			i = mid + 1;
		else
			j = mid - 1;
	}

	return j;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	if (!nums.size()) return {-1, -1};
        int minId = findMin(nums, target);
        int maxId = findMax(nums, target);

        return minId > maxId ? vector<int>{-1, -1} : vector<int>{minId, maxId};
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {5, 7, 7, 8, 8, 10};
	vector<int> input2 = {1};

	vector<int> rslt1 = {3, 4};
	vector<int> rslt2 = {-1, -1};

	VERIFY_IS_EQUAL(sln.searchRange(input1, 8), rslt1);
	VERIFY_IS_EQUAL(sln.searchRange(input2, 0), rslt2);
}
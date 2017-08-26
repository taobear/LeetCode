/*
 Author: 		TaoBear
 Update:		Aug 25, 2017
 Problem: 		Search in Rotated Sorted Array II
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 Tags: 			Binary Search, Array
*/


// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// Write a function to determine if a given target is in the array.

// The array may contain duplicates.

#include "leetcode.hpp"

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size(), i = 1;
        if (n < 1) 
        	return false;
        for ( ; i < n; ++i) {
        	if (nums[i] < nums[i - 1]) 
     			break;
        }
        // if (i >= n) 
        // 	return helper(nums, 0, n - 1, target);

        if (i >= n || nums[0] <= target) 
        	return helper(nums, 0, i - 1, target);
        return helper(nums, i, n - 1, target);
    }

    bool helper(vector<int>& nums, int left, int right, int target) {
    	while (left <= right) {
    		int mid = left + (right - left) / 2;
    		if (nums[mid] < target) {
    			left = mid + 1;
    		} else if (nums[mid] > target) {
    			right = mid - 1;
    		} else 
    			return true;
    	}
    	return false;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {0, 1, 2, 4, 5, 6, 7};
	vector<int> input2 = {3, 1};

	bool target1 = true;
	bool target2 = true;

	VERIFY_IS_EQUAL(sln.search(input1, 5), true);
	VERIFY_IS_EQUAL(sln.search(input2, 1), true);
}
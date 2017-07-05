/*
 Author: 		TaoBear
 Update:		July 5, 2017
 Problem: 		Search in Rotated Sorted Array
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/search-in-rotated-sorted-array/#/description
 Tags: 			Binary Search, Array
*/

// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.
#include "leetcode.hpp"

// 可改进， 将首次查找也改为2分查找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return -1;
        if (len == 1)
            return nums[0] == target ? 0 : -1; 
        
        int i = 0, j = len - 1;
        if (nums[0] > nums[len - 1])
        {
        	while (nums[j - 1] <= nums[j] && --j > 0);
        	if (nums[j - 1] < target)
        		return -1;
        	else if (nums[i] <= target)
        	{
        		i = 0;
        		j = j - 1;
        	}
        	else if (nums[len - 1] >= target)
        	{
        		i = j;
        		j = len - 1;
        	}
        	else 
        		return -1;
        }

        int mid = 0;
        while (i <= j) {
        	mid = i + (j - i) / 2;
        	if (nums[mid] > target)
        		j = mid - 1;
        	else if (nums[mid] < target)
        		i = mid + 1;
        	else
        		return mid;
        }
        return -1;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {4, 5, 6, 1, 2, 3};

	int rslt = 1;

	VERIFY_IS_EQUAL(sln.search(input1, 5), rslt);
}
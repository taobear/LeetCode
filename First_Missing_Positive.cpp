/*
 Author: 		TaoBear
 Update:		July 22, 2017
 Problem: 		First Missing Positive
 Difficulty: 	Hard
 Source:		https://leetcode.com/problems/first-missing-positive/#/description
 Tags: 			Array
*/

// Given an unsorted integer array, find the first missing positive integer.

// For example,
// Given [1,2,0] return 3,
// and [3,4,-1,1] return 2.

// Your algorithm should run in O(n) time and uses constant space.
#include "leetcode.hpp"
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

    	int n = nums.size();
    	for (int i = 0; i < n;) {
    		if (nums[i] > 0 && nums[i] != i + 1 && nums[i] - 1 < n && nums[i] != nums[nums[i]-1])
    			std::swap(nums[i], nums[nums[i] - 1]);
    		else
    			i++;
    	}

    	for (int i = 0; i < n; ++i)
    	{
    		if (nums[i] != i + 1)
    		{
    			return i + 1;
    		}
    	}
    	return n + 1;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {1, 2, 0};

	VERIFY_IS_EQUAL(sln.firstMissingPositive(input1), 3);
}
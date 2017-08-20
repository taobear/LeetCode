/*
 Author: 		TaoBear
 Update:		June 16, 2017
 Problem: 		Container With Most Water
 Difficulty: 	Median
 Source:		https://leetcode.com/problems/container-with-most-water/#/description
 Tags: 			Array, Two Pointer
*/


// Given a collection of distinct numbers, return all possible permutations.

// For example,
// [1,2,3] have the following permutations:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include "leetcode.hpp"

void next_permute(vector<vector<int>>& rslt, vector<int> nums)
{
	int len = nums.size();

	if (len < 2) return;

	int cur = len, j;
    	
    while (--cur > 0) {
    	if (nums[cur - 1] < nums[cur]) {
    		j = len;
    		while (--j >= cur && nums[j] <= nums[cur - 1]);
    		
    		int tmp = nums[cur - 1];
    		nums[cur - 1] = nums[j];
    		nums[j] = tmp; 

   			reverse(nums.begin() + cur, nums.end());
   			
   			rslt.push_back(nums);
   			return next_permute(rslt, nums);
   			
    	}
    }

    // reverse(nums.begin(), nums.end());
    // rslt.push_back(nums);
    // return next_permute(rslt, nums);
}

class Solution
{
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> rslt;
		next_permute(rslt, nums);
		return rslt;
	}
	
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input = {1, 2, 3};

	vector<vector<int>> target = {{1, 2, 3},
								  {1, 3, 2},
								  {2, 1, 3},
								  {2, 3, 1},
								  {3, 1, 2},
								  {3, 2, 1}};

	VERIFY_IS_EQUAL(sln.permute(input), target);
}
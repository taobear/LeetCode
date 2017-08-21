/*
 Author: 		TaoBear
 Update:		Aug 21, 2017
 Problem: 		Permutations II
 Difficulty: 	Median
 Source:		https://leetcode.com/problems/permutations-ii/description/
 Tags: 			Backtracking
*/

// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

// For example,
// [1,1,2] have the following unique permutations:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]


#include "leetcode.hpp"

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
    	vector<vector<int>> rslt;
    	
    	sort(nums.begin(), nums.end());

    	permuteRecusive(rslt, nums, 0);
    	return rslt;
	}

	void permuteRecusive(vector<vector<int>> &rslt, vector<int> nums, int begin)
	{
		if (begin == nums.size() - 1) rslt.push_back(nums);

		//sort(nums.begin() + begin, nums.end());

		// find first unique num
		for (int i = begin; i < nums.size(); ++i)
		{
			if (i != begin && nums[i] == nums[begin])
				continue;
			swap(nums[i], nums[begin]);
			permuteRecusive(rslt, nums, begin + 1);
			//swap(nums[i], nums[begin]);
		}
	}
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input = {1, 2, 3, 4, 5};
	
	sln.permuteUnique(input);

}
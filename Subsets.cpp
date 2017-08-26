/*
 Author: 		TaoBear
 Update:		Aug 24, 2017
 Problem: 		Subsets
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/subsets/description/
 Tags: 			Backtracking, Array, Bit Manipulation
*/

// Given a set of distinct integers, nums, return all possible subsets.

// Note: The solution set must not contain duplicate subsets.

// For example,
// If nums = [1,2,3], a solution is:

// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

#include "leetcode.hpp"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        vector<vector<int>> rslt;
        //rslt.push_back(vec);
        helper(rslt, vec, nums, nums.size(), 0);
        return rslt;
    }

    void helper(vector<vector<int>> &rslt, vector<int>& vec, vector<int>& nums,
    			 int n, int level) {
    	if (level >= n) {
    		rslt.push_back(vec);
    	} else {

    	// for (int i = level; i < n; ++i) {
    		helper(rslt, vec, nums, n, level + 1);

    		vec.push_back(nums[level]);
    		helper(rslt, vec, nums, n, level + 1);
    		vec.pop_back();
    	}
    	// }
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {1, 2, 3};

	vector<vector<int>> target1 = {{3},
								   {1},
								   {2},
								   {1, 2, 3}, 
								   {1, 3}, 
								   {2, 3}, 
								   {1, 2},
								   {}};

	VERIFY_IS_EQUAL(sln.subsets(input1), target1);
}
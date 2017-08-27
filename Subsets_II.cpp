/*
 Author: 		TaoBear
 Update:		Aug 26, 2017
 Problem: 		Gray Code
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/subsets-ii/description/
 Tags: 			Backtracking;
*/

// Given a collection of integers that might contain duplicates, nums, return all possible subsets.

// Note: The solution set must not contain duplicate subsets.

// For example,
// If nums = [1,2,2], a solution is:

// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

#include "leetcode.hpp"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> rslt;
        vector<int> tmp;

        int n = nums.size();
        helper(rslt, nums, tmp, n, 0);
        return rslt;
    }

    void helper(vector<vector<int>>& rslt, vector<int>& nums,
    			vector<int>& tmp, int n, int level) {
    	rslt.push_back(tmp);
    	for (int i = level; i < n; ++i) {
    		if (i == level || nums[i] != nums[i - 1]) {
    			tmp.push_back(nums[i]);
    			helper(rslt, nums, tmp, n, i + 1);
    			tmp.pop_back();
    		}
    	}
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {1, 2, 2};

	vector<vector<int>> target1 = {{2}, 
								  {1},
								  {1, 2, 2},
								  {2, 2},
								  {1, 2},
								  {}};

	VERIFY_IS_EQUAL(sln.subsetsWithDup(input1), target1);
}
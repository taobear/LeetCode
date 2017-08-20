/*
 Author: 		TaoBear
 Update:		July 8, 2017
 Problem: 		Combination Sum
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/combination-sum/#/description
 Tags: 			Array, Backtracing
*/


// Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// For example, given candidate set [2, 3, 6, 7] and target 7, 
// A solution set is: 
// [
//   [7],
//   [2, 2, 3]
// ]
#include "leetcode.hpp"


void selectKth(vector<vector<int>> &rst, vector<int>& candidates, vector<int> stk, int k, int left) {

	if (left == 0) {
		reverse(stk.begin(), stk.end());
		rst.push_back(stk);
	}

	if (left < 0 || left < candidates[0]) 
		return;

	if (candidates[k] <= left) {
		vector<int> tmp = stk;
		tmp.push_back(candidates[k]);
		selectKth(rst, candidates, tmp, k, left - candidates[k]);
	}

	if (k - 1 >= 0 && left != 0) {
		selectKth(rst, candidates, stk, k - 1, left);
	}

}

void combinationSumDFS(vector<int> &candidates, int target, vector<vector<int>>& res, vector<int>& out, int start) 
{
	if (target < 0) 
		return;
	else if (target == 0)
		res.push_back(out);
	else {
		for (int i = start; i < candidates.size(); ++i) {
			out.push_back(candidates[i]);
			combinationSumDFS(candidates, target - candidates[i], res, out, i);
			out.pop_back();
		}
	}
}

vector<vector<int>> CombinationSum(vector<int> &candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> rslt;
	std::vector<int> combination;
	combinationSumDFS(candidates, target, rslt, combination, 0);
	return rslt;
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	// int sz = candidates.size();
    	// if (!sz) return vector<vector<int>>();
    	// sort(candidates.begin(), candidates.end());

    	// std::vector<vector<int>> rslt;
    	// vector<int> stk;
    	// selectKth(rslt, candidates, stk, sz - 1, target);
    	// return rslt;
    	return ::CombinationSum(candidates, target);
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {2, 3, 6, 7};

	vector<vector<int>> result = {{7}, {2, 2, 3}};
	VERIFY_IS_EQUAL(sln.combinationSum(input1, 7), result);
}
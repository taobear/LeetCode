/*
 Author: 		TaoBear
 Update:		July 22, 2017
 Problem: 		Combination Sum II
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/combination-sum-ii/#/description
 Tags: 			Array, Backtracing
*/

// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// Each number in C may only be used once in the combination.

// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
// A solution set is: 
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]

#include "leetcode.hpp"

void combinationSumDFS(vector<vector<int>> &rslt, vector<int>& candidates, vector<int>& stk, int target, int start)
{

	if (target == 0) 
		rslt.push_back(stk);
	if (target < candidates[start] || start >= candidates.size()) 
		return;
	else {
		
		stk.push_back(candidates[start]);
		combinationSumDFS(rslt, candidates, stk, target - candidates[start], start + 1);
		stk.pop_back();

		while (start++ < candidates.size() && candidates[start] == candidates[start - 1]);
		combinationSumDFS(rslt, candidates, stk, target, start);
	}
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
		vector<vector<int>> rslt;
		std::vector<int> combination;

		combinationSumDFS(rslt, candidates, combination, target, 0);

		return rslt;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {10, 1, 2, 7, 6, 1, 5};

	vector<vector<int>> rslt = {{1, 7}, {1, 2, 5}, {2, 6}, {1, 1, 6}};

	VERIFY_IS_EQUAL(sln.combinationSum2(input1, 8), rslt);
}
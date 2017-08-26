/*
 Author: 		TaoBear
 Update:		Aug 23, 2017
 Problem: 		Combinations
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/combinations/description/
 Tags: 			Backtracking
*/

// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// For example,
// If n = 4 and k = 2, a solution is:

// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#include "leetcode.hpp"

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> rslt;
		vector<int> vec;
		helper(rslt, vec, n, 0, k);
		return rslt;

	}

	void helper(vector<vector<int>> &rslt, vector<int>& vec, int n, int i, 
				int level) {
		if (i >= n || !level) {
			if (!level)  
				rslt.push_back(vec) ;
			return;
		}

		for (int j = i; j < n; ++j) {
			vec.push_back(j + 1);
			helper(rslt, vec, n, j + 1, level - 1);
			vec.pop_back();
		}
	}
};

int main(int argc, char **argv)
{
	Solution sln;

	int n1 = 4, k1 = 2;

	vector<vector<int>> target = {{2, 4},
								  {3, 4},
								  {2, 3},
								  {1, 2},
								  {1, 3},
								  {1, 4}};

	VERIFY_IS_EQUAL(sln.combine(n1, k1), target);
}
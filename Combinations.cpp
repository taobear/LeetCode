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
		vector<int> visited(n, 0);
		vector<int> tmp;
		combineDFS(rslt, visited, n, tmp, 0, k, 0);
		return rslt;
	}

	void combineDFS(vector<vector<int>>& rslt, vector<int>& visited,
						int n, vector<int>& vec, int i, int k, int level) 
	{
		if (i > k) 
			rslt.push_back(vec);

		for (int j = 0; j < n; ++j) {
			if (visited[j] || level >= j)
				continue;

			visited[j] = 1;
			vec.push_back(j + 1);
			combineDFS(rslt, visited, n, vec, j + 1, k, j);
			visited[j] = 0;
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
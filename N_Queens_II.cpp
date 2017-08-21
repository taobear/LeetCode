/*
 Author: 		TaoBear
 Update:		Aug 21, 2017
 Problem: 		N-Queens II
 Difficulty: 	Hard
 Source:		https://leetcode.com/problems/n-queens-ii/description/
 Tags: 			Backtracking
*/

// Follow up for N-Queens problem.

// Now, instead outputting board configurations, return the total number of distinct solutions.

#include "leetcode.hpp"

class Solution {
public:
	int totalNQueens(int n) {
		if (n < 1) return 0;

		vector<int> recorder(n, 0);
		return helper(recorder, n, 0);
	}

	int helper(vector<int> recorder, int n, int i) {
		if (i >= n)
			return 1;
		
		int rslt = 0;
		for (int j = 0; j < n; ++j) {
			if (!isVaild(recorder, i, j))
				continue;

			recorder[i] = j;
			
			rslt += helper(recorder, n, i + 1);

			recorder[i] = 0;
		}
		return rslt;
	}

	bool isVaild(vector<int> &recorder, int i, int j) {
		for (int k = 0; k < i; ++k) {
			if (recorder[k] == j || abs(recorder[k] - j) == abs(k - i))
				return false;
		}
		return true;
	}
};

int main(int argc, char **argv)
{
	Solution sln;

	int input1 = 10;

	int target1 = 724;

	VERIFY_IS_EQUAL(sln.totalNQueens(input1), target1);
}
/*
 Author: 		TaoBear
 Update:		Aug 21, 2017
 Problem: 		N-Queens
 Difficulty: 	Hard
 Source:		https://leetcode.com/problems/n-queens/description/
 Tags: 			Backtracking
*/

// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



// Given an integer n, return all distinct solutions to the n-queens puzzle.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

// For example,
// There exist two distinct solutions to the 4-queens puzzle:

// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]


#include "leetcode.hpp"

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> rslt;
		vector<int> recorder(n, 0);
		vector<string> str(n, string(n, '.'));
		helper(rslt, str, recorder, n, 0);

		return rslt;
	}

	void helper(vector<vector<string>> &rslt, vector<string> &str, 
				vector<int> &recorder, int n, int i)
	{
		if (i == n)
			rslt.push_back(str);

		//str[i].assign(n, '.');

		for (int j = 0; j < n; ++j) {
			if (!isVaild(recorder, i, j))
				continue;

			recorder[i] = j;
			str[i][j] = 'Q';
			helper(rslt, str, recorder, n, i + 1);
			str[i][j] = '.';
			recorder[i] = 0;
		}
	}

	bool isVaild(vector<int> &recorder, int i, int j) {
		for (int k = 0; k < i; ++k) {
			if (recorder[k] == j || abs(recorder[k] - j) == abs(i - k))
				return false;
		}
		return true;
	}
};

int main(int argc, char **argv)
{

}
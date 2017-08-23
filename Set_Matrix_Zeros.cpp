/*
 Author: 		TaoBear
 Update:		Aug 23, 2017
 Problem: 		Set Matrix Zeros
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/set-matrix-zeroes/description/
 Tags: 			Array
*/


// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

#include "leetcode.hpp"

void setZeroes1(vector<vector<int>>& matrix)
{
	int m = matrix.size();
	if (!m) return ;
	int n = matrix[0].size();
	if (!n) return;

	vector<int> rowRec(m, 0), colRec(n, 0);

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!matrix[i][j]) {
				rowRec[i] = 1;
				colRec[j] = 1;
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		if (rowRec[i])
			continue;
		for (int j = 0; j < n; ++j)
			matrix[i][j] = 0;
	}

	for (int j = 0; j < n; ++j) {
		if (colRec[j])
			continue;

		for (int i = 0; i < m; ++i)
			matrix[i][j] = 0;
	}

}

void setZeroes2(vector<vector<int>>& matrix)
{
	if (matrix.empty() || matrix[0].empty())
		return;

	int m = matrix.size();
	int n = matrix[0].size();

	bool rowFlag = false, colFlag = false;

	for (int i = 0; i < m; ++i) {
		if (!matrix[i][0])
			rowFlag = true;
	}
	for (int j = 0; j < n; ++j) {
		if (!matrix[0][j])
			colFlag = true;
	}

	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			if (!matrix[i][j]) {
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	for (int i = 1; i < m; ++i) {
		if (!matrix[i][0]) {
			for (int j = 1; j < n; ++j) {
				matrix[i][j] = 0;
			}
		}
	}

	for (int j = 1; j < n; ++j) {
		if (!matrix[0][j]) {
			for (int i = 1; i < m; ++i) {
				matrix[i][j] = 0;
			}
		}
	}

	if (rowFlag) {
		for (int i = 0; i < m; ++i) {
			matrix[i][0] = 0;
		}
	}
	if (colFlag) {
		for (int j = 0; j < n; ++j) {
			matrix[0][j] = 0;
		}
	}
}

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
    }
};

int main(int argc, char **argv)
{

}
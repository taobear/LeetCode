/*
 Author: 		TaoBear
 Update:		Aug 21, 2017
 Problem: 		Rotate Image
 Difficulty: 	Median
 Source:		https://leetcode.com/problems/rotate-image/description/
 Tags: 			Array
*/

// You are given an n x n 2D matrix representing an image.

// Rotate the image by 90 degrees (clockwise).

// Follow up:
// Could you do this in-place?

#include "leetcode.hpp"


class Solution {
public:
	void rotate(vector<vector<int>> &matrix) {
		 //int row = matrix.size();
		int row = matrix.size(), col = row;

		for (int i = 0; i < row; ++i)
			for (int j = i + 1; j < col; ++j)
				swap(matrix[i][j], matrix[j][i]);

		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col / 2; ++j)
				swap(matrix[i][j], matrix[i][col - j - 1]);

	}
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<vector<int>> input1 = {{1, 2, 3},
								 {4, 5, 6},
								 {7, 8, 9}};

	vector<vector<int>> target1 = {{7, 4, 1},
								  {8, 5, 2},
								  {9, 6, 3}};

	vector<vector<int>> input2 = {{1, 2},
								  {3, 4}};

	vector<vector<int>> target2 = {{3, 1},
								   {4, 2}};

  	sln.rotate(input1);

  	sln.rotate(input2);

  	VERIFY_IS_EQUAL(input1, target1);
  	VERIFY_IS_EQUAL(input2, target2);
}
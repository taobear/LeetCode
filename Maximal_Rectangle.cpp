/*
 Author: 		TaoBear
 Update:		Aug 26, 2017
 Problem: 		Maximal Rectangle
 Difficulty: 	Hard
 Source:		https://leetcode.com/problems/maximal-rectangle/description/
 Tags: 			Array, Hash Table, Stack, Dynamic Programming
*/

// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// For example, given the following matrix:

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
// Return 6.

#include "leetcode.hpp"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<vector<char>> matrix1 = {{'1', '0', '1', '0', '0'},
									{'1', '0', '1', '1', '1'},
									{'1', '1', '1', '1', '1'},
								    {'1', '0', '0', '1', '0'}};

	int target1 = 6;

	VERIFY_IS_EQUAL(sln.maximalRectangle(matrix1), target1);
}
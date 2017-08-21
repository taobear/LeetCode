/*
 Author: 		TaoBear
 Update:		Aug 21, 2017
 Problem: 		Spiral Matrix
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/spiral-matrix/description/
 Tags: 			Array
*/

// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

// For example,
// Given the following matrix:

// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].

#include "leetcode.hpp"

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int row = matrix.size();
        if (row < 1) 
        	return vector<int>{};
        int col = matrix[0].size();

        vector<int> rslt; 

        int top = 0, lef = 0, rig = col - 1, bot = row - 1;

        //int i = 0, j = 0;

        while (top <= bot && lef <= rig) {
        	for (int j = lef; j <= rig; j++)
        		rslt.push_back(matrix[top][j]);

        	top++;

        	for (int i = top; i <= bot; i++)
        		rslt.push_back(matrix[i][rig]);
        	rig--;

        	if (top <= bot) {
        		for (int j = rig; j >= lef; j--)
        			rslt.push_back(matrix[bot][j]);
        	}
        	bot--;

        	if (lef <= rig) {
        		for (int i = bot; i >= top; i--)
        			rslt.push_back(matrix[i][lef]);
        	}
        	lef++;
        }

        return rslt;

	}

};

int main(int argc, char **argv)
{
	Solution sln;

	vector<vector<int>> input1 = {{1, 2, 3},
								  {4, 5, 6},
								  {7, 8, 9}};
	vector<int> target1 = {1, 2, 3, 6, 9, 8, 7, 4, 5};

	VERIFY_IS_EQUAL(sln.spiralOrder(input1), target1);
}
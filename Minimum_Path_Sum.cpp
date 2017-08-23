/*
 Author: 		TaoBear
 Update:		Aug 23, 2017
 Problem: 		Minimum Path Sum
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/minimum-path-sum/description/
 Tags: 			Array, Dynamic Programming
*/

// Given a m x n grid filled with non-negative numbers, 
// find a path from top left to bottom right which minimizes the sum
// of all numbers along its path.

// Note: You can only move either down or right at any point in time.

#include "leetcode.hpp"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	int row = grid.size();
    	if (!row) return 0;
    	int col = grid[0].size();
    	if (!col) return 0;

    	vector<int> dpRow(col, 0);
    	dpRow[0] = grid[0][0];

    	for (int j = 1; j < col; ++j) {
    		dpRow[j] = grid[0][j] + dpRow[j - 1];
    	}
    	
    	for (int i = 1; i < row; ++i) {
    		for (int j = 0; j < col; ++j) {
    			if (j == 0) {
    				dpRow[j] += grid[i][0];
    			} else {
    				dpRow[j] = grid[i][j] + min(dpRow[j], dpRow[j - 1]);
    			}
    		}
    	}

    	return dpRow[col - 1]; 
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	
}
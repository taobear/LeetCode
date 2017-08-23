/*
 Author: 		TaoBear
 Update:		Aug 23, 2017
 Problem: 		Unique Paths II
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/unique-paths-ii/description/
 Tags: 			Array, Dynamic Programming
*/

// Follow up for "Unique Paths":

// Now consider if some obstacles are added to the grids. How many unique paths would there be?

// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// For example,
// There is one obstacle in the middle of a 3x3 grid as illustrated below.

// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// The total number of unique paths is 2.

#include "leetcode.hpp"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m < 1) return 0;
        int n = obstacleGrid[0].size();
        if (n < 1) return 0;

        vector<int> dpRow(n);

        dpRow[0] = obstacleGrid[0][0] ? 0 : 1;

        for (int j = 1; j < n; ++j)
        	dpRow[j] = obstacleGrid[0][j] ? 0 : dpRow[j - 1];

        for (int i = 1; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (obstacleGrid[i][j]) {
        			dpRow[j] = 0;
        		} else if (j == 0){
        		
        		} else {
        			dpRow[j] = dpRow[j - 1] + dpRow[j];
        		}
        	}
        }

        return dpRow[n - 1];
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<vector<int>> input1 = {{0, 0, 0},
								  {0, 1, 0},
								  {0, 0, 0}};

	int target1 = 2;

	VERIFY_IS_EQUAL(sln.uniquePathsWithObstacles(input1), target1);
}
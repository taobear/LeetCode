/*
 Author: 		TaoBear
 Update:		Aug 30, 2017
 Problem: 		Triangle
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/triangle/description/
 Tags: 			Array, Dynamic Programming
*/

// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

// For example, given the following triangle
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

// Note:
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

#include "leetcode.hpp"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    	int numRows = triangle.size();
    	if (numRows < 1) return 0;
        vector<int> dp(numRows);

        dp[0] = triangle[0][0];

        for (int row = 1; row < numRows; ++row) {
        	for (int col = row; col >= 0; --col) {
        		int left = col - 1 < 0 ? INT_MAX : dp[col - 1];
        		int right = col >= row ? INT_MAX : dp[col];
        		dp[col] = min(left, right) + triangle[row][col];
        	}
        }
        int minVal = INT_MAX;
        for (int i = 0; i < numRows; ++i) {
        	if (minVal > dp[i])
        		minVal = dp[i];
        }

        return minVal;
    }

    int minimum2(vector<vector<int>>& triangle) {
    	int numRows = triangle.size();

    	vector<int> minlen(triangle.back());
    	for (int layer = n - 1; i <= layer; --layer) {
    		for (int i = 0; i <= layer; ++i) {
    			minlen[i] = min(minlen[i], minlen[i + 1]) + triangle[layer][i];
    		}
    	}
    	return minlen[0];
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<vector<int>> input1 = {{2},
								  {3, 4},
								  {6, 5, 7},
								  {4, 1, 8, 3}};

	int target1 = 11;

	VERIFY_IS_EQAUL(sln.minimumTotal(input1), target1);
}
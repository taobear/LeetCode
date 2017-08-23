/*
 Author: 		TaoBear
 Update:		Aug 23, 2017
 Problem: 		Search a 2D Matrix
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/search-a-2d-matrix/description/
 Tags: 			Array, Binary Search
*/

// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// For example,

// Consider the following matrix:

// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// Given target = 3, return true.

#include "leetcode.hpp"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
        	return false;
        int m = matrix.size();
        int n = matrix[0].size();

        int num = m * n;
        int i = 0, j = num - 1;

        while (i <= j) {
        	int mid = i + (j - i) / 2;
        	int val = matrix[mid / n][mid % n];
        	if (val < target) 
        		i = mid + 1;
        	else if (val > target)
        		j = mid - 1;
        	else
        		return true;
        }
        return false;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<vector<int>> matrix = {{1, 3, 5, 7},
								  {10, 11, 16, 20},
								  {23, 30, 34, 50}};

	VERIFY_IS_EQUAL(sln.searchMatrix(matrix, 3), true);
}
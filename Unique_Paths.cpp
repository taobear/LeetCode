/*
 Author: 		TaoBear
 Update:		Aug 23, 2017
 Problem: 		Unique Paths
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/unique-paths/description/
 Tags: 			Array, Dynamic Programming
*/

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?
#include "leetcode.hpp"

class Solution {
public:
    int uniquePaths(int m, int n) {
        //vector<int> dpRow(m, 1);
        if (!n || !m) return 0;
        vector<int> dpCol(n, 1);

        for (int row = 1; row < m; ++row) {
        	for (int col = 1; col < n; ++col) {
        		dpCol[col] = dpCol[col - 1] + dpCol[col];
        	}
        }
        return dpCol[n - 1];
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	int m1 = 3, n1 = 7;

	int target1 = 28;

	VERIFY_IS_EQUAL(sln.uniquePaths(m1, n1), target1);
}

/*
 Author: 		TaoBear
 Update:		Aug 21, 2017
 Problem: 		Spiral Matrix II
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/spiral-matrix-ii/description/
 Tags: 			Array
*/

// Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

// For example,
// Given n = 3,

// You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]
#include "leetcode.hpp"

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		int row = n, col = n;
        //int col = matrix[0].size();

        vector<vector<int>> rslt(row, vector<int>(col)); 

        int top = 0, lef = 0, rig = col - 1, bot = row - 1;

        //int i = 0, j = 0;
        int cnt = 0;
        while (top <= bot && lef <= rig) {
        	for (int j = lef; j <= rig; j++)
        		rslt[top][j] = ++cnt;
        		//rslt.push_back(matrix[top][j]);

        	top++;

        	for (int i = top; i <= bot; i++)
        		rslt[i][rig] = ++cnt;
        		//rslt.push_back(matrix[i][rig]);
        	rig--;

        	if (top <= bot) {
        		for (int j = rig; j >= lef; j--)
        			rslt[bot][j] = ++cnt;
        			//rslt.push_back(matrix[bot][j]);
        	}
        	bot--;

        	if (lef <= rig) {
        		for (int i = bot; i >= top; i--)
        			rslt[i][lef] = ++cnt;
        			//rslt.push_back(matrix[i][lef]);
        	}
        	lef++;
        }

        return rslt;
	}
};

int main(int argc, char **argv)
{

}
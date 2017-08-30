/*
 Author: 		TaoBear
 Update:		Aug 30, 2017
 Problem: 		Pascal's Triangle
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/pascals-triangle/description/
 Tags: 			Array
*/

// Given numRows, generate the first numRows of Pascal's triangle.

// For example, given numRows = 5,
// Return

// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
#include "leetcode.hpp"


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> tmp{0, 1};
        vector<vector<int>> rslt;
        while (numRows--) {
        	rslt.push_back(vector<int>(tmp.begin() + 1, tmp.end()));
        	tmp.push_back(0);
        	for (int i = tmp.size() - 1; i >= 1; --i)
        		tmp[i] = tmp[i - 1] + tmp[i];
        }
        return rslt;
    }

    vector<vector<int>> generate(int numRows) {
    	vector<vector<int>> r(numRows);

    	for (int i = 0; i < numRows; ++i) {
    		r[i].resize(i + 1);
    		r[i][0] = r[i][i] = 1;

    		for (int j = 1; j < i; ++i) {
    			r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
    		}
    	}
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	int input1 = 5;

	vector<vector<int>> target1 = {{1},
                                  {1, 1},
                                  {1, 2, 1},
                                  {1, 3, 3, 1},
                                  {1, 4, 6, 4, 1}};
    VERIFY_IS_EQUAL(sln.generate(input1), target1);
}

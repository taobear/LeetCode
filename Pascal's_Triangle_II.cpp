/*
 Author: 		TaoBear
 Update:		Aug 30, 2017
 Problem: 		Pascal's Triangle II
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/pascals-triangle-ii/description/
 Tags: 			Array
*/

// Given an index k, return the kth row of the Pascal's triangle.

// For example, given k = 3,
// Return [1,3,3,1].

// Note:
// Could you optimize your algorithm to use only O(k) extra space?

#include "leetcode.hpp"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rslt(rowIndex + 1);
        rslt[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
        	// rslt[] = 1;
        	for (int j = i; j > 0; --j)
        		rslt[j] = rslt[j - 1] + rslt[j];
        }

        return rslt;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	int input1 = 3;

	vector<int> target1 = {1, 3, 3, 1};

	VERIFY_IS_EQUAL(sln.getRow(input1), target1);
}
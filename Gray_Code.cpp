/*
 Author: 		TaoBear
 Update:		Aug 26, 2017
 Problem: 		Gray Code
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/gray-code/description/
 Tags: 			Backtracking;
*/

// The gray code is a binary numeral system where two successive values differ in only one bit.

// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
// Note:
// For a given n, a gray code sequence is not uniquely defined.

// For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

// For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

#include "leetcode.hpp"

class Solution {
public:
    vector<int> grayCode(int n) {
    	// int all = pow(2, n);

    	// vector<int> visited(all, 0);
    	// vector<int> rslt;

    	// rslt.push_back(0);
    	// visited[0] = 1;
    	// helper(rslt, visited, all, n);
    	// return rslt;
    	int num = 1 << n;
    	vector<int> rslt;
    	rslt.reserve(num);

    	for (int i = 0; i < num; ++i) {
    		rslt.push_back(i ^ (i >> 1));
    	}
    	return rslt;
    }

    // void helper(vector<int>& rslt, vector<int>& visited, int n, int i) {
    // 	for (int j = i + 1; j < n; ++j) {
    // 		if (!visited[j] && !(((j ^ i) - 1) & (j ^ i))) {
    // 			visited[j] = 1;
    // 			rslt.push_back(j);
    // 			return helper(rslt, visited, n, j);
    // 		}
    // 	}

    // 	for (int j = 1; j < i; ++j) {
    // 		if (!visited[j] && !(((j ^ i) - 1) & (j ^ i))) {
    // 			visited[j] = 1;
    // 			rslt.push_back(j);
    // 			return helper(rslt, visited, n, j);
    // 		}
    // 	}
    // }
};

int main(int argc, char **argv)
{
	Solution sln;

	int input1 = 2;

	vector<int> target1 = {0, 1, 3, 2};

	VERIFY_IS_EQUAL(sln.grayCode(input1), target1);
}
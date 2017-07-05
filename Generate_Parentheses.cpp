/*
 Author: 		TaoBear
 Update:		July 3, 2017
 Problem: 		Generate Parentheses
 Difficulty: 	Median
 Source:		https://leetcode.com/problems/generate-parentheses/#/description
 Tags: 			Backtracking, String
*/

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

// 选择，限制，结束条件

// 选择： 加左括号， 加右括号

// 限制： 1）左括号用完
// 		  2）右括号和左括号一样多

// 结束条件： 左右括号都用完

#include "leetcode.hpp"

void recurseParenth(vector<string>& rslt, string tmp, int lp, int rp)
{

	if (!lp && !rp) {
		rslt.push_back(tmp);
		return;
	}

	if (lp)
		recurseParenth(rslt, tmp + '(', lp - 1, rp);

	if (lp < rp)
		recurseParenth(rslt, tmp + ')', lp, rp - 1);

}

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> rslt;

		recurseParenth(rslt, "", n, n);
		return rslt;
    }
};

int main(int argc, char **argv) 
{
	Solution sln;

	int input1 = 3;

	vector<string> expect = {"((()))", "(()())", "(())()", "()(())", "()()()"};

	VERIFY_IS_EQUAL(sln.generateParenthesis(input1), expect);
}
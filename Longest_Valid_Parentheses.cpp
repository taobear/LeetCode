/*
 Author: 		TaoBear
 Update:		July 5, 2017
 Problem: 		Longest Valid Parentheses
 Difficulty: 	Hard
 Source:		https://leetcode.com/problems/longest-valid-parentheses/#/description
 Tags: 			String, Dynamic Programming
*/

// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

// For "(()", the longest valid parentheses substring is "()", which has length = 2.

// Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
#include "leetcode.hpp"
#include <stack>

int longestValidParentheses1(string s) 
{
	stack<int> mem;
	int len = s.size(), rslt = 0;
	int start = 0;

	for (int i = 0; i < len; ++i) {
		if (s[i] == '(')
		{
			mem.push(i);
		}
		else if (s[i] == ')' && !mem.empty())
		{
			mem.pop();
			rslt = mem.empty() ? max(rslt, i - start + 1) : max(rslt, i - mem.top());
		}
		else
		{
			start = i + 1;
		}
	}
	return rslt;

}

int longestValidParentheses2(string s) 
{

}

class Solution {
public:
    int longestValidParentheses(string s) {
        return longestValidParentheses1(s);
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	string input1 = "(()";
	string input2 = ")()())";
	string input3 = "()(()";

	int rslt1 = 2;
	int rslt2 = 4;
	int rslt3 = 2;

	VERIFY_IS_EQUAL(sln.longestValidParentheses(input1), rslt1);
	VERIFY_IS_EQUAL(sln.longestValidParentheses(input2), rslt2);
	VERIFY_IS_EQUAL(sln.longestValidParentheses(input3), rslt3);
}
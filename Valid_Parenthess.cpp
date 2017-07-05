/*
 Author: 		TaoBear
 Update:		July 2, 2017
 Problem: 		Valid Parenthess
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/valid-parentheses/#/description
 Tags: 			Stack, String
*/

// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
#include "leetcode.hpp"
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> c_stk;
        for (auto & c : s) {
        	if (c_stk.empty())
        		c_stk.push(c);
        	else if (c == ')' && c_stk.top() == '(')
        		c_stk.pop();
        	else if (c == ']' && c_stk.top() == '[')
        		c_stk.pop();
        	else if (c == '}' && c_stk.top() == '{')
        		c_stk.pop();
        	else
        		c_stk.push(c);
        }

        return c_stk.empty() ? true : false;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	string input1 = "()";
	string input2 = "()[]{}";
	string input3 = "([)]";

	bool result1 = sln.isValid(input1);
	bool result2 = sln.isValid(input2);
	bool result3 = sln.isValid(input3);

	VERIFY_IS_EQUAL(result1, true);
	VERIFY_IS_EQUAL(result2, true);
	VERIFY_IS_EQUAL(result3, false);
}
/*
 Author: 		TaoBear
 Update:		August 14, 2017
 Problem: 		Regular Expression Matching
 Difficulty: 	Hard
 Source:		https://leetcode.com/problems/regular-expression-matching/description/
 Tags: 			Dynamic Programing, Backtracking, String
*/
// Implement regular expression matching with support for '.' and '*'.

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.

// The matching should cover the entire input string (not partial).

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") ? false
// isMatch("aa","aa") ? true
// isMatch("aaa","aa") ? false
// isMatch("aa", "a*") ? true
// isMatch("aa", ".*") ? true
// isMatch("ab", ".*") ? true
// isMatch("aab", "c*a*b") ? true
#include "leetcode.hpp"

// 特殊情况 p 字符串或者 s 字符串结束
//	(1) s 字符串结束，p 也结束或者间隔 '*'，否则无法匹配
// （2）s 字符串未结束，p 字符串结束，则无法匹配
// *s 与 *p 字符串均未结束
//  (1) p+1 的字符不为 '*', 比较 s 字符与 p 字符，若相等则递归到 s+1 字符串与 p+1 字符的比较，否则无法匹配
//  (2) p+1 字符为 '*'，则 p 可以匹配 s 字符串中从 0 开始人一多等于 p 的字符，然后递归到 s + i + 1 字符串 与 p + 2 字符串比较

bool isMatch(string s, string p)
{
	if (p.empty())
		return s.empty();
	if (p.size() == 1)
		return s.size() == 1 && (s[0] == p[0] || p[0] == '.');
	if (p[1] != '*') {
		if (s.empty()) return false;
		return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
	}

	while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
		if (isMatch(s, p.substr(2))) return true;
		s = s.substr(1);
	}

	return isMatch(s, p.substr(2));
}


class Solution 
{
public:
	bool isMatch(string s, string p) {

	}
};


int main(int argc, char **argv)
{
	Solution sln;

	string s1 = "aa", p1 = "a";
	string s2 = "aab", p2 = "c*a*b";

	VERIFY_IS_EQUAL(sln.isMatch(s1, p1), false);
	VERIFY_IS_EQUAL(sln.isMatch(s2, p2), true);	
}
/*
 Author: 		TaoBear
 Update:		June 16, 2017
 Problem: 		Wildcard Matching
 Difficulty: 	Hard
 Source:		https://leetcode.com/problems/wildcard-matching/description/
 Tags: 			Dynamic Programing, Backtracking, Greedy, String
*/


// Implement wildcard pattern matching with support for '?' and '*'.

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).

// The matching should cover the entire input string (not partial).

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") ? false
// isMatch("aa","aa") ? true
// isMatch("aaa","aa") ? false
// isMatch("aa", "*") ? true
// isMatch("aa", "a*") ? true
// isMatch("ab", "?*") ? true
// isMatch("aab", "c*a*b") ? false

/*
 * 1. 假设碰到 * 号时 s 串的位置是 l, p 串的位置是 r，则将 r + 1 作为 * 号后续进行比较的起点
 * 2. 从 l 开始与 r + 1 位置的元素进行比较，
 *					* 如果相同，按照常规匹配的方式往后面继续比
 * 					* 如果不同，s -> l + 1, p -> r + 1
 * 3. 没有 * 号，正常的字符串比较不匹配情况
 * 4. p 串中间有多个 * 号，
 */
#include "leetcode.hpp"

bool isMatch1(string str, string pat) 
{
	int s = 0, p = 0, match = 0, starIdx = -1;
	while (s < str.size()) {
		if (p < pat.size() && (pat[p] == '?' || str[s] == pat[p])) {
			s++;
			p++;
		}
		else if (p < pat.size() && pat[p] == '*') {
			starIdx = p;
			match = s;
			p++;
		}
		else if (starIdx != -1) {
			p = starIdx + 1;
			match++;
			s = match;
		}
		else 
			return false;
	}

	while (p < pat.size() && pat[p] == '*')
		p++;

	return p == pat.size();
}

bool isMatch2(string str, string pat, int l, int r)
{
	if (r == pat.size()) 
		return l == s.size();

	if (pat[r] == '*') {
		while (r < pat.size() && pat[r] == '*')
			r++;

		while (l < s.size()) {
			if (isMatch2(str, pat, l, r))
				return true;
			l++;
		}
		return isMatch2(str, pat, l, r);
	} else if (l < str.size() && (pat[r] = '?' || str[l] = pat[r]))
		return isMatch2(str, pat, l + 1, r + 1);
	return false;

}


class Solution {
public:
	bool isMatch(string s, string p) {

	}
};

int main(int argc, char** argv)
{

}
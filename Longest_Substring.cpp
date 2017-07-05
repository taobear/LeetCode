/*
 Author: 		TaoBear
 Update:		June 06, 2017
 Problem: 		Longest Substring Without Repeating Characters
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description
 Tags: 			Hash Table, Two pointers, string
*/

// Given a string, find the length of the longest substring without repeating characters.

// Examples:

// Given "abcabcbb", the answer is "abc", which the length is 3.

// Given "bbbbb", the answer is "b", with the length of 1.

// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


#include "leetcode.hpp"

bool allUnique(string s, int start, int end)
{
	set<char> sc;
	for (int i = start; i < end; i++)
	{
		if (sc.find(s[i]) != sc.end())
			return false;
		sc.insert(s[i]);
	}
	return true;
}

int lengthOfLongestSubstring1(string s)
{
	int n = s.size();
	int rst = 0;

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (allUnique(s, i, j)) rst = max(rst, j - i);
	return rst;
}


int lengthOfLongestSubstring2(string s)
{
	int n = s.size();
	unordered_set<char> unset_char;
	int rst = 0, i = 0, j = 0;
	while (i < n && j < n) {
		if (unset_char.find(s[j]) == unset_char.end())
		{
			rst = max(rst, j - i + 1);
			unset_char.insert(s[j++]);
		}
		else {
			//rst = max(rst, j - i);
			unset_char.erase(s[i++]);
		}

	}
	return rst;
}


int lengthOfLongstSubstring3(string s)
{
	int n = s.size();
	map<char, size_t> map_cs;
	size_t rst = 0;
	size_t i = 0, j = 0;
	for (; j < n; ++j) {
		if (map_cs.find(s[j]) != map_cs.end()) {
			i = max(i, map_cs[s[j]] + 1);
		}
		rst = max(rst, j - i + 1);
		map_cs[s[j]] = j;
	}
	return rst;
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	//return lengthOfLongestSubstring1(s);
    	//return lengthOfLongestSubstring2(s);
    	return lengthOfLongstSubstring3(s);
    }
};




int main(int argc, char **argv)
{
	string input1 = "abcabcbb";
	string input2 = "bbbbb";
	string input3 = "pwwkew";
	string input4 = "tmmzuxt";

	Solution sln;

	int rst1 = sln.lengthOfLongestSubstring(input1);
	int rst2 = sln.lengthOfLongestSubstring(input2);
	int rst3 = sln.lengthOfLongestSubstring(input3);
	int rst4 = sln.lengthOfLongestSubstring(input4);

	VERIFY_IS_EQUAL(rst1, 3);
	VERIFY_IS_EQUAL(rst2, 1);
	VERIFY_IS_EQUAL(rst3, 3);
	VERIFY_IS_EQUAL(rst4, 5);

	VERIFY_REPORT();
}
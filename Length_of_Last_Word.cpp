/*
 Author: 		TaoBear
 Update:		Aug 21, 2017
 Problem: 		Length of Last Word
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/length-of-last-word/description/
 Tags: 			string
*/

// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

// If the last word does not exist, return 0.

// Note: A word is defined as a character sequence consists of non-space characters only.

// For example, 
// Given s = "Hello World",
// return 5.
#include "leetcode.hpp"

class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = s.size();
		int ans = 0;
		bool flag = false;
		for (int i = len - 1; i >= 0; --i)
		{
			if (flag && s[i] == ' ')
				break;

			if (s[i] != ' ') {
				ans++;
				flag = true;
			}
		}

		return ans;
	}
};

int main(int argc, char **argv)
{
	Solution sln;

	string input = "Hello World";
	int    target = 5;

	VERIFY_IS_EQUAL(sln.lengthOfLastWord(input), target);
}
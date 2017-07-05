/*
 Author: 		TaoBear
 Update:		June 10, 2017
 Problem: 		Median of Two Sorted Arrays
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/median-of-two-sorted-arrays/#/description
 Tags: 			string
*/


// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// Example:

// Input: "babad"

// Output: "bab"

// Note: "aba" is also a valid answer.
// Example:

// Input: "cbbd"

// Output: "bb"

#include "leetcode.hpp"

string longestPalindrome1(string s)
{
	if (s.size() == 0)	return "";
	if (s.size() == 1)	return s;

	vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
	for (int i = 0; i < s.size(); ++i)
		dp[i][i] = true;

	for (int i = 0; i < s.size() - 1; ++i)
	{
		dp[i][i + 1] = true;
		dp[i + 1][i] = true;
	}

	int longestbeg = 0, maxLen = 1;

	for (int j = 0; j < s.size(); ++j)
	{
		for (int i = j - 1; i >= 0; --i)
		{
			if (dp[i + 1][j - 1] && s[i] == s[j])
			{
				dp[i][j] = true;
				if (j - i + 1 > maxLen)
				{
					longestbeg = i;
					maxLen = j - i + 1;
				}
			}
			else
				dp[i][j] = false;
		}
	}

	return s.substr(longestbeg, maxLen);


}

string expandAroundCenter(string s, int c1, int c2)
{
	int l = c1, r = c2;
	int n = s.size();

	while (l >= 0 && r < n && s[l] == s[r])
	{
		l--;
		r++;
	}
	return s.substr(l + 1, r - l - 1);
}

string longestPalindrome2(string s) 
{
	int n = s.size();

	if (n == 0) return "";
	string lstr = s.substr(0, 1);

	for (int i = 0; i < n - 1; ++i) {
		string str_odd = expandAroundCenter(s, i, i);
		if (str_odd.size() > lstr.size())
			lstr = str_odd;

		string str_even = expandAroundCenter(s, i, i + 1);
		if (str_even.size() > lstr.size())
			lstr = str_even;
	}
	return lstr;
}

string Manacher(string s)
{
	string t = "$#";
	for (int i = 0; i < s.size(); ++i)
	{
		t += s[i];
		t += "#";
	}

	vector<int> p(t.size(), 0);
	int mx = 0, id = 0, resLen = 0, resCenter = 0;
    for (int i = 1; i < t.size(); ++i) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (t[i + p[i]] == t[i - p[i]]) ++p[i];
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        if (resLen < p[i]) {
            resLen = p[i];
            resCenter = i;
        }
    }
    return s.substr((resCenter - resLen) / 2, resLen - 1);
}

string longestPalindrome3(string s)
{
	return Manacher(s);
}

class Solution {
public:
	string longestPalindrome(string s) {
		// return longestPalindrome1(s);
		return longestPalindrome2(s);
		// return longestPalindrome3(s);
	}
};


int main(int argc, char **argv)
{
	string input1 = "babad";
	string input2 = "cbbd";
	string input3 = "abcba";

	Solution sln;
	string result1 = sln.longestPalindrome(input1);
	string result2 = sln.longestPalindrome(input2);
	string result3 = sln.longestPalindrome(input3);
	
	VERIFY_IS_EQUAL(result1, "bab");
	VERIFY_IS_EQUAL(result2, "bb");
	VERIFY_IS_EQUAL(result3, "abcba");

	VERIFY_REPORT();
}
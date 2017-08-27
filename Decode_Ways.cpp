/*
 Author: 		TaoBear
 Update:		Aug 26, 2017
 Problem: 		Decode Ways
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/decode-ways/description/
 Tags: 			Dynamic Programming, String
*/


// A message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of ways to decode it.

// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

// The number of ways decoding "12" is 2.

#include "leetcode.hpp"

class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if (len < 1)
        	return len;
        if (s[0] == '0')
     		return 0; 

        int prev = 1, cur = 1;
        //int ans = 0;

        for (int i = 1; i < len; ++i) {
        	if (s[i] == '0') {
        		if (s[i - 1] > '2' || s[i - 1] == '0')
        			return 0;
        		else {
        			swap(cur, prev);
        		}
        	}
        	else if (s[i - 1] == '1'
        				|| (s[i - 1] == '2' && s[i] <= '6')) {
        		int tmp = cur;
        		cur = cur + prev;
        		prev = tmp;
        	} else {
        		prev = cur;
        	}

        }

        return cur;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	string input1 = "12";
	string input2 = "10";

	int target1 = 2;
	int target2 = 1;

	VERIFY_IS_EQUAL(sln.numDecodings(input1), target1);
	VERIFY_IS_EQUAL(sln.numDecodings(input2), target2);
}


/*
 Author: 		TaoBear
 Update:		July 1, 2017
 Problem: 		Integer to Roman
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/integer-to-roman/#/description
 Tags: 			string
*/

// Given an integer, convert it to a roman numeral.

// Input is guaranteed to be within the range from 1 to 3999.

#include "leetcode.hpp"

class Solution {
public:
	string intToRoman(int num) {
		const char* c[4][10] = {
			{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
			{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
			{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
			{"", "M", "MM", "MMM"}
		};

		string roman;
		roman += c[3][num / 1000];
		roman += c[2][num / 100 % 10];
		roman += c[1][num / 10 % 10];
		roman += c[0][num % 10];

		return roman;
	}
};

int main(int argc, char **argv)
{
	int input1 = 1;
	int input2 = 11;
	int input3 = 111;

	Solution sln;
	string rst1 = sln.intToRoman(input1);
	string rst2 = sln.intToRoman(input2);
	string rst3 = sln.intToRoman(input3);

	VERIFY_IS_EQUAL(rst1, "I");
	VERIFY_IS_EQUAL(rst2, "XI");
	VERIFY_IS_EQUAL(rst3, "CXI");
}
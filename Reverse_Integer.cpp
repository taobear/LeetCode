/*
 Author: 		TaoBear
 Update:		June 16, 2017
 Problem: 		String to Integer (atoi)
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/string-to-integer-atoi/#/description
 Tags: 			string, Math
*/

// Reverse digits of an integer.

// Example1: x = 123, return 321
// Example2: x = -123, return -321


// click to show spoilers.
// Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

// If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

// Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

// For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.


// Note:
// The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
#include "leetcode.hpp"

int reverse1(int x)
{
	int max = 0x7fffffff;
	int min = 0x80000000;

	long long ret = 0;

	while (x)
	{
		int carry = x % 10;
		ret = ret * 10 + carry;
		if (ret < min || ret > max)
		{
			ret = 0;
			break;
		}
		x /= 10;
	}
	return ret;
}


class Solution {
public:
	int reverse(int x) {
		return reverse1(x);
	}
};

int main(int argc, char **argv)
{
	Solution sln;

	int input1 = 123;
	int input2 = -123;
	int input3 = 1000000003;

	int rst1 = sln.reverse(input1);
	int rst2 = sln.reverse(input2);
	int rst3 = sln.reverse(input3);

	VERIFY_IS_EQUAL(rst1, 321);
	VERIFY_IS_EQUAL(rst2, -321);

	VERIFY_REPORT();
}
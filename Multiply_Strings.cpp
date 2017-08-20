/*
 Author: 		TaoBear
 Update:		July 27, 2017
 Problem: 		Multiply Strings
 Difficulty: 	medium
 Source:		https://leetcode.com/problems/trapping-rain-water/#/description
 Tags: 			Math, String
*/

// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

// Note:

// The length of both num1 and num2 is < 110.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include "leetcode.hpp"

string mul_num(string str_num, char c)
{
	string rslt;
	int n = c - '0';

	//cout << n << endl;
	int carry = 0, mul = 0;

	reverse(str_num.begin(), str_num.end());

	//cout << str_num	<< endl;

	for (int i = 0; i < str_num.size(); ++i)
	{
		mul = carry + (str_num[i] - '0') * n;

		//cout << mul << endl;

		rslt += char (mul % 10 + '0');

		carry = mul / 10;
	}

	if (carry) rslt += carry + '0';

	//cout << rslt << endl;
	return string(rslt.rbegin(), rslt.rend());
}

string add_num(string nums1, string nums2)
{
	int len1 = nums1.size(), len2 = nums2.size();

	string rslt;
	int carry = 0, sum = 0;

	reverse(nums1.begin(), nums1.end());
	reverse(nums2.begin(), nums2.end());

	int i = 0, j = 0, n1 = 0, n2 = 0;
	while (i < len1 || j < len2) {

		n1 = i < len1 ? nums1[i] - '0' : 0;
		n2 = j < len2 ? nums2[j] - '0' : 0;

		sum = n1 + n2 +  carry;

		rslt += char (sum % 10 + '0');

		carry = sum / 10; 

		i++; j++;
	}

	if (carry) rslt += carry + '0';

	return string(rslt.rbegin(), rslt.rend());
}

class Solution {
public:
	string multiply(string num1, string num2) {
		int len1 = num1.size(), len2 = num2.size();
        if (len1 < 1 || len2 < 1)
            return string("0");
		if ((len1 == 1 && num1[0] == '0') || (len2 == 1 && num2[0] == '0'))
			return string("0");
		string rslt, mul;

		for (int j = 0; j < len2; ++j) {
			mul = mul_num(num1, num2[len2 - j - 1]);

			//cout << mul << endl;
			mul += string(j, '0');
			rslt = add_num(rslt, mul);
		}

		return rslt;
	}
};


int main(int argc, char **argv)
{
	Solution sln;

	VERIFY_IS_EQUAL(sln.multiply("1", "1"), "1");
	VERIFY_IS_EQUAL(sln.multiply("123", "456"), "56088");
}
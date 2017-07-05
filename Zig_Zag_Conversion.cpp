/*
 Author: 		TaoBear
 Update:		June 16, 2017
 Problem: 		Zig Zag Conversion
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/zigzag-conversion/#/description
 Tags: 			string
*/

// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

#include "leetcode.hpp"

string convert1(string s, int numRows)
{
	vector<string> vec_str(numRows);

	int len = s.size(), cnt = 0;
	int id_cnt = 0;
	bool plus = true;
	while (cnt < len)
	{
		if (plus)
		{
			vec_str[id_cnt++].push_back(s[cnt]);
			if (id_cnt == numRows - 1) plus = false;
		}
		else
		{
			vec_str[id_cnt--].push_back(s[cnt]);
			if (id_cnt == 0) plus = true;
		}

		cnt++;
	}

	string rst;
	for (int i = 0; i < numRows; ++ i)
		rst += vec_str[i];
	return rst;
}

class Solution {
public:
    string convert(string s, int numRows) {
        return convert1(s, numRows);
    }
};

int main(int argc, char **argv)
{
	string input1 = "PAYPALISHIRING";
	string input2 = "AB";

	Solution sln;
	string rst1 = sln.convert(input1, 3);
	string rst2 = sln.convert(input2, 4);

	VERIFY_IS_EQUAL(rst1, "PAHNAPLSIIGYIR");
	VERIFY_IS_EQUAL(rst2, "AB");

	VERIFY_REPORT();
}
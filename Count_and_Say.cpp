/*
 Author: 		TaoBear
 Update:		July 5, 2017
 Problem: 		Count and Say
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/count-and-say/#/description
 Tags: 			String
*/

// The count-and-say sequence is the sequence of integers with the first five terms as following:

// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth term of the count-and-say sequence.

// Note: Each term of the sequence of integers will be represented as a string.

// Example 1:

// Input: 1
// Output: "1"


// Example 2:

// Input: 4
// Output: "1211"
#include "leetcode.hpp"



class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string tmp = countAndSay(n - 1), rslt;
        int i = 0, j = 0;
        for (j = 1; j < tmp.size(); ++j) {
        	if (tmp[i] != tmp[j])
        	{
        		rslt += std::to_string(j - i) + tmp[i];
        		i = j;
        	}
        }

        return rslt;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	int input1 = 3;

	string rslt1 = "21";

	VERIFY_IS_EQUAL(sln.countAndSay(input1), rslt1);
}
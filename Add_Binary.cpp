/*
 Author: 		TaoBear
 Update:		Aug 23, 2017
 Problem: 		Add Binary
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/plus-one/description/
 Tags: 			Array, Math
*/

// Given two binary strings, return their sum (also a binary string).

// For example,
// a = "11"
// b = "1"
// Return "100".

#include "leetcode.hpp"

class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.size();
        int blen = b.size();
        int mlen = max(alen, blen);

        int cnt = 0;
        string ans;
        int sum = 0, carry = 0;

        while (cnt < mlen || carry) {
        	sum = carry;
        	if (cnt < alen) 
        		sum += a[alen - 1 - cnt] - '0';
        	if (cnt < blen)
        		sum += b[blen - 1 - cnt] - '0';

        	carry = sum >> 1;
        	ans += sum & 1 ? '1' : '0';
        	cnt++;
        }
        return string(ans.rbegin(), ans.rend());
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	string a1 = "11";
	string b1 = "1";
	string target1 = "100";

	VERIFY_IS_EQUAL(sln.addBinary(a1, b1), target1);
}

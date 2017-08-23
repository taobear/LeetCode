/*
 Author: 		TaoBear
 Update:		Aug 23, 2017
 Problem: 		Plus One
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/plus-one/description/
 Tags: 			Array, Math
*/

// Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

// You may assume the integer do not contain any leading zero, except the number 0 itself.

// The digits are stored such that the most significant digit is at the head of the list.

#include "leetcode.hpp"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int sum = 0;
        vector<int> rslt;
        int  n = digits.size(), i = n;
        while (i-- > 0 || carry) {
        	sum = digits[i] + carry;
        	rslt.push_back(sum % 10);
        	carry = sum / 10;
        	//i++;
        }
        return vector<int>(rslt.rbegin(), rslt.rend());
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {1, 1, 1, 1};
	vector<int> input2 = {1, 0};

	vector<int> target1 = {1, 1, 1, 2};
	vector<int> target2 = {1, 1};

	VERIFY_IS_EQUAL(sln.plusOne(input1), target1);
	VERIFY_IS_EQUAL(sln.plusOne(input2), target2);
}
/*
 Author: 		TaoBear
 Update:		June 16, 2017
 Problem: 		Palindrome Numbers
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/palindrome-number/#/description
 Tags: 			Math
*/

// Determine whether an integer is a palindrome. Do this without extra space.

// Some hints:
// Could negative integers be palindromes? (ie, -1)

// If you are thinking of converting the integer to string, note the restriction of using extra space.

// You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
#include "leetcode.hpp"

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int high_dig = 1;
        int num = x;
        while (num /= 10) high_dig *= 10;

        int left = high_dig, right = 1;
        while (left >= right)
        {
        	if (x / left % 10 != x / right % 10)
        		return false;
        	left /= 10;
        	right *= 10;
        }
        return true;

    }
};

int main(int argc, char **argv)
{
	Solution sln;

	int input1 = 12321;

	bool rst1 = sln.isPalindrome(input1);

	VERIFY_IS_EQUAL(rst1, true);

	VERIFY_REPORT();
}
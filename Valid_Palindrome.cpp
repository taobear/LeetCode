/*
 Author: 		TaoBear
 Update:		Aug 30, 2017
 Problem: 		Valid Palindrome
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/valid-palindrome/description/
 Tags: 			Two Pointer, String
*/

// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

// Note:
// Have you consider that the string might be empty? This is a good question to ask during an interview.

// For the purpose of this problem, we define empty string as valid palindrome.

#include "leetcode.hpp"

class Solution {
public:
    bool isPalindrome(string s) {
    	int len = s.size();
        int i = 0, j = len - 1;

        while (i <= j) {
        	if ((s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z') && (s[i] < '0' || s[i] > '9'))
        		i++;
        	else if ((s[j] < 'a' || s[j] > 'z') && (s[j] < 'A' || s[j] >'Z') && (s[j] < '0' || s[j] > '9'))
        		j--;
        	else if (tolower(s[i++]) != tolower(s[j--]))
        		return false;
        }
        return true;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	string input1 = "A man, a plan, a canal: Panama";
	string input2 = "race a car";

	bool target1 = true;
	bool target2 = false;

	VERIFY_IS_EQUAL(sln.isPalindrome(input1), target1);
	VERIFY_IS_EQUAL(sln.isPalindrome(input2), target2);
}

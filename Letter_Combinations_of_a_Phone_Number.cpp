/*
 Author: 		TaoBear
 Update:		July 2, 2017
 Problem: 		Letter Combinations of a Phone Number
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/letter-combinations-of-a-phone-number/#/description
 Tags: 			Backtracking, String
*/

// Given a digit string, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below.



// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:
// Although the above answer is in lexicographical order, your answer could be in any order you want.

#include "leetcode.hpp"
#include <string.h>

class Solution {
public:
	vector<string> letterCombinations(string digits) {
        vector<string> prev{""}, next;

        const char *dict[10] = {"", "", "abc", "def", 
    						   "ghi", "jkl", "mno",
    						   "pqrs", "tuv", "wxyz"};

    	auto lam = [](char c) {
    		return c - '0' >= 0 && c - '0' < 10;
    	};

        size_t len = digits.size();
        for (auto& c : digits) {
        	next.clear();

        	if (!lam(c) || c == '0' || c == '1')
        		break;

        	for (auto &str : prev) 
        		for (size_t i = 0; i < strlen(dict[c - '0']); ++i)
        			next.push_back(str + dict[c - '0'][i]);
        	prev = next;
        }
        return next;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	string input1 = "12";
	string input2 = "23";
	
	vector<string> output1 = {};
	vector<string> output2 = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};

	auto result1 = sln.letterCombinations(input1);
	auto result2 = sln.letterCombinations(input2);

	VERIFY_IS_EQUAL(result1, output1);
	VERIFY_IS_EQUAL(result2, output2);
}
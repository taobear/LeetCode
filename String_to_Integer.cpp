/*
 Author: 		TaoBear
 Update:		June 16, 2017
 Problem: 		String to Integer (atoi)
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/string-to-integer-atoi/#/description
 Tags: 			string, Math
*/

// Implement atoi to convert a string to an integer.

// Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

// Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

// Update (2015-02-10):
// The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

// spoilers alert... click to show requirements for atoi.

// Requirements for atoi:
// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

// If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

#include "leetcode.hpp"
class Solution {
public:
    int myAtoi(string str) {
    	size_t n = str.size();
        if (n == 0) return 0;

        int i = 0; 
        bool flag = true;
        while (i < n && str[i] == ' ')
        	i++;
        auto isNum = [](const char a) {
        	if (a - '0' >= 0 && a - '0' < 10)
        		return true;
        	return false;
        };

        if (!isNum(str[i]))
        {
        	if (str[i] == '+')
        	{
        		i++;
        	}
        	else if (str[i] == '-')
        	{
        		flag = false;
     			i++;
        	}
        }

        unsigned long long carry = 0, num = 0;
        while (i < n)
        {
        	if (isNum(str[i]))
        	{
        		num = num * 10 + (str[i] - '0');
        	}
        	else if (!isNum(str[i]) || num > 2147483648)
        	{
        		break;
        	}
        	i++;
        }
        
        if (flag)
        {
        	if (num > 2147483647)
        		return 2147483647;
        }
        else
        {
        	if (num > 2147483648)
        		return -2147483648;
        	else
        		num =-num;
        }
        return num;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	int rst1 = sln.myAtoi("1");
	int rst2 = sln.myAtoi("-2147483649");
	//int rst3 = sln.myAtoi("9223372036854775809");
	int rst4 = sln.myAtoi("9223372036854775809");
	VERIFY_IS_EQUAL(rst1, 1);
	VERIFY_IS_EQUAL(rst2, -2147483648);
	VERIFY_IS_EQUAL(rst3, 2147483647);
}
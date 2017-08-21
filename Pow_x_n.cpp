/*
 Author: 		TaoBear
 Update:		Aug 21, 2017
 Problem: 		Group Anagrams
 Difficulty: 	Median
 Source:		https://leetcode.com/problems/powx-n/description/
 Tags: 			Binary Search, Math
*/


// Implement pow(x, n).

#include "leetcode.hpp"

class Solution
{
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1;
		if (n == 1)
			return x;
		if (n == -1)
			return 1. / x;

		double pow = myPow(x, n / 2);

		if (n % 2) 
			return pow * pow * myPow(x, n % 2);
		else
			return pow * pow;
	}	
};

int main(int argc, char **argv)
{
	Solution sln;

	double x1 = 10;
	int n1 = 2;

	double o1 = 100;


	double x2 = 8.88023;
	int    n2 = 3;

	double o2 = 700.2814829;

	VERIFY_IS_EQUAL(sln.myPow(x1, n1), o1);
	VERIFY_IS_EQUAL(sln.myPow(x2, n2), o2);

}
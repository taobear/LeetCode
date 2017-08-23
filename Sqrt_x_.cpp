/*
 Author: 		TaoBear
 Update:		Aug 23, 2017
 Problem: 		Sqrt(x)
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/sqrtx/description/
 Tags: 			Array, Math
*/

// Implement int sqrt(int x).

// Compute and return the square root of x.
#include "leetcode.hpp"

class Solution {
public:
    int mySqrt(int x) {
    	
    	int i = 1, j = x;
    	while (i <= j) {
    		int mid = i + (j - i) / 2;
    		// int mul = mid * mid; // 会溢出
    		int div = x / mid;

    		if (div > mid) 
    			i = mid + 1;
    		else if (div < mid)
    			j = mid - 1;
    		else
    			return mid;
    	}    
    	return j;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	VERIFY_IS_EQUAL(sln.mySqrt(9), 3);
	VERIFY_IS_EQUAL(sln.mySqrt(10), 3);
}
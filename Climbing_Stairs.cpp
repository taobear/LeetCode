/*
 Author: 		TaoBear
 Update:		Aug 23, 2017
 Problem: 		Climbing Stairs
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/climbing-stairs/description/
 Tags: 			Dynamic Programming
*/


// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Note: Given n will be a positive integer.

#include "leetcode.hpp"

class Solution {
public:
    int climbStairs(int n) {
    	if (n < 3)
    		return n == 2 ? 2 : 1;

    	int pp = 1, p = 2;
    	int cur = 0;
    	for (int i = 3; i <= n; ++i) {
    		cur = pp + p;
    		pp = p;
    		p = cur;
    	}    
    	return cur;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	int input1 = 10;

	int target1 = 55;

	VERIFY_IS_EQUAL(sln.climbStairs(input1), target1);
}
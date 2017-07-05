/*
 Author: 		TaoBear
 Update:		July 5, 2017
 Problem: 		Divide Two Integers
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/divide-two-integers/#/description
 Tags: 			Math, Binary Search
*/

// Divide two integers without using multiplication, division and mod operator.

// If it is overflow, return MAX_INT.
#include "leetcode.hpp"

static const int INT_MAX = numeric_limits<int>::max();
static const int INT_MIN = numeric_limits<int>::min();

int divide1(int dividend, int divisor) 
{
	if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;

	long long m = abs((long long)dividend), n = abs((long long) divisor), res = 0;

    	int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1; // 异或
    	while (m >= n) {
    		long long t = n, p = 1;
    		while (m >= (t << 1)) {
    			t << 1;
    			p << 1;
    		}
    		m -= t;
    		res += p;
    	}
    	return sign == 1 ? res : -res;
}

int divide2(int dividend, int divisor) 
{
	long long res = 0;
	long long m = abs((long long) dividend), n = abs((long long) divisor);

	if (m < n) return 0;
	long long t = n, p = 1;
	while (m > (t >> 1)) {
		t >> 1;
		p >> 1;
	}

	res += p + divide2(m - t, n);

	if ((dividend < 0) ^ (divisor < 0)) res = - res;

	return res > INT_MAX ? INT_MAX : res;
}

class Solution {
public:
    int divide(int dividend, int divisor) {
    	return divide1(dividend, divisor);

    }
};

int main(int argc, char **argv)
{
	int dividend1 = 1, divisor1 = 1;

	Solution sln;

	VERIFY_IS_EQUAL(sln.divide(dividend1, divisor1), 1);
}
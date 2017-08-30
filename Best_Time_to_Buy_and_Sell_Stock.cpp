/*
 Author: 		TaoBear
 Update:		Aug 30, 2017
 Problem: 		Best Time to Buy and Sell Stock
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/triangle/description/
 Tags: 			Array, Dynamic Programming
*/

// Say you have an array for which the ith element is the price of a given stock on day i.

// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
// design an algorithm to find the maximum profit.

// Example 1:
// Input: [7, 1, 5, 3, 6, 4]
// Output: 5

// max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
// Example 2:
// Input: [7, 6, 4, 3, 1]
// Output: 0

// In this case, no transaction is done, i.e. max profit = 0.
#include "leetcode.hpp"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 1) return 0;

        int min = INT_MAX;
        int pro = 0;

        for (int i = 0; i < len; ++i) {
        	if (prices[i] > min) {
        		pro = max(pro, prices[i] - min);
        	} else {
        		min = prices[i];
        	}
        }
        return pro;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {7, 1, 5, 3, 6, 4};
	vector<int> input2 = {7, 6, 4, 3, 1};

	int target1 = 5;
	int target2 = 0;

	VERIFY_IS_EQUAL(sln.maxProfit(input1), target1);
	VERIFY_IS_EQUAL(sln.maxProfit(input2), target2);
}
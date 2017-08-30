/*
 Author: 		TaoBear
 Update:		Aug 30, 2017
 Problem: 		Best Time to Buy and Sell Stock II
 Difficulty: 	Easy
 Source:		https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 Tags: 			Array, Greedy
*/

// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one 
// and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the 
// sametime (ie, you must sell the stock before you buy again).

#include "leetcode.hpp"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;

        for (int i = 1; i < prices.size(); ++i) {
        	if (prices[i] > prices[i - 1])
        		max += prices[i] - prices[i - 1];
        }

        return max;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> input1 = {7, 1, 5, 3, 6, 4};
	vector<int> input2 = {7, 6, 4, 3, 1};

	int target1 = 7;
	int target2 = 0;

	VERIFY_IS_EQUAL(sln.maxProfit(input1), target1);
	VERIFY_IS_EQUAL(sln.maxProfit(input2), target2);
}
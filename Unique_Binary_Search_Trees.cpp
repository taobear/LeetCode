/*
 Author: 		TaoBear
 Update:		Aug 26, 2017
 Problem: 		Unique Binary Search Trees
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/unique-binary-search-trees/description/
 Tags: 			Tree, Dynamic Programming
*/

// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

// For example,
// Given n = 3, there are a total of 5 unique BST's.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include "leetcode.hpp"

class Solution {
public:
    int numTrees(int n) {
        // int ans = 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < n + 1; ++i) {
        	for (int j = 1; j <= i; ++j) {
        		dp[i] += dp[j - 1] * dp[i - j];
        	}
        }

        return dp[n];
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	int input1 = 1;
	int input2 = 2;
	int input3 = 3;

	int target1 = 1;
	int target2 = 2;
	int target3 = 5;

	VERIFY_IS_EQUAL(sln.numTrees(input1), target1);
	VERIFY_IS_EQUAL(sln.numTrees(input2), target2);
	VERIFY_IS_EQUAL(sln.numTrees(input3), target3);
}
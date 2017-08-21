/*
 Author: 		TaoBear
 Update:		Aug 21, 2017
 Problem: 		Permutation Sequence
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/permutation-sequence/description/
 Tags: 			Backtracking, Math
*/


// The set [1,2,3,…,n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

#include "leetcode.hpp"

class Solution {
	string getPermutation(int n, int k) {
		int *fact = new int[n](1);
		for (int i = 1; i < n; ++i)
			fact[i] = fact[i - 1] * i;

		
	}
};

int main(int argc, char **argv)
{

}
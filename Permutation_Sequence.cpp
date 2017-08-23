/*
 Author: 		TaoBear
 Update:		Aug 23, 2017
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
#include <string>
class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> fact(n, 1);
		for (int i = 1; i < n; ++i)
			fact[i] = fact[i - 1] * i;
        
        string ans;
        vector<int> visited(n, 0);
        int kth = k - 1;

        for (int i = n - 1; i >= 0; --i) {
        	int dig = kth / fact[i];
        	for (int j = 0; j < n && dig >= 0; ++j) {
        		if (visited[j]) 
        			continue;

        		if (dig == 0) {
        			ans += std::to_string(j + 1);
        			visited[j] = 1;
        		}

        		dig--;
        	}
        	kth %= fact[i];
        }

		return ans;
	}
};

int main(int argc, char **argv)
{
	Solution sln;

	int n1 = 3, k1 = 3;

	VERIFY_IS_EQUAL(sln.getPermutation(n1, k1), "213");

}
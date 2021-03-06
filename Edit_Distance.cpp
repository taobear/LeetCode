/*
 Author: 		TaoBear
 Update:		Aug 23, 2017
 Problem: 		Edit Distance
 Difficulty: 	Hard
 Source:		https://leetcode.com/problems/edit-distance/description/
 Tags: 			Dynamic Programming, String
*/


// Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

// You have the following 3 operations permitted on a word:

// a) Insert a character
// b) Delete a character
// c) Replace a character

#include "leetcode.hpp"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if (!m || !n)
        	return m ? m : n;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; ++i)
        	dp[i][0] = i;
        for (int j = 0; j <= n; ++j)
        	dp[0][j] = j;

        for (int i = 1; i <= m; ++i) {
        	for (int j = 1; j <= n; ++j) {
        		if (word1[i - 1] == word2[j - 1])
        			dp[i][j] = dp[i - 1][j - 1];
        		else
        			dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
        	}
        }

		return dp[m][n];        
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	VERIFY_IS_EQUAL(sln.minDistance("abcdee", "abccc"), 3);
	VERIFY_IS_EQUAL(sln.minDistance("a", "b"), 1);
}
/*
 Author: 		TaoBear
 Update:		Aug 25, 2017
 Problem: 		Word Search
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/word-search/description/
 Tags: 			Backtracking, Array
*/

// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

// For example,
// Given board =

// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

#include "leetcode.hpp"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	int m = board.size();
    	if (!m) return word.empty();
    	int n = board[0].size();
    	if (!n) return word.empty();
    	int len = word.size();
    	if (!len) return false;

        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
        	for (int j = 0; j < n; j++){
        		if (board[i][j] != word[0])
        			continue;
        		visited[i][j] = 1;
				if (helper(board, m, n, i, j, word, len, 1, visited))
					return true;
				visited[i][j] = 0;
        	}
        }

		return false;
    }

    bool helper(vector<vector<char>>& board, int row, int col, 
    			int i, int j, string& word, int n, int level,
    			vector<vector<int>> &visited) {
    	if (level >= n)
    		return true;

    	if ((i - 1 >= 0 && !visited[i - 1][j]) && board[i - 1][j] == word[level]) {
    		visited[i - 1][j] = 1;
    		if (helper(board, row, col, i - 1, j, word, n, level + 1, visited))
    			return true;
    		visited[i - 1][j] = 0;
    	}

    	if ((j - 1 >= 0 && !visited[i][j - 1]) && board[i][j - 1] == word[level]) {
    		visited[i][j - 1] = 1;
    		if (helper(board, row, col, i, j - 1, word, n, level + 1, visited))
    			return true;
    		visited[i][j - 1] = 0;
    	}

    	if ((i + 1 < row && !visited[i + 1][j]) && board[i + 1][j] == word[level]) {
    		visited[i + 1][j] = 1;
    		if (helper(board, row, col, i + 1, j, word, n, level + 1, visited))
    			return true;
    		visited[i + 1][j] = 0;
    	}

    	if ((j + 1 < col && !visited[i][j + 1] && board[i][j + 1] == word[level])) {
    		visited[i][j + 1] = 1;
    		if (helper(board, row, col, i, j + 1, word, n, level + 1, visited))
    			return true;
    		visited[i][j + 1] = 0;
    	}
    	return false;
    }
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<vector<char>> board1 = {{'A', 'B', 'C', 'E'},
								   {'S', 'F', 'C', 'S'},
								   {'A', 'D', 'E', 'E'}};

	string word1 = "ABCCED";
	string word2 = "SEE";
	string word3 = "ABCB";

	vector<vector<char>> board2 = {{'a'}};
	string word21 = "a";

	VERIFY_IS_EQUAL(sln.exist(board1, word1), true);
	VERIFY_IS_EQUAL(sln.exist(board1, word2), true);
	VERIFY_IS_EQUAL(sln.exist(board1, word3), false);
	VERIFY_IS_EQUAL(sln.exist(board2, word21), true);
}
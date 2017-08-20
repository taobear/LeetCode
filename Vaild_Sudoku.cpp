/*
 Author: 		TaoBear
 Update:		July 5, 2017
 Problem: 		Valid Sudoku
 Difficulty: 	Medium
 Source:		https://leetcode.com/problems/valid-sudoku/#/description
 Tags: 			Hash Table
*/

// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


// A partially filled sudoku which is valid.

// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

 bool isValidSudoku2(vector<vector<char>>& board) {
    vector<short> col(9, 0);
    vector<short> block(9, 0);
    vector<short> row(9, 0);
    for (int i = 0; i < 9; i++)
     for (int j = 0; j < 9; j++) {
         if (board[i][j] != '.') {
             int idx = 1 << (board[i][j] - '0');
             if (row[i] & idx || col[j] & idx || block[i/3 * 3 + j / 3] & idx)
                return false;
            row[i] |= idx;
            col[j] |= idx;
            block[i/3 * 3 + j/3] |= idx;
         }
     }
     return true;
 } 


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 行
        int row = board.size();
        if (row != 9) return false;
        int col = board[0].size();
        if (col != 9) return false;

        auto lam = [](const pair<char, int>& e) {
        	if ((e.first >= '0' && e.first <= '9' && e.second < 1)
        		|| e.first == '.')
        		return true;
        	return false;
        };
        for (int i = 0; i < row; ++i)
        {
        	map<char, int> tmp_map_row;
        	map<char, int> tmp_map_col;
        	for (int j = 0; j < col; ++j)
        	{
        		tmp_map_row[board[i][j]]++;
        		tmp_map_col[board[j][i]]++;
        	}
        	
        	for (auto &e : tmp_map_row) 
        		if (!lam(e))
        			return false;

        	for (auto &e : tmp_map_col)
        		if (!lam(e))
        			return false;
        	tmp_map_col.clear();
        	tmp_map_row.clear();
        }

        for (int i = 0; i < 3; ++i)
        {
        	int row_stt = i * 3;
        	for (int j = 0; j < 3; ++j)
        	{
        		int col_stt = j * 3;
        		map<char, int> tmp_map;

        		for (int ii = 0; ii < 3; ++ii)
        		{
        			for (int jj = 0; jj < 3; ++jj)
        			{
        				tmp_map[board[ii + row_stt][jj + col_stt]]++;
        			}
        		}

        		if (auto &e : tmp_map)
        			if (!lam(e))
        				return false;

        		tmp_map.clear();
        	}
        }

        return true;

    }
};

int main(int argc, char **argv)
{
	
}
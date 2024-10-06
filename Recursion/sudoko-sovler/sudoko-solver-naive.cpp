// Problem link: https://leetcode.com/problems/sudoku-solver/
// Time: 
// Space:

class Solution {
private:
	bool isValid(int row, int col, char c, vector<vector<char>>& board) {
		for(int i = 0; i < 9; i++) {
			if(board[i][col] == c) {
				return false;
			}
			if(board[row][i] == c) {
				return false;
			}
			if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
				return false;
			}
		}
		return true;
	}

	bool solve(vector<vector<char>>& board) {
		int row = board.size();
		int col = board[0].size();
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				if(board[i][j] == '.') {
					for(char c = '1'; c <= '9'; c++) {
						if(isValid(i, j, c, board) == true) {
							board[i][j] = c;
							if(solve(board) == true) {
								return true;
							}
							board[i][j] = '.';
						}
					}
					return false;
				}
			}
		}
		return true;
	}

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
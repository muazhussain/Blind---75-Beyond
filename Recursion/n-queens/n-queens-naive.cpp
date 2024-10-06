// Problem link: https://leetcode.com/problems/n-queens/
// Time: O(n!)
// Space: O(n^2)

class Solution {
private:
	bool isSafe(int row, int col, int n, vector<string>& board) {
		int r = row, c = col;
		while(r >= 0 && c >= 0) {
			if(board[r][c] == 'Q') {
				return false;
			}
			r--;
			c--;
		}
		r = row;
		c = col;
		while(r >= 0 && c < n) {
			if(board[r][c] == 'Q') {
				return false;
			}
			r--;
			c++;
		}
		r = row;
		c = col;
		while(r >= 0) {
			if(board[r][c] == 'Q') {
				return false;
			}
			r--;
		}
		return true;
	}

	void solve(int row, int n, vector<string>& board, vector<vector<string>>& res) {
		if(row == n) {
			res.push_back(board);
			return;
		}
		for(int col = 0; col < n; col++) {
			if(isSafe(row, col, n, board) == true) {
				board[row][col] = 'Q';
				solve(row + 1, n, board, res);
				board[row][col] = '.';
			}
		}	
	}

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
		solve(0, n, board, res);        
		return res;
    }
};
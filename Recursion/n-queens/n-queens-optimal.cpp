// Problem link: https://leetcode.com/problems/n-queens/
// Time: O(n! * n)
// Space: O(n)

class Solution {
private:
	void solve(int row, int n, vector<string>& board, vector<vector<string>>& res, vector<bool>& topCol, vector<bool>& upperDiagonal, vector<bool>& lowerDiagonal) {
		if(row == n) {
			res.push_back(board);
			return;
		}
		for(int col = 0; col < n; col++) {
			if(topCol[col] == false && upperDiagonal[n - 1 + col - row] == false && lowerDiagonal[row + col] == false) {
				topCol[col] = true;
				upperDiagonal[n - 1 + col - row] = true;
				lowerDiagonal[row + col] = true;
				board[row][col] = 'Q';
				solve(row + 1, n, board, res, topCol, upperDiagonal, lowerDiagonal);
				topCol[col] = false;
				upperDiagonal[n - 1 + col - row] = false;
				lowerDiagonal[row + col] = false;
				board[row][col] = '.';
			}
		}	
	}

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<bool> topCol(n), upperDiagonal(n), lowerDiagonal(n);
		solve(0, n, board, res, topCol, upperDiagonal, lowerDiagonal);        
		return res;
    }
};
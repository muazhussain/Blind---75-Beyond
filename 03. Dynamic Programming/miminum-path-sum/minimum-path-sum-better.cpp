// Problem link: https://leetcode.com/problems/minimum-path-sum/
// Time: O(m * n)
// Space: O(m * n)

class Solution {
private:
	int calcMinimum(int r, int c, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
		if(r >= m || c >= n) {
			return INT_MAX;
		}
		if(r == m - 1 && c == n - 1) {
			return grid[r][c];
		}
		if(dp[r][c] != -1) {
			return dp[r][c];
		}
		return dp[r][c] = grid[r][c] + min(calcMinimum(r + 1, c, m, n, grid, dp), calcMinimum(r, c + 1, m, n, grid, dp));
	}

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return calcMinimum(0, 0, m, n, grid, dp);
    }
};
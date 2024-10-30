// Problem link: https://leetcode.com/problems/minimum-path-sum/
// Time: O(2^(m + n))
// Space: O(m + n)

class Solution {
private:
	int calcMinimum(int r, int c, int m, int n, vector<vector<int>>& grid) {
		if(r >= m || c >= n) {
			return INT_MAX;
		}
		if(r == m - 1 && c == n - 1) {
			return grid[r][c];
		}
		return grid[r][c] + min(calcMinimum(r + 1, c, m, n, grid), calcMinimum(r, c + 1, m, n, grid));
	}

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return calcMinimum(0, 0, m, n, grid);
    }
};
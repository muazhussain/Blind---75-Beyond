// Problem link: https://leetcode.com/problems/triangle/
// Time: O(row * col)
// Space: O(row * row)

class Solution {
private:
	int calcMinimum(int row, int col, int rows, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
		if(row == rows - 1) {
			return dp[row][col] = triangle[row][col];
		}	
		if(dp[row][col] != -1) {
			return dp[row][col];
		}
		return dp[row][col] = triangle[row][col] + min(calcMinimum(row + 1, col, rows, triangle, dp), calcMinimum(row + 1, col + 1, rows, triangle, dp));
	}

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<vector<int>> dp(rows, vector<int> (rows, -1));
        return calcMinimum(0, 0, rows, triangle, dp);
    }
};
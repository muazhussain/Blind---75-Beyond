// Problem link: https://leetcode.com/problems/triangle/
// Time: O(2^rows)
// Space: O(rows)

class Solution {
private:
	int calcMinimum(int row, int col, int rows, vector<vector<int>>& triangle) {
		if(row == rows - 1) {
			return triangle[row][col];
		}	
		return triangle[row][col] + min(calcMinimum(row + 1, col, rows, triangle), calcMinimum(row + 1, col + 1, rows, triangle));
	}

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        return calcMinimum(0, 0, rows, triangle);
    }
};
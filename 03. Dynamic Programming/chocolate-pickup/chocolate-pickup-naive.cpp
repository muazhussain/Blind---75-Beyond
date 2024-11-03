// Problem link: https://www.naukri.com/code360/problems/ninja-and-his-friends_3125885?leftPanelTabValue=PROBLEM
// Time: O(3^n * 3^n)
// Space: O(n)

#include <bits/stdc++.h> 
bool isValidCell(int c1, int c2, int n) {
	return (c1 >= 0 && c1 < n && c2 >= 0 && c2 < n);
}

int calcMaxChocolates(int r, int c1, int c2, int m, int n, vector<vector<int>>& grid) {
	if(isValidCell(c1, c2, n) == false) {
		return INT_MIN;
	}
	if(r == m - 1) {
		if(c1 == c2) {
			return grid[r][c1];
		}
		return grid[r][c1] + grid[r][c2];
	}
	long long res = 0;
	for(int dx = -1; dx <= 1; dx++) {
		for(int dy = -1; dy <= 1; dy++) {
			if(c1 == c2) {
				res = max(res, 1LL * grid[r][c1] + calcMaxChocolates(r + 1, c1 + dx, c2 + dy, m, n, grid));
			} else {
				res = max(res, 1LL * grid[r][c1] + grid[r][c2] + calcMaxChocolates(r + 1, c1 + dx, c2 + dy, m, n, grid));
			}
		}
	}
	return (int)res;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
	int m = grid.size();
	int n = grid[0].size();
	return calcMaxChocolates(0, 0, n - 1, m, n, grid);
}
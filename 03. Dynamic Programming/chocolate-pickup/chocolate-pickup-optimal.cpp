// Problem link: https://www.naukri.com/code360/problems/ninja-and-his-friends_3125885?leftPanelTabValue=PROBLEM
// Time: O(m * n * n
// Space: O(m * m)

#include <bits/stdc++.h> 
bool isValidCell(int c1, int c2, int n) {
	return (c1 >= 0 && c1 < n && c2 >= 0 && c2 < n);
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> prev(n, vector<int> (n, 0));
	for(int c1 = 0; c1 < n; c1++) {
		for(int c2 = 0; c2 < n; c2++) {
			prev[c1][c2] = grid[m - 1][c1];
			if(c1 != c2) {
				prev[c1][c2] += grid[m - 1][c2];
			}
		}
	}
	for(int i = m - 2; i >= 0; i--) {
		vector<vector<int>> curr(n, vector<int> (n, 0));
		for(int c1 = 0; c1 < n; c1++) {
			for(int c2 = 0; c2 < n; c2++) {
				int value = grid[i][c1];
				if(c1 != c2) {
					value += grid[i][c2];
				}
				int res = 0;
				for(int dx = -1; dx <= 1; dx++) {
					for(int dy = -1; dy <= 1; dy++) {
						if(isValidCell(c1 + dx, c2 + dy, n)) {
							res = max(res, value + prev[c1 + dx][c2 + dy]);
						}
					}
				}
				curr[c1][c2] = res;
			}
		}
		prev = curr;
	}
	return prev[0][n - 1];
}
// Problem link: https://leetcode.com/problems/number-of-islands/
// Time: O(m * n)
// Space: O(m * n)

class Solution {
private:
	bool isValidCell(int r, int c, int row, int col) {
		return (r >= 0 && r < row && c >= 0 && c < col);
	}

	void bfs(int r, int c, int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
		vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
		queue<pair<int, int>> q;
		q.push({r, c});
		vis[r][c] = true;
		while(!q.empty()) {
			int curr_row = q.front().first;
			int curr_col = q.front().second;
			q.pop();
			for(auto dir : dirs) {
				int nr = curr_row + dir.first;
				int nc = curr_col + dir.second;
				if(isValidCell(nr, nc, row, col) == true && !vis[nr][nc] && grid[nr][nc] == '1') {
					q.push({nr, nc});
					vis[nr][nc] = true;
				}
			}
		}
	}

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int res = 0;
        for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++) {
        		if(grid[i][j] == '1' && vis[i][j] == false) {
        			bfs(i, j, m, n, grid, vis);
        			res++;
        		}
        	}
        }
        return res;
    }
};
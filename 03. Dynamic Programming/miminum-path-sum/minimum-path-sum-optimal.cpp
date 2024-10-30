// Problem link: https://leetcode.com/problems/minimum-path-sum/
// Time: O(m * n)
// Space: O(n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, INT_MAX);
        for(int i = 0; i < m; i++) {
        	vector<int> curr(n, INT_MAX);
        	for(int j = 0; j < n; j++) {
        		if(i == 0 && j == 0) {
        			curr[j] = grid[i][j];
        		}
        		if(i > 0) {
        			curr[j] = min(curr[j], prev[j] + grid[i][j]);
        		}
        		if(j > 0) {
        			curr[j] = min(curr[j], curr[j - 1] + grid[i][j]);
        		}
        	}
        	prev = curr;
        }
        return prev[n - 1];
    }
};
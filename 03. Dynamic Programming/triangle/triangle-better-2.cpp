// Problem link: https://leetcode.com/problems/triangle/
// Time: O(number_of_cells)
// Space: O(rows * rows)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<vector<int>> dp(rows, vector<int> (rows, INT_MAX));
        for(int i = 0; i < rows; i++) {
        	for(int j = 0; j <= i; j++) {
        		if(i == 0 && j == 0) {
        			dp[i][j] = triangle[i][j];
        			continue;
        		}
        		if(j == 0) {
        			dp[i][j] = dp[i - 1][j] + triangle[i][j];
        		} else if(j == i) {
        			dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
        		} else {
        			dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        		}
        	}
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};
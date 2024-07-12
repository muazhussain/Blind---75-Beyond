// Problem link: https://leetcode.com/problems/unique-paths/
// Time complexity: O(m * n)
// Space complexity: O(m * n)

class Solution {
private:
    int dfs(vector<vector<int>>& dp, int i, int j) {
        if(i >= dp.size() || j >= dp[0].size()) return 0;
        if(i == dp.size() - 1 && j == dp[0].size() - 1) return 1;
        if(dp[i][j]) return dp[i][j];
        return dp[i][j] = dfs(dp, i + 1, j) + dfs(dp, i, j + 1);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n));
        return countPaths(m, n, 0, 0, dp);
    }
};
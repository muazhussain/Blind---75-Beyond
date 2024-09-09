// Problem link: https://leetcode.com/problems/rotate-image/
// Time: O(m * n)
// Space: O(m * n)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp(matrix.size(), vector<int>(matrix.size()));
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < n; j++) {
        		temp[j][n - i - 1] = matrix[i][j];
        	}
        }
        matrix = temp;
     }
};
// Problem link: https://leetcode.com/problems/set-matrix-zeroes/
// Time: O(m * n * (m + n))
// Space O(m * n)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> temp = matrix;

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    for(int k = 0; k < matrix[0].size(); k++) {
                        temp[i][k] = 0;
                    }
                    for(int k = 0; k < matrix.size(); k++) {
                        temp[k][j] = 0;
                    }
                }
            }
        }

        matrix = temp;
    }
};
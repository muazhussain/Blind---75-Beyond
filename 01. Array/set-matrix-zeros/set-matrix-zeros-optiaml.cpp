// Problem link: https://leetcode.com/problems/set-matrix-zeroes/
// Time: O(m * n)
// Space O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool flag = false;

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;

                    if(j != 0) {
                        matrix[0][j] = 0;
                    } else {
                        flag = true;
                    }
                }
            }
        }

        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[0].size(); j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0) {
            for(int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }

        if(flag) {
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
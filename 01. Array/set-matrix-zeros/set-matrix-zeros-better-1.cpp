// Problem link: https://leetcode.com/problems/set-matrix-zeroes/
// Time: O(m * n)
// Space O(m + n)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> columns;

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(rows.count(i) > 0 || columns.count(j) > 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
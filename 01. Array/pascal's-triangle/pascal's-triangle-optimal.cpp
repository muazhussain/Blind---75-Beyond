// Problem link: https://leetcode.com/problems/pascals-triangle/
// Time: O(numRows ^ 2)
// Space: O(numRows ^ 2)

class Solution {
private:
	vector<int> generateRow(int row) {
		vector<int> resRow;
		int res = 1;
		resRow.push_back(res);
		for(int col = 1; col < row; col++) {
			res *= (row - col);
			res /= col;
			resRow.push_back(res);
		}
		return resRow;
	}

public:
    vector<vector<int>> generate(int numRows) {
    	vector<vector<int>> res;
    	for(int i = 1; i <= numRows; i++) {
    		res.push_back(generateRow(i));	
    	}
    	return res;
    }
};
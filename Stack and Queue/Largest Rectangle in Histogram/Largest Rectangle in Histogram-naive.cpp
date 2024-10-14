// Problem link: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
        	int minHeight = INT_MAX;
        	for(int j = i; j < n; j++) {
        		minHeight = min(minHeight, heights[j]);
        		res = max(res, minHeight * (j - i + 1));
        	}
        }
        return res;
    }
};
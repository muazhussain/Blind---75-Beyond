// Problem link: https://leetcode.com/problems/trapping-rain-water/
// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    int trap(vector<int>& height) {
    	int n = height.size();
    	int res = 0;
    	for(int i = 0; i < n; i++) {
    		int leftMax = INT_MIN;
    		for(int j = i; j >= 0; j--) {
    			leftMax = max(leftMax, height[j]);
    		}
    		int rightMax = INT_MIN;
    		for(int j = i; j < n; j++) {
    			rightMax = max(rightMax, height[j]);
    		}
    		res += min(leftMax, rightMax) - height[i];
    	}
    	return res;
    }
};
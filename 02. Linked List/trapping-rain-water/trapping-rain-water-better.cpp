// Problem link: https://leetcode.com/problems/trapping-rain-water/
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int trap(vector<int>& height) {
    	int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0] = height[0];
        for(int i = 1; i < n; i++) {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }
        rightMax[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            res += min(leftMax[i], rightMax[i]) - height[i];
        }
    	return res;
    }
};
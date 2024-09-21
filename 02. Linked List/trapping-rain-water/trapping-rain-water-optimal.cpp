// Problem link: https://leetcode.com/problems/trapping-rain-water/
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int trap(vector<int>& height) {
    	int n = height.size();
    	int leftMax = height[0], rightMax = height[n - 1], left = 1, right = n - 2;
        int res = 0;
        while(left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if(leftMax < rightMax) {
                res += leftMax - height[left];
                left++;
            } else {
                res += rightMax - height[right];
                right--;
            }
        }
    	return res;
    }
};
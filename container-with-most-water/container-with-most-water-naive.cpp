// Problem link: https://leetcode.com/problems/container-with-most-water/
// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for(int i = 0; i < height.size(); i++) {
            for(int j = i + 1; j < height.size(); j++) {
                int area = (j - i) * min(height[i], height[j]);
                res = max(res, area);
            }
        } 
        return res;
    }
};
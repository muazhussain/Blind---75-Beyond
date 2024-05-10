// Problem link: https://leetcode.com/problems/container-with-most-water/
// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int low = 0, high = height.size() - 1;
        while(low < high) {
            int area = (high - low) * min(height[low], height[high]);
            res = max(res, area);
            if(height[low] < height[high]) {
                low++;
            } else {
                high--;
            }
        }
        return res;
    }
};
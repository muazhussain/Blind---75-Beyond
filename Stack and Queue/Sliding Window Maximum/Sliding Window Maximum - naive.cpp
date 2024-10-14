// Problem link: https://leetcode.com/problems/sliding-window-maximum/
// Time: O(n * k)
// Space: O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i <= n - k; i++) {
        	int maxNum = INT_MIN;
        	for(int j = i; j < i + k; j++) {
        		maxNum = max(maxNum, nums[j]);
        	}
        	res.push_back(maxNum);
        }
        return res;
    }
};
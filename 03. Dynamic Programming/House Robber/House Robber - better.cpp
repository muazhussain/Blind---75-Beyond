// Problem link: https://leetcode.com/problems/house-robber/
// Time: O(n)
// Space: O(n)

class Solution {
private:
	int calc(int index, vector<int>& nums, vector<int>& dp) {
		if(index == 0) {
			return nums[0];
		}
		if(index < 0) {
			return 0;
		}
		if(dp[index] != -1) {
			return dp[index];
		}
		int pick = nums[index] + calc(index - 2, nums, dp);
		int notPick = 0 + calc(index - 1, nums, dp);
		return dp[index] = max(pick, notPick);
	}

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return calc(n - 1, nums, dp);
    }
};
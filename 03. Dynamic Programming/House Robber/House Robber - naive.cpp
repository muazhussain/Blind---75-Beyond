// Problem link: https://leetcode.com/problems/house-robber/
// Time: (2^n)
// Space: O(n)

class Solution {
private:
	int calc(int index, vector<int>& nums) {
		if(index == 0) {
			return nums[0];
		}
		if(index < 0) {
			return 0;
		}
		int pick = nums[index] + calc(index - 2, nums);
		int notPick = 0 + calc(index - 1, nums);
		return max(pick, notPick);
	}

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return calc(n - 1, nums);
    }
};
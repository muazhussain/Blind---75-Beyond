// Problem link: https://leetcode.com/problems/house-robber/
// Time: O(n)
// Space: O(1)

class Solution {
private:
	int calc(int n, vector<int>& nums) {
		int prev2 = 0, prev1 = nums[0];
		for(int i = 1; i < n; i++) {
			int pick = nums[i];
			if(i > 1) {
				pick += prev2;
			}
			int notPick = 0 + prev1;
			int curr = max(pick, notPick);
			prev2 = prev1;
			prev1 = curr;
		}
		return prev1;
	}

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return calc(n, nums);
    }
};
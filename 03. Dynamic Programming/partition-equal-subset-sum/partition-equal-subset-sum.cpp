// Problem link: https://leetcode.com/problems/partition-equal-subset-sum/
// Time: O(n * k)
// Space: O(k)

class Solution {
private:
	bool findTargetSum(vector<int>& nums, int k) {
		int n = nums.size();
		vector<bool> prev(k + 1, false);
		prev[0] = true;
		prev[nums[0] <= k ? nums[0] : 0] = true;
		for(int index = 1; index < n; index++) {
			vector<bool> curr(k + 1, false);
			curr[0] = true;
			for(int target = 1; target <= k; target++) {
				int notTake = prev[target];
				int take = false;
				if(target >= nums[index]) {
					take = prev[target - nums[index]];
				}
				curr[target] = take | notTake;
			}
			prev = curr;
		}
		return prev[k];
	}

public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) {
        	return false;
        }
        return findTargetSum(nums, sum / 2);
    }
};
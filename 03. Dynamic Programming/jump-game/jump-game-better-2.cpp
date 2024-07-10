// Problem link: https://leetcode.com/problems/jump-game/
// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        dp[n - 1] = 1;

        for(int idx = n - 2; idx >= 0; idx--) {
            if(nums[idx] == 0) {
                dp[idx] = false;
                continue;
            }

            int flag = 0;
            int reach = idx + nums[idx];
            for(int jump = idx + 1; jump <= reach; jump++) {
                if(jump < n && dp[jump] == true) {
                    dp[idx] = true;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                dp[idx] = false;
            }
        }
        return dp[0];
    }
};
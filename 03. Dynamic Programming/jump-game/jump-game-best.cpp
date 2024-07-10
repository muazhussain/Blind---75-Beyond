// Problem link: https://leetcode.com/problems/jump-game/
// Time: O(n)
// Space: O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for(int idx = 0; idx < nums.size(); idx++) {
            if(reach < idx) {
                return false;
            }
            reach = max(reach, idx + nums[idx]);
        }
        return true;
    }
};
// Problem link: https://leetcode.com/problems/jump-game/
// Time: O(n^n)
// Space: O(n)

class Solution {
public:
    bool create(vector<int>& nums, int idx) {
        if(idx == nums.size() - 1) {
            return true;
        }
        if(nums[idx] == 0) {
            return false;
        }
        int reach = idx + nums[idx];
        for(int jump = idx + 1; jump <= reach; jump++) {
            if(jump < nums.size() && create(nums, jump) == true) {
                return true;
            }
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        return create(nums, 0);
    }
};
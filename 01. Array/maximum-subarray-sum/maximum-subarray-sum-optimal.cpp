// Problem link: https://leetcode.com/problems/maximum-subarray/
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = -1e5 - 5;
        int cur_max = -1e5 - 5;
        for(int i = 0; i < nums.size(); i++) {
            cur_max = max(cur_max + nums[i], nums[i]);
            res = max(res, cur_max);
        } 
        return res;
    }
};
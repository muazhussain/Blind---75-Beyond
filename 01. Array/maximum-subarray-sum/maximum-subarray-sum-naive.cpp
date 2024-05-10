// Problem link: https://leetcode.com/problems/maximum-subarray/
// Time: O(n^3)
// Space: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i; j < nums.size(); j++) {
                int sum = 0;
                for(int k = i; k <= j; k++) {
                    sum += nums[k];
                }
                res = max(res, sum);
            }
        } 
        return res;
    }
};
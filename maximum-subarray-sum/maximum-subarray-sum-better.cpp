// Problem link: https://leetcode.com/problems/maximum-subarray/
// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for(int j = i; j < nums.size(); j++) {
                sum += nums[j]; 
                res = max(res, sum);
            }
        } 
        return res;
    }
};
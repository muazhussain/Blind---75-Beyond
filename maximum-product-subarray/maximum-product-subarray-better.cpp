// Problem link: https://leetcode.com/problems/maximum-product-subarray/
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int res = nums[0];
        int prev = 1;
        int suff = 1;
        for(int i = 0; i < len; i++) {
            prev *= nums[i];
            suff *= nums[len - i - 1];
            res = max(res, max(prev, suff));
            if(prev == 0) {
                prev = 1;
            }
            if(suff == 0) {
                suff = 1;
            }
        } 
        return res;
    }
};
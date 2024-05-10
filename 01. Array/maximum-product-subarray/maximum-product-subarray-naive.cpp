// Problem link: https://leetcode.com/problems/maximum-product-subarray/
// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            int product = 1;
            for(int j = i; j < nums.size(); j++) {
                product *= nums[j];
                res = max(res, product);
            }
        }
        return res;
    }
};
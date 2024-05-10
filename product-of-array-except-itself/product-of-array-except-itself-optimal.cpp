// Problem link: https://leetcode.com/problems/product-of-array-except-self/
// Time: O(n)
// Space: O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 1);
        int curr = 1;
        for(int i = 0; i < len; i++) {
            res[i] *= curr;
            curr *= nums[i];
        }
        curr = 1;
        for(int i = len - 1; i >= 0; i--) {
            res[i] *= curr;
            curr *= nums[i];
        }
        return res;
    }
};
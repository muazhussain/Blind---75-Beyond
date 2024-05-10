// Problem link: https://leetcode.com/problems/product-of-array-except-self/
// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            int suff = 1, pref = 1;
            for(int j = i - 1; j >= 0; j--) {
                pref *= nums[j];
            }
            for(int j = i + 1; j < nums.size(); j++) {
                suff *= nums[j];
            }
            res.push_back(pref * suff);
        }
        return res;
    }
};
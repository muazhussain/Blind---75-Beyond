// Problem link: https://leetcode.com/problems/product-of-array-except-self/
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> pref(len, 1), suff(len, 1);
        for(int i = 1; i < len; i++) {
            pref[i] = pref[i - 1] * nums[i - 1];
        }        
        for(int i = len - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] * nums[i + 1];
        }
        vector<int> res;
        for(int i = 0; i < len; i++) {
            res.push_back(pref[i] * suff[i]);
        }
        return res;
    }
};
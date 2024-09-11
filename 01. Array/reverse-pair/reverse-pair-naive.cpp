// Problem link: https://leetcode.com/problems/reverse-pairs/
// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] * 1LL > nums[j] * 2LL) {
                    count++;
                }
            }
        }
        return count;
    }
};
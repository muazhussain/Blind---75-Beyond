// Problem link: https://leetcode.com/problems/longest-consecutive-sequence/
// Time: O(nlogn)
// Space: O(1)

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int lastSmaller = INT_MIN;
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] - 1 == lastSmaller) {
                count++;
                lastSmaller = nums[i];
            } else if(nums[i] != lastSmaller) {
                lastSmaller = nums[i];
                count = 1;
            }
            res = max(res, count);
        } 
        return res;
    }
};
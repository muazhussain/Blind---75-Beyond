// Problem link: https://leetcode.com/problems/longest-consecutive-sequence/
// Time: O(n^3)
// Space: O(1)

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        int res = 0;
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int curr = nums[i] + 1;
            count = 1;
            while(find(nums.begin(), nums.end(), curr) != nums.end()) {
                curr++;
                count++;
            }
            res = max(res, count);
        }
        return res;
    }
};
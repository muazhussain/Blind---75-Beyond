// Problem link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Time: O(logn)
// Space: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int res = INT_MAX;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] <= nums[high]) {
                res = min(res, nums[mid]);
                high = mid - 1;
            } else {
                res = min(res, nums[low]);
                low = mid + 1;
            }
        }
        return res;
    }
};
// Problem link: https://leetcode.com/problems/find-the-duplicate-number/
// Time: O(nlogn)
// Space: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for(int e : nums) {
                if(e <= mid) {
                    count++;
                }
            }
            if(count > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
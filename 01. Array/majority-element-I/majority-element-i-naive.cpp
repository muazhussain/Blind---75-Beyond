// Problem link: https://leetcode.com/problems/majority-element-ii/
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = nums[0];
        int count = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
            if(count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }
        count = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == candidate) {
                count++;
            }
        }
        if(count > n / 2) {
            return candidate;
        }
        return -1;
    }
};
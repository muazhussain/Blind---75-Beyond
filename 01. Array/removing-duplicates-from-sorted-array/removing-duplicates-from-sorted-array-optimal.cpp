// Problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int index = 0, curr = 0;
        int n = nums.size();
        while(curr < n) {
            if(nums[index] != nums[curr]) {
                swap(nums[index + 1], nums[curr]);
                index++;
            }
            curr++;
        }
        return index + 1;
    }
};
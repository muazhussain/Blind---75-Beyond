// Problem link: https://leetcode.com/problems/contains-duplicate/
// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
        	for(int j = i + 1; j < nums.size(); j++) {
        		if(nums[i] == nums[j]) {
        			return true;
        		}
        	}
        }
        return false;
    }
};
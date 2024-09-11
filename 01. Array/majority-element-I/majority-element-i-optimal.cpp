// Problem link: https://leetcode.com/problems/majority-element-ii/
// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
        	int count = 1;
        	for(int j = i + 1; j < n; j++) {
        		if(nums[j] == nums[i]) {
        			count++;
        		}
        	}
        	if(count > n / 2) {
        		return nums[i];
        	}
        }
        return -1;
    }
};
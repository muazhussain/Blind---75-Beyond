// Problem link: https://leetcode.com/problems/next-greater-element-ii/
// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    	int n = nums.size();
        vector<int> nge(n, -1);
        for(int i = 0; i < n; i++) {
        	for(int j = i + 1; j < i + n; j++) {
        		if(nums[j % n] > nums[i]) {
        			nge[i] = nums[j % n];
        			break;
        		}
        	}
        }
        return nge;
    }
};
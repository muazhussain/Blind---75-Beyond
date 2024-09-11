// Problem link: https://leetcode.com/problems/two-sum/
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	int n = nums.size();
    	unordered_map<int, int> mark;
        for(int i = 0; i < n; i++) {
            int comp = target - nums[i];
            if(mark.find(comp) != mark.end()) {
                return {i, mark[comp]};
            }
            mark[nums[i]] = i;
        }
    	return {};
    }
};
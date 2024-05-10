// Problem link: https://leetcode.com/problems/two-sum/
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> lookup;
        for(int i = 0; i < nums.size(); i++) {
            if(lookup.find(target - nums[i]) != lookup.end()) {
                return {i, lookup[target - nums[i]]};
            }
            lookup[nums[i]] = i;
        }
        return {};
    }
};
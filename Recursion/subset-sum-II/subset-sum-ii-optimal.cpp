// Problem link: https://leetcode.com/problems/subsets-ii/
// Time: (2^len * len)
// Space: (2^len * len)
// Aux Space: O(len)

class Solution {
private:
    void findSubset(int index, vector<int>& nums, vector<int>& ds, vector<vector<int>>& res) {
        res.push_back(ds);
        for(int i = index; i < nums.size(); i++) {
            if(i != index && nums[i] == nums[i - 1]) {
                continue;
            }
            ds.push_back(nums[i]);
            findSubset(i + 1, nums, ds, res);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
        vector<int> ds;
        vector<vector<int>> res;
        findSubset(0, nums, ds, res);
        return res;
    }
};
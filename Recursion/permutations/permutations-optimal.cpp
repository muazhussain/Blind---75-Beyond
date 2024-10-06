// Problem link: https://leetcode.com/problems/permutations/
// Time: O(n!)
// Space: O(1)

class Solution {
private:
	void generatePermutations(int index, int n, vector<int>& nums, vector<vector<int>>& res) {
		if(index == n) {
			res.push_back(nums);
			return;
		}
		for(int i = index; i < n; i++) {
			swap(nums[i], nums[index]);
			generatePermutations(index + 1, n, nums, res);
			swap(nums[i], nums[index]);
		}
	}

public:
    vector<vector<int>> permute(vector<int>& nums) {
    	int n = nums.size();
        vector<vector<int>> res;
        generatePermutations(0, n, nums, res);
        return res;
    }
};
// Problem link: https://leetcode.com/problems/permutations/
// Time: O(n!)
// Space: O(n)

class Solution {
private:
	void generatePermutations(int n, vector<int>& nums, vector<int>& current, vector<bool>& freq, vector<vector<int>>& res) {
		if(current.size() == n) {
			res.push_back(current);
			return;
		}
		for(int i = 0; i < n; i++) {
			if(!freq[i]) {
				current.push_back(nums[i]);
				freq[i] = true;
				generatePermutations(n, nums, current, freq, res);
				current.pop_back();
				freq[i] = false;
			}
		}
	}

public:
    vector<vector<int>> permute(vector<int>& nums) {
    	int n = nums.size();
        vector<vector<int>> res;
        vector<bool> freq(n);
        vector<int> current;
        generatePermutations(n, nums, current, freq, res);
        return res;
    }
};
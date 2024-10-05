// Problem link: https://leetcode.com/problems/combination-sum-ii/
// Time: O(2^n)
// Space: O(average_size * number_of_combination)

class Solution {
private:
	void findCombinations(int index, int target, vector<int>& candidates, vector<int> current, vector<vector<int>>& res) {
		if(target == 0) {
			res.push_back(current);
			return;
		}
		for(int i = index; i < candidates.size(); i++) {
			if(i != index && candidates[i] == candidates[i - 1]) {
				continue;
			}
			if(candidates[i] > target) {
				break;
			}
			current.push_back(candidates[i]);
			findCombinations(i + 1, target - candidates[i], candidates, current, res);
			current.pop_back();
		}
	}

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    	sort(candidates.begin(), candidates.end());
    	vector<int> current;
    	vector<vector<int>> res;
    	findCombinations(0, target, candidates, current, res);   
    	return res;
    }
};
// Problem link: https://leetcode.com/problems/combination-sum/
// Time: O(2^t * k)
// Space: Unknown

class Solution {
private:
    void findCombinations(int index, int target, vector<int>& candidates, vector<int> current, vector<vector<int>>& res) {
        if(index == candidates.size()) {
            return;
        } else if(target == 0) {
            res.push_back(current);
            return;
        }
        if(candidates[index] <= target) {
            current.push_back(candidates[index]);
            findCombinations(index, target - candidates[index], candidates, current, res);
            current.pop_back();
        }
        findCombinations(index + 1, target, candidates, current, res);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> current;
        findCombinations(0, target, candidates, current, res);
        return res;
    }
};
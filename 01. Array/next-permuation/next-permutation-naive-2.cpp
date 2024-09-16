// Problem link: https://leetcode.com/problems/next-permutation/
// Time: O(n! * n)
// Space: O(n^2)

// doesnot work

class Solution {
private:
    void generatePermutations(vector<bool>& used, vector<int>& current, vector<int>& nums, vector<vector<int>>& list) {
        if(current.size() == nums.size()) {
            list.push_back(current);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(!used[i]) {
                current.push_back(nums[i]);
                used[i] = true;
                generatePermutations(used, current, nums, list);
                current.pop_back();
                used[i] = false;
            }
        }
    }

public:
    void nextPermutation(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> nums_copy = nums;
        sort(nums_copy.begin(), nums_copy.end());
        vector<int> current;
        vector<bool> used(nums.size());
        generatePermutations(used, current, nums_copy, list);
        for(int i = 0; i < list.size(); i++) {
            if(list[i] == nums) {
                if(i == list.size() - 1) {
                    nums = list[0];
                } else {
                    nums = list[i + 1];
                }
                break;
            }
        }
    }
};
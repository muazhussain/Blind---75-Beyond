// Problem link: https://leetcode.com/problems/next-permutation/
// Time: O(n! * n)
// Space: O(n^2)

// doesnot work

class Solution {
private:
    void generatePermutations(int index, vector<int>& nums, vector<vector<int>>& list) {
        if(index == nums.size()) {
            list.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            generatePermutations(index + 1, nums, list);
            swap(nums[i], nums[index]);
        }
    }

public:
    void nextPermutation(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> nums_copy = nums;
        sort(nums_copy.begin(), nums_copy.end());
        generatePermutations(0, nums_copy, list);
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
// Problem link: https://leetcode.com/problems/3sum/
// Time: O(n^2 + nlogn)
// Space: O(number-of-unique-triplets)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0) {
                    k--;
                } else if(sum < 0) {
                    j++;
                } else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    res.push_back(temp);
                    k--;
                    j++;
                    while(k > j && nums[k] == nums[k + 1]) k--;
                    while(j < k && nums[j] == nums[j - 1]) j++;
                }
            }
        }
        return res;
    }
};
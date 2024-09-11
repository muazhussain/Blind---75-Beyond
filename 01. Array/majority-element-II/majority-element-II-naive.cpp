// Problem link: https://leetcode.com/problems/majority-element-ii/
// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int count = 1;
            for(int j = i + 1; j < n; j++) {
                if(nums[j] == nums[i]) {
                    count++;
                }
            }
            if(count > n / 3) {
                s.insert(nums[i]);
            }
        }
        vector<int> res;
        for(int e : s) {
            res.push_back(e);
        }
        return res;
    }
};
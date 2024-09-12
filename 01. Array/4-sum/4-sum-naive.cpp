// Problem link: https://leetcode.com/problems/4sum/
// Time: O(n^4)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i = 0; i < n - 3; i++) {
            for(int j = i + 1; j < n - 2; j++) {
                for(int k = j + 1; k < n - 1; k++) {
                    for(int l = k + 1; l < n; l++) {
                        if(nums[i] * 1LL + nums[j] + nums[k] + nums[l] == target * 1LL) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};
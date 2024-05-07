// Problem link: https://leetcode.com/problems/3sum/
// Time: O(n^3 * log(number-of-unique-triplets))
// Space: O(number-of-triplets)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        for(int i = 0; i < nums.size() - 2; i++) {
            for(int j = i + 1; j < nums.size() - 1; j++) {
                for(int k = 0; k < nums.size(); k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        } 
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};
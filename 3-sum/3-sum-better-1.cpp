// Problem link: https://leetcode.com/problems/3sum/
// Time: O(n^2 * log(size-of-the-set))
// Space: O(n) + O(number-of-unique-triplets)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        for(int i = 0; i < nums.size() - 1; i++) {
            set<int> lookup;
            for(int j = i + 1; j < nums.size(); j++) {
                int third = -(nums[i] + nums[j]);
                if(lookup.find(third) != lookup.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                lookup.insert(nums[j]);
            }
        } 
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};
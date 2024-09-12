// Problem link: https://leetcode.com/problems/4sum/
// Time: O(n^3 * log(m))
// Space: O(n)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                set<long long> lookup;
                for(int k = j + 1; k < n; k++) {
                    long long comp = 1LL * target - (nums[i] * 1LL + nums[j] + nums[k]);  
                    if(lookup.find(comp) != lookup.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int) comp};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    } else {
                        lookup.insert(nums[k] * 1LL);
                    }
                }
            }
        }
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};
// Problem link: https://leetcode.com/problems/4sum/
// Time: O(n^3 + nlogn)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for(int j = i + 1; j < n; j++) {
                if(j != (i + 1) && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1, l = n - 1;
                while(k < l) {
                    long long sum = nums[i] * 1LL + nums[j] + nums[k] + nums[l];
                    if(sum == 1LL * target) {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        while(k < l && nums[k] == nums[k - 1]) {
                            k++;
                        }
                        l--;
                        while(k < l && nums[l] == nums[l + 1]) {
                            l--;
                        }
                    } else if(sum < target * 1LL) {
                        k++;
                    } else {
                        l--;
                    } 
                }
            }
        }
        return res;
    }
};
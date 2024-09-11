// Problem link: https://leetcode.com/problems/two-sum/
// Time: O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> temp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            temp.push_back({nums[i], i});
        }
        sort(temp.begin(), temp.end());
        int low = 0, high = n - 1;
        while(low < high) {
            int sum = temp[low].first + temp[high].first;
            if(sum == target) {
                return {temp[low].second, temp[high].second};
            } else if(sum < target) {
                low++;
            } else {
                high--;
            }
        }
    	return {};
    }
};
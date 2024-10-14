// Problem link: https://leetcode.com/problems/sliding-window-maximum/
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        deque<pair<int, int>> dq;
        for(int i = 0; i < n; i++) {
            while(!dq.empty() && dq.front().first <= nums[i]) {
                dq.pop_front();
            }
            dq.push_front({nums[i], i});
            while(!dq.empty() && dq.back().second <= i - k) {
                dq.pop_back();
            }
            if(i >= k - 1) {
                res.push_back(dq.back().first);
            }
        }
        return res;
    }
};
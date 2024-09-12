// Problem link: https://leetcode.com/problems/longest-consecutive-sequence/
// Time: O(nlogn)
// Space: O(n)

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        set<int> st(nums.begin(), nums.end());
        vector<int> temp(st.begin(), st.end());
        int res = 0;
        int n = temp.size();
        int i = 0;
        while(i < n) {
            int curr = temp[i] + 1;
            int count = 1;
            while(i + 1 < n && temp[i + 1] == curr) {
                count++;
                curr++;
                i++;
            }
            i++;
            res = max(res, count);
        } 
        return res;
    }
};
// Problem link: https://leetcode.com/problems/longest-consecutive-sequence/
// Time: O(n)
// Space: O(1)

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> st;
        for(int e : nums) {
            st.insert(e);
        }
        int res = 0;
        for(int e : st) {
            if(st.count(e - 1)) {
                continue;
            }
            int count = 1;
            int curr = e + 1;
            while(st.count(curr)) {
                curr++;
                count++;
            }
            res = max(res, count);
        }
        return res;
    }
};
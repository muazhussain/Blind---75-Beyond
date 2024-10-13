// Problem link: https://leetcode.com/problems/next-greater-element-i/
// Time: O(m + n)
// Space: O(m + n)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        unordered_map<int, int> nextGreater;
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() &&st.top() <= nums2[i]) {
                st.pop();
            }
            nextGreater[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        vector<int> res(m, -1);
        for(int i = 0; i < m; i++) {
            res[i] = nextGreater[nums1[i]];
        }
        return res;
    }
};
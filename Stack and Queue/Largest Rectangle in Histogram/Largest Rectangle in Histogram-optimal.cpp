// Problem link: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                res = max(res, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }
        while(!st.empty()) {
            int element = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            res = max(res, heights[element] * (nse - pse - 1));
        }
        return res;
    }
};
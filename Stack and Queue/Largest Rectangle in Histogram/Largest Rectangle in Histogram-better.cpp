// Problem link: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n, -1);
        vector<int> nse(n, -1);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        while(!st.empty()) {
            st.pop();
        }
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            res = max(res, heights[i] * (nse[i] - pse[i] + 1));
        }
        return res;
    }
};
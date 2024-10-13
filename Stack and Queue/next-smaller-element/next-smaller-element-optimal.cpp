// Problem link: https://www.naukri.com/code360/problems/next-smaller-element_1112581
// Time: O(n^2)
// Space: O(n)

#include<stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> nse(n, -1);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        nse[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return nse;
}
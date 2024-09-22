// Problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	set<int> st;
        for(int el : nums) {
        	st.insert(el);
        }
        int idx = 0;
        for(int el : st) {
            nums[idx++] = el;
        }
        return idx;
    }
};
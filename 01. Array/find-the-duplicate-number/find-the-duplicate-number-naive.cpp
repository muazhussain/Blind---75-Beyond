// Problem link: https://leetcode.com/problems/find-the-duplicate-number/
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> count;
        for(int e : nums) {
        	count[e]++;
        }
        for(auto p : count) {
        	if(p.second > 1) {
        		return p.first;
        	}
        }
        return -1;
    }
};
// Problem link: https://leetcode.com/problems/max-consecutive-ones/
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, res = 0;
        for(int el : nums) {
        	if(el == 1) {
        		count++;
        		res = max(res, count);
        	} else {
        		count = 0;
        	}
        }
        return res;
    }
};
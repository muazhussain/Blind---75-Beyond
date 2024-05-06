// Problem link: https://leetcode.com/problems/contains-duplicate/
// Time: O(n)
// Space: O(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> lookup;
        for(int i = 0; i < nums.size(); i++) {
            if(lookup[nums[i]] == true) {
                return true;
            }
            lookup[nums[i]] = true;
        }
        return false;
    }
};
// Problem link: https://leetcode.com/problems/majority-element-ii/
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> count;
        for(int e : nums) {
            count[e]++;
        }
        vector<int> res;
        for(auto p : count) {
            if(p.second > n / 3) {
                res.push_back(p.first);
            }
        }
        return res;
    }
};
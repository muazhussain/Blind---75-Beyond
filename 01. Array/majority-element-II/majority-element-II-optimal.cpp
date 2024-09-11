// Problem link: https://leetcode.com/problems/majority-element-ii/
// Time: O(n)
// Space: O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0, element1 = INT_MIN, count2 = 0, element2 = INT_MIN;
        for(int e : nums) {
            if(count1 == 0 && element2 != e) {
                count1++;
                element1 = e;
            } else if(count2 == 0 && element1 != e) {
                count2++;
                element2 = e;
            } else if(element1 == e) {
                count1++;
            } else if(element2 == e) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int e : nums) {
            if(e == element1) {
                count1++;
            } else if(e == element2) {
                count2++;
            }
        }
        vector<int> res;
        if(count1 > n / 3) {
            res.push_back(element1);
        }
        if(count2 > n / 3) {
            res.push_back(element2);
        }
        return res;
    }
};
// Problem link: https://leetcode.com/problems/sort-colors/
// Time: O(n)
// Space: O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0, twos = 0;
        for(int e : nums) {
            e == 0 ? zeros ++ : e == 1 ? ones++ : twos++;
        }
        int index = 0;
        while(zeros--) {
            nums[index++] = 0;
        }
        while(ones--) {
            nums[index++] = 1;
        }
        while(twos--) {
            nums[index++] = 2;
        }
    }
};
// Problem link: https://leetcode.com/problems/next-greater-element-i/
// Time: O(m * n)
// Space: O(m)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res(m, -1);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(nums1[i] == nums2[j]) {
                    for(int k = j + 1; k < n; k++) {
                        if(nums2[k] > nums2[j]) {
                            res[i] = nums2[k];
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return res;
    }
};
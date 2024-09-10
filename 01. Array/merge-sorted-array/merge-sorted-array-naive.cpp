// Problem link: https://leetcode.com/problems/merge-sorted-array/
// Time: O((m + n)log(m + n))
// Space: O(m + n)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
 		vector<int> temp(m + n);
 		for(int i = 0; i < m; i++) {
 			temp[i] = nums1[i];
 		}       
 		for(int i = 0; i < n; i++) {
 			temp[m + i] = nums2[i];
 		}
 		sort(temp.begin(), temp.end());
 		nums1 = temp;
    }
};
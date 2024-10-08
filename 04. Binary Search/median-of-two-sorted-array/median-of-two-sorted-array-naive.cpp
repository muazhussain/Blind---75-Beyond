// Problem link: 
// Time: O(m + n)
// Space: O(m + n)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> temp(m + n);
        int i = 0, j = 0, idx = 0;
        while(i < m && j < n) {
        	if(nums1[i] < nums2[j]) {
        		temp[idx] = nums1[i];
        		i++;
        	} else {
        		temp[idx] = nums2[j];
        		j++;
        	}
        	idx++;
        }
        while(i < m) {
        	temp[idx] = nums1[i];
			i++;
			idx++;
        }
        while(j < n) {
        	temp[idx] = nums2[j];
        	j++;
        	idx++;
        }
        if((m + n) % 2 == 0) {
	        return (temp[(m + n) / 2] + temp[(m + n) / 2 - 1]) / 2.0;
        }
		return temp[(m + n) / 2] / 1.0;
    }
};
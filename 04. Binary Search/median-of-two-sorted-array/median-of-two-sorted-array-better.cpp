// Problem link: 
// Time: O(m + n)
// Space: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int idx1 = (m + n) / 2;
        int idx2 = (m + n) / 2 - 1;
        int cnt = 0;
        int idx1El = -1, idx2El = -1;
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                if(cnt == idx1) {
                    idx1El = nums1[i];
                }
                if(cnt == idx2) {
                    idx2El = nums1[i];
                }
                i++;
            } else {
                if(cnt == idx1) {
                    idx1El = nums2[j];
                }
                if(cnt == idx2) {
                    idx2El = nums2[j];
                }
                j++;
            }
            cnt++;
        }
        while(i < m) {
            if(cnt == idx1) {
                idx1El = nums1[i];
            }
            if(cnt == idx2) {
                idx2El = nums1[i];
            }
            i++;
            cnt++;
        }
        while(j < n) {
            if(cnt == idx1) {
                idx1El = nums2[j];
            }
            if(cnt == idx2) {
                idx2El = nums2[j];
            }
            j++;    
            cnt++;
        }
        if((m + n) % 2 == 0) {
            return (idx1El + idx2El) / 2.0;
        }
        return idx1El / 1.0;
    }
};
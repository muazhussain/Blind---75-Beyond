// Problem link: 
// Time: O(log(m))
// Space: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int low = 0, high = m;
        int max1, max2;
        int min1, min2;
        while(low <= high) {
            int i1 = (low + high) / 2;
            int i2 = (m + n + 1) / 2 - i1;
            min1 = (i1 == m) ? INT_MAX : nums1[i1];
            max1 = (i1 == 0) ? INT_MIN : nums1[i1 - 1];
            min2 = (i2 == n) ? INT_MAX : nums2[i2];
            max2 = (i2 == 0) ? INT_MIN : nums2[i2 - 1];
            if(max1 <= min2 && max2 <= min1) {
                break;
            } else if(max1 > min2) {
                high = i1 - 1;
            } else {
                low = i1 + 1;
            }
        }
        if((m + n) % 2 == 1) {
            return max(max1, max2) / 1.0;
        }
        return ((max(max1, max2) + min(min1, min2)) / 2.0);
    }
};
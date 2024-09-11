// Problem link: https://leetcode.com/problems/reverse-pairs/
// Time: O(nlogn)
// Space: O(n)

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int res = mergeSort(nums, 0, nums.size() - 1);
        return res;
    }

    int countPairs(vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int i = low, j = mid + 1;
        while(i <= mid) {
            while(j <= high && nums[i] * 1LL > nums[j] * 2LL) {
                j++;
            }
            count += (j - (mid + 1));
            i++;
        }
        return count;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        if(low >= high) {
            return 0;
        }
        int count = 0;
        int mid = low + (high - low) / 2;
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return count;
    }

    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp(high - low + 1);
        int i = low, j = mid + 1, k = 0;
        while(i <= mid && j <= high) {
            if(nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while(i <= mid) {
            temp[k++] = nums[i++];
        }
        while(j <= high) {
            temp[k++] = nums[j++];
        }
        for(k = low; k <= high; k++) {
            nums[k] = temp[k - low];
        }
    }
};
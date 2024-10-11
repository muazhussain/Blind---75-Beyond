// Problem link: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
// Time: O(max_element) * log(max)
// Space: O(1)

class Solution {
private:
	int countStore(vector<int>& quantities, int item) {
		int count = 0;
		for(int quantity : quantities) {
			count += (quantity + item - 1) / item;
		}
		return count;
	}

public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        while(low <= high) {
        	int mid = low + (high - low) / 2;
        	int stores = countStore(quantities, mid);
        	if(stores <= n) {
        		high = mid - 1;
        	} else {
        		low = mid + 1;
        	}
        }
        return low;
    }
};
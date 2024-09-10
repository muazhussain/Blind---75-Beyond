// Problem link: https://www.interviewbit.com/problems/repeat-and-missing-number-array/
// Time: O(n)
// Space: O(1)

class Solution {
  public:
   vector<int> findTwoElement(vector<int> arr) {
        int xr = 0;
        int n = arr.size();
		for(int i = 0; i < n; i++) {
			xr	^= arr[i];
			xr ^= (i + 1);
		}
		int bitNum = (xr & ~(xr - 1));
		int x = 0, y = 0;
		for(int e : arr) {
			if((e & bitNum) == 0) {
				x ^= e;
			} else{
				y ^= e;
			}
		}
		for(int i = 1; i <= n; i++) {
			if((i & bitNum) == 0) {
				x ^= i;
			} else {
				y ^= i;
			}
		}
		int count = 0;
		for(int e : arr) {
			if(e == x) {
				count++;
			}
		}
		if(count == 2) {
			return {x, y};
		}
		return {y, x};
    }
};
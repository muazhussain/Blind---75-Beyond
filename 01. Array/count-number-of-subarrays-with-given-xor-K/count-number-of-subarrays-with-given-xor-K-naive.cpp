// Problem link: https://www.naukri.com/code360/problems/count-subarrays-with-given-xor_1115652
// Time: O(n^3)
// Space: O(1)

int subarraysXor(vector<int> &arr, int x) {
	int n = arr.size();
	int res = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			int xr = 0;
			for(int k = i; k <= j; k++) {
				xr ^= arr[k];
			}
			if(xr == x) {
				res++;
			}
		}
	}
	return res;
}
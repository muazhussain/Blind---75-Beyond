// Problem link: https://www.naukri.com/code360/problems/count-subarrays-with-given-xor_1115652
// Time: O(n^2)
// Space: O(1)

int subarraysXor(vector<int> &arr, int x) {
	int n = arr.size();
	int res = 0;
	for(int i = 0; i < n; i++) {
		int xr = 0;
		for(int j = i; j < n; j++) {
			xr ^= arr[j];	
			if(xr == x) {
				res++;
			}
		}
	}
	return res;
}
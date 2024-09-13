// Problem link: https://www.naukri.com/code360/problems/count-subarrays-with-given-xor_1115652
// Time: O(n)
// Space: O(n)

int subarraysXor(vector<int> &arr, int x) {
	int n = arr.size();
	int res = 0;
	int curr = 0;
	unordered_map<int, int> lookup;
	lookup[curr]++;
	for(int i = 0; i < n; i++) {
		curr ^= arr[i];
		int comp = curr^x;
		if(lookup.find(comp) != lookup.end()) {
			res += lookup[comp];
		}
		lookup[curr]++;
	}
	return res;
}
// Problem link: https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0&leftPanelTabValue=PROBLEM
// Time: O(n)
// Space: O(k)

#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
	vector<bool> prev(k + 1, false);
	prev[0] = true;
	prev[arr[0]] = true;
	for(int index = 1; index < n; index++) {
		vector<bool> curr(k + 1, false);
		curr[0] = true;
		for(int target = 1; target <= k; target++) {
			bool notTake = prev[target];
			bool take = false;
			if(arr[index] <= target) {
				take = prev[target - arr[index]];
			}
			curr[target] = take | notTake;
		}
		prev = curr;
	}
	return prev[k];
}
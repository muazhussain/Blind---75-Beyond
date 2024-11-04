// Problem link: https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0&leftPanelTabValue=PROBLEM
// Time: O(n)
// Space: O(n * k)

#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr) {
	vector<vector<bool>> dp(n, vector<bool> (k + 1, false));
	for(int i = 0; i < n; i++) {
		dp[i][0] = true;
	}
	dp[0][arr[0]] = true;
	for(int index = 1; index < n; index++) {
		for(int target = 1; target <= k; target++) {
			bool notTake = dp[index - 1][target];
			bool take = false;
			if(target >= arr[index]) {
				take = dp[index - 1][target - arr[index]];
			}
			dp[index][target] = take || notTake;
		}
	}
	return dp[n - 1][k];
}
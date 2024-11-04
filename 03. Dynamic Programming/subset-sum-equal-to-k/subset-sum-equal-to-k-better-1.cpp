// Problem link: https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0&leftPanelTabValue=PROBLEM
// Time: O(n)
// Space: O(n * k)

#include <bits/stdc++.h> 
int findSequence(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
	if(target == 0) {
		return true;
	}
	if(index == 0) {
		return arr[index] == target;
	}
	if(dp[index][target] != -1) {
		return dp[index][target];
	}
	bool notTake = findSequence(index - 1, target, arr, dp);
	bool take = false;
	if(target >= arr[index]) {
		take = findSequence(index - 1, target - arr[index], arr, dp);
	}
	return dp[index][target] = (int) take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
	vector<vector<int>> dp(n, vector<int> (k + 1, -1));
	return (bool) findSequence(n - 1, k, arr, dp);
}
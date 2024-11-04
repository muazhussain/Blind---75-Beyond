// Problem link: https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0&leftPanelTabValue=PROBLEM
// Time: O(2^n)
// Space: O(n)

#include <bits/stdc++.h> 
bool findSequence(int index, int target, vector<int>& arr) {
	if(target == 0) {
		return true;
	}
	if(index == 0) {
		return arr[index] == target;
	}
	bool notTake = findSequence(index - 1, target, arr);
	bool take = false;
	if(target >= arr[index]) {
		take = findSequence(index - 1, target - arr[index], arr);
	}
	return take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
	return findSequence(n - 1, k, arr);
}
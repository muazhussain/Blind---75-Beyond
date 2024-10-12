// Problem link: https://www.spoj.com/problems/AGGRCOW/
// Time: O(log(max-min) * n + nlog(n))
// Space: O(1)

#include<bits/stdc++.h>
using namespace std;

int countCows(vector<int>& stalls, int dist) {
	int cows = 1;
	int lastStallPos = stalls[0];
	for(int i = 1; i < stalls.size(); i++) {
		if(stalls[i] - lastStallPos >= dist) {
			cows++;
			lastStallPos = stalls[i];
		}
	}
	return cows;
}

void solve() {
	int n, c;
	cin >> n >> c;
	vector<int> stalls(n);
	for(int &el : stalls) {
		cin >> el;
	}
	sort(stalls.begin(), stalls.end());
	int low = 1, high = stalls[n - 1] - stalls[0];
	int res = -1;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		int cows = countCows(stalls, mid);
		if(cows >= c) {
			res = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	cout << res << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}
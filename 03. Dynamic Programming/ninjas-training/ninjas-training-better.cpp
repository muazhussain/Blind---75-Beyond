// Problem link: https://www.naukri.com/code360/problems/ninja-s-training_3621003
// Time: (n)
// Space: O(n)

int findMax(int day, int task, vector<vector<int>>& points, vector<vector<int>>& dp) {
	if(dp[day][task] != -1) {
		return dp[day][task];
	}
	if(day == 0) {
		int maxPoint = 0;
		for(int i = 0; i < 3; i++) {
			if(i != task) {
				maxPoint = max(maxPoint, points[0][i]);
			}
		}
		return dp[day][task] = maxPoint;
	}
	int maxPoint = 0;
	for(int i = 0; i < 3; i++) {
		if(i != task) {
			maxPoint = max(maxPoint, points[day][i] + findMax(day - 1, i, points, dp));
		}
	}
	return dp[day][task] = maxPoint;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
	vector<vector<int>> dp(n, vector<int> (4, -1));
	return findMax(n - 1, 3, points, dp);
}
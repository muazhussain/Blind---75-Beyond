// Problem link: https://www.naukri.com/code360/problems/ninja-s-training_3621003
// Time: (3^n)
// Space: O(n)

int findMax(int day, int task, vector<vector<int>>& points) {
	if(day == 0) {
		int maxPoint = 0;
		for(int i = 0; i < 3; i++) {
			if(i != task) {
				maxPoint = max(maxPoint, points[0][i]);
			}
		}
		return maxPoint;
	}
	int maxPoint = 0;
	for(int i = 0; i < 3; i++) {
		if(i != task) {
			maxPoint = max(maxPoint, points[day][i] + findMax(day - 1, i, points));
		}
	}
	return maxPoint;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
	return findMax(n - 1, 3, points);
}